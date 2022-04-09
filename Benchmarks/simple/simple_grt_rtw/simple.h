/*
 * simple.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "simple".
 *
 * Model version              : 1.96
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Tue Nov  9 21:37:01 2021
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_simple_h_
#define RTW_HEADER_simple_h_
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef simple_COMMON_INCLUDES_
#define simple_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* simple_COMMON_INCLUDES_ */

#include "simple_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
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
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
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
