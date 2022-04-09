/*
 * euler321_I2B_12B.c
 *
 * Code generation for model "euler321_I2B_12B".
 *
 * Model version              : 1.44
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Fri Aug 27 10:33:21 2021
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "euler321_I2B_12B.h"
#include "euler321_I2B_12B_private.h"

/* External inputs (root inport signals with default storage) */
ExtU_euler321_I2B_12B_T euler321_I2B_12B_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_euler321_I2B_12B_T euler321_I2B_12B_Y;

/* Real-time model */
RT_MODEL_euler321_I2B_12B_T euler321_I2B_12B_M_;
RT_MODEL_euler321_I2B_12B_T *const euler321_I2B_12B_M = &euler321_I2B_12B_M_;

/* Model output function */
static void euler321_I2B_12B_output(void)
{
  real_T rtb_Product2_j[3];
  real_T rtb_ArrayVectorSubtract1[3];
  real_T rtb_Product2_n[3];
  real_T rtb_TrigonometricFunction2;
  real_T rtb_TrigonometricFunction4;
  real_T rtb_VectorConcatenate[9];
  real_T rtb_VectorConcatenate_k[9];
  real_T rtb_VectorConcatenate_p[9];
  real_T rtb_Product1_d[9];
  real_T rtb_TrigonometricFunction4_tmp;
  real_T rtb_TrigonometricFunction2_tmp;
  real_T rtb_TrigonometricFunction2_tm_0;
  real_T rtb_TrigonometricFunction4_tm_0;
  real_T rtb_TrigonometricFunction2_tm_1;
  real_T rtb_TrigonometricFunction4_tm_1;
  real_T rtb_VectorConcatenate_f[9];
  real_T rtb_VectorConcatenate_h[9];
  int32_T i;
  int32_T i_0;
  int32_T rtb_VectorConcatenate_f_tmp;

  /* Trigonometry: '<S7>/sincos' incorporates:
   *  Inport: '<Root>/phi'
   *  Trigonometry: '<S13>/sincos'
   *  Trigonometry: '<S19>/sincos'
   *  Trigonometry: '<S4>/Trigonometric Function3'
   *  Trigonometry: '<S4>/Trigonometric Function6'
   */
  rtb_TrigonometricFunction4_tmp = sin(euler321_I2B_12B_U.phi);
  rtb_TrigonometricFunction2_tmp = cos(euler321_I2B_12B_U.phi);

  /* Fcn: '<S7>/Fcn11' */
  rtb_VectorConcatenate[0] = 1.0;

  /* Fcn: '<S7>/Fcn21' */
  rtb_VectorConcatenate[1] = 0.0;

  /* Fcn: '<S7>/Fcn31' */
  rtb_VectorConcatenate[2] = 0.0;

  /* Fcn: '<S7>/Fcn12' */
  rtb_VectorConcatenate[3] = 0.0;

  /* Fcn: '<S7>/Fcn22' incorporates:
   *  Trigonometry: '<S7>/sincos'
   */
  rtb_VectorConcatenate[4] = rtb_TrigonometricFunction2_tmp;

  /* Fcn: '<S7>/Fcn32' incorporates:
   *  Trigonometry: '<S7>/sincos'
   */
  rtb_VectorConcatenate[5] = -rtb_TrigonometricFunction4_tmp;

  /* Fcn: '<S7>/Fcn13' */
  rtb_VectorConcatenate[6] = 0.0;

  /* Fcn: '<S7>/Fcn23' incorporates:
   *  Trigonometry: '<S7>/sincos'
   */
  rtb_VectorConcatenate[7] = rtb_TrigonometricFunction4_tmp;

  /* Fcn: '<S7>/Fcn33' incorporates:
   *  Trigonometry: '<S7>/sincos'
   */
  rtb_VectorConcatenate[8] = rtb_TrigonometricFunction2_tmp;

  /* Trigonometry: '<S6>/sincos' incorporates:
   *  Inport: '<Root>/theta'
   *  Trigonometry: '<S12>/sincos'
   *  Trigonometry: '<S4>/Trigonometric Function4'
   *  Trigonometry: '<S4>/Trigonometric Function7'
   */
  rtb_TrigonometricFunction2_tm_0 = sin(euler321_I2B_12B_U.theta);
  rtb_TrigonometricFunction4_tm_0 = cos(euler321_I2B_12B_U.theta);

  /* Fcn: '<S6>/Fcn11' incorporates:
   *  Trigonometry: '<S6>/sincos'
   */
  rtb_VectorConcatenate_k[0] = rtb_TrigonometricFunction4_tm_0;

  /* Fcn: '<S6>/Fcn21' */
  rtb_VectorConcatenate_k[1] = 0.0;

  /* Fcn: '<S6>/Fcn31' incorporates:
   *  Trigonometry: '<S6>/sincos'
   */
  rtb_VectorConcatenate_k[2] = rtb_TrigonometricFunction2_tm_0;

  /* Fcn: '<S6>/Fcn12' */
  rtb_VectorConcatenate_k[3] = 0.0;

  /* Fcn: '<S6>/Fcn22' */
  rtb_VectorConcatenate_k[4] = 1.0;

  /* Fcn: '<S6>/Fcn32' */
  rtb_VectorConcatenate_k[5] = 0.0;

  /* Fcn: '<S6>/Fcn13' incorporates:
   *  Trigonometry: '<S6>/sincos'
   */
  rtb_VectorConcatenate_k[6] = -rtb_TrigonometricFunction2_tm_0;

  /* Fcn: '<S6>/Fcn23' */
  rtb_VectorConcatenate_k[7] = 0.0;

  /* Fcn: '<S6>/Fcn33' incorporates:
   *  Trigonometry: '<S6>/sincos'
   */
  rtb_VectorConcatenate_k[8] = rtb_TrigonometricFunction4_tm_0;

  /* Trigonometry: '<S5>/sincos' incorporates:
   *  Inport: '<Root>/psi'
   *  Trigonometry: '<S11>/sincos'
   *  Trigonometry: '<S17>/sincos'
   *  Trigonometry: '<S4>/Trigonometric Function2'
   *  Trigonometry: '<S4>/Trigonometric Function5'
   */
  rtb_TrigonometricFunction2_tm_1 = sin(euler321_I2B_12B_U.psi);
  rtb_TrigonometricFunction4_tm_1 = cos(euler321_I2B_12B_U.psi);

  /* Fcn: '<S5>/Fcn11' incorporates:
   *  Trigonometry: '<S5>/sincos'
   */
  rtb_VectorConcatenate_p[0] = rtb_TrigonometricFunction4_tm_1;

  /* Fcn: '<S5>/Fcn21' incorporates:
   *  Trigonometry: '<S5>/sincos'
   */
  rtb_VectorConcatenate_p[1] = -rtb_TrigonometricFunction2_tm_1;

  /* Fcn: '<S5>/Fcn31' */
  rtb_VectorConcatenate_p[2] = 0.0;

  /* Fcn: '<S5>/Fcn12' incorporates:
   *  Trigonometry: '<S5>/sincos'
   */
  rtb_VectorConcatenate_p[3] = rtb_TrigonometricFunction2_tm_1;

  /* Fcn: '<S5>/Fcn22' incorporates:
   *  Trigonometry: '<S5>/sincos'
   */
  rtb_VectorConcatenate_p[4] = rtb_TrigonometricFunction4_tm_1;

  /* Fcn: '<S5>/Fcn32' */
  rtb_VectorConcatenate_p[5] = 0.0;

  /* Fcn: '<S5>/Fcn13' */
  rtb_VectorConcatenate_p[6] = 0.0;

  /* Fcn: '<S5>/Fcn23' */
  rtb_VectorConcatenate_p[7] = 0.0;

  /* Fcn: '<S5>/Fcn33' */
  rtb_VectorConcatenate_p[8] = 1.0;

  /* Product: '<S1>/Product' */
  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      rtb_VectorConcatenate_f_tmp = i_0 + 3 * i;
      rtb_VectorConcatenate_f[rtb_VectorConcatenate_f_tmp] = 0.0;
      rtb_VectorConcatenate_f[rtb_VectorConcatenate_f_tmp] +=
        rtb_VectorConcatenate_p[3 * i] * rtb_VectorConcatenate_k[i_0];
      rtb_VectorConcatenate_f[rtb_VectorConcatenate_f_tmp] +=
        rtb_VectorConcatenate_p[3 * i + 1] * rtb_VectorConcatenate_k[i_0 + 3];
      rtb_VectorConcatenate_f[rtb_VectorConcatenate_f_tmp] +=
        rtb_VectorConcatenate_p[3 * i + 2] * rtb_VectorConcatenate_k[i_0 + 6];
    }
  }

  /* End of Product: '<S1>/Product' */

  /* Product: '<S1>/Product1' */
  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      rtb_VectorConcatenate_f_tmp = i_0 + 3 * i;
      rtb_Product1_d[rtb_VectorConcatenate_f_tmp] = 0.0;
      rtb_Product1_d[rtb_VectorConcatenate_f_tmp] += rtb_VectorConcatenate_f[3 *
        i] * rtb_VectorConcatenate[i_0];
      rtb_Product1_d[rtb_VectorConcatenate_f_tmp] += rtb_VectorConcatenate_f[3 *
        i + 1] * rtb_VectorConcatenate[i_0 + 3];
      rtb_Product1_d[rtb_VectorConcatenate_f_tmp] += rtb_VectorConcatenate_f[3 *
        i + 2] * rtb_VectorConcatenate[i_0 + 6];
    }
  }

  /* End of Product: '<S1>/Product1' */

  /* Outport: '<Root>/DCM321' */
  memcpy(&euler321_I2B_12B_Y.DCM321[0], &rtb_Product1_d[0], 9U * sizeof(real_T));

  /* Fcn: '<S13>/Fcn11' */
  rtb_VectorConcatenate_p[0] = 1.0;

  /* Fcn: '<S13>/Fcn21' */
  rtb_VectorConcatenate_p[1] = 0.0;

  /* Fcn: '<S13>/Fcn31' */
  rtb_VectorConcatenate_p[2] = 0.0;

  /* Fcn: '<S13>/Fcn12' */
  rtb_VectorConcatenate_p[3] = 0.0;

  /* Fcn: '<S13>/Fcn22' */
  rtb_VectorConcatenate_p[4] = rtb_TrigonometricFunction2_tmp;

  /* Fcn: '<S13>/Fcn32' */
  rtb_VectorConcatenate_p[5] = -rtb_TrigonometricFunction4_tmp;

  /* Fcn: '<S13>/Fcn13' */
  rtb_VectorConcatenate_p[6] = 0.0;

  /* Fcn: '<S13>/Fcn23' */
  rtb_VectorConcatenate_p[7] = rtb_TrigonometricFunction4_tmp;

  /* Fcn: '<S13>/Fcn33' */
  rtb_VectorConcatenate_p[8] = rtb_TrigonometricFunction2_tmp;

  /* Fcn: '<S12>/Fcn11' */
  rtb_VectorConcatenate_k[0] = rtb_TrigonometricFunction4_tm_0;

  /* Fcn: '<S12>/Fcn21' */
  rtb_VectorConcatenate_k[1] = 0.0;

  /* Fcn: '<S12>/Fcn31' */
  rtb_VectorConcatenate_k[2] = rtb_TrigonometricFunction2_tm_0;

  /* Fcn: '<S12>/Fcn12' */
  rtb_VectorConcatenate_k[3] = 0.0;

  /* Fcn: '<S12>/Fcn22' */
  rtb_VectorConcatenate_k[4] = 1.0;

  /* Fcn: '<S12>/Fcn32' */
  rtb_VectorConcatenate_k[5] = 0.0;

  /* Fcn: '<S12>/Fcn13' */
  rtb_VectorConcatenate_k[6] = -rtb_TrigonometricFunction2_tm_0;

  /* Fcn: '<S12>/Fcn23' */
  rtb_VectorConcatenate_k[7] = 0.0;

  /* Fcn: '<S12>/Fcn33' */
  rtb_VectorConcatenate_k[8] = rtb_TrigonometricFunction4_tm_0;

  /* Fcn: '<S11>/Fcn11' */
  rtb_VectorConcatenate[0] = rtb_TrigonometricFunction4_tm_1;

  /* Fcn: '<S11>/Fcn21' */
  rtb_VectorConcatenate[1] = -rtb_TrigonometricFunction2_tm_1;

  /* Fcn: '<S11>/Fcn31' */
  rtb_VectorConcatenate[2] = 0.0;

  /* Fcn: '<S11>/Fcn12' */
  rtb_VectorConcatenate[3] = rtb_TrigonometricFunction2_tm_1;

  /* Fcn: '<S11>/Fcn22' */
  rtb_VectorConcatenate[4] = rtb_TrigonometricFunction4_tm_1;

  /* Fcn: '<S11>/Fcn32' */
  rtb_VectorConcatenate[5] = 0.0;

  /* Fcn: '<S11>/Fcn13' */
  rtb_VectorConcatenate[6] = 0.0;

  /* Fcn: '<S11>/Fcn23' */
  rtb_VectorConcatenate[7] = 0.0;

  /* Fcn: '<S11>/Fcn33' */
  rtb_VectorConcatenate[8] = 1.0;
  for (i_0 = 0; i_0 < 3; i_0++) {
    /* Product: '<S1>/Product2' incorporates:
     *  Inport: '<Root>/Vi'
     *  Product: '<S2>/Product'
     */
    rtb_Product2_j[i_0] = 0.0;
    for (i = 0; i < 3; i++) {
      /* Product: '<S2>/Product' */
      rtb_VectorConcatenate_f_tmp = i_0 + 3 * i;
      rtb_VectorConcatenate_f[rtb_VectorConcatenate_f_tmp] = 0.0;
      rtb_VectorConcatenate_f[rtb_VectorConcatenate_f_tmp] +=
        rtb_VectorConcatenate[3 * i] * rtb_VectorConcatenate_k[i_0];
      rtb_VectorConcatenate_f[rtb_VectorConcatenate_f_tmp] +=
        rtb_VectorConcatenate[3 * i + 1] * rtb_VectorConcatenate_k[i_0 + 3];
      rtb_VectorConcatenate_f[rtb_VectorConcatenate_f_tmp] +=
        rtb_VectorConcatenate[3 * i + 2] * rtb_VectorConcatenate_k[i_0 + 6];
      rtb_Product2_j[i_0] += rtb_Product1_d[rtb_VectorConcatenate_f_tmp] *
        euler321_I2B_12B_U.Vi[i];
    }

    /* End of Product: '<S1>/Product2' */

    /* Outport: '<Root>/Vb' */
    euler321_I2B_12B_Y.Vb[i_0] = rtb_Product2_j[i_0];
  }

  for (i = 0; i < 3; i++) {
    /* Product: '<S2>/Product2' */
    rtb_ArrayVectorSubtract1[i] = 0.0;
    for (i_0 = 0; i_0 < 3; i_0++) {
      /* Product: '<S2>/Product1' incorporates:
       *  Product: '<S2>/Product2'
       */
      rtb_VectorConcatenate_f_tmp = i + 3 * i_0;
      rtb_VectorConcatenate_h[rtb_VectorConcatenate_f_tmp] = 0.0;
      rtb_VectorConcatenate_h[rtb_VectorConcatenate_f_tmp] +=
        rtb_VectorConcatenate_f[3 * i_0] * rtb_VectorConcatenate_p[i];
      rtb_VectorConcatenate_h[rtb_VectorConcatenate_f_tmp] +=
        rtb_VectorConcatenate_f[3 * i_0 + 1] * rtb_VectorConcatenate_p[i + 3];
      rtb_VectorConcatenate_h[rtb_VectorConcatenate_f_tmp] +=
        rtb_VectorConcatenate_f[3 * i_0 + 2] * rtb_VectorConcatenate_p[i + 6];

      /* Product: '<S2>/Product2' incorporates:
       *  Inport: '<Root>/Vi'
       */
      rtb_ArrayVectorSubtract1[i] +=
        rtb_VectorConcatenate_h[rtb_VectorConcatenate_f_tmp] *
        euler321_I2B_12B_U.Vi[i_0];
    }
  }

  /* S-Function (sdspdmult2): '<Root>/Array-Vector Subtract' */
  rtb_Product2_n[0] = rtb_Product2_j[0] - rtb_ArrayVectorSubtract1[0];
  rtb_Product2_n[1] = rtb_Product2_j[1] - rtb_ArrayVectorSubtract1[1];
  rtb_Product2_n[2] = rtb_Product2_j[2] - rtb_ArrayVectorSubtract1[2];

  /* Fcn: '<S19>/Fcn11' */
  rtb_VectorConcatenate_p[0] = 1.0;

  /* Fcn: '<S19>/Fcn21' */
  rtb_VectorConcatenate_p[1] = 0.0;

  /* Fcn: '<S19>/Fcn31' */
  rtb_VectorConcatenate_p[2] = 0.0;

  /* Fcn: '<S19>/Fcn12' */
  rtb_VectorConcatenate_p[3] = 0.0;

  /* Fcn: '<S19>/Fcn22' */
  rtb_VectorConcatenate_p[4] = rtb_TrigonometricFunction2_tmp;

  /* Fcn: '<S19>/Fcn32' */
  rtb_VectorConcatenate_p[5] = -rtb_TrigonometricFunction4_tmp;

  /* Fcn: '<S19>/Fcn13' */
  rtb_VectorConcatenate_p[6] = 0.0;

  /* Fcn: '<S19>/Fcn23' */
  rtb_VectorConcatenate_p[7] = rtb_TrigonometricFunction4_tmp;

  /* Fcn: '<S19>/Fcn33' */
  rtb_VectorConcatenate_p[8] = rtb_TrigonometricFunction2_tmp;

  /* Trigonometry: '<S18>/sincos' incorporates:
   *  Inport: '<Root>/Inport'
   */
  rtb_TrigonometricFunction2 = sin(euler321_I2B_12B_U.Inport);
  rtb_TrigonometricFunction4 = cos(euler321_I2B_12B_U.Inport);

  /* Fcn: '<S18>/Fcn11' */
  rtb_VectorConcatenate_k[0] = rtb_TrigonometricFunction4;

  /* Fcn: '<S18>/Fcn21' */
  rtb_VectorConcatenate_k[1] = 0.0;

  /* Fcn: '<S18>/Fcn31' */
  rtb_VectorConcatenate_k[2] = rtb_TrigonometricFunction2;

  /* Fcn: '<S18>/Fcn12' */
  rtb_VectorConcatenate_k[3] = 0.0;

  /* Fcn: '<S18>/Fcn22' */
  rtb_VectorConcatenate_k[4] = 1.0;

  /* Fcn: '<S18>/Fcn32' */
  rtb_VectorConcatenate_k[5] = 0.0;

  /* Fcn: '<S18>/Fcn13' */
  rtb_VectorConcatenate_k[6] = -rtb_TrigonometricFunction2;

  /* Fcn: '<S18>/Fcn23' */
  rtb_VectorConcatenate_k[7] = 0.0;

  /* Fcn: '<S18>/Fcn33' */
  rtb_VectorConcatenate_k[8] = rtb_TrigonometricFunction4;

  /* Fcn: '<S17>/Fcn11' */
  rtb_VectorConcatenate[0] = rtb_TrigonometricFunction4_tm_1;

  /* Fcn: '<S17>/Fcn21' */
  rtb_VectorConcatenate[1] = -rtb_TrigonometricFunction2_tm_1;

  /* Fcn: '<S17>/Fcn31' */
  rtb_VectorConcatenate[2] = 0.0;

  /* Fcn: '<S17>/Fcn12' */
  rtb_VectorConcatenate[3] = rtb_TrigonometricFunction2_tm_1;

  /* Fcn: '<S17>/Fcn22' */
  rtb_VectorConcatenate[4] = rtb_TrigonometricFunction4_tm_1;

  /* Fcn: '<S17>/Fcn32' */
  rtb_VectorConcatenate[5] = 0.0;

  /* Fcn: '<S17>/Fcn13' */
  rtb_VectorConcatenate[6] = 0.0;

  /* Fcn: '<S17>/Fcn23' */
  rtb_VectorConcatenate[7] = 0.0;

  /* Fcn: '<S17>/Fcn33' */
  rtb_VectorConcatenate[8] = 1.0;
  for (i_0 = 0; i_0 < 3; i_0++) {
    /* Outport: '<Root>/outTheta' */
    euler321_I2B_12B_Y.outTheta[i_0] = rtb_Product2_n[i_0];

    /* Product: '<S3>/Product' */
    for (i = 0; i < 3; i++) {
      rtb_VectorConcatenate_f_tmp = i_0 + 3 * i;
      rtb_VectorConcatenate_f[rtb_VectorConcatenate_f_tmp] = 0.0;
      rtb_VectorConcatenate_f[rtb_VectorConcatenate_f_tmp] +=
        rtb_VectorConcatenate[3 * i] * rtb_VectorConcatenate_k[i_0];
      rtb_VectorConcatenate_f[rtb_VectorConcatenate_f_tmp] +=
        rtb_VectorConcatenate[3 * i + 1] * rtb_VectorConcatenate_k[i_0 + 3];
      rtb_VectorConcatenate_f[rtb_VectorConcatenate_f_tmp] +=
        rtb_VectorConcatenate[3 * i + 2] * rtb_VectorConcatenate_k[i_0 + 6];
    }

    /* End of Product: '<S3>/Product' */
  }

  for (i = 0; i < 3; i++) {
    /* Product: '<S3>/Product2' */
    rtb_Product2_n[i] = 0.0;
    for (i_0 = 0; i_0 < 3; i_0++) {
      /* Product: '<S3>/Product1' incorporates:
       *  Product: '<S3>/Product2'
       */
      rtb_VectorConcatenate_f_tmp = i + 3 * i_0;
      rtb_VectorConcatenate_h[rtb_VectorConcatenate_f_tmp] = 0.0;
      rtb_VectorConcatenate_h[rtb_VectorConcatenate_f_tmp] +=
        rtb_VectorConcatenate_f[3 * i_0] * rtb_VectorConcatenate_p[i];
      rtb_VectorConcatenate_h[rtb_VectorConcatenate_f_tmp] +=
        rtb_VectorConcatenate_f[3 * i_0 + 1] * rtb_VectorConcatenate_p[i + 3];
      rtb_VectorConcatenate_h[rtb_VectorConcatenate_f_tmp] +=
        rtb_VectorConcatenate_f[3 * i_0 + 2] * rtb_VectorConcatenate_p[i + 6];

      /* Product: '<S3>/Product2' incorporates:
       *  Inport: '<Root>/Vi'
       */
      rtb_Product2_n[i] += rtb_VectorConcatenate_h[rtb_VectorConcatenate_f_tmp] *
        euler321_I2B_12B_U.Vi[i_0];
    }
  }

  /* Outport: '<Root>/outGamma' incorporates:
   *  S-Function (sdspdmult2): '<Root>/Array-Vector Subtract1'
   */
  euler321_I2B_12B_Y.outGamma[0] = rtb_Product2_j[0] - rtb_Product2_n[0];
  euler321_I2B_12B_Y.outGamma[1] = rtb_Product2_j[1] - rtb_Product2_n[1];
  euler321_I2B_12B_Y.outGamma[2] = rtb_Product2_j[2] - rtb_Product2_n[2];

  /* Product: '<S4>/Product2' incorporates:
   *  Product: '<S4>/Product4'
   */
  rtb_TrigonometricFunction2 = rtb_TrigonometricFunction4_tm_1 *
    rtb_TrigonometricFunction2_tm_0;

  /* Product: '<S4>/Product7' incorporates:
   *  Product: '<S4>/Product9'
   */
  rtb_TrigonometricFunction4 = rtb_TrigonometricFunction2_tm_1 *
    rtb_TrigonometricFunction2_tm_0;

  /* Outport: '<Root>/outR1' incorporates:
   *  Logic: '<S4>/AND'
   *  Product: '<S4>/Product'
   *  Product: '<S4>/Product1'
   *  Product: '<S4>/Product10'
   *  Product: '<S4>/Product11'
   *  Product: '<S4>/Product2'
   *  Product: '<S4>/Product3'
   *  Product: '<S4>/Product4'
   *  Product: '<S4>/Product5'
   *  Product: '<S4>/Product6'
   *  Product: '<S4>/Product7'
   *  Product: '<S4>/Product8'
   *  Product: '<S4>/Product9'
   *  RelationalOperator: '<S4>/Relational Operator'
   *  RelationalOperator: '<S4>/Relational Operator1'
   *  RelationalOperator: '<S4>/Relational Operator2'
   *  RelationalOperator: '<S4>/Relational Operator3'
   *  RelationalOperator: '<S4>/Relational Operator4'
   *  RelationalOperator: '<S4>/Relational Operator5'
   *  RelationalOperator: '<S4>/Relational Operator6'
   *  RelationalOperator: '<S4>/Relational Operator7'
   *  RelationalOperator: '<S4>/Relational Operator8'
   *  Sum: '<S4>/Add'
   *  Sum: '<S4>/Add1'
   *  Sum: '<S4>/Add2'
   *  Sum: '<S4>/Add3'
   *  UnaryMinus: '<S4>/Unary Minus'
   *  UnaryMinus: '<S4>/Unary Minus1'
   *  UnaryMinus: '<S4>/Unary Minus2'
   */
  euler321_I2B_12B_Y.outR1 = ((rtb_TrigonometricFunction4_tm_1 *
    rtb_TrigonometricFunction4_tm_0 == rtb_Product1_d[0]) &&
    (rtb_TrigonometricFunction2 * rtb_TrigonometricFunction4_tmp +
     -rtb_TrigonometricFunction2_tmp * rtb_TrigonometricFunction2_tm_1 ==
     rtb_Product1_d[1]) && (rtb_TrigonometricFunction2 *
    rtb_TrigonometricFunction2_tmp + rtb_TrigonometricFunction4_tmp *
    rtb_TrigonometricFunction2_tm_1 == rtb_Product1_d[2]) &&
    (rtb_TrigonometricFunction2_tm_1 * rtb_TrigonometricFunction4_tm_0 ==
     rtb_Product1_d[3]) && (rtb_TrigonometricFunction4 *
    rtb_TrigonometricFunction4_tmp + rtb_TrigonometricFunction4_tm_1 *
    rtb_TrigonometricFunction2_tmp == rtb_Product1_d[4]) &&
    (rtb_TrigonometricFunction4 * rtb_TrigonometricFunction2_tmp +
     -rtb_TrigonometricFunction4_tmp * rtb_TrigonometricFunction4_tm_1 ==
     rtb_Product1_d[5]) && (-rtb_TrigonometricFunction2_tm_0 == rtb_Product1_d[6])
    && (rtb_TrigonometricFunction4_tmp * rtb_TrigonometricFunction4_tm_0 ==
        rtb_Product1_d[7]) && (rtb_TrigonometricFunction2_tmp *
    rtb_TrigonometricFunction4_tm_0 == rtb_Product1_d[8]));
}

