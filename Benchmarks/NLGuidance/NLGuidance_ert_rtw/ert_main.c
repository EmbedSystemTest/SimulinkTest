/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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

#include <stddef.h>
#include <stdio.h>            /* This example main program uses printf/fflush */
#include "NLGuidance.h"                /* Model's header file */

static RT_MODEL_NLGuidance_T NLGuidance_M_;
static RT_MODEL_NLGuidance_T *const NLGuidance_MPtr = &NLGuidance_M_;/* Real-time model */

/* '<Root>/Xtarg' */
static real_T NLGuidance_U_Xtarg[3];

/* '<Root>/Xv' */
static real_T NLGuidance_U_Xv[3];

/* '<Root>/Vv' */
static real_T NLGuidance_U_Vv[3];

/* '<Root>/Vt' */
static real_T NLGuidance_U_Vt[3];

/* '<Root>/r' */
static real_T NLGuidance_U_r;

/* '<Root>/yout' */
static real_T NLGuidance_Y_yout[3];

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
void rt_OneStep(RT_MODEL_NLGuidance_T *const NLGuidance_M);
void rt_OneStep(RT_MODEL_NLGuidance_T *const NLGuidance_M)
{
  static boolean_T OverrunFlag = false;

  /* Disable interrupts here */

  /* Check for overrun */
  if (OverrunFlag) {
    rtmSetErrorStatus(NLGuidance_M, "Overrun");
    return;
  }

  OverrunFlag = true;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  /* Set model inputs here */

  /* Step the model */
  NLGuidance_step(NLGuidance_M, NLGuidance_U_Xtarg, NLGuidance_U_Xv,
                  NLGuidance_U_Vv, NLGuidance_U_r, NLGuidance_Y_yout);

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
  RT_MODEL_NLGuidance_T *const NLGuidance_M = NLGuidance_MPtr;

  /* Unused arguments */
  (void)(argc);
  (void)(argv);

  /* Pack model data into RTM */

  /* Initialize model */
  NLGuidance_initialize(NLGuidance_M, NLGuidance_U_Xtarg, NLGuidance_U_Xv,
                        NLGuidance_U_Vv, NLGuidance_U_Vt, &NLGuidance_U_r,
                        NLGuidance_Y_yout);

  /* Attach rt_OneStep to a timer or interrupt service routine with
   * period 0.02 seconds (the model's base sample time) here.  The
   * call syntax for rt_OneStep is
   *
   *  rt_OneStep(NLGuidance_M);
   */
  printf("Warning: The simulation will run forever. "
         "Generated ERT main won't simulate model step behavior. "
         "To change this behavior select the 'MAT-file logging' option.\n");
  fflush((NULL));
  while (rtmGetErrorStatus(NLGuidance_M) == (NULL)) {
    /*  Perform application tasks here */
  }

  /* Disable rt_OneStep here */
  /* Terminate model */
  NLGuidance_terminate(NLGuidance_M);
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
