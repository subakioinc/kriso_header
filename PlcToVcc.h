#include <stdint.h>

typedef struct _PlcToVcc
{
    uint16_t mr_mtr_sta;
    uint16_t mr_flt_msg_err1;
    uint16_t mr_flt_msg_err2;
    uint16_t mr_flt_msg_warn1;
    uint16_t mr_flt_msg_warn2;
    uint16_t mr_mtr_curr_real;
    uint16_t mr_temp;
    uint16_t mr_mtr_rpm_real;
    uint16_t mr_mtr_rot_real;
    uint16_t rsv3509;

    uint16_t ml_mtr_sta;
    uint16_t ml_flt_msg_err1;
    uint16_t ml_flt_msg_err2;
    uint16_t ml_flt_msg_warn1;
    uint16_t ml_flt_msg_warn2;
    uint16_t ml_mtr_curr_real;
    uint16_t ml_temp;
    uint16_t ml_mtr_rpm_real;
    uint16_t ml_mtr_rot_real;
    uint16_t rsv3519;

    uint16_t br_mtr_sta;
    uint16_t br_flt_msg;
    uint16_t br_mtr_curr_real;
    uint16_t br_temp;
    uint16_t br_mtr_rpm;
    uint16_t br_mtr_rot_sta;
    uint16_t rsv3526;
    uint16_t rsv3527;
    uint16_t rsv3528;
    uint16_t rsv3529;

    uint16_t bl_mtr_sta;
    uint16_t bl_flt_msg;
    uint16_t bl_mtr_curr_real;
    uint16_t bl_temp;
    uint16_t bl_mtr_rpm;
    uint16_t bl_mtr_rot_sta;
    uint16_t rsv3536;
    uint16_t rsv3537;
    uint16_t rsv3538;
    uint16_t rsv3539;

    uint16_t sr_str_rpm;
    uint16_t sr_str_ang;
    uint16_t sl_str_rpm;
    uint16_t sl_str_ang;
    uint16_t batt400vdc;
    uint16_t batt24vdc_1;
    uint16_t batt24vdc_2;
} PlcToVcc;