#include <stdint.h>

// @hspark(230531) Waypoint 구조체 생성
typedef struct _Waypoint {
    double lat;                 // 경유점 경도(deg)
    double lon;                 // 경유점 위도(deg)
    float spd_cmd;              // 경유점에서의 속도 명령값(knots)
    float acceptance_radius;    // 경유점 도착 반경(L), L: 10.44m
} Waypoint;

typedef struct _ControlcmdtoVcc  // @hspark(230614) Mode 공통 구조체 // @hspark(230615) oper_mode 1 or 2 일 때 송신
{
    // 제어 명령
    float t1_rpm;       // 좌현 선수추진기 회전수, QGC
    float t2_rpm;       // 우현 선수추진기 회전수, QGC
    float t3_rpm;       // 좌현 메인추진기 회전수, QGC
    float t3_angle;     // 좌현 메인추진기 각도, QGC
    float t4_rpm;       // 우현 메인추진기 회전수, QGC
    float t4_angle;     // 우현 메인추진기 각도, QGC
    uint32_t oper_mode; // 현재 운용 모드 // @hspark(230531) 무인선 운용 모드 0: 수동, 1: 자동, 2: 시뮬레이션 --> 현재 상태값 리턴
	uint32_t mission_mode; // @hspark(230531) 무인선 현재 운용 임무 0: WP, 1: HDG, 2: DP --> 현재 상태값 리턴
    // Echo Back 신호
    //uint8_t rx_signal[180]; // 통합운항제어로부터 수신 정보(180 Byte)
} ControlcmdtoVcc;

typedef struct _WTtoVcc      // @hspark(230614) Waypoint Tracking Mode 용 구조체 // @hspark(230615) oper_mode 1 or 2, mission_mode 0 일 때 송신
{    
    float psi_d;        // 추종 선수각
    float spd_d;        // 추종 속도
    double wp_lat_d;     // 추종 경유점 경도 // @hspark(230531) float 맞는지 확인 필요 // @hspark(230615) float --> double 변경
    double wp_lon_d;     // 추종 경유점 위도 // @hspark(230531) float 맞는지 확인 필요 // @hspark(230615) float --> double 변경
    uint32_t track_path_idx; // 추종 경유점 번호
} WTtoVcc;

typedef struct _CKtoVcc      // @hspark(230614) Course Keeping Mode 용 구조체 // @hspark(230615) oper_mode 1 or 2, mission_mode 1 일 때 송신
{
    float psi_d;        // 추종 선수각 // @hspark(230615) 명령값 리턴
    float spd_d;        // 추종 속도 // @hspark(230615) 명령값 리턴
} CKtoVcc;

typedef struct _CAtoVcc      // @hspark(230614) Collision Avoidance Mode 용 구조체 // @hspark(230615) oper_mode 1 or 2, mission_mode 0 or 1, ca_mode 1 일 때 송신
{    
    // 충돌 회피
    uint32_t ca_mode; // 충돌회피 모드 (Enable/Disable) // @hspark(230531) 0: Disable, 1: Enable  --> 현재 상태값 리턴
    uint32_t ca_method; // 충돌회피 방법 (Reactive / Path plan) // @hspark(230531) 0: Path plan, 1: Reactive  --> 현재 상태값 리턴
    uint32_t ca_status;     // 회피 상태 - 안전 / 충돌회피
    float ca_risk_arr[900]; // 충돌위험도 배열(1도 간격 180도, 5개 속도 후보)
    float reactive_spd_d;   // 반응형 충돌회피 속도명령
    float reactive_psi_d;   // 반응형 충돌회피 선수각명령
    // 경로 계획
    Waypoint local_path[100]; // @hspark(230531) 회피경로, Waypoint 구조체 배열로 변경
} CAtoVcc;

typedef struct _DPtoVcc      // @hspark(230614) Dynamic Positioning Mode 용 구조체 // @hspark(230615) oper_mode 1 or 2, mission_mode 2 일 때 송신
    // DP
    double surge_error;     // 현재 운동과 목표 위치 차이(North, East +)
    double sway_error;      // 현재 운동과 목표 위치 차이(North, East +)
    double yaw_error;       // 현재 운동과 목표 위치 차이(CW +)
    //double heave;           // 운동 데이터(Down +) // @hspark(230615) 운동값은 MW에서 올라오는 값으로 대체
    //double roll;            // 운동 데이터 // @hspark(230615) 운동값은 MW에서 올라오는 값으로 대체
    //double pitch;           // 운동 데이터 // @hspark(230615) 운동값은 MW에서 올라오는 값으로 대체
    uint32_t dp_start_stop; // DP 시작/중지 상태
} DPtoVcc;
