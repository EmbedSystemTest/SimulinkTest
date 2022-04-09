/*
 * EB_12B.h
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

#ifndef RTW_HEADER_EB_12B_h_
#define RTW_HEADER_EB_12B_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef EB_12B_COMMON_INCLUDES_
# define EB_12B_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* EB_12B_COMMON_INCLUDES_ */

#include "EB_12B_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Divide_DWORK4[25];            /* '<S1>/Divide' */
  real_T Divide1_DWORK4[9];            /* '<S1>/Divide1' */
} DW_EB_12B_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T B[15];                        /* '<Root>/B' */
} ExtU_EB_12B_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T id[9];                        /* '<Root>/id' */
  real_T check[9];                     /* '<Root>/check' */
  real_T yinv[9];                      /* '<Root>/yinv' */
  real_T P[15];                        /* '<Root>/P' */
  real_T u[5];                         /* '<Root>/u' */
  real_T Buminusd[3];                  /* '<Root>/Buminusd' */
  real_T J;                            /* '<Root>/J' */
  boolean_T ridge_on;                  /* '<Root>/ridge_on' */
} ExtY_EB_12B_T;

/* Parameters (default storage) */
struct P_EB_12B_T_ {
  real_T I[9];                         /* Variable: I
                                        * Referenced by: '<S3>/Constant4'
                                        */
  real_T I0[9];                        /* Variable: I0
                                        * Referenced by: '<S3>/Constant3'
                                        */
  real_T ID_Value[9];                  /* Expression: [ 1 0 0 ; 0 1 0 ; 0 0 1 ]
                                        * Referenced by: '<S1>/ID'
                                        */
  real_T Const_Value[25];
              /* Expression: [1 0 0 0 0;0 1 0 0 0;0 0 1 0 0;0 0 0 1 0;0 0 0 0 1]
               * Referenced by: '<Root>/Const'
               */
  real_T Constant1_Value;              /* Expression: 1e-12
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T fix_on_Value;                 /* Expression: 1
                                        * Referenced by: '<S3>/fix_on'
                                        */
  real_T Switch1_Threshold;            /* Expression: 1e-1
                                        * Referenced by: '<S3>/Switch1'
                                        */
  real_T Const2_Value[3];              /* Expression: [3;-1;2]
                                        * Referenced by: '<Root>/Const2'
                                        */
  real_T Const3_Value[5];              /* Expression: [0;0;0;0;0]
                                        * Referenced by: '<Root>/Const3'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_EB_12B_T {
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

/* Block parameters (default storage) */
extern P_EB_12B_T EB_12B_P;

/* Block states (default storage) */
extern DW_EB_12B_T EB_12B_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_EB_12B_T EB_12B_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_EB_12B_T EB_12B_Y;

/* Model entry point functions */
extern void EB_12B_initialize(void);
extern void EB_12B_step(void);
extern void EB_12B_terminate(void);

/* Real-time Model object */
extern RT_MODEL_EB_12B_T *const EB_12B_M;

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
