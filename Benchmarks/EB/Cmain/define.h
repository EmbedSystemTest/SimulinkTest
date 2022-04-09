#ifndef _DEFINE_H_
#define _DEFINE_H_
#include "BitmapCov.h"
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
typedef struct tag_RTM_EB_12B_T RT_MODEL_EB_12B_T;
typedef struct DW_EB_12B_T DW_EB_12B_T;
typedef struct ConstB_EB_12B_T ConstB_EB_12B_T;
typedef struct ConstP_EB_12B_T ConstP_EB_12B_T;
struct DW_EB_12B_T;
struct ConstB_EB_12B_T;
struct ConstP_EB_12B_T;
struct creal32_T;
struct creal64_T;
struct creal_T;
struct cint8_T;
struct cuint8_T;
struct cint16_T;
struct cuint16_T;
struct cint32_T;
struct cuint32_T;
struct tag_RTM_EB_12B_T;
struct DW_EB_12B_T {
    real_T Divide_DWORK4[25];
    real_T Divide1_DWORK4[9];
};
struct ConstB_EB_12B_T {
    const real_T MathFunction[25];
    const real_T Divide[25];
};
struct ConstP_EB_12B_T {
    real_T ID_Value[9];
    real_T Const_Value[25];
    real_T Const2_Value[3];
    real_T Constant4_Value[9];
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
struct tag_RTM_EB_12B_T {
    char_T * errorStatus;
    struct DW_EB_12B_T * dwork;
};
/* Global Variable define of  */
extern struct ConstB_EB_12B_T EB_12B_ConstB;
/* Global Variable define of  */
extern struct ConstP_EB_12B_T EB_12B_ConstP;
/* Update function of "EB_12B.Func" */
void EB_12B_step(RT_MODEL_EB_12B_T* EB_12B_M, real_T EB_12B_U_B[15], real_T EB_12B_Y_check[9], real_T EB_12B_Y_yinv[9], real_T EB_12B_Y_P[15], real_T EB_12B_Y_u[5], real_T EB_12B_Y_Buminusd[3], real_T* EB_12B_Y_J, boolean_T* EB_12B_Y_ridge_on);
/* Init function of "EB_12B.Func" */
void EB_12B_init(RT_MODEL_EB_12B_T* EB_12B_M, real_T EB_12B_U_B[15], real_T EB_12B_Y_id[9], real_T EB_12B_Y_check[9], real_T EB_12B_Y_yinv[9], real_T EB_12B_Y_P[15], real_T EB_12B_Y_u[5], real_T EB_12B_Y_Buminusd[3], real_T* EB_12B_Y_J, boolean_T* EB_12B_Y_ridge_on);
/* Update function of  */
void rt_invd3x3_snf(real_T u[9], real_T y[9]);
#endif


