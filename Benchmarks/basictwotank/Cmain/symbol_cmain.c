#include <string.h>
#include <math.h>
#include <stdlib.h>
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
typedef struct tag_RTM_basictwotanks_T RT_MODEL_basictwotanks_T;
typedef struct DW_basictwotanks_T DW_basictwotanks_T;
typedef struct ConstB_basictwotanks_T ConstB_basictwotanks_T;
struct DW_basictwotanks_T;
struct ConstB_basictwotanks_T;
struct creal32_T;
struct creal64_T;
struct creal_T;
struct cint8_T;
struct cuint8_T;
struct cint16_T;
struct cuint16_T;
struct cint32_T;
struct cuint32_T;
struct tag_RTM_basictwotanks_T;
struct DW_basictwotanks_T {
    real_T Pump_State_Delay_DSTATE;
    real_T Valve_State_Delay_DSTATE;
    real_T UnitDelay_DSTATE_j;
    real_T Emergency_Valve_State_Delay_DST;
    real_T Production_Valve_State_Delay_DS;
    real_T UnitDelay_DSTATE_c;
};
struct ConstB_basictwotanks_T {
    const real_T Product;
    const real_T Product_g;
    const real_T Product_p;
    const real_T Product_h;
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
struct tag_RTM_basictwotanks_T {
    char_T * errorStatus;
    struct DW_basictwotanks_T * dwork;
};
extern char __VERIFIER_nondet_char(void);
extern short __VERIFIER_nondet_short(void);
extern int __VERIFIER_nondet_int(void);
extern long long __VERIFIER_nondet_long_long(void);
extern float __VERIFIER_nondet_float(void);
extern double __VERIFIER_nondet_double(void);
extern long double __VERIFIER_nondet_long_double(void);
extern unsigned char __VERIFIER_nondet_unsigned_char(void);
extern unsigned short __VERIFIER_nondet_unsigned_short(void);
extern unsigned int __VERIFIER_nondet_unsigned_int(void);
extern unsigned long long __VERIFIER_nondet_unsigned_long_long(void);
struct ConstB_basictwotanks_T basictwotanks_ConstB = {0.020000000000000004, 0.005000000000000001, 0.020000000000000004, 0.010000000000000002};
void basictwotanks_step(RT_MODEL_basictwotanks_T* basictwotanks_M, real_T* basictwotanks_Y_t1_h, real_T* basictwotanks_Y_t2_h, real_T* basictwotanks_Y_t1_sh, real_T* basictwotanks_Y_t1_sl, real_T* basictwotanks_Y_t2_sh, real_T* basictwotanks_Y_t2_sm, real_T* basictwotanks_Y_t2_sl, real_T* basictwotanks_Y_pump_state, real_T* basictwotanks_Y_valve_state, real_T* basictwotanks_Y_p_valve_state, real_T* basictwotanks_Y_e_valve_state);
void basictwotanks_init(RT_MODEL_basictwotanks_T* basictwotanks_M, real_T* basictwotanks_Y_t1_h, real_T* basictwotanks_Y_t2_h, real_T* basictwotanks_Y_t1_sh, real_T* basictwotanks_Y_t1_sl, real_T* basictwotanks_Y_t2_sh, real_T* basictwotanks_Y_t2_sm, real_T* basictwotanks_Y_t2_sl, real_T* basictwotanks_Y_pump_state, real_T* basictwotanks_Y_valve_state, real_T* basictwotanks_Y_p_valve_state, real_T* basictwotanks_Y_e_valve_state);
void basictwotanks_step(RT_MODEL_basictwotanks_T* basictwotanks_M, real_T* basictwotanks_Y_t1_h, real_T* basictwotanks_Y_t2_h, real_T* basictwotanks_Y_t1_sh, real_T* basictwotanks_Y_t1_sl, real_T* basictwotanks_Y_t2_sh, real_T* basictwotanks_Y_t2_sm, real_T* basictwotanks_Y_t2_sl, real_T* basictwotanks_Y_pump_state, real_T* basictwotanks_Y_valve_state, real_T* basictwotanks_Y_p_valve_state, real_T* basictwotanks_Y_e_valve_state) {
    struct DW_basictwotanks_T * basictwotanks_DW = basictwotanks_M->dwork;
    real_T rtb_Switch4_idx_0;
    real_T rtb_Switch4_idx_1;
    real_T rtb_Switch_i;
    real_T rtb_tank1_previous_height_m;
    real_T rtb_tank2_previous_height_m;
    int32_T rtb_Switch;
    int32_T rtb_Switch_b;
    int32_T rtb_Switch_j;
    int32_T rtb_Switch_k;
    int32_T rtb_Switch_m;
    boolean_T rtb_Compare_dl;
    boolean_T rtb_LogicalOperator3;
    if (basictwotanks_DW->UnitDelay_DSTATE_j > 0.0) {
        rtb_Switch_i = 1.2647;
    }
    else {
        rtb_Switch_i = 0.0;
    }
    rtb_tank1_previous_height_m = rtb_Switch_i + *basictwotanks_Y_t1_h;
    rtb_Switch_k = !(2.0 > rtb_tank1_previous_height_m);
    rtb_Switch = !(5.0 > rtb_tank1_previous_height_m);
    if (rtb_Switch_k != 1) {
        basictwotanks_DW->Pump_State_Delay_DSTATE = 1.0;
        *basictwotanks_Y_valve_state = 0.0;
    }
    else if (rtb_Switch == 1) {
        basictwotanks_DW->Pump_State_Delay_DSTATE = 0.0;
        *basictwotanks_Y_valve_state = 1.0;
    }
    else {
        *basictwotanks_Y_valve_state = basictwotanks_DW->Valve_State_Delay_DSTATE;
    }
    *basictwotanks_Y_pump_state = basictwotanks_DW->Pump_State_Delay_DSTATE;
    if (basictwotanks_DW->UnitDelay_DSTATE_c > 0.0) {
        rtb_Switch_i = 0.09754;
    }
    else {
        rtb_Switch_i = 0.0;
    }
    rtb_tank2_previous_height_m = rtb_Switch_i + *basictwotanks_Y_t2_h;
    rtb_Switch_j = !(2.0 > rtb_tank2_previous_height_m);
    rtb_Switch_m = !(3.0 > rtb_tank2_previous_height_m);
    rtb_Switch_b = !(1.0 > rtb_tank2_previous_height_m);
    if (rtb_Switch_b != 1) {
        basictwotanks_DW->Production_Valve_State_Delay_DS = 0.0;
        basictwotanks_DW->Emergency_Valve_State_Delay_DST = 0.0;
    }
    else if ((!(basictwotanks_DW->Emergency_Valve_State_Delay_DST == 1.0)) && (!(basictwotanks_DW->Production_Valve_State_Delay_DS == 1.0))) {
        basictwotanks_DW->Production_Valve_State_Delay_DS = 1.0;
        basictwotanks_DW->Emergency_Valve_State_Delay_DST = 0.0;
    }
    else {
        rtb_Compare_dl = (rtb_Switch_m == 1);
        if (rtb_Compare_dl && ((!(basictwotanks_DW->Emergency_Valve_State_Delay_DST == 1.0)) && (basictwotanks_DW->Production_Valve_State_Delay_DS == 1.0))) {
            basictwotanks_DW->Production_Valve_State_Delay_DS = 1.0;
            basictwotanks_DW->Emergency_Valve_State_Delay_DST = 1.0;
        }
        else {
            rtb_LogicalOperator3 = ((basictwotanks_DW->Emergency_Valve_State_Delay_DST == 1.0) && (basictwotanks_DW->Production_Valve_State_Delay_DS == 1.0));
            if ((!(basictwotanks_DW->Valve_State_Delay_DSTATE == 1.0)) && ((!rtb_Compare_dl) && rtb_LogicalOperator3)) {
                basictwotanks_DW->Production_Valve_State_Delay_DS = 1.0;
                basictwotanks_DW->Emergency_Valve_State_Delay_DST = 0.0;
            }
            else if (rtb_LogicalOperator3 && (rtb_Switch_j != 1)) {
                basictwotanks_DW->Production_Valve_State_Delay_DS = 1.0;
                basictwotanks_DW->Emergency_Valve_State_Delay_DST = 0.0;
            }
        }
    }
    *basictwotanks_Y_p_valve_state = basictwotanks_DW->Production_Valve_State_Delay_DS;
    *basictwotanks_Y_e_valve_state = basictwotanks_DW->Emergency_Valve_State_Delay_DST;
    if (*basictwotanks_Y_valve_state > 0.5) {
        rtb_Switch_i = basictwotanks_ConstB.Product_h;
    }
    else {
        rtb_Switch_i = 0.0;
    }
    if (basictwotanks_DW->Production_Valve_State_Delay_DS > 0.5) {
        rtb_Switch4_idx_0 = basictwotanks_ConstB.Product_g;
    }
    else {
        rtb_Switch4_idx_0 = 0.0;
    }
    if (basictwotanks_DW->Emergency_Valve_State_Delay_DST > 0.5) {
        rtb_Switch4_idx_1 = basictwotanks_ConstB.Product;
    }
    else {
        rtb_Switch4_idx_1 = 0.0;
    }
    *basictwotanks_Y_t2_h = ((rtb_Switch_i - rtb_Switch4_idx_0) - rtb_Switch4_idx_1) / 2.0 + rtb_tank2_previous_height_m;
    if (basictwotanks_DW->Pump_State_Delay_DSTATE > 0.5) {
        rtb_tank2_previous_height_m = basictwotanks_ConstB.Product_p;
    }
    else {
        rtb_tank2_previous_height_m = 0.0;
    }
    *basictwotanks_Y_t1_h = (rtb_tank2_previous_height_m - rtb_Switch_i) + rtb_tank1_previous_height_m;
    *basictwotanks_Y_t2_sl = rtb_Switch_b;
    *basictwotanks_Y_t2_sh = rtb_Switch_m;
    *basictwotanks_Y_t2_sm = rtb_Switch_j;
    *basictwotanks_Y_t1_sh = rtb_Switch;
    *basictwotanks_Y_t1_sl = rtb_Switch_k;
    basictwotanks_DW->Valve_State_Delay_DSTATE = *basictwotanks_Y_valve_state;
    basictwotanks_DW->UnitDelay_DSTATE_j = 0.0;
    basictwotanks_DW->UnitDelay_DSTATE_c = 0.0;
}
void basictwotanks_init(RT_MODEL_basictwotanks_T* basictwotanks_M, real_T* basictwotanks_Y_t1_h, real_T* basictwotanks_Y_t2_h, real_T* basictwotanks_Y_t1_sh, real_T* basictwotanks_Y_t1_sl, real_T* basictwotanks_Y_t2_sh, real_T* basictwotanks_Y_t2_sm, real_T* basictwotanks_Y_t2_sl, real_T* basictwotanks_Y_pump_state, real_T* basictwotanks_Y_valve_state, real_T* basictwotanks_Y_p_valve_state, real_T* basictwotanks_Y_e_valve_state) {
    struct DW_basictwotanks_T * basictwotanks_DW = basictwotanks_M->dwork;
    (void)memset((void*)basictwotanks_DW, 0, sizeof(DW_basictwotanks_T));
    *basictwotanks_Y_t1_h = 0.0;
    *basictwotanks_Y_t2_h = 0.0;
    *basictwotanks_Y_t1_sh = 0.0;
    *basictwotanks_Y_t1_sl = 0.0;
    *basictwotanks_Y_t2_sh = 0.0;
    *basictwotanks_Y_t2_sm = 0.0;
    *basictwotanks_Y_t2_sl = 0.0;
    *basictwotanks_Y_pump_state = 0.0;
    *basictwotanks_Y_valve_state = 0.0;
    *basictwotanks_Y_p_valve_state = 0.0;
    *basictwotanks_Y_e_valve_state = 0.0;
    basictwotanks_DW->UnitDelay_DSTATE_j = 1.0;
    basictwotanks_DW->UnitDelay_DSTATE_c = 1.0;
}


// Add head file code
// Add declaration code
// Add Function code
int main()
{
    // Add init code
    struct tag_RTM_basictwotanks_T* basictwotanks_M = (struct tag_RTM_basictwotanks_T*) malloc(sizeof(struct tag_RTM_basictwotanks_T) * 1);
    basictwotanks_M[0].errorStatus = (char*) malloc(sizeof(char) * 1);
    basictwotanks_M[0].dwork = (struct DW_basictwotanks_T*) malloc(sizeof(struct DW_basictwotanks_T) * 1);
    double* basictwotanks_Y_t1_h = (double*) malloc(sizeof(double) * 1);
    double* basictwotanks_Y_t2_h = (double*) malloc(sizeof(double) * 1);
    double basictwotanks_Y_t1_sh[1];
    double basictwotanks_Y_t1_sl[1];
    double basictwotanks_Y_t2_sh[1];
    double basictwotanks_Y_t2_sm[1];
    double basictwotanks_Y_t2_sl[1];
    double basictwotanks_Y_pump_state[1];
    double basictwotanks_Y_valve_state[1];
    double basictwotanks_Y_p_valve_state[1];
    double basictwotanks_Y_e_valve_state[1];
    // Add init buffer code
    for (int i = 0; i < 1; i++) {
        basictwotanks_init(&basictwotanks_M[i],&(basictwotanks_Y_t1_h[i]),&(basictwotanks_Y_t2_h[i]),&(basictwotanks_Y_t1_sh[i]),&(basictwotanks_Y_t1_sl[i]),&(basictwotanks_Y_t2_sh[i]),&(basictwotanks_Y_t2_sm[i]),&(basictwotanks_Y_t2_sl[i]),&(basictwotanks_Y_pump_state[i]),&(basictwotanks_Y_valve_state[i]),&(basictwotanks_Y_p_valve_state[i]),&(basictwotanks_Y_e_valve_state[i]));
    }
    basictwotanks_M[0].errorStatus[0] = __VERIFIER_nondet_char();
    __CPROVER_input("char", basictwotanks_M[0].errorStatus[0]);
    basictwotanks_M[0].dwork[0].Pump_State_Delay_DSTATE = __VERIFIER_nondet_double();
    __CPROVER_input("double", basictwotanks_M[0].dwork[0].Pump_State_Delay_DSTATE);
    basictwotanks_M[0].dwork[0].Valve_State_Delay_DSTATE = __VERIFIER_nondet_double();
    __CPROVER_input("double", basictwotanks_M[0].dwork[0].Valve_State_Delay_DSTATE);
    basictwotanks_M[0].dwork[0].UnitDelay_DSTATE_j = __VERIFIER_nondet_double();
    __CPROVER_input("double", basictwotanks_M[0].dwork[0].UnitDelay_DSTATE_j);
    basictwotanks_M[0].dwork[0].Emergency_Valve_State_Delay_DST = __VERIFIER_nondet_double();
    __CPROVER_input("double", basictwotanks_M[0].dwork[0].Emergency_Valve_State_Delay_DST);
    basictwotanks_M[0].dwork[0].Production_Valve_State_Delay_DS = __VERIFIER_nondet_double();
    __CPROVER_input("double", basictwotanks_M[0].dwork[0].Production_Valve_State_Delay_DS);
    basictwotanks_M[0].dwork[0].UnitDelay_DSTATE_c = __VERIFIER_nondet_double();
    __CPROVER_input("double", basictwotanks_M[0].dwork[0].UnitDelay_DSTATE_c);
    basictwotanks_Y_t1_h[0] = __VERIFIER_nondet_double();
    __CPROVER_input("double", basictwotanks_Y_t1_h[0]);
    basictwotanks_Y_t2_h[0] = __VERIFIER_nondet_double();
    __CPROVER_input("double", basictwotanks_Y_t2_h[0]);
    // Add target function code
    for (int i = 0; i < 1; i++) {
        basictwotanks_step(&basictwotanks_M[i],&basictwotanks_Y_t1_h[i],&basictwotanks_Y_t2_h[i],&(basictwotanks_Y_t1_sh[i]),&(basictwotanks_Y_t1_sl[i]),&(basictwotanks_Y_t2_sh[i]),&(basictwotanks_Y_t2_sm[i]),&(basictwotanks_Y_t2_sl[i]),&(basictwotanks_Y_pump_state[i]),&(basictwotanks_Y_valve_state[i]),&(basictwotanks_Y_p_valve_state[i]),&(basictwotanks_Y_e_valve_state[i]));
    }
    // Add code after execute
    // Add release code
    return 0;
}
