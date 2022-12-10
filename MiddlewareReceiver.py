import socket
import struct
from time import sleep


IP_ADDR = "127.0.0.1"
PORT = 20211

PACKET_FORMAT = '=1B8f2d14f'

# 1. packet 구조체
# 2. 특정 field 1씩 증가시키기
# 3. UDP로 전송

class MiddlewareToVccPacket:
    def __init__(self):
        self.nav_mode = 1
        self.nav_roll  = 2.0
        self.nav_pitch = 3.0
        self.nav_yaw = 4.0
        self.nav_cog = 5.0
        self.nav_sog = 6.0
        self.nav_uspd = 7.0
        self.nav_vspd  = 8.0
        self.nav_wspd  = 9.0
        self.nav_longitude = 10.0
        self.nav_latitude = 11.0
        self.nav_heave  = 12.0
        self.nav_gpstime  = 13.0
        self.wea_airtem   = 14.0
        self.wea_wattem   = 15.0
        self.wea_press    = 16.0
        self.wea_relhum    = 17.0
        self.wea_dewpt    = 18.0
        self.wea_windirt   = 19.0
        self.wea_winspdt  = 20.0
        self.wea_windirr  = 21.0
        self.wea_watspdr  = 22.0
        self.wea_watdir   = 23.0
        self.wea_watspd   = 24.0
        self.wea_visibiran = 25.0
    def update(self):
        self.nav_mode=(self.nav_mode +1)% 255
        self.nav_longitude+=0.1
        self.nav_latitude+=0.1
        self.wea_visibiran+=1.0
    def toBuffer(self):
        return struct.pack('=1B8f2d14f',
        self.nav_mode,
        self.nav_roll ,
        self.nav_pitch,
        self.nav_yaw,
        self.nav_cog,
        self.nav_sog, 
        self.nav_uspd,
        self.nav_vspd ,
        self.nav_wspd ,
        self.nav_longitude,
        self.nav_latitude,
        self.nav_heave ,
        self.nav_gpstime ,
        self.wea_airtem  ,
        self.wea_wattem  ,
        self.wea_press   ,
        self.wea_relhum   ,
        self.wea_dewpt   ,
        self.wea_windirt  ,
        self.wea_winspdt ,
        self.wea_windirr ,
        self.wea_watspdr ,
        self.wea_watdir  ,
        self.wea_watspd  ,
        self.wea_visibiran)
    def fromBuffer(self, buf):
        result = struct.unpack(PACKET_FORMAT, buf)
        print(result[0]) #mode
        print(result[9]) #nav_longitude
        print(result[10]) # nav_latitude
        print(result[24]) # wea_visibiran

# def main():
#     print("Middleware to VCC UDP Server Start!!")
#     serverAddressPort   = ("127.0.0.1", 20211)
#     bufferSize          = 2048

#     sendPacket = MiddlewareToVccPacket()
        
#     # 클라이언트 쪽에서 UDP 소켓 생성
#     UDPClientSocket = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM)

#     while(1):
#         UDPClientSocket.sendto(sendPacket.toBuffer(), serverAddressPort)
#         sendPacket.update()
#         print("Middleware packet was sent to VCC")     
#         sendPacket.fromBuffer()   
#         sleep(1)

def main():
    print("Middleware Receiver Start!!")

    # 데이터그램 소켓을 생성
    UDPServerSocket = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM)
    MiddlewarePort   = (IP_ADDR, PORT)
    # 주소와 IP로 Bind
    UDPServerSocket.bind(MiddlewarePort)

    # bufferSize          = 1024
    bufferSize = struct.calcsize(PACKET_FORMAT)
    print("Should be: 105!!! Buffer Size : ", bufferSize)

    packet = MiddlewareToVccPacket()
        
    while(1):
        bytesAddressPair = UDPServerSocket.recvfrom(bufferSize)
        message = bytesAddressPair[0]
        address = bytesAddressPair[1]
        
        packet.fromBuffer(message)
        # packet.printMsg()

        print("Middleware packet was received !!")        
        sleep(1)

if __name__ == "__main__":
    main()
