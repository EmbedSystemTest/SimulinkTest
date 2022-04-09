/*
 * simple.c
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

#include "simple.h"
#include "simple_private.h"

/* Named constants for Chart: '<Root>/Chart' */
#define simple_CALL_EVENT              (-1)
#define simple_IN_NO_ACTIVE_CHILD      ((uint8_T)0U)
#define simple_IN_a                    ((uint8_T)1U)
#define simple_IN_b                    ((uint8_T)2U)
#define simple_IN_c                    ((uint8_T)3U)
#define simple_IN_c1                   ((uint8_T)1U)
#define simple_IN_c2                   ((uint8_T)2U)
#define simple_event_e                 (0)

/* Block signals (default storage) */
B_simple_T simple_B;

/* Block states (default storage) */
DW_simple_T simple_DW;

/* External inputs (root inport signals with default storage) */
ExtU_simple_T simple_U;

/* Real-time model */
static RT_MODEL_simple_T simple_M_;
RT_MODEL_simple_T *const simple_M = &simple_M_;

/* Forward declaration for local functions */
static void simple_broadcast_e(void);
static void simple_c3_simple(void);

/* Function for Chart: '<Root>/Chart' */
static void simple_broadcast_e(void)
{
  int32_T b_previousEvent;
  b_previousEvent = simple_DW.sfEvent;
  simple_DW.sfEvent = simple_event_e;

  /* Chart: '<Root>/Chart' */
  simple_c3_simple();
  simple_DW.sfEvent = b_previousEvent;
}

/* Function for Chart: '<Root>/Chart' */
static void simple_c3_simple(void)
{
  boolean_T guard1 = false;
  boolean_T guard2 = false;

  /* Chart: '<Root>/Chart' incorporates:
   *  Inport: '<Root>/in1'
   *  Inport: '<Root>/in2'
   */
  if (simple_DW.is_active_c3_simple == 0U) {
    simple_DW.is_active_c3_simple = 1U;
    simple_DW.is_active_p1 = 1U;
    simple_B.x = simple_U.in1;
    simple_B.y = simple_U.in2;
    simple_DW.is_p1 = simple_IN_a;
    simple_DW.is_active_p2 = 1U;
    simple_DW.is_p2 = simple_IN_a;
  } else {
    if (simple_DW.is_active_p1 != 0U) {
      guard1 = false;
      guard2 = false;
      switch (simple_DW.is_p1) {
       case simple_IN_a:
        if ((simple_DW.sfEvent == simple_event_e) && (simple_B.x == 10.0)) {
          simple_B.x = 10.0;
          simple_DW.is_p1 = simple_IN_b;
        }
        break;

       case simple_IN_b:
        if (simple_B.x < 100.0) {
          simple_B.x++;
          if (simple_B.x < 100.0) {
            simple_B.x += 10.0;
            if (simple_B.x == 1.0) {
              simple_B.y += 10.0;
              guard1 = true;
            } else {
              guard2 = true;
            }
          } else {
            guard2 = true;
          }
        }
        break;

       case simple_IN_c:
        if ((simple_DW.sfEvent == simple_event_e) && (simple_B.x == 0.0)) {
          simple_B.x = 0.0;
          simple_broadcast_e();
          if (simple_DW.is_p1 == 3) {
            simple_DW.is_c = simple_IN_NO_ACTIVE_CHILD;
            simple_DW.is_p1 = simple_IN_a;
          }
        } else {
          switch (simple_DW.is_c) {
           case simple_IN_c1:
            simple_broadcast_e();
            if (simple_DW.is_c == 1) {
              simple_DW.is_c = simple_IN_c2;
            }
            break;

           case simple_IN_c2:
            simple_DW.is_c = simple_IN_c1;
            break;

           default:
            /* Unreachable state, for coverage only */
            simple_DW.is_c = simple_IN_NO_ACTIVE_CHILD;
            break;
          }
        }
        break;

       default:
        /* Unreachable state, for coverage only */
        simple_DW.is_p1 = simple_IN_NO_ACTIVE_CHILD;
        break;
      }

      if (guard2) {
        if (simple_B.y == 0.0) {
          simple_B.y++;
          if (simple_B.y == 1.0) {
            guard1 = true;
          }
        }
      }

      if (guard1) {
        simple_DW.is_p1 = simple_IN_c;
        simple_B.x = 0.0;
        simple_DW.is_c = simple_IN_c1;
      }
    }

    if (simple_DW.is_active_p2 != 0U) {
      switch (simple_DW.is_p2) {
       case simple_IN_a:
        if (simple_B.x < 100.0) {
          simple_broadcast_e();
          if (simple_DW.is_p2 == 1) {
            simple_DW.is_p2 = simple_IN_b;
          }
        }
        break;

       case simple_IN_b:
        simple_DW.is_p2 = simple_IN_a;
        break;

       default:
        /* Unreachable state, for coverage only */
        simple_DW.is_p2 = simple_IN_NO_ACTIVE_CHILD;
        break;
      }
    }
  }

  /* End of Chart: '<Root>/Chart' */
}

