typedef struct _VccToController{
    // 관제 명령(운항+DP)
    uint32_t Oper_Mode; // 무인선 운용 모드
    float Spd_Cmd; // 속도 명령
    float Hdg_Cmd; // 선수각명령(해딩제어 모드)
    double Target_WP_lat; // 목표 경유점 경도
    double Target_WP_lon; // 목표 경유점 위도
    double TargetPosition_X; // 목표 위치유지 목표 위치
    double TargetPosition_Y; // 목표 위치유지 목표 위치
    float TargetPosition_Yaw; // 동적 위치유지 목표 선수각
    // 충돌회피
    uint32_t CA_Mode; // 충돌회피 모드 (Enable/Disable)
    uint32_t CA_Method; // 충돌회피 방법 (Reactive / Path plan)
    float CA_Alert_Range; // 회피시작 조건(거리)
    float CA_Avoid_Range; // VO 반지름 거리
    float CA_param1; // TBD
    float CA_param2; // TBD
    float CA_param3; // TBD
    float CA_param4; // TBD
    float CA_param5; // TBD
    float CA_param6; // TBD
    float CA_param7; // TBD
    // 운항 제어 게인
    float Nav_Surge_Pgain; // 제어 게인(튜닝용)
    float Nav_Surge_Dgain; // 제어 게인(튜닝용)
    float Nav_Yaw_Pgain;   // 제어 게인(튜닝용)
    float Nav_Yaw_Dgain;   // 제어 게인(튜닝용)
} VccToController;
