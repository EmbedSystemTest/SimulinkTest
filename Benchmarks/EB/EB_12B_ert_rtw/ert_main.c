/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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

#include <stddef.h>
#include <stdio.h>            /* This example main program uses printf/fflush */
#include "EB_12B.h"                    /* Model's header file */

static RT_MODEL_EB_12B_T EB_12B_M_;
static RT_MODEL_EB_12B_T *const EB_12B_MPtr = &EB_12B_M_;/* Real-time model */
static DW_EB_12B_T EB_12B_DW;          /* Observable states */

/* '<Root>/B' */
static real_T EB_12B_U_B[15];

/* '<Root>/id' */
static real_T EB_12B_Y_id[9];

/* '<Root>/check' */
static real_T EB_12B_Y_check[9];

/* '<Root>/yinv' */
static real_T EB_12B_Y_yinv[9];

/* '<Root>/P' */
static real_T EB_12B_Y_P[15];

/* '<Root>/u' */
static real_T EB_12B_Y_u[5];

/* '<Root>/Buminusd' */
static real_T EB_12B_Y_Buminusd[3];

/* '<Root>/J' */
static real_T EB_12B_Y_J;

/* '<Root>/ridge_on' */
static boolean_T EB_12B_Y_ridge_on;

/*
 * Associating rt_OneStep with a real-time clock or interrupt service routine
 * is what makes the generated code "real-time".  The function rt_OneStep is
 * always associated with the base rate of the model.  Subrates are managed
 * by the base rate from inside the generated code.  Enabling/disabling
 * interrupts and floating point context switches are target specific.  This
 * example code indicates where these should take place relative to executing
 * the generated code step function.  Overrun behavior should be tailored to
 * your application needs.  This example simply sets an error status in the
 * real-time model and returns from rt_OneStep.
 */
void rt_OneStep(RT_MODEL_EB_12B_T *const EB_12B_M);
void rt_OneStep(RT_MODEL_EB_12B_T *const EB_12B_M)
{
  static boolean_T OverrunFlag = false;

  /* Disable interrupts here */

  /* Check for overrun */
  if (OverrunFlag) {
    rtmSetErrorStatus(EB_12B_M, "Overrun");
    return;
  }

  OverrunFlag = true;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  /* Set model inputs here */

  /* Step the model */
  EB_12B_step(EB_12B_M, EB_12B_U_B, EB_12B_Y_check, EB_12B_Y_yinv, EB_12B_Y_P,
              EB_12B_Y_u, EB_12B_Y_Buminusd, &EB_12B_Y_J, &EB_12B_Y_ridge_on);

  /* Get model outputs here */

  /* Indicate task complete */
  OverrunFlag = false;

  /* Disable interrupts here */
  /* Restore FPU context here (if necessary) */
  /* Enable interrupts here */
}

/*
 * The example "main" function illustrates what is required by your
 * application code to initialize, execute, and terminate the generated code.
 * Attaching rt_OneStep to a real-time clock is target specific.  This example
 * illustrates how you do this relative to initializing the model.
 */
int_T main(int_T argc, const char *argv[])
{
  RT_MODEL_EB_12B_T *const EB_12B_M = EB_12B_MPtr;

  /* Unused arguments */
  (void)(argc);
  (void)(argv);

  /* Pack model data into RTM */
  EB_12B_M->dwork = &EB_12B_DW;

  /* Initialize model */
  EB_12B_initialize(EB_12B_M, EB_12B_U_B, EB_12B_Y_id, EB_12B_Y_check,
                    EB_12B_Y_yinv, EB_12B_Y_P, EB_12B_Y_u, EB_12B_Y_Buminusd,
                    &EB_12B_Y_J, &EB_12B_Y_ridge_on);

  /* Attach rt_OneStep to a timer or interrupt service routine with
   * period 0.01 seconds (the model's base sample time) here.  The
   * call syntax for rt_OneStep is
   *
   *  rt_OneStep(EB_12B_M);
   */
  printf("Warning: The simulation will run forever. "
         "Generated ERT main won't simulate model step behavior. "
         "To change this behavior select the 'MAT-file logging' option.\n");
  fflush((NULL));
  while (rtmGetErrorStatus(EB_12B_M) == (NULL)) {
    /*  Perform application tasks here */
  }

  /* Disable rt_OneStep here */
  /* Terminate model */
  EB_12B_terminate(EB_12B_M);
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