/* Model step function */
void simple_step(void)
{
  /* Chart: '<Root>/Chart' */
  simple_DW.sfEvent = simple_CALL_EVENT;
  simple_c3_simple();

  /* Matfile logging */
  rt_UpdateTXYLogVars(simple_M->rtwLogInfo, (&simple_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [1.0s, 0.0s] */
    if ((rtmGetTFinal(simple_M)!=-1) &&
        !((rtmGetTFinal(simple_M)-simple_M->Timing.taskTime0) >
          simple_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(simple_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++simple_M->Timing.clockTick0)) {
    ++simple_M->Timing.clockTickH0;
  }

  simple_M->Timing.taskTime0 = simple_M->Timing.clockTick0 *
    simple_M->Timing.stepSize0 + simple_M->Timing.clockTickH0 *
    simple_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void simple_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)simple_M, 0,
                sizeof(RT_MODEL_simple_T));
  rtmSetTFinal(simple_M, 10.0);
  simple_M->Timing.stepSize0 = 1.0;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    simple_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(simple_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(simple_M->rtwLogInfo, (NULL));
    rtliSetLogT(simple_M->rtwLogInfo, "tout");
    rtliSetLogX(simple_M->rtwLogInfo, "");
    rtliSetLogXFinal(simple_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(simple_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(simple_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(simple_M->rtwLogInfo, 0);
    rtliSetLogDecimation(simple_M->rtwLogInfo, 1);
    rtliSetLogY(simple_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(simple_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(simple_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &simple_B), 0,
                sizeof(B_simple_T));

  /* states (dwork) */
  (void) memset((void *)&simple_DW, 0,
                sizeof(DW_simple_T));

  /* external inputs */
  (void)memset(&simple_U, 0, sizeof(ExtU_simple_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(simple_M->rtwLogInfo, 0.0, rtmGetTFinal
    (simple_M), simple_M->Timing.stepSize0, (&rtmGetErrorStatus(simple_M)));

  /* SystemInitialize for Chart: '<Root>/Chart' */
  simple_DW.sfEvent = simple_CALL_EVENT;
  simple_DW.is_active_p1 = 0U;
  simple_DW.is_p1 = simple_IN_NO_ACTIVE_CHILD;
  simple_DW.is_c = simple_IN_NO_ACTIVE_CHILD;
  simple_DW.is_active_p2 = 0U;
  simple_DW.is_p2 = simple_IN_NO_ACTIVE_CHILD;
  simple_DW.is_active_c3_simple = 0U;
  simple_B.x = 0.0;
  simple_B.y = 0.0;
}

/* Model terminate function */
void simple_terminate(void)
{
  /* (no terminate code required) */
}
