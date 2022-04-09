/*
 * EB_12B_data.c
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

#include "EB_12B.h"
#include "EB_12B_private.h"

/* Block parameters (default storage) */
P_EB_12B_T EB_12B_P = {
  /* Variable: I
   * Referenced by: '<S3>/Constant4'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  /* Variable: I0
   * Referenced by: '<S3>/Constant3'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: [ 1 0 0 ; 0 1 0 ; 0 0 1 ]
   * Referenced by: '<S1>/ID'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  /* Expression: [1 0 0 0 0;0 1 0 0 0;0 0 1 0 0;0 0 0 1 0;0 0 0 0 1]
   * Referenced by: '<Root>/Const'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 },

  /* Expression: 1e-12
   * Referenced by: '<S3>/Constant1'
   */
  1.0E-12,

  /* Expression: 1
   * Referenced by: '<S3>/fix_on'
   */
  1.0,

  /* Expression: 1e-1
   * Referenced by: '<S3>/Switch1'
   */
  0.1,

  /* Expression: [3;-1;2]
   * Referenced by: '<Root>/Const2'
   */
  { 3.0, -1.0, 2.0 },

  /* Expression: [0;0;0;0;0]
   * Referenced by: '<Root>/Const3'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0 }
};
