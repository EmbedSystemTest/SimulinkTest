/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: simple.h
 *
 * Code generated for Simulink model 'simple'.
 *
 * Model version                  : 1.96
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Tue Nov  9 21:39:28 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_simple_h_
#define RTW_HEADER_simple_h_
#ifndef simple_COMMON_INCLUDES_
#define simple_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* simple_COMMON_INCLUDES_ */

#include "simple_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T x;                            /* '<Root>/Chart' */
  real_T y;                            /* '<Root>/Chart' */
} B_simple_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  int32_T sfEvent;                     /* '<Root>/Chart' */
  uint8_T is_active_c3_simple;         /* '<Root>/Chart' */
  uint8_T is_c;                        /* '<Root>/Chart' */
  uint8_T is_p1;                       /* '<Root>/Chart' */
  uint8_T is_active_p1;                /* '<Root>/Chart' */
  uint8_T is_p2;                       /* '<Root>/Chart' */
  uint8_T is_active_p2;                /* '<Root>/Chart' */
} DW_simple_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T in1;                          /* '<Root>/in1' */
  real_T in2;                          /* '<Root>/in2' */
} ExtU_simple_T;

/* Real-time Model Data Structure */
struct tag_RTM_simple_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_simple_T simple_B;

/* Block states (default storage) */
extern DW_simple_T simple_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_simple_T simple_U;

/* Model entry point functions */
extern void simple_initialize(void);
extern void simple_step(void);
extern void simple_terminate(void);

/* Real-time Model object */
extern RT_MODEL_simple_T *const simple_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
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
 * '<Root>' : 'simple'
 * '<S1>'   : 'simple/Chart'
 */
#endif                                 /* RTW_HEADER_simple_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
