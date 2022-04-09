/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: EB_12B.h
 *
 * Code generated for Simulink model 'EB_12B'.
 *
 * Model version                  : 7.0
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Mon Apr  4 00:48:20 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_EB_12B_h_
#define RTW_HEADER_EB_12B_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef EB_12B_COMMON_INCLUDES_
#define EB_12B_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* EB_12B_COMMON_INCLUDES_ */

#include "EB_12B_types.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Divide_DWORK4[25];            /* '<S1>/Divide' */
  real_T Divide1_DWORK4[9];            /* '<S1>/Divide1' */
} DW_EB_12B_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T MathFunction[25];       /* '<S1>/Math Function' */
  const real_T Divide[25];             /* '<S1>/Divide' */
} ConstB_EB_12B_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: [ 1 0 0 ; 0 1 0 ; 0 0 1 ]
   * Referenced by: '<S1>/ID'
   */
  real_T ID_Value[9];

  /* Expression: [1 0 0 0 0;0 1 0 0 0;0 0 1 0 0;0 0 0 1 0;0 0 0 0 1]
   * Referenced by: '<Root>/Const'
   */
  real_T Const_Value[25];

  /* Expression: [3;-1;2]
   * Referenced by: '<Root>/Const2'
   */
  real_T Const2_Value[3];

  /* Expression: I*1E-12
   * Referenced by: '<S3>/Constant4'
   */
  real_T Constant4_Value[9];
} ConstP_EB_12B_T;

/* Real-time Model Data Structure */
struct tag_RTM_EB_12B_T {
  const char_T * volatile errorStatus;
  DW_EB_12B_T *dwork;
};

extern const ConstB_EB_12B_T EB_12B_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_EB_12B_T EB_12B_ConstP;

/* Model entry point functions */
extern void EB_12B_initialize(RT_MODEL_EB_12B_T *const EB_12B_M, real_T
  EB_12B_U_B[15], real_T EB_12B_Y_id[9], real_T EB_12B_Y_check[9], real_T
  EB_12B_Y_yinv[9], real_T EB_12B_Y_P[15], real_T EB_12B_Y_u[5], real_T
  EB_12B_Y_Buminusd[3], real_T *EB_12B_Y_J, boolean_T *EB_12B_Y_ridge_on);
extern void EB_12B_step(RT_MODEL_EB_12B_T *const EB_12B_M, real_T EB_12B_U_B[15],
  real_T EB_12B_Y_check[9], real_T EB_12B_Y_yinv[9], real_T EB_12B_Y_P[15],
  real_T EB_12B_Y_u[5], real_T EB_12B_Y_Buminusd[3], real_T *EB_12B_Y_J,
  boolean_T *EB_12B_Y_ridge_on);
extern void EB_12B_terminate(RT_MODEL_EB_12B_T *const EB_12B_M);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Check' : Unused code path elimination
 * Block '<S1>/Display2' : Unused code path elimination
 * Block '<S1>/Display3' : Unused code path elimination
 * Block '<S1>/Display4' : Unused code path elimination
 * Block '<S1>/Display5' : Unused code path elimination
 * Block '<S1>/Display6' : Unused code path elimination
 * Block '<S1>/Inverse' : Unused code path elimination
 * Block '<S3>/Display' : Unused code path elimination
 * Block '<S3>/Display1' : Unused code path elimination
 * Block '<Root>/input:B' : Unused code path elimination
 * Block '<S2>/Math Function' : Unused code path elimination
 * Block '<S2>/Math Function1' : Unused code path elimination
 * Block '<S2>/Sum of Elements' : Unused code path elimination
 * Block '<Root>/output:check' : Unused code path elimination
 * Block '<Root>/output:norm' : Unused code path elimination
 * Block '<Root>/output:ridge_on' : Unused code path elimination
 * Block '<S4>/Reshape' : Reshape block reduction
 * Block '<S3>/fix_on' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'EB_12B'
 * '<S1>'   : 'EB_12B/EB'
 * '<S2>'   : 'EB_12B/norm'
 * '<S3>'   : 'EB_12B/EB/ridge'
 * '<S4>'   : 'EB_12B/EB/ridge/det'
 */
#endif                                 /* RTW_HEADER_EB_12B_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
