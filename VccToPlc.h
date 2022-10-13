#include <stdint.h>

typedef struct _VccToPlc
{
    uint16_t mr_mtr_run;
    uint16_t mr_mtr_rpm;
    uint16_t mr_mtr_trq;
    uint16_t rsv3003;
    uint16_t rsv3004;
    uint16_t rsv3005;
    uint16_t rsv3006;
    uint16_t rsv3007;
    uint16_t rsv3008;
    uint16_t rsv3009;

    uint16_t ml_mtr_run;
    uint16_t ml_mtr_rpm;
    uint16_t ml_mtr_trq;
    uint16_t rsv3013;
    uint16_t rsv3014;
    uint16_t rsv3015;
    uint16_t rsv3016;
    uint16_t rsv3017;
    uint16_t rsv3018;
    uint16_t rsv3019;

    uint16_t br_mtr_rot;
    uint16_t br_mtr_thr_per;
    uint16_t spare3022;
    uint16_t spare3023;
    uint16_t spare3024;
    uint16_t spare3025;
    uint16_t spare3026;
    uint16_t spare3027;
    uint16_t spare3028;
    uint16_t spare3029;

    uint16_t bl_mtr_rot;
    uint16_t bl_mtr_thr_per;
    uint16_t spare3032;
    uint16_t spare3033;
    uint16_t spare3034;
    uint16_t spare3035;
    uint16_t spare3036;
    uint16_t spare3037;
    uint16_t spare3038;
    uint16_t spare3039;

    uint16_t sr_str_srv_on;
    uint16_t st_str_srv_home;
    uint16_t sr_str_rpm;
    uint16_t sr_str_ang;
    uint16_t sr_rfrg;
    uint16_t spare3045;
    uint16_t spare3046;
    uint16_t spare3047;
    uint16_t spare3048;
    uint16_t spare3049;

    uint16_t sl_str_srv_on;
    uint16_t sl_str_srv_home;
    uint16_t sl_str_rpm;
    uint16_t sl_str_ang;
    uint16_t sl_rfrg;
    uint16_t spare3055;
    uint16_t spare3056;
    uint16_t spare3057;
    uint16_t spare3058;
    uint16_t spare3059;

    uint16_t emer_stop;
    uint16_t nav_mode;
    uint16_t nav_light1;
    uint16_t nav_light2;
    uint16_t br_s1;
    uint16_t br_s2;
    uint16_t br_s3;
    uint16_t br_s4;
    uint16_t pr_s1;
    uint16_t pr_s2;

    uint16_t bl_s1;
    uint16_t bl_s2;
    uint16_t bl_s3;
    uint16_t bl_s4;
    uint16_t pl_s1;
    uint16_t pl_s2;
} VccToPlc;