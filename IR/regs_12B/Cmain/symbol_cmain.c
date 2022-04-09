#include <string.h>
#define RT_PI 3.14159265358979323846
#define RT_PIF 3.1415927F
#define RT_LN_10 2.30258509299404568402
#define RT_LN_10F 2.3025851F
#define RT_LOG10E 0.43429448190325182765
#define RT_LOG10EF 0.43429449F
#define RT_E 2.7182818284590452354
#define RT_EF 2.7182817F
#define false 0
#define true 1
#define UNUSED_PARAMETER(x) (void)(x)
#define rtmGetErrorStatus(rtm) ((rtm)->errorStatus)
#define rtmSetErrorStatus(rtm,val) ((rtm)->errorStatus=(val))
typedef signed char int8_T;
typedef unsigned char uint8_T;
typedef short int16_T;
typedef unsigned short uint16_T;
typedef int int32_T;
typedef unsigned int uint32_T;
typedef float real32_T;
typedef double real64_T;
typedef double real_T;
typedef double time_T;
typedef unsigned char boolean_T;
typedef int int_T;
typedef unsigned int uint_T;
typedef unsigned long ulong_T;
typedef char char_T;
typedef unsigned char uchar_T;
typedef char_T byte_T;
typedef struct creal32_T creal32_T;
typedef struct creal64_T creal64_T;
typedef struct creal_T creal_T;
typedef struct cint8_T cint8_T;
typedef struct cuint8_T cuint8_T;
typedef struct cint16_T cint16_T;
typedef struct cuint16_T cuint16_T;
typedef struct cint32_T cint32_T;
typedef struct cuint32_T cuint32_T;
typedef void * pointer_T;
typedef struct tag_RTM_regs_12B_T RT_MODEL_regs_12B_T;
typedef struct DW_regs_12B_T DW_regs_12B_T;
typedef struct ConstB_regs_12B_T ConstB_regs_12B_T;
typedef struct ConstP_regs_12B_T ConstP_regs_12B_T;
struct DW_regs_12B_T;
struct ConstB_regs_12B_T;
struct ConstP_regs_12B_T;
struct creal32_T;
struct creal64_T;
struct creal_T;
struct cint8_T;
struct cuint8_T;
struct cint16_T;
struct cuint16_T;
struct cint32_T;
struct cuint32_T;
struct tag_RTM_regs_12B_T;
struct DW_regs_12B_T {
    real_T UnitDelay_DSTATE;
    real_T UnitDelay1_DSTATE;
    real_T UnitDelay1_DSTATE_k;
    real_T UnitDelay_DSTATE_o;
    real_T Memory_PreviousInput;
};
struct ConstB_regs_12B_T {
    const real_T Sum7;
    const real_T Switch1;
    const real_T Switch2;
    const real_T Switch1_p;
    const real_T Switch2_d;
    const real_T Kcmd_Kbeta;
    const real_T kts2fps1;
    const real_T two_zeta_omega_DR;
    const real_T Sum2;
    const boolean_T RelationalOperator;
    const boolean_T RelationalOperator_k;
};
struct ConstP_regs_12B_T {
    real_T pooled4[5];
    real_T transition_bvr_XData[2];
    real_T transition_bvr_YData[2];
};
struct creal32_T {
    real32_T re;
    real32_T im;
};
struct creal64_T {
    real64_T re;
    real64_T im;
};
struct creal_T {
    real_T re;
    real_T im;
};
struct cint8_T {
    int8_T re;
    int8_T im;
};
struct cuint8_T {
    uint8_T re;
    uint8_T im;
};
struct cint16_T {
    int16_T re;
    int16_T im;
};
struct cuint16_T {
    uint16_T re;
    uint16_T im;
};
struct cint32_T {
    int32_T re;
    int32_T im;
};
struct cuint32_T {
    uint32_T re;
    uint32_T im;
};
struct tag_RTM_regs_12B_T {
    char_T * errorStatus;
    struct DW_regs_12B_T * dwork;
};
struct ConstB_regs_12B_T regs_12B_ConstB = {1.0, 9999.0, -9999.0, 9999.0, -9999.0, 4.0, 2.0, 4.0, 1.5, 0, 0};
struct ConstP_regs_12B_T regs_12B_ConstP = {{1.0, 2.0, 3.0, 4.0, 5.0}, {120.0, 185.0}, {15.0, 20.0}};
void regs_12B_step(RT_MODEL_regs_12B_T* regs_12B_M, real_T regs_12B_U_beta_adc_deg, real_T regs_12B_U_vtas_adc_kts, real_T regs_12B_U_lcv_cmd_fcs_dps, real_T regs_12B_U_mcv_cmd_fcs_dps, real_T regs_12B_U_ncv_cmd_fcs_dps, real_T regs_12B_U_xcv_cmd_fcs_fps, real_T regs_12B_U_hcv_cmd_fcs_fps, real_T regs_12B_U_lcv_fps_dps, real_T regs_12B_U_mcv_fcs_dps, real_T regs_12B_U_ncv_fcs_dps, real_T regs_12B_U_dcv_fcs_fps, real_T regs_12B_U_zcv_fcs_fps, real_T regs_12B_U_beta_dot, real_T* regs_12B_Y_lcvdt_cmd_fcs_dps2, real_T* regs_12B_Y_mcvdt_cmd_fcs_dps2, real_T* regs_12B_Y_ncvdt_cmd_fcs_dps2, real_T* regs_12B_Y_xcvdt_cmd_fcs_fps2, real_T* regs_12B_Y_hcvdt_cmd_fcs_fps2);
void regs_12B_init(RT_MODEL_regs_12B_T* regs_12B_M, real_T* regs_12B_U_beta_adc_deg, real_T* regs_12B_U_vtas_adc_kts, real_T* regs_12B_U_lcv_cmd_fcs_dps, real_T* regs_12B_U_hdg_des_deg, real_T* regs_12B_U_mcv_cmd_fcs_dps, real_T* regs_12B_U_alt_des_ft, real_T* regs_12B_U_ncv_cmd_fcs_dps, real_T* regs_12B_U_xcv_cmd_fcs_fps, real_T* regs_12B_U_airspeed_des_fps, real_T* regs_12B_U_hcv_cmd_fcs_fps, real_T* regs_12B_U_lcv_fps_dps, real_T* regs_12B_U_mcv_fcs_dps, real_T* regs_12B_U_ncv_fcs_dps, real_T* regs_12B_U_dcv_fcs_fps, real_T* regs_12B_U_zcv_fcs_fps, real_T* regs_12B_U_beta_dot, real_T* regs_12B_Y_lcvdt_cmd_fcs_dps2, real_T* regs_12B_Y_mcvdt_cmd_fcs_dps2, real_T* regs_12B_Y_ncvdt_cmd_fcs_dps2, real_T* regs_12B_Y_xcvdt_cmd_fcs_fps2, real_T* regs_12B_Y_hcvdt_cmd_fcs_fps2);
int_T rt_GetLookupIndex(real_T* x, int_T xlen, real_T u);
real_T rt_Lookup(real_T* x, int_T xlen, real_T u, real_T* y);
void regs_12B_step(RT_MODEL_regs_12B_T* regs_12B_M, real_T regs_12B_U_beta_adc_deg, real_T regs_12B_U_vtas_adc_kts, real_T regs_12B_U_lcv_cmd_fcs_dps, real_T regs_12B_U_mcv_cmd_fcs_dps, real_T regs_12B_U_ncv_cmd_fcs_dps, real_T regs_12B_U_xcv_cmd_fcs_fps, real_T regs_12B_U_hcv_cmd_fcs_fps, real_T regs_12B_U_lcv_fps_dps, real_T regs_12B_U_mcv_fcs_dps, real_T regs_12B_U_ncv_fcs_dps, real_T regs_12B_U_dcv_fcs_fps, real_T regs_12B_U_zcv_fcs_fps, real_T regs_12B_U_beta_dot, real_T* regs_12B_Y_lcvdt_cmd_fcs_dps2, real_T* regs_12B_Y_mcvdt_cmd_fcs_dps2, real_T* regs_12B_Y_ncvdt_cmd_fcs_dps2, real_T* regs_12B_Y_xcvdt_cmd_fcs_fps2, real_T* regs_12B_Y_hcvdt_cmd_fcs_fps2) {
    struct DW_regs_12B_T * regs_12B_DW = ((DW_regs_12B_T*)regs_12B_M->dwork);
    real_T rtb_CVdt_cmd;
    real_T rtb_Sum3;
    *regs_12B_Y_lcvdt_cmd_fcs_dps2 = (regs_12B_U_lcv_cmd_fcs_dps - regs_12B_U_lcv_fps_dps) * 2.5;
    rtb_CVdt_cmd = rt_Lookup(regs_12B_ConstP.pooled4, 5, regs_12B_U_vtas_adc_kts, regs_12B_ConstP.pooled4);
    *regs_12B_Y_ncvdt_cmd_fcs_dps2 = ((regs_12B_U_ncv_cmd_fcs_dps * regs_12B_ConstB.Kcmd_Kbeta + regs_12B_ConstB.Kcmd_Kbeta * regs_12B_U_beta_adc_deg) + regs_12B_ConstB.Sum2 * regs_12B_U_beta_dot) * rtb_CVdt_cmd + (1.0 - rtb_CVdt_cmd) * (regs_12B_U_ncv_cmd_fcs_dps - regs_12B_U_ncv_fcs_dps);
    rtb_CVdt_cmd = regs_12B_U_hcv_cmd_fcs_fps - (-regs_12B_U_zcv_fcs_fps);
    if (rtb_CVdt_cmd > 1.0) {
        rtb_CVdt_cmd = 1.0;
    }
    else {
        if (rtb_CVdt_cmd < -1.0) {
            rtb_CVdt_cmd = -1.0;
        }
    }
    rtb_CVdt_cmd = 0.0 * regs_12B_DW->Memory_PreviousInput * -0.2 + rtb_CVdt_cmd * regs_12B_ConstB.Sum7;
    regs_12B_DW->UnitDelay1_DSTATE += (rtb_CVdt_cmd + regs_12B_DW->UnitDelay_DSTATE) * 0.5 * 2.0;
    if (regs_12B_DW->UnitDelay1_DSTATE > regs_12B_ConstB.Switch1) {
        regs_12B_DW->UnitDelay1_DSTATE = regs_12B_ConstB.Switch1;
    }
    else {
        if (regs_12B_DW->UnitDelay1_DSTATE < regs_12B_ConstB.Switch2) {
            regs_12B_DW->UnitDelay1_DSTATE = regs_12B_ConstB.Switch2;
        }
    }
    *regs_12B_Y_hcvdt_cmd_fcs_fps2 = 0.25 * regs_12B_DW->UnitDelay1_DSTATE + rtb_CVdt_cmd;
    rtb_Sum3 = regs_12B_U_mcv_cmd_fcs_dps - regs_12B_U_mcv_fcs_dps;
    regs_12B_DW->UnitDelay1_DSTATE_k += (rtb_Sum3 + regs_12B_DW->UnitDelay_DSTATE_o) * 0.5 * 2.0;
    if (regs_12B_DW->UnitDelay1_DSTATE_k > regs_12B_ConstB.Switch1_p) {
        regs_12B_DW->UnitDelay1_DSTATE_k = regs_12B_ConstB.Switch1_p;
    }
    else {
        if (regs_12B_DW->UnitDelay1_DSTATE_k < regs_12B_ConstB.Switch2_d) {
            regs_12B_DW->UnitDelay1_DSTATE_k = regs_12B_ConstB.Switch2_d;
        }
    }
    *regs_12B_Y_mcvdt_cmd_fcs_dps2 = rt_Lookup(regs_12B_ConstP.transition_bvr_XData, 2, regs_12B_U_vtas_adc_kts, regs_12B_ConstP.transition_bvr_YData) * rtb_Sum3 + 5.0 * regs_12B_DW->UnitDelay1_DSTATE_k;
    *regs_12B_Y_xcvdt_cmd_fcs_fps2 = (regs_12B_U_xcv_cmd_fcs_fps - (-regs_12B_U_dcv_fcs_fps)) * 0.5;
    regs_12B_DW->Memory_PreviousInput = regs_12B_DW->UnitDelay1_DSTATE;
    regs_12B_DW->UnitDelay_DSTATE = rtb_CVdt_cmd;
    regs_12B_DW->UnitDelay_DSTATE_o = rtb_Sum3;
}
void regs_12B_init(RT_MODEL_regs_12B_T* regs_12B_M, real_T* regs_12B_U_beta_adc_deg, real_T* regs_12B_U_vtas_adc_kts, real_T* regs_12B_U_lcv_cmd_fcs_dps, real_T* regs_12B_U_hdg_des_deg, real_T* regs_12B_U_mcv_cmd_fcs_dps, real_T* regs_12B_U_alt_des_ft, real_T* regs_12B_U_ncv_cmd_fcs_dps, real_T* regs_12B_U_xcv_cmd_fcs_fps, real_T* regs_12B_U_airspeed_des_fps, real_T* regs_12B_U_hcv_cmd_fcs_fps, real_T* regs_12B_U_lcv_fps_dps, real_T* regs_12B_U_mcv_fcs_dps, real_T* regs_12B_U_ncv_fcs_dps, real_T* regs_12B_U_dcv_fcs_fps, real_T* regs_12B_U_zcv_fcs_fps, real_T* regs_12B_U_beta_dot, real_T* regs_12B_Y_lcvdt_cmd_fcs_dps2, real_T* regs_12B_Y_mcvdt_cmd_fcs_dps2, real_T* regs_12B_Y_ncvdt_cmd_fcs_dps2, real_T* regs_12B_Y_xcvdt_cmd_fcs_fps2, real_T* regs_12B_Y_hcvdt_cmd_fcs_fps2) {
    struct DW_regs_12B_T * regs_12B_DW = ((DW_regs_12B_T*)regs_12B_M->dwork);
    (void)memset((void*)regs_12B_DW, 0, sizeof(DW_regs_12B_T));
    *regs_12B_U_beta_adc_deg = 0.0;
    *regs_12B_U_vtas_adc_kts = 0.0;
    *regs_12B_U_lcv_cmd_fcs_dps = 0.0;
    *regs_12B_U_hdg_des_deg = 0.0;
    *regs_12B_U_mcv_cmd_fcs_dps = 0.0;
    *regs_12B_U_alt_des_ft = 0.0;
    *regs_12B_U_ncv_cmd_fcs_dps = 0.0;
    *regs_12B_U_xcv_cmd_fcs_fps = 0.0;
    *regs_12B_U_airspeed_des_fps = 0.0;
    *regs_12B_U_hcv_cmd_fcs_fps = 0.0;
    *regs_12B_U_lcv_fps_dps = 0.0;
    *regs_12B_U_mcv_fcs_dps = 0.0;
    *regs_12B_U_ncv_fcs_dps = 0.0;
    *regs_12B_U_dcv_fcs_fps = 0.0;
    *regs_12B_U_zcv_fcs_fps = 0.0;
    *regs_12B_U_beta_dot = 0.0;
    (*regs_12B_Y_lcvdt_cmd_fcs_dps2) = 0.0;
    (*regs_12B_Y_mcvdt_cmd_fcs_dps2) = 0.0;
    (*regs_12B_Y_ncvdt_cmd_fcs_dps2) = 0.0;
    (*regs_12B_Y_xcvdt_cmd_fcs_fps2) = 0.0;
    (*regs_12B_Y_hcvdt_cmd_fcs_fps2) = 0.0;
}

int_T rt_GetLookupIndex(real_T* x, int_T xlen, real_T u) {
    int_T idx = 0;
    int_T bottom = 0;
    int_T top = xlen - 1;
    int_T retValue = 0;
    boolean_T returnStatus = 0U;
    if (u <= x[bottom]) {
        retValue = bottom;
        returnStatus = 1U;
    }
    else if (u >= x[top]) {
        retValue = top - 1;
        returnStatus = 1U;
    }
    else {
    }
    if (returnStatus == 0U) {
        if (u < 0) {
            for (;;) {
                idx = (bottom + top) / 2;
                if (u < x[idx]) {
                    top = idx - 1;
                }
                else if (u >= x[idx + 1]) {
                    bottom = idx + 1;
                }
                else {
                    retValue = idx;
                    break;
                }
            }
        }
        else {
            for (;;) {
                idx = (bottom + top) / 2;
                if (u <= x[idx]) {
                    top = idx - 1;
                }
                else if (u > x[idx + 1]) {
                    bottom = idx + 1;
                }
                else {
                    retValue = idx;
                    break;
                }
            }
        }
    }
    return retValue;
}
real_T rt_Lookup(real_T* x, int_T xlen, real_T u, real_T* y) {
    int_T idx = rt_GetLookupIndex(x, xlen, u);
    real_T num = y[idx + 1] - y[idx];
    real_T den = x[idx + 1] - x[idx];
    real_T m = num / den;
    return (y[idx] + (m * (u - x[idx])));
}

