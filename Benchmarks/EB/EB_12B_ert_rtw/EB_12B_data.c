/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: EB_12B_data.c
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

#include "EB_12B.h"
#include "EB_12B_private.h"

/* Invariant block signals (default storage) */
const ConstB_EB_12B_T EB_12B_ConstB = {
  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 },/* '<S1>/Math Function' */

  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 }/* '<S1>/Divide' */
};

/* Constant parameters (default storage) */
const ConstP_EB_12B_T EB_12B_ConstP = {
  /* Expression: [ 1 0 0 ; 0 1 0 ; 0 0 1 ]
   * Referenced by: '<S1>/ID'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  /* Expression: [1 0 0 0 0;0 1 0 0 0;0 0 1 0 0;0 0 0 1 0;0 0 0 0 1]
   * Referenced by: '<Root>/Const'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 },

  /* Expression: [3;-1;2]
   * Referenced by: '<Root>/Const2'
   */
  { 3.0, -1.0, 2.0 },

  /* Expression: I*1E-12
   * Referenced by: '<S3>/Constant4'
   */
  { 1.0E-12, 0.0, 0.0, 0.0, 1.0E-12, 0.0, 0.0, 0.0, 1.0E-12 }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
