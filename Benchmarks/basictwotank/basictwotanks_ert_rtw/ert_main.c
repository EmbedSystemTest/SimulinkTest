/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'basictwotanks'.
 *
 * Model version                  : 1.170
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Mon Apr  4 06:19:26 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include <stddef.h>
#include <stdio.h>            /* This example main program uses printf/fflush */
#include "basictwotanks.h"             /* Model's header file */

static RT_MODEL_basictwotanks_T basictwotanks_M_;
static RT_MODEL_basictwotanks_T *const basictwotanks_MPtr = &basictwotanks_M_;/* Real-time model */
static DW_basictwotanks_T basictwotanks_DW;/* Observable states */

/* '<Root>/t1_h' */
static real_T basictwotanks_Y_t1_h;

/* '<Root>/t2_h' */
static real_T basictwotanks_Y_t2_h;

/* '<Root>/t1_sh' */
static real_T basictwotanks_Y_t1_sh;

/* '<Root>/t1_sl' */
static real_T basictwotanks_Y_t1_sl;

/* '<Root>/t2_sh' */
static real_T basictwotanks_Y_t2_sh;

/* '<Root>/t2_sm' */
static real_T basictwotanks_Y_t2_sm;

/* '<Root>/t2_sl' */
static real_T basictwotanks_Y_t2_sl;

/* '<Root>/pump_state' */
static real_T basictwotanks_Y_pump_state;

/* '<Root>/valve_state' */
static real_T basictwotanks_Y_valve_state;

/* '<Root>/p_valve_state' */
static real_T basictwotanks_Y_p_valve_state;

/* '<Root>/e_valve_state' */
static real_T basictwotanks_Y_e_valve_state;

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
void rt_OneStep(RT_MODEL_basictwotanks_T *const basictwotanks_M);
void rt_OneStep(RT_MODEL_basictwotanks_T *const basictwotanks_M)
{
  static boolean_T OverrunFlag = false;

  /* Disable interrupts here */

  /* Check for overrun */
  if (OverrunFlag) {
    rtmSetErrorStatus(basictwotanks_M, "Overrun");
    return;
  }

  OverrunFlag = true;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  /* Set model inputs here */

  /* Step the model */
  basictwotanks_step(basictwotanks_M, &basictwotanks_Y_t1_h,
                     &basictwotanks_Y_t2_h, &basictwotanks_Y_t1_sh,
                     &basictwotanks_Y_t1_sl, &basictwotanks_Y_t2_sh,
                     &basictwotanks_Y_t2_sm, &basictwotanks_Y_t2_sl,
                     &basictwotanks_Y_pump_state, &basictwotanks_Y_valve_state,
                     &basictwotanks_Y_p_valve_state,
                     &basictwotanks_Y_e_valve_state);

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
  RT_MODEL_basictwotanks_T *const basictwotanks_M = basictwotanks_MPtr;

  /* Unused arguments */
  (void)(argc);
  (void)(argv);

  /* Pack model data into RTM */
  basictwotanks_M->dwork = &basictwotanks_DW;

  /* Initialize model */
  basictwotanks_initialize(basictwotanks_M, &basictwotanks_Y_t1_h,
    &basictwotanks_Y_t2_h, &basictwotanks_Y_t1_sh, &basictwotanks_Y_t1_sl,
    &basictwotanks_Y_t2_sh, &basictwotanks_Y_t2_sm, &basictwotanks_Y_t2_sl,
    &basictwotanks_Y_pump_state, &basictwotanks_Y_valve_state,
    &basictwotanks_Y_p_valve_state, &basictwotanks_Y_e_valve_state);

  /* Attach rt_OneStep to a timer or interrupt service routine with
   * period 0.1 seconds (the model's base sample time) here.  The
   * call syntax for rt_OneStep is
   *
   *  rt_OneStep(basictwotanks_M);
   */
  printf("Warning: The simulation will run forever. "
         "Generated ERT main won't simulate model step behavior. "
         "To change this behavior select the 'MAT-file logging' option.\n");
  fflush((NULL));
  while (rtmGetErrorStatus(basictwotanks_M) == (NULL)) {
    /*  Perform application tasks here */
  }

  /* Disable rt_OneStep here */
  /* Terminate model */
  basictwotanks_terminate(basictwotanks_M);
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
