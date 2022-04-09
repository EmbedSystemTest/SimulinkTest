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
typedef struct tag_RTM_NLGuidance_T RT_MODEL_NLGuidance_T;
typedef struct DW_NLGuidance_T DW_NLGuidance_T;
struct creal32_T;
struct creal64_T;
struct creal_T;
struct cint8_T;
struct cuint8_T;
struct cint16_T;
struct cuint16_T;
struct cint32_T;
struct cuint32_T;
struct tag_RTM_NLGuidance_T;
struct DW_NLGuidance_T;
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
struct tag_RTM_NLGuidance_T {
    char_T * errorStatus;
    struct DW_NLGuidance_T * dwork;
};
struct DW_NLGuidance_T {
    real_T Memory_PreviousInput;
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
void NLGuidance_step(RT_MODEL_NLGuidance_T* NLGuidance_M, real_T NLGuidance_U_Xtarg[3], real_T NLGuidance_U_Xv[3], real_T NLGuidance_U_Vv[3], real_T NLGuidance_U_r, real_T NLGuidance_Y_yout[3]);
void NLGuidance_init(RT_MODEL_NLGuidance_T* NLGuidance_M, real_T NLGuidance_U_Xtarg[3], real_T NLGuidance_U_Xv[3], real_T NLGuidance_U_Vv[3], real_T NLGuidance_U_Vt[3], real_T NLGuidance_Y_yout[3], real_T* NLGuidance_U_r);
void NLGuidance_step(RT_MODEL_NLGuidance_T* NLGuidance_M, real_T NLGuidance_U_Xtarg[3], real_T NLGuidance_U_Xv[3], real_T NLGuidance_U_Vv[3], real_T NLGuidance_U_r, real_T NLGuidance_Y_yout[3]) {
    real_T rtb_Divide4;
    real_T rtb_MathFunction1_m;
    real_T rtb_MathFunction_idx_0;
    real_T rtb_MathFunction_idx_1;
    real_T rtb_Product2;
    real_T rtb_Sum;
    real_T rtb_Sum4;
    real_T rtb_Xr_idx_0;
    real_T rtb_Xr_idx_1;
    rtb_Sum = NLGuidance_U_Xtarg[0] - NLGuidance_U_Xv[0];
    rtb_MathFunction_idx_0 = rtb_Sum * rtb_Sum;
    rtb_Xr_idx_0 = rtb_Sum;
    rtb_Sum = NLGuidance_U_Xtarg[1] - NLGuidance_U_Xv[1];
    rtb_MathFunction_idx_1 = rtb_Sum * rtb_Sum;
    rtb_Xr_idx_1 = rtb_Sum;
    rtb_Sum = NLGuidance_U_Xtarg[2] - NLGuidance_U_Xv[2];
    rtb_MathFunction1_m = (rtb_MathFunction_idx_0 + rtb_MathFunction_idx_1) + rtb_Sum * rtb_Sum;
    rtb_Sum4 = (rtb_Xr_idx_0 * NLGuidance_U_Vv[0] + rtb_Xr_idx_1 * NLGuidance_U_Vv[1]) + rtb_Sum * NLGuidance_U_Vv[2];
    if (rtb_MathFunction1_m < 0.0) {
        rtb_MathFunction_idx_0 = -sqrt(fabs(rtb_MathFunction1_m));
    }
    else {
        rtb_MathFunction_idx_0 = sqrt(rtb_MathFunction1_m);
    }
    rtb_Divide4 = rtb_MathFunction_idx_0 * rtb_MathFunction_idx_0;
    rtb_MathFunction_idx_1 = rtb_Divide4 - NLGuidance_U_r * NLGuidance_U_r;
    rtb_MathFunction1_m = (NLGuidance_U_Vv[0] * NLGuidance_U_Vv[0] + NLGuidance_U_Vv[1] * NLGuidance_U_Vv[1]) + NLGuidance_U_Vv[2] * NLGuidance_U_Vv[2];
    if (rtb_MathFunction1_m < 0.0) {
        rtb_MathFunction1_m = -sqrt(fabs(rtb_MathFunction1_m));
    }
    else {
        rtb_MathFunction1_m = sqrt(rtb_MathFunction1_m);
    }
    rtb_MathFunction1_m = rtb_MathFunction1_m * rtb_MathFunction1_m * rtb_Divide4 - rtb_Sum4 * rtb_Sum4;
    if ((rtb_MathFunction_idx_1 <= 0.0) || (rtb_MathFunction1_m <= 0.0)) {
        rtb_Product2 = NLGuidance_U_r / rtb_MathFunction_idx_0;
        rtb_Sum = rtb_Product2 * rtb_Xr_idx_0 + NLGuidance_U_Xtarg[0];
        rtb_Sum4 = rtb_Xr_idx_1 * rtb_Product2 + NLGuidance_U_Xtarg[1];
        rtb_MathFunction_idx_0 = rtb_Sum - NLGuidance_U_Xv[0];
        rtb_MathFunction_idx_1 = rtb_Sum4 - NLGuidance_U_Xv[1];
        rtb_MathFunction1_m = (0.0 - NLGuidance_U_Xv[2]) * (0.0 - NLGuidance_U_Xv[2]);
        rtb_Divide4 = (rtb_MathFunction_idx_0 * rtb_MathFunction_idx_0 + rtb_MathFunction_idx_1 * rtb_MathFunction_idx_1) + rtb_MathFunction1_m;
        rtb_Xr_idx_0 = -rtb_Product2 * rtb_Xr_idx_0 + NLGuidance_U_Xtarg[0];
        rtb_Xr_idx_1 = rtb_Xr_idx_1 * -rtb_Product2 + NLGuidance_U_Xtarg[1];
        rtb_MathFunction_idx_0 = rtb_Xr_idx_0 - NLGuidance_U_Xv[0];
        rtb_MathFunction_idx_1 = rtb_Xr_idx_1 - NLGuidance_U_Xv[1];
        rtb_MathFunction1_m += rtb_MathFunction_idx_0 * rtb_MathFunction_idx_0 + rtb_MathFunction_idx_1 * rtb_MathFunction_idx_1;
        if (rtb_Divide4 < 0.0) {
            rtb_Divide4 = -sqrt(fabs(rtb_Divide4));
        }
        else {
            rtb_Divide4 = sqrt(rtb_Divide4);
        }
        if (rtb_MathFunction1_m < 0.0) {
            rtb_MathFunction1_m = -sqrt(fabs(rtb_MathFunction1_m));
        }
        else {
            rtb_MathFunction1_m = sqrt(rtb_MathFunction1_m);
        }
        if (rtb_Divide4 < rtb_MathFunction1_m) {
            NLGuidance_Y_yout[0] = rtb_Sum;
            NLGuidance_Y_yout[1] = rtb_Sum4;
        }
        else {
            NLGuidance_Y_yout[0] = rtb_Xr_idx_0;
            NLGuidance_Y_yout[1] = rtb_Xr_idx_1;
        }
        NLGuidance_Y_yout[2] = 0.0;
    }
    else {
        rtb_Product2 = sqrt(rtb_MathFunction_idx_1 / rtb_MathFunction1_m);
        rtb_MathFunction_idx_0 = rtb_Product2 * NLGuidance_U_Vv[0];
        rtb_MathFunction_idx_1 = rtb_Product2 * NLGuidance_U_Vv[1];
        rtb_MathFunction1_m = rtb_Product2 * NLGuidance_U_Vv[2];
        rtb_Divide4 = 1.0 / rtb_Divide4;
        rtb_Product2 *= rtb_Sum4;
        rtb_Sum4 = NLGuidance_U_r + rtb_Product2;
        NLGuidance_Y_yout[0] = (rtb_Sum4 * rtb_Xr_idx_0 * -rtb_Divide4 + rtb_MathFunction_idx_0) * NLGuidance_U_r + rtb_Xr_idx_0;
        NLGuidance_Y_yout[1] = (rtb_Sum4 * rtb_Xr_idx_1 * -rtb_Divide4 + rtb_MathFunction_idx_1) * NLGuidance_U_r + rtb_Xr_idx_1;
        NLGuidance_Y_yout[2] = (rtb_Sum4 * rtb_Sum * -rtb_Divide4 + rtb_MathFunction1_m) * NLGuidance_U_r + rtb_Sum;
        rtb_Sum4 = rtb_Xr_idx_0 * NLGuidance_Y_yout[1];
        rtb_Product2 -= NLGuidance_U_r;
        if (rtb_Sum4 - rtb_Sum4 < 0.0) {
            NLGuidance_Y_yout[0] += NLGuidance_U_Xv[0];
            NLGuidance_Y_yout[1] += NLGuidance_U_Xv[1];
            NLGuidance_Y_yout[2] += NLGuidance_U_Xv[2];
        }
        else {
            NLGuidance_Y_yout[0] = ((rtb_Product2 * rtb_Xr_idx_0 * rtb_Divide4 - rtb_MathFunction_idx_0) * NLGuidance_U_r + rtb_Xr_idx_0) + NLGuidance_U_Xv[0];
            NLGuidance_Y_yout[1] = ((rtb_Product2 * rtb_Xr_idx_1 * rtb_Divide4 - rtb_MathFunction_idx_1) * NLGuidance_U_r + rtb_Xr_idx_1) + NLGuidance_U_Xv[1];
            NLGuidance_Y_yout[2] = ((rtb_Product2 * rtb_Sum * rtb_Divide4 - rtb_MathFunction1_m) * NLGuidance_U_r + rtb_Sum) + NLGuidance_U_Xv[2];
        }
    }
    UNUSED_PARAMETER(NLGuidance_M);
}
void NLGuidance_init(RT_MODEL_NLGuidance_T* NLGuidance_M, real_T NLGuidance_U_Xtarg[3], real_T NLGuidance_U_Xv[3], real_T NLGuidance_U_Vv[3], real_T NLGuidance_U_Vt[3], real_T NLGuidance_Y_yout[3], real_T* NLGuidance_U_r) {
    rtmSetErrorStatus(NLGuidance_M, (NULL));
    (void)memset(&NLGuidance_U_Xtarg[0], 0, 3U * sizeof(real_T));
    (void)memset(&NLGuidance_U_Xv[0], 0, 3U * sizeof(real_T));
    (void)memset(&NLGuidance_U_Vv[0], 0, 3U * sizeof(real_T));
    (void)memset(&NLGuidance_U_Vt[0], 0, 3U * sizeof(real_T));
    *NLGuidance_U_r = 0.0;
    (void)memset(&NLGuidance_Y_yout[0], 0, 3U * sizeof(real_T));
    UNUSED_PARAMETER(NLGuidance_M);
}


// Add head file code
// Add declaration code
// Add Function code
int main()
{
    // Add init code
    struct tag_RTM_NLGuidance_T* NLGuidance_M = (struct tag_RTM_NLGuidance_T*) malloc(sizeof(struct tag_RTM_NLGuidance_T) * 1);
    NLGuidance_M[0].errorStatus = (char*) malloc(sizeof(char) * 1);
    NLGuidance_M[0].dwork = (struct DW_NLGuidance_T*) malloc(sizeof(struct DW_NLGuidance_T) * 1);
    double NLGuidance_U_Xtarg[1][3];
    double NLGuidance_U_Xv[1][3];
    double NLGuidance_U_Vv[1][3];
    double NLGuidance_U_r[1];
    double NLGuidance_Y_yout[1][3];
    double NLGuidance_U_Vt[1][3];
    // Add init buffer code
    for (int i = 0; i < 1; i++) {
        NLGuidance_init(&NLGuidance_M[i],NLGuidance_U_Xtarg[i],NLGuidance_U_Xv[i],NLGuidance_U_Vv[i],NLGuidance_U_Vt[i],NLGuidance_Y_yout[i],&(NLGuidance_U_r[i]));
    }
    NLGuidance_U_Xtarg[0][0] = __VERIFIER_nondet_double();
    __CPROVER_input("double", NLGuidance_U_Xtarg[0][0]);
    NLGuidance_U_Xtarg[0][1] = __VERIFIER_nondet_double();
    __CPROVER_input("double", NLGuidance_U_Xtarg[0][1]);
    NLGuidance_U_Xtarg[0][2] = __VERIFIER_nondet_double();
    __CPROVER_input("double", NLGuidance_U_Xtarg[0][2]);
    NLGuidance_U_Xv[0][0] = __VERIFIER_nondet_double();
    __CPROVER_input("double", NLGuidance_U_Xv[0][0]);
    NLGuidance_U_Xv[0][1] = __VERIFIER_nondet_double();
    __CPROVER_input("double", NLGuidance_U_Xv[0][1]);
    NLGuidance_U_Xv[0][2] = __VERIFIER_nondet_double();
    __CPROVER_input("double", NLGuidance_U_Xv[0][2]);
    NLGuidance_U_Vv[0][0] = __VERIFIER_nondet_double();
    __CPROVER_input("double", NLGuidance_U_Vv[0][0]);
    NLGuidance_U_Vv[0][1] = __VERIFIER_nondet_double();
    __CPROVER_input("double", NLGuidance_U_Vv[0][1]);
    NLGuidance_U_Vv[0][2] = __VERIFIER_nondet_double();
    __CPROVER_input("double", NLGuidance_U_Vv[0][2]);
    NLGuidance_U_r[0] = __VERIFIER_nondet_double();
    __CPROVER_input("double", NLGuidance_U_r[0]);
    NLGuidance_Y_yout[0][0] = __VERIFIER_nondet_double();
    __CPROVER_input("double", NLGuidance_Y_yout[0][0]);
    NLGuidance_Y_yout[0][1] = __VERIFIER_nondet_double();
    __CPROVER_input("double", NLGuidance_Y_yout[0][1]);
    NLGuidance_Y_yout[0][2] = __VERIFIER_nondet_double();
    __CPROVER_input("double", NLGuidance_Y_yout[0][2]);
    // Add target function code
    for (int i = 0; i < 1; i++) {
        NLGuidance_step(&NLGuidance_M[0],NLGuidance_U_Xtarg[i],NLGuidance_U_Xv[i],NLGuidance_U_Vv[i],NLGuidance_U_r[i],NLGuidance_Y_yout[i]);
    }
    // Add code after execute
    // Add release code
    return 0;
}
