/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: EB_12B.c
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

void rt_invd3x3_snf(const real_T u[9], real_T y[9])
{
  real_T x[9];
  real_T absx11;
  real_T absx21;
  real_T absx31;
  int32_T itmp;
  int32_T p1;
  int32_T p2;
  int32_T p3;
  memcpy(&x[0], &u[0], 9U * sizeof(real_T));
  p1 = 1;
  p2 = 3;
  p3 = 6;
  absx11 = fabs(u[0]);
  absx21 = fabs(u[1]);
  absx31 = fabs(u[2]);
  if ((absx21 > absx11) && (absx21 > absx31)) {
    p1 = 4;
    p2 = 0;
    x[0] = u[1];
    x[1] = u[0];
    x[3] = u[4];
    x[4] = u[3];
    x[6] = u[7];
    x[7] = u[6];
  } else if (absx31 > absx11) {
    p1 = 7;
    p3 = 0;
    x[2] = x[0];
    x[0] = u[2];
    x[5] = x[3];
    x[3] = u[5];
    x[8] = x[6];
    x[6] = u[8];
  }

  absx11 = x[1] / x[0];
  x[1] = absx11;
  absx21 = x[2] / x[0];
  x[2] = absx21;
  x[4] -= absx11 * x[3];
  x[5] -= absx21 * x[3];
  x[7] -= absx11 * x[6];
  x[8] -= absx21 * x[6];
  if (fabs(x[5]) > fabs(x[4])) {
    itmp = p2;
    p2 = p3;
    p3 = itmp;
    x[1] = absx21;
    x[2] = absx11;
    absx11 = x[4];
    x[4] = x[5];
    x[5] = absx11;
    absx11 = x[7];
    x[7] = x[8];
    x[8] = absx11;
  }

  absx11 = x[5] / x[4];
  x[8] -= absx11 * x[7];
  absx21 = (x[1] * absx11 - x[2]) / x[8];
  absx31 = -(x[7] * absx21 + x[1]) / x[4];
  y[p1 - 1] = ((1.0 - x[3] * absx31) - x[6] * absx21) / x[0];
  y[p1] = absx31;
  y[p1 + 1] = absx21;
  absx21 = -absx11 / x[8];
  absx31 = (1.0 - x[7] * absx21) / x[4];
  y[p2] = -(x[3] * absx31 + x[6] * absx21) / x[0];
  y[p2 + 1] = absx31;
  y[p2 + 2] = absx21;
  absx21 = 1.0 / x[8];
  absx31 = -x[7] * absx21 / x[4];
  y[p3] = -(x[3] * absx31 + x[6] * absx21) / x[0];
  y[p3 + 1] = absx31;
  y[p3 + 2] = absx21;
}