// Add head file code
// Add declaration code
// Add Function code
int main()
{
    // Add init code
    struct tag_RTM_regs_12B_T* regs_12B_M = (struct tag_RTM_regs_12B_T*) malloc(sizeof(struct tag_RTM_regs_12B_T) * 1);
    regs_12B_M[0].errorStatus = (char*) malloc(sizeof(char) * 1);
    regs_12B_M[0].dwork = (struct DW_regs_12B_T*) malloc(sizeof(struct DW_regs_12B_T) * 1);
    double regs_12B_U_beta_adc_deg[1];
    double regs_12B_U_vtas_adc_kts[1];
    double regs_12B_U_lcv_cmd_fcs_dps[1];
    double regs_12B_U_mcv_cmd_fcs_dps[1];
    double regs_12B_U_ncv_cmd_fcs_dps[1];
    double regs_12B_U_xcv_cmd_fcs_fps[1];
    double regs_12B_U_hcv_cmd_fcs_fps[1];
    double regs_12B_U_lcv_fps_dps[1];
    double regs_12B_U_mcv_fcs_dps[1];
    double regs_12B_U_ncv_fcs_dps[1];
    double regs_12B_U_dcv_fcs_fps[1];
    double regs_12B_U_zcv_fcs_fps[1];
    double regs_12B_U_beta_dot[1];
    double regs_12B_Y_lcvdt_cmd_fcs_dps2[1];
    double regs_12B_Y_mcvdt_cmd_fcs_dps2[1];
    double regs_12B_Y_ncvdt_cmd_fcs_dps2[1];
    double regs_12B_Y_xcvdt_cmd_fcs_fps2[1];
    double regs_12B_Y_hcvdt_cmd_fcs_fps2[1];
    double regs_12B_U_hdg_des_deg[1];
    double regs_12B_U_alt_des_ft[1];
    double regs_12B_U_airspeed_des_fps[1];
    // Add init buffer code
    for (int i = 0; i < 1; i++) {
        regs_12B_init(&regs_12B_M[i],&(regs_12B_U_beta_adc_deg[i]),&(regs_12B_U_vtas_adc_kts[i]),&(regs_12B_U_lcv_cmd_fcs_dps[i]),&(regs_12B_U_hdg_des_deg[i]),&(regs_12B_U_mcv_cmd_fcs_dps[i]),&(regs_12B_U_alt_des_ft[i]),&(regs_12B_U_ncv_cmd_fcs_dps[i]),&(regs_12B_U_xcv_cmd_fcs_fps[i]),&(regs_12B_U_airspeed_des_fps[i]),&(regs_12B_U_hcv_cmd_fcs_fps[i]),&(regs_12B_U_lcv_fps_dps[i]),&(regs_12B_U_mcv_fcs_dps[i]),&(regs_12B_U_ncv_fcs_dps[i]),&(regs_12B_U_dcv_fcs_fps[i]),&(regs_12B_U_zcv_fcs_fps[i]),&(regs_12B_U_beta_dot[i]),&(regs_12B_Y_lcvdt_cmd_fcs_dps2[i]),&(regs_12B_Y_mcvdt_cmd_fcs_dps2[i]),&(regs_12B_Y_ncvdt_cmd_fcs_dps2[i]),&(regs_12B_Y_xcvdt_cmd_fcs_fps2[i]),&(regs_12B_Y_hcvdt_cmd_fcs_fps2[i]));
    }
    regs_12B_U_beta_adc_deg[0] = nondet_double();
    __CPROVER_input("double", regs_12B_U_beta_adc_deg[0]);
    regs_12B_U_vtas_adc_kts[0] = nondet_double();
    __CPROVER_input("double", regs_12B_U_vtas_adc_kts[0]);
    regs_12B_U_lcv_cmd_fcs_dps[0] = nondet_double();
    __CPROVER_input("double", regs_12B_U_lcv_cmd_fcs_dps[0]);
    regs_12B_U_mcv_cmd_fcs_dps[0] = nondet_double();
    __CPROVER_input("double", regs_12B_U_mcv_cmd_fcs_dps[0]);
    regs_12B_U_ncv_cmd_fcs_dps[0] = nondet_double();
    __CPROVER_input("double", regs_12B_U_ncv_cmd_fcs_dps[0]);
    regs_12B_U_xcv_cmd_fcs_fps[0] = nondet_double();
    __CPROVER_input("double", regs_12B_U_xcv_cmd_fcs_fps[0]);
    regs_12B_U_hcv_cmd_fcs_fps[0] = nondet_double();
    __CPROVER_input("double", regs_12B_U_hcv_cmd_fcs_fps[0]);
    regs_12B_U_lcv_fps_dps[0] = nondet_double();
    __CPROVER_input("double", regs_12B_U_lcv_fps_dps[0]);
    regs_12B_U_mcv_fcs_dps[0] = nondet_double();
    __CPROVER_input("double", regs_12B_U_mcv_fcs_dps[0]);
    regs_12B_U_ncv_fcs_dps[0] = nondet_double();
    __CPROVER_input("double", regs_12B_U_ncv_fcs_dps[0]);
    regs_12B_U_dcv_fcs_fps[0] = nondet_double();
    __CPROVER_input("double", regs_12B_U_dcv_fcs_fps[0]);
    regs_12B_U_zcv_fcs_fps[0] = nondet_double();
    __CPROVER_input("double", regs_12B_U_zcv_fcs_fps[0]);
    regs_12B_U_beta_dot[0] = nondet_double();
    __CPROVER_input("double", regs_12B_U_beta_dot[0]);
    // Add target function code
    for (int i = 0; i < 1; i++) {
        regs_12B_step(&regs_12B_M[0],regs_12B_U_beta_adc_deg[i],regs_12B_U_vtas_adc_kts[i],regs_12B_U_lcv_cmd_fcs_dps[i],regs_12B_U_mcv_cmd_fcs_dps[i],regs_12B_U_ncv_cmd_fcs_dps[i],regs_12B_U_xcv_cmd_fcs_fps[i],regs_12B_U_hcv_cmd_fcs_fps[i],regs_12B_U_lcv_fps_dps[i],regs_12B_U_mcv_fcs_dps[i],regs_12B_U_ncv_fcs_dps[i],regs_12B_U_dcv_fcs_fps[i],regs_12B_U_zcv_fcs_fps[i],regs_12B_U_beta_dot[i],&(regs_12B_Y_lcvdt_cmd_fcs_dps2[i]),&(regs_12B_Y_mcvdt_cmd_fcs_dps2[i]),&(regs_12B_Y_ncvdt_cmd_fcs_dps2[i]),&(regs_12B_Y_xcvdt_cmd_fcs_fps2[i]),&(regs_12B_Y_hcvdt_cmd_fcs_fps2[i]));
    }
    // Add code after execute
    // Add release code
    return 0;
}
