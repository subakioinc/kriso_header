#include <stdint.h>

typedef struct _PlcToVcc
{
    uint16_t mr_str_srv;
    uint16_t mr_mtr_run;
    uint16_t mr_flt_msg;
    uint16_t mr_pwr_cns;
    uint16_t mr_temp;
    uint16_t mr_str_rpm;
    uint16_t mr_str_ang;
    uint16_t mr_thr_rpm;
    uint16_t mr_thr_rot;
    uint16_t mr_rfrg;

    uint16_t ml_str_srv;
    uint16_t ml_mtr_run;
    uint16_t ml_flt_msg;
    uint16_t ml_pwr_cns;
    uint16_t ml_temp;
    uint16_t ml_str_rpm;
    uint16_t ml_str_ang;
    uint16_t ml_thr_rpm;
    uint16_t ml_thr_rot;
    uint16_t ml_rfrg;

    uint16_t br_mtr_run;
    uint16_t br_flt_msg;
    uint16_t br_pwr_cns;
    uint16_t br_temp;
    uint16_t br_rot_sta;
    uint16_t br_thr_rpm;
    uint16_t spare0036;
    uint16_t spare0037;
    uint16_t spare0038;
    uint16_t spare0039;

    uint16_t bl_mtr_run;
    uint16_t bl_flt_msg;
    uint16_t bl_pwr_cns;
    uint16_t bl_temp;
    uint16_t bl_rot_sta;
    uint16_t bl_thr_rpm;
    uint16_t spare0046;
    uint16_t spare0047;
    uint16_t spare0048;
    uint16_t spare0049;

    uint16_t bp_400_vlt;
    uint16_t bp_24_vlt;
    uint16_t bp_72_vlt;
    uint16_t spare0053;
    uint16_t spare0054;
    uint16_t spare0055;
    uint16_t spare0056;
    uint16_t spare0057;
    uint16_t spare0058;
    uint16_t spare0059;

    uint16_t emrg_stop;
    uint16_t oper_mode;
    uint16_t spare0062;
    uint16_t spare0063;
    uint16_t spare0064;
    uint16_t spare0065;
    uint16_t spare0066;
    uint16_t spare0067;
    uint16_t spare0068;
    uint16_t spare0069;

    uint16_t nav_light;
    uint16_t ach_light;
    uint16_t spare0072;
    uint16_t spare0073;
    uint16_t spare0074;
    uint16_t spare0075;
    uint16_t spare0076;
    uint16_t spare0077;
    uint16_t spare0078;
    uint16_t spare0079;

    uint16_t port_blg_pmp1;
    uint16_t port_blg_pmp2;
    uint16_t port_blg_pmp3;
    uint16_t port_blg_pmp4;
    uint16_t stbd_blg_pmp1;
    uint16_t stbd_blg_pmp2;
    uint16_t stbd_blg_pmp3;
    uint16_t stbd_blg_pmp4;
    uint16_t port_fan1;
    uint16_t port_fan2;
    uint16_t port_fan3;
    uint16_t stbd_fan1;
    uint16_t stbd_fan2;
    uint16_t stbd_fan3;
    uint16_t port_level1;
    uint16_t port_level2;
    uint16_t port_level3;
    uint16_t port_level4;
    uint16_t stbd_level1;
    uint16_t stbd_level2;
    uint16_t stbd_level3;
    uint16_t stbd_level4;
} PlcToVcc;