import socket
from threading import Thread
from multiprocessing import Process,Queue

'''
服务端有固定ip和port，24小时不间断，能支持并发
'''

server = socket.socket() #括号内不加参数默认是tcp协议
server.bind(('127.0.0.1',8080))
server.listen(5)


#将服务代码封装成一个单独的函数
# 通信循环
def task(conn):
    while True:
        try:
            data = conn.recv(1024)
            if len(data) == 0:break
            print(data.decode('utf-8'))
            conn.send(data.upper())
        except ConnectionResetError as e:
            print(e)
            break
    conn.close()


while True:
    conn, addr = server.accept()
    #叫其他人来服务顾客
    t = Thread(target=task, args=(conn,))
    t.start()