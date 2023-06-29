import socket
import struct
from time import sleep


# 1. packet 구조체
# 2. 특정 field 1씩 증가시키기
# 3. UDP로 전송
IP_ADDR = "127.0.0.1"
PORT = 20211

PACKET_FORMAT = '=1B8f2d14f'

class VccToControl:
    def __init__(self):
        self.oper_mode = 100
        self.mission_mode = 200
        self.ca_mode = 300
        self.ca_method = 400
        self.packet_foramt = '=4I'
    def update(self):
        self.oper_mode+=1
        self.mission_mode+=1
        self.ca_mode+=1
        self.ca_method+=1
    def toBuffer(self):
        return struct.pack('=4I',
            self.oper_mode,
            self.mission_mode,
            self.ca_mode,
            self.ca_method)
    def fromBuffer(self, buf):
        result = struct.unpack(self.packet_foramt, buf)
        print(result[0])
        print(result[1])
        print(result[2])
        print(result[3])

class WtToControl:
    def __init__(self):
        self.nav_surge_pgain=10.1
        self.nav_surge_dgain=11.1          
        self.nav_yaw_pgain=12.1     
        self.nav_yaw_dgain=13.1

        self.packet_foramt = '=4f'
    def update(self):
        self.nav_surge_pgain+=0.1
        self.nav_surge_dgain+=0.1          
        self.nav_yaw_pgain+=0.1   
        self.nav_yaw_dgain+=0.1
    def toBuffer(self):
        return struct.pack(self.packet_foramt, 
            self.nav_surge_pgain, 
            self.nav_surge_dgain,     
            self.nav_yaw_pgain,
            self.nav_yaw_dgain
        )
    def fromBuffer(self, buf):
        result = struct.unpack(self.packet_foramt, buf)
        print(result[0])
        print(result[1])
        print(result[2])
        print(result[3])
class CkToControl:
    def __init__(self):
        self.spd_cmd = 20.1
        self.hdg_cmd = 21.1
        self.nav_surge_pgain = 22.1
        self.nav_surge_dgain = 23.1
        self.nav_yaw_pgain = 24.1
        self.nav_yaw_dgain = 25.1
        self.packet_foramt = '=6f'
    def update(self):
        self.spd_cmd+=0.1
        self.hdg_cmd+=0.1
        self.nav_surge_pgain+=0.1
        self.nav_surge_dgain+=0.1
        self.nav_yaw_pgain+=0.1
        self.nav_yaw_dgain+=0.1
    def toBuffer(self):
        return struct.pack(self.packet_foramt,
            self.spd_cmd,
            self.hdg_cmd,
            self.nav_surge_pgain,
            self.nav_surge_dgain,
            self.nav_yaw_pgain, 
            self.nav_yaw_dgain)
    def fromBuffer(self, buf):
        result = struct.unpack(self.packet_foramt, buf)
        print(result[0])
        print(result[1])
        print(result[2])
        print(result[3])

class CaToControl:
    def __init__(self):
        self.ca_alert_range = 40.0
        self.ca_avoid_range = 41.0
        self.ca_param1 = 42.0     
        self.ca_param2 = 43.0     
        self.ca_param3 = 44.0     
        self.ca_param4 = 45.0     
        self.ca_param5 = 46.0     
        self.ca_param6 = 47.0     
        self.ca_param7 = 48.0
        self.packet_foramt = '=9f'
        # self.ca_risk_arr[900]
        # self.reactive_spd_d  
        # self.reactive_psi_d  
        # self.local_path[100] 
    def update(self):
        self.ca_alert_range+=0.1
        self.ca_avoid_range+=0.1
        self.ca_param1+=0.1    
        self.ca_param2+=0.1    
        self.ca_param3+=0.1    
        self.ca_param4+=0.1    
        self.ca_param5+=0.1    
        self.ca_param6+=0.1    
        self.ca_param7+=0.1
         
    def toBuffer(self):
        return struct.pack(self.packet_foramt,
            self.ca_alert_range,
            self.ca_avoid_range,
            self.ca_param1,     
            self.ca_param2,     
            self.ca_param3,     
            self.ca_param4,     
            self.ca_param5,     
            self.ca_param6,     
            self.ca_param7)
    def fromBuffer(self, buf):
        result = struct.unpack(self.packet_foramt, buf)
        print(result[0])
        print(result[1])
        print(result[2])
        print(result[3])

class DpToControl:
    def __init__(self):
        self.target_wp_lat = 100.0
        self.target_wp_lon = 101.0
        self.targetposition_yaw = 102.0
        self.dp_surge_pgain = 103.0
        self.dp_surge_dgain = 104.0
        self.dp_sway_pgain = 105.0
        self.dp_sway_dgain = 106.0
        self.dp_yaw_pgain = 107.0
        self.dp_yaw_dgain = 108.0
    def update(self):
        self.target_wp_lat+=0.1
        self.target_wp_lon+=0.1
        self.targetposition_yaw+=0.1
        self.dp_surge_pgain+=0.1
        self.dp_surge_dgain+=0.1
        self.dp_sway_pgain+=0.1
        self.dp_sway_dgain+=0.1
        self.dp_yaw_pgain+=0.1
        self.dp_yaw_dgain+=0.1
    def toBuffer(self):
        return struct.pack('=2d7f',
            self.target_wp_lat, 
            self.target_wp_lon, 
            self.targetposition_yaw,
            self.dp_surge_pgain,
            self.dp_surge_dgain,
            self.dp_sway_pgain,
            self.dp_sway_dgain,
            self.dp_yaw_pgain,
            self.dp_yaw_dgain
        )

def main():
    print("VccToControl Receiver Start!!")

    # 데이터그램 소켓을 생성
    UDPServerSocket = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM)
    MiddlewarePort   = (IP_ADDR, PORT)
    # 주소와 IP로 Bind
    UDPServerSocket.bind(MiddlewarePort)

    packet = VccToControl()
    # bufferSize          = 1024
    bufferSize = struct.calcsize(packet.packet_foramt)
    print("Buffer Size : ", bufferSize)



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