/* Model step function */
void EB_12B_step(RT_MODEL_EB_12B_T *const EB_12B_M, real_T EB_12B_U_B[15],
                 real_T EB_12B_Y_check[9], real_T EB_12B_Y_yinv[9], real_T
                 EB_12B_Y_P[15], real_T EB_12B_Y_u[5], real_T EB_12B_Y_Buminusd
                 [3], real_T *EB_12B_Y_J, boolean_T *EB_12B_Y_ridge_on)
{
  real_T rtb_MathFunction2[15];
  real_T rtb_Product1_f[15];
  real_T rtb_Product7[15];
  real_T rtb_Product1_a[9];
  real_T rtb_RelationalOperator_0;
  int32_T i;
  int32_T i_0;
  int32_T rtb_MathFunction2_tmp;
  int32_T rtb_Product7_tmp;

  /* Product: '<S1>/Product5' incorporates:
   *  Inport: '<Root>/B'
   *  Math: '<S1>/Math Function1'
   *  Product: '<S1>/Divide'
   *  Product: '<S1>/Product7'
   */
  for (i = 0; i < 5; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      rtb_Product7_tmp = 5 * i_0 + i;
      rtb_Product7[rtb_Product7_tmp] = 0.0;
      for (rtb_MathFunction2_tmp = 0; rtb_MathFunction2_tmp < 5;
           rtb_MathFunction2_tmp++) {
        rtb_Product7[rtb_Product7_tmp] += EB_12B_ConstB.Divide[5 *
          rtb_MathFunction2_tmp + i] * EB_12B_U_B[3 * rtb_MathFunction2_tmp +
          i_0];
      }
    }
  }

  /* End of Product: '<S1>/Product5' */

  /* Product: '<S1>/Product1' incorporates:
   *  Inport: '<Root>/B'
   *  Product: '<S1>/Product7'
   */
  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      rtb_MathFunction2_tmp = 3 * i + i_0;
      rtb_Product1_a[rtb_MathFunction2_tmp] = 0.0;
      for (rtb_Product7_tmp = 0; rtb_Product7_tmp < 5; rtb_Product7_tmp++) {
        rtb_Product1_a[rtb_MathFunction2_tmp] += EB_12B_U_B[3 * rtb_Product7_tmp
          + i_0] * rtb_Product7[5 * i + rtb_Product7_tmp];
      }
    }
  }

  memcpy(&rtb_Product1_f[0], &rtb_Product1_a[0], 9U * sizeof(real_T));

  /* End of Product: '<S1>/Product1' */

  /* RelationalOperator: '<S3>/Relational Operator' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Product: '<S4>/Product'
   *  Product: '<S4>/Product1'
   *  Product: '<S4>/Product2'
   *  Product: '<S4>/Product3'
   *  Product: '<S4>/Product4'
   *  Product: '<S4>/Product5'
   *  Sum: '<S4>/Sum'
   */
  *EB_12B_Y_ridge_on = (((((rtb_Product1_f[0] * rtb_Product1_f[4] *
    rtb_Product1_f[8] - rtb_Product1_f[0] * rtb_Product1_f[5] * rtb_Product1_f[7])
    - rtb_Product1_f[1] * rtb_Product1_f[3] * rtb_Product1_f[8]) +
    rtb_Product1_f[2] * rtb_Product1_f[3] * rtb_Product1_f[7]) + rtb_Product1_f
    [1] * rtb_Product1_f[5] * rtb_Product1_f[6]) - rtb_Product1_f[2] *
                        rtb_Product1_f[4] * rtb_Product1_f[6] <= 1.0E-12);

  /* Sum: '<S3>/Sum4' */
  for (i = 0; i < 9; i++) {
    /* Switch: '<S3>/Switch' incorporates:
     *  Constant: '<S3>/Constant4'
     */
    if (*EB_12B_Y_ridge_on) {
      rtb_RelationalOperator_0 = EB_12B_ConstP.Constant4_Value[i];
    } else {
      rtb_RelationalOperator_0 = 0.0;
    }

    /* End of Switch: '<S3>/Switch' */
    rtb_Product1_a[i] = rtb_Product1_f[i] + rtb_RelationalOperator_0;
  }

  /* Product: '<S1>/Divide1' incorporates:
   *  Sum: '<S3>/Sum4'
   */
  rt_invd3x3_snf(rtb_Product1_a, EB_12B_Y_yinv);

  /* Product: '<S1>/Product2' incorporates:
   *  Math: '<S1>/Math Function2'
   *  Product: '<S1>/Divide1'
   *  Product: '<S1>/Product7'
   */
  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 5; i_0++) {
      rtb_MathFunction2_tmp = 5 * i + i_0;
      rtb_MathFunction2[rtb_MathFunction2_tmp] = 0.0;
      rtb_MathFunction2[rtb_MathFunction2_tmp] += EB_12B_Y_yinv[3 * i] *
        rtb_Product7[i_0];
      rtb_MathFunction2[rtb_MathFunction2_tmp] += EB_12B_Y_yinv[3 * i + 1] *
        rtb_Product7[i_0 + 5];
      rtb_MathFunction2[rtb_MathFunction2_tmp] += EB_12B_Y_yinv[3 * i + 2] *
        rtb_Product7[i_0 + 10];
    }
  }

  /* End of Product: '<S1>/Product2' */

  /* Outport: '<Root>/P' incorporates:
   *  Math: '<S1>/Math Function2'
   */
  memcpy(&EB_12B_Y_P[0], &rtb_MathFunction2[0], 15U * sizeof(real_T));

  /* Product: '<S1>/Product4' */
  memcpy(&rtb_Product1_a[0], &rtb_Product1_f[0], 9U * sizeof(real_T));

  /* Outport: '<Root>/check' incorporates:
   *  Product: '<S1>/Divide1'
   *  Product: '<S1>/Product4'
   */
  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      /* Product: '<S1>/Product4' */
      rtb_MathFunction2_tmp = 3 * i + i_0;
      EB_12B_Y_check[rtb_MathFunction2_tmp] = 0.0;
      EB_12B_Y_check[rtb_MathFunction2_tmp] += EB_12B_Y_yinv[3 * i] *
        rtb_Product1_a[i_0];
      EB_12B_Y_check[rtb_MathFunction2_tmp] += EB_12B_Y_yinv[3 * i + 1] *
        rtb_Product1_a[i_0 + 3];
      EB_12B_Y_check[rtb_MathFunction2_tmp] += EB_12B_Y_yinv[3 * i + 2] *
        rtb_Product1_a[i_0 + 6];
    }
  }

  /* End of Outport: '<Root>/check' */
  for (i = 0; i < 5; i++) {
    /* Product: '<S1>/Product3' incorporates:
     *  Constant: '<Root>/Const2'
     *  Math: '<S1>/Math Function2'
     */
    EB_12B_Y_u[i] = 0.0;
    EB_12B_Y_u[i] += rtb_MathFunction2[i] * 3.0;
    EB_12B_Y_u[i] += -rtb_MathFunction2[i + 5];
    EB_12B_Y_u[i] += rtb_MathFunction2[i + 10] * 2.0;

    /* Sum: '<S1>/Sum1' incorporates:
     *  Product: '<S1>/Product3'
     */
    rtb_MathFunction2[i] = EB_12B_Y_u[i];
  }

  /* Product: '<S1>/Product7' incorporates:
   *  Constant: '<Root>/Const'
   */
  for (i = 0; i < 5; i++) {
    rtb_Product7[i] = 0.0;
    for (i_0 = 0; i_0 < 5; i_0++) {
      rtb_Product7[i] += EB_12B_ConstP.Const_Value[5 * i_0 + i] *
        rtb_MathFunction2[i_0];
    }
  }

  /* End of Product: '<S1>/Product7' */

  /* Outport: '<Root>/Buminusd' incorporates:
   *  Constant: '<Root>/Const2'
   *  Inport: '<Root>/B'
   *  Product: '<S1>/Product3'
   *  Product: '<S1>/Product6'
   *  Sum: '<S1>/Sum'
   */
  for (i = 0; i < 3; i++) {
    rtb_RelationalOperator_0 = 0.0;
    for (i_0 = 0; i_0 < 5; i_0++) {
      rtb_RelationalOperator_0 += EB_12B_U_B[3 * i_0 + i] * EB_12B_Y_u[i_0];
    }

    EB_12B_Y_Buminusd[i] = rtb_RelationalOperator_0 -
      EB_12B_ConstP.Const2_Value[i];
  }

  /* End of Outport: '<Root>/Buminusd' */

  /* Product: '<S1>/Product8' */
  *EB_12B_Y_J = 0.0;
  for (i = 0; i < 5; i++) {
    *EB_12B_Y_J += rtb_MathFunction2[i] * rtb_Product7[i];
  }

  /* End of Product: '<S1>/Product8' */
  UNUSED_PARAMETER(EB_12B_M);
}

