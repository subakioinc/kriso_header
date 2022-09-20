#include <stdint.h>

typedef struct _VccToController{
    // 관제 명령(운항+DP)
    uint32_t oper_mode; // 무인선 운용 모드
    float spd_cmd; // 속도 명령
    float hdg_cmd; // 선수각명령(해딩제어 모드)
    double target_wp_lat; // 목표 경유점 경도
    double target_wp_lon; // 목표 경유점 위도
    double targetposition_X; // 목표 위치유지 목표 위치
    double targetposition_Y; // 목표 위치유지 목표 위치
    float targetposition_yaw; // 동적 위치유지 목표 선수각
    // 충돌회피
    uint32_t ca_mode; // 충돌회피 모드 (Enable/Disable)
    uint32_t ca_method; // 충돌회피 방법 (Reactive / Path plan)
    float ca_alert_range; // 회피시작 조건(거리)
    float ca_avoid_range; // VO 반지름 거리
    float ca_param1; // TBD
    float ca_param2; // TBD
    float ca_param3; // TBD
    float ca_param4; // TBD
    float ca_param5; // TBD
    float ca_param6; // TBD
    float ca_param7; // TBD
    // 운항 제어 게인
    float nav_surge_pgain; // 제어 게인(튜닝용)
    float nav_surge_dgain; // 제어 게인(튜닝용)
    float nav_yaw_pgain;   // 제어 게인(튜닝용)
    float nav_yaw_dgain;   // 제어 게인(튜닝용)
    // DP 제어 게인
    float dp_surge_pgain;
    float dp_surge_dgain;
    float dp_sway_pgain;
    float dp_sway_dgain;
    float dp_yaw_pgain;
    float dp_yaw_dgain;
    // DP
    double surge_current;
    double sway_current;
    double yaw_current;
    double heave_current;
    double roll_current;
    double pitch_current;
} VccToController;
