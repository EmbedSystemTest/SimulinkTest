/*
 * EB_12B_private.h
 *
 * Code generation for model "EB_12B".
 *
 * Model version              : 1.83
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Sat Aug 28 14:21:06 2021
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_EB_12B_private_h_
#define RTW_HEADER_EB_12B_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

extern void rt_invd5x5_snf(const real_T u[25], real_T y[25]);
extern void rt_invd3x3_snf(const real_T u[9], real_T y[9]);

#endif                                 /* RTW_HEADER_EB_12B_private_h_ */
