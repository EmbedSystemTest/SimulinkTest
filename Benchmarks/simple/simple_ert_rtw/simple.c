/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: simple.c
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
          }
        }
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
}

/* Model initialize function */
void simple_initialize(void)
{
  /* SystemInitialize for Chart: '<Root>/Chart' */
  simple_DW.sfEvent = simple_CALL_EVENT;
}

/* Model terminate function */
void simple_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