/* Model initialize function */
void EB_12B_initialize(RT_MODEL_EB_12B_T *const EB_12B_M, real_T EB_12B_U_B[15],
  real_T EB_12B_Y_id[9], real_T EB_12B_Y_check[9], real_T EB_12B_Y_yinv[9],
  real_T EB_12B_Y_P[15], real_T EB_12B_Y_u[5], real_T EB_12B_Y_Buminusd[3],
  real_T *EB_12B_Y_J, boolean_T *EB_12B_Y_ridge_on)
{
  DW_EB_12B_T *EB_12B_DW = EB_12B_M->dwork;

  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(EB_12B_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)EB_12B_DW, 0,
                sizeof(DW_EB_12B_T));

  /* external inputs */
  (void)memset(&EB_12B_U_B[0], 0, 15U * sizeof(real_T));

  /* external outputs */
  (void)memset(&EB_12B_Y_id[0], 0, 9U * sizeof(real_T));
  (void)memset(&EB_12B_Y_check[0], 0, 9U * sizeof(real_T));
  (void)memset(&EB_12B_Y_yinv[0], 0, 9U * sizeof(real_T));
  (void)memset(&EB_12B_Y_P[0], 0, 15U * sizeof(real_T));
  (void)memset(&EB_12B_Y_u[0], 0, 5U * sizeof(real_T));
  (void)memset(&EB_12B_Y_Buminusd[0], 0, 3U * sizeof(real_T));
  *EB_12B_Y_J = 0.0;
  *EB_12B_Y_ridge_on = false;

  /* ConstCode for Outport: '<Root>/id' incorporates:
   *  Constant: '<S1>/ID'
   */
  memcpy(&EB_12B_Y_id[0], &EB_12B_ConstP.ID_Value[0], 9U * sizeof(real_T));
}

/* Model terminate function */
void EB_12B_terminate(RT_MODEL_EB_12B_T *const EB_12B_M)
{
  /* (no terminate code required) */
  UNUSED_PARAMETER(EB_12B_M);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
