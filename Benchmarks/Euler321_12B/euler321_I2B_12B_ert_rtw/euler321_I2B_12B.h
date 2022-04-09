#ifndef RTW_HEADER_euler321_I2B_12B_h_
#define RTW_HEADER_euler321_I2B_12B_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef euler321_I2B_12B_COMMON_INCLUDES_
#define euler321_I2B_12B_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif

#include "euler321_I2B_12B_types.h"
#include "rt_defines.h"

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

struct tag_RTM_euler321_I2B_12B_T {
  const char_T * volatile errorStatus;
};

extern void euler321_I2B_12B_initialize(RT_MODEL_euler321_I2B_12B_T *const
  euler321_I2B_12B_M, real_T *euler321_I2B_12B_U_phi, real_T
  *euler321_I2B_12B_U_theta, real_T *euler321_I2B_12B_U_psi, real_T
  euler321_I2B_12B_U_Vi[3], real_T *euler321_I2B_12B_U_Inport, real_T
  euler321_I2B_12B_Y_DCM321[9], real_T euler321_I2B_12B_Y_Vb[3], real_T
  euler321_I2B_12B_Y_outTheta[3], real_T euler321_I2B_12B_Y_outGamma[3],
  boolean_T *euler321_I2B_12B_Y_outR1);
extern void euler321_I2B_12B_step(RT_MODEL_euler321_I2B_12B_T *const
  euler321_I2B_12B_M, real_T euler321_I2B_12B_U_phi, real_T
  euler321_I2B_12B_U_theta, real_T euler321_I2B_12B_U_psi, real_T
  euler321_I2B_12B_U_Vi[3], real_T euler321_I2B_12B_U_Inport, real_T
  euler321_I2B_12B_Y_DCM321[9], real_T euler321_I2B_12B_Y_Vb[3], real_T
  euler321_I2B_12B_Y_outTheta[3], real_T euler321_I2B_12B_Y_outGamma[3],
  boolean_T *euler321_I2B_12B_Y_outR1);
extern void euler321_I2B_12B_terminate(RT_MODEL_euler321_I2B_12B_T *const
  euler321_I2B_12B_M);

#endif

