import socket
import struct
from time import sleep


# 1. packet 구조체
# 2. 특정 field 1씩 증가시키기
# 3. UDP로 전송

class ControlToVcc:
    def __init__(self):
        self.t1_rpm = 0.1
        self.t2_rpm = 1.1
        self.t3_rpm = 2.1
        self.t3_angle = 3.1
        self.t4_rpm = 4.1
        self.t4_angle = 5.1
        self.oper_mode = 100
        self.mission_mode = 200
    def update(self):
        self.t1_rpm+= 0.1
        self.t2_rpm+= 0.1
        self.t3_rpm+= 0.1
        self.t3_angle+= 0.1
        self.t4_rpm+= 0.1
        self.t4_angle+= 0.1
        self.oper_mode+= 1
        self.mission_mode+= 1
    def toBuffer(self):
        return struct.pack('=6f2I',
            self.t1_rpm, 
            self.t2_rpm, 
            self.t3_rpm, 
            self.t3_angle, 
            self.t4_rpm, 
            self.t4_angle, 
            self.oper_mode, 
            self.mission_mode)
    
class WtToVcc:
    def __init__(self):
        self.psi_d=10.1
        self.spd_d=11.1          
        self.wp_lat_d=12.1     
        self.wp_lon_d=13.1     
        self.track_path_id=1100
    def update(self):
        self.psi_d+=0.1
        self.spd_d+=0.1          
        self.wp_lat_d+=0.1     
        self.wp_lon_d+=0.1     
        self.track_path_id+=1

    def toBuffer(self):
        return struct.pack('=4f1I', 
            self.psi_d, 
            self.spd_d,     
            self.wp_lat_d,
            self.wp_lon_d,
            self.track_path_id
        )
    
class CkToVcc:
    def __init__(self):
        self.psi_d = 20.1
        self.spd_d = 30.1
    def update(self):
        self.psi_d+=0.1
        self.spd_d+=0.1
    def toBuffer(self):
        return struct.pack('=2f',
            self.psi_d,
            self.spd_d)

class CaToVcc:
    def __init__(self):
        self.ca_mode = 400        
        self.ca_method = 500
        self.ca_status = 600 
        # self.ca_risk_arr[900]
        # self.reactive_spd_d  
        # self.reactive_psi_d  
        # self.local_path[100] 
    def update(self):
        self.ca_mode+=1        
        self.ca_method+=1
        self.ca_status+=1 
        
    def toBuffer(self):
        return struct.pack('=3I',
            self.ca_mode,     
            self.ca_method,
            self.ca_status 
            )

class DpToVcc:
    def __init__(self):
        self.surge_error = 40.1
        self.sway_error = 50.1
        self.yaw_error = 60.1
        self.dp_start_stop = 800
    def update(self):
        self.surge_error+=0.1
        self.sway_error+=0.1
        self.yaw_error+=0.1
        self.dp_start_stop+=1
    def toBuffer(self):
        return struct.pack('=3d1I',
            self.surge_error,
            self.sway_error,
            self.yaw_error,
            self.dp_start_stop)

def main():
    print("Middleware to VCC Sender Start!!")
    serverAddressPort   = ("127.0.0.1", 20211)
    bufferSize          = 2048

    sendPacket = ControlToVcc()
        
    # 클라이언트 쪽에서 UDP 소켓 생성
    UDPClientSocket = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM)

    while(1):
        UDPClientSocket.sendto(sendPacket.toBuffer(), serverAddressPort)
        sendPacket.update()
        print("ControlToVccMiddleware packet was sent to VCC")     
        sendPacket.fromBuffer()   
        sleep(1)

if __name__ == "__main__":
    main()
