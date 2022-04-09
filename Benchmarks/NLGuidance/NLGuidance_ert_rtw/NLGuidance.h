/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: NLGuidance.h
 *
 * Code generated for Simulink model 'NLGuidance'.
 *
 * Model version                  : 1.72
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Mon Apr  4 01:14:53 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_NLGuidance_h_
#define RTW_HEADER_NLGuidance_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef NLGuidance_COMMON_INCLUDES_
#define NLGuidance_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* NLGuidance_COMMON_INCLUDES_ */

#include "NLGuidance_types.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Real-time Model Data Structure */
struct tag_RTM_NLGuidance_T {
  const char_T * volatile errorStatus;
};

/* Model entry point functions */
extern void NLGuidance_initialize(RT_MODEL_NLGuidance_T *const NLGuidance_M,
  real_T NLGuidance_U_Xtarg[3], real_T NLGuidance_U_Xv[3], real_T
  NLGuidance_U_Vv[3], real_T NLGuidance_U_Vt[3], real_T *NLGuidance_U_r, real_T
  NLGuidance_Y_yout[3]);
extern void NLGuidance_step(RT_MODEL_NLGuidance_T *const NLGuidance_M, real_T
  NLGuidance_U_Xtarg[3], real_T NLGuidance_U_Xv[3], real_T NLGuidance_U_Vv[3],
  real_T NLGuidance_U_r, real_T NLGuidance_Y_yout[3]);
extern void NLGuidance_terminate(RT_MODEL_NLGuidance_T *const NLGuidance_M);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Display' : Unused code path elimination
 * Block '<S1>/Display1' : Unused code path elimination
 * Block '<S1>/Display2' : Unused code path elimination
 * Block '<S2>/To Workspace1' : Unused code path elimination
 * Block '<S2>/To Workspace2' : Unused code path elimination
 * Block '<S3>/Divide2' : Unused code path elimination
 * Block '<S3>/Divide3' : Unused code path elimination
 * Block '<S3>/Gain' : Unused code path elimination
 * Block '<S3>/Gain1' : Unused code path elimination
 * Block '<S3>/Math Function' : Unused code path elimination
 * Block '<S3>/Math Function1' : Unused code path elimination
 * Block '<S3>/Product1' : Unused code path elimination
 * Block '<S3>/Sum1' : Unused code path elimination
 * Block '<S3>/Sum2' : Unused code path elimination
 * Block '<S3>/Sum3' : Unused code path elimination
 * Block '<S3>/To Workspace' : Unused code path elimination
 * Block '<S3>/To Workspace1' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
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
 * '<Root>' : 'NLGuidance'
 * '<S1>'   : 'NLGuidance/NLGuidance'
 * '<S2>'   : 'NLGuidance/NLGuidance/Inner'
 * '<S3>'   : 'NLGuidance/NLGuidance/Outer'
 * '<S4>'   : 'NLGuidance/NLGuidance/norm1'
 * '<S5>'   : 'NLGuidance/NLGuidance/norm2'
 * '<S6>'   : 'NLGuidance/NLGuidance/Inner/Act1'
 * '<S7>'   : 'NLGuidance/NLGuidance/Inner/Act2'
 * '<S8>'   : 'NLGuidance/NLGuidance/Inner/Arg1'
 * '<S9>'   : 'NLGuidance/NLGuidance/Inner/Arg2'
 * '<S10>'  : 'NLGuidance/NLGuidance/Inner/norm'
 * '<S11>'  : 'NLGuidance/NLGuidance/Inner/norm1'
 * '<S12>'  : 'NLGuidance/NLGuidance/Outer/CCW'
 * '<S13>'  : 'NLGuidance/NLGuidance/Outer/CW'
 * '<S14>'  : 'NLGuidance/NLGuidance/Outer/cross'
 * '<S15>'  : 'NLGuidance/NLGuidance/Outer/r_computation'
 * '<S16>'  : 'NLGuidance/NLGuidance/Outer/cross/Subsystem1'
 * '<S17>'  : 'NLGuidance/NLGuidance/Outer/cross/Subsystem2'
 */
#endif                                 /* RTW_HEADER_NLGuidance_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
