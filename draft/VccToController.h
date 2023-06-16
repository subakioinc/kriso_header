#include <stdint.h>

// @hspark(230531) Waypoint 구조체 생성
typedef struct _Waypoint {
    double lat;                 // 경유점 경도(deg)
    double lon;                 // 경유점 위도(deg)
    float spd_cmd;              // 경유점에서의 속도 명령값(knots)
    float acceptance_radius;    // 경유점 도착 반경(L), L: 10.44m
} Waypoint;

typedef struct _CmdtoController{ // @hspark(230615) 항상 송신 혹은 oper_mode 1 or 2 일 때 송신
    // 관제 명령(운항+DP)
    uint32_t oper_mode; // 현재 운용 모드 // @hspark(230531) 무인선 운용 모드 0: 수동, 1: 자동, 2: 시뮬레이션
    uint32_t mission_mode; // @hspark(230531) 무인선 운용 임무 0: WP, 1: HDG, 2: DP 
    // 충돌회피
    uint32_t ca_mode; // 충돌회피 모드 (Enable/Disable) // @hspark(230531) 0: Disable, 1: Enable
    uint32_t ca_method; // 충돌회피 방법 (Reactive / Path plan) // @hspark(230531) 0: Path plan, 1: Reactive
    // DP // @hspark(230531) 지움. 센서에서 올라오는 값 사용
//    double surge_current;
//    double sway_current;
//    double yaw_current;
//    double heave_current;
//    double roll_current;
//    double pitch_current;
} CmdtoController;

typedef struct _WTtoController { // @hspark(230615) oper_mode 1 or 2, mission_mode 0 일 때 송신
    Waypoint global_path[100]; // @hspark(230531) QGC로부터 수신받은 전역경로의 경유점 
    // 운항 제어 게인
    float nav_surge_pgain; // 제어 게인(튜닝용)
    float nav_surge_dgain; // 제어 게인(튜닝용)
    float nav_yaw_pgain;   // 제어 게인(튜닝용)
    float nav_yaw_dgain;   // 제어 게인(튜닝용)
} WTtoController;

typedef struct _CKtoController { // @hspark(230615) oper_mode 1 or 2, mission_mode 1 일 때 송신
    float spd_cmd; // 속도 명령
    float hdg_cmd; // 선수각명령(해딩제어 모드)
    // 운항 제어 게인
    float nav_surge_pgain; // 제어 게인(튜닝용)
    float nav_surge_dgain; // 제어 게인(튜닝용)
    float nav_yaw_pgain;   // 제어 게인(튜닝용)
    float nav_yaw_dgain;   // 제어 게인(튜닝용)
} CKtoController;

typedef struct _DPtoController { // @hspark(230615) oper_mode 1 or 2, mission_mode 2 일 때 송신
    double target_wp_lat; // 목표 경유점 경도 
    double target_wp_lon; // 목표 경유점 위도
    float targetposition_yaw; // 동적 위치유지 목표 선수각
    // DP 제어 게인
    float dp_surge_pgain;
    float dp_surge_dgain;
    float dp_sway_pgain;
    float dp_sway_dgain;
    float dp_yaw_pgain;
    float dp_yaw_dgain;
} DPtoController;

typedef struct _CAtoController { // @hspark(230615) oper_mode 1 or 2, mission_mode 0 or 1, ca_mode 1 일 때 송신
    float ca_alert_range; // 회피시작 조건(거리)
    float ca_avoid_range; // VO 반지름 거리
    float ca_param1; // TBD  // @hspark(230531) QGC에서 온 DCPA
    float ca_param2; // TBD  // @hspark(230531) QGC에서 온 TCPA
    float ca_param3; // TBD
    float ca_param4; // TBD
    float ca_param5; // TBD
    float ca_param6; // TBD
    float ca_param7; // TBD
} CAtoController;