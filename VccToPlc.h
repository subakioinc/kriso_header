#include <stdint.h>

typedef struct _VccToPlc
{
    uint16_t mr_str_srv;
    uint16_t spare1011;
    uint16_t spare1012;
    uint16_t mr_str_rpm;
    uint16_t mr_str_ang;
    uint16_t mr_thr_rpm;
    uint16_t mr_thr_rot;
    uint16_t mr_rfrg;
    uint16_t spare1018;
    uint16_t spare1019;

    uint16_t ml_str_srv;
    uint16_t spare1021;
    uint16_t spare1022;
    uint16_t ml_str_rpm;
    uint16_t ml_str_ang;
    uint16_t ml_thr_rpm;
    uint16_t ml_thr_rot;
    uint16_t ml_rfrg;
    uint16_t spare1028;
    uint16_t spare1029;

    uint16_t br_mtr_run;
    uint16_t br_rot_sta;
    uint16_t br_thr_rpm;
    uint16_t spare1033;
    uint16_t spare1034;
    uint16_t spare1035;
    uint16_t spare1036;
    uint16_t spare1037;
    uint16_t spare1038;
    uint16_t spare1039;

    uint16_t bl_mtr_run;
    uint16_t bl_rot_sta;
    uint16_t bl_thr_rpm;
    uint16_t spare1043;
    uint16_t spare1044;
    uint16_t spare1045;
    uint16_t spare1046;
    uint16_t spare1047;
    uint16_t spare1048;
    uint16_t spare1049;

    uint16_t emrg_stop;
    uint16_t oper_mode;
} VccToPlc;