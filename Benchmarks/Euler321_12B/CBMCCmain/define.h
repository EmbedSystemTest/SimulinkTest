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
typedef struct tag_RTM_euler321_I2B_12B_T RT_MODEL_euler321_I2B_12B_T;
typedef struct DW_euler321_I2B_12B_T DW_euler321_I2B_12B_T;
struct creal32_T;
struct creal64_T;
struct creal_T;
struct cint8_T;
struct cuint8_T;
struct cint16_T;
struct cuint16_T;
struct cint32_T;
struct cuint32_T;
struct tag_RTM_euler321_I2B_12B_T;
struct DW_euler321_I2B_12B_T;
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
struct tag_RTM_euler321_I2B_12B_T {
    char_T * errorStatus;
    struct DW_euler321_I2B_12B_T * dwork;
};
struct DW_euler321_I2B_12B_T {
    real_T Memory_PreviousInput;
};
/* Update function of "euler321_I2B_12B.Func" */
void euler321_I2B_12B_step(RT_MODEL_euler321_I2B_12B_T* euler321_I2B_12B_M, real_T euler321_I2B_12B_U_phi, real_T euler321_I2B_12B_U_theta, real_T euler321_I2B_12B_U_psi, real_T euler321_I2B_12B_U_Vi[3], real_T euler321_I2B_12B_U_Inport, real_T euler321_I2B_12B_Y_DCM321[9], real_T euler321_I2B_12B_Y_Vb[3], real_T euler321_I2B_12B_Y_outTheta[3], real_T euler321_I2B_12B_Y_outGamma[3], boolean_T* euler321_I2B_12B_Y_outR1);
/* Init function of "euler321_I2B_12B.Func" */
void euler321_I2B_12B_init(RT_MODEL_euler321_I2B_12B_T* euler321_I2B_12B_M, real_T euler321_I2B_12B_U_Vi[3], real_T euler321_I2B_12B_Y_DCM321[9], real_T euler321_I2B_12B_Y_Vb[3], real_T euler321_I2B_12B_Y_outTheta[3], real_T euler321_I2B_12B_Y_outGamma[3], real_T* euler321_I2B_12B_U_phi, real_T* euler321_I2B_12B_U_theta, real_T* euler321_I2B_12B_U_psi, real_T* euler321_I2B_12B_U_Inport, boolean_T* euler321_I2B_12B_Y_outR1);
#endif