/* Model update function */
static void euler321_I2B_12B_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++euler321_I2B_12B_M->Timing.clockTick0)) {
    ++euler321_I2B_12B_M->Timing.clockTickH0;
  }

  euler321_I2B_12B_M->Timing.t[0] = euler321_I2B_12B_M->Timing.clockTick0 *
    euler321_I2B_12B_M->Timing.stepSize0 +
    euler321_I2B_12B_M->Timing.clockTickH0 *
    euler321_I2B_12B_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void euler321_I2B_12B_initialize(void)
{
}

/* Model terminate function */
static void euler321_I2B_12B_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  euler321_I2B_12B_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  euler321_I2B_12B_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  euler321_I2B_12B_initialize();
}

void MdlTerminate(void)
{
  euler321_I2B_12B_terminate();
}

/* Registration function */
RT_MODEL_euler321_I2B_12B_T *euler321_I2B_12B(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)euler321_I2B_12B_M, 0,
                sizeof(RT_MODEL_euler321_I2B_12B_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = euler321_I2B_12B_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    euler321_I2B_12B_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    euler321_I2B_12B_M->Timing.sampleTimes =
      (&euler321_I2B_12B_M->Timing.sampleTimesArray[0]);
    euler321_I2B_12B_M->Timing.offsetTimes =
      (&euler321_I2B_12B_M->Timing.offsetTimesArray[0]);

    /* task periods */
    euler321_I2B_12B_M->Timing.sampleTimes[0] = (0.01);

    /* task offsets */
    euler321_I2B_12B_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(euler321_I2B_12B_M, &euler321_I2B_12B_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = euler321_I2B_12B_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    euler321_I2B_12B_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(euler321_I2B_12B_M, 10.0);
  euler321_I2B_12B_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    euler321_I2B_12B_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(euler321_I2B_12B_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(euler321_I2B_12B_M->rtwLogInfo, (NULL));
    rtliSetLogT(euler321_I2B_12B_M->rtwLogInfo, "tout");
    rtliSetLogX(euler321_I2B_12B_M->rtwLogInfo, "");
    rtliSetLogXFinal(euler321_I2B_12B_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(euler321_I2B_12B_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(euler321_I2B_12B_M->rtwLogInfo, 2);
    rtliSetLogMaxRows(euler321_I2B_12B_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(euler321_I2B_12B_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &euler321_I2B_12B_Y.DCM321[0],
        &euler321_I2B_12B_Y.Vb[0],
        &euler321_I2B_12B_Y.outTheta[0],
        &euler321_I2B_12B_Y.outGamma[0],
        &euler321_I2B_12B_Y.outR1
      };

      rtliSetLogYSignalPtrs(euler321_I2B_12B_M->rtwLogInfo, ((LogSignalPtrsType)
        rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        9,
        3,
        3,
        3,
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        2,
        1,
        2,
        2,
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        3, 3,
        3,
        3, 1,
        3, 1,
        1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0,
        0,
        0,
        0,
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL), (NULL),
        (NULL),
        (NULL), (NULL),
        (NULL), (NULL),
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4, 4,
        4,
        4, 4,
        4, 4,
        4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_BOOLEAN
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0,
        0,
        0,
        0,
        0
      };

      static RTWPreprocessingFcnPtr rt_LoggingPreprocessingFcnPtrs[] = {
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL)
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "",
        "",
        "",
        "",
        "" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "euler321_I2B_12B/DCM321",
        "euler321_I2B_12B/Vb",
        "euler321_I2B_12B/outTheta",
        "euler321_I2B_12B/outGamma",
        "euler321_I2B_12B/outR1" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_BOOLEAN, SS_BOOLEAN, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          5,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedCurrentSignalDimensionsSize,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          (NULL),
          rt_LoggingPreprocessingFcnPtrs,

          { rt_LoggedOutputLabels },
          (NULL),
          (NULL),
          (NULL),

          { rt_LoggedOutputBlockNames },

          { (NULL) },
          (NULL),
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo(euler321_I2B_12B_M->rtwLogInfo,
                            rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[2] = &rt_LoggedOutputWidths[1];
      rt_LoggedCurrentSignalDimensions[3] = &rt_LoggedOutputWidths[2];
      rt_LoggedCurrentSignalDimensions[4] = &rt_LoggedOutputWidths[2];
      rt_LoggedCurrentSignalDimensions[5] = &rt_LoggedOutputWidths[3];
      rt_LoggedCurrentSignalDimensions[6] = &rt_LoggedOutputWidths[3];
      rt_LoggedCurrentSignalDimensions[7] = &rt_LoggedOutputWidths[4];
    }

    rtliSetLogY(euler321_I2B_12B_M->rtwLogInfo, "yout");
  }

  euler321_I2B_12B_M->solverInfoPtr = (&euler321_I2B_12B_M->solverInfo);
  euler321_I2B_12B_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&euler321_I2B_12B_M->solverInfo, 0.01);
  rtsiSetSolverMode(&euler321_I2B_12B_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* external inputs */
  euler321_I2B_12B_M->inputs = (((void*)&euler321_I2B_12B_U));
  (void)memset(&euler321_I2B_12B_U, 0, sizeof(ExtU_euler321_I2B_12B_T));

  /* external outputs */
  euler321_I2B_12B_M->outputs = (&euler321_I2B_12B_Y);
  (void) memset((void *)&euler321_I2B_12B_Y, 0,
                sizeof(ExtY_euler321_I2B_12B_T));

  /* Initialize Sizes */
  euler321_I2B_12B_M->Sizes.numContStates = (0);/* Number of continuous states */
  euler321_I2B_12B_M->Sizes.numY = (19);/* Number of model outputs */
  euler321_I2B_12B_M->Sizes.numU = (7);/* Number of model inputs */
  euler321_I2B_12B_M->Sizes.sysDirFeedThru = (1);/* The model is direct feedthrough */
  euler321_I2B_12B_M->Sizes.numSampTimes = (1);/* Number of sample times */
  euler321_I2B_12B_M->Sizes.numBlocks = (150);/* Number of blocks */
  euler321_I2B_12B_M->Sizes.numBlockIO = (0);/* Number of block outputs */
  return euler321_I2B_12B_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
