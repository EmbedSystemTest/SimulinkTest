/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: NLGuidance.c
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

#include "NLGuidance.h"
#include "NLGuidance_private.h"

/* Model step function */
void NLGuidance_step(RT_MODEL_NLGuidance_T *const NLGuidance_M, real_T
                     NLGuidance_U_Xtarg[3], real_T NLGuidance_U_Xv[3], real_T
                     NLGuidance_U_Vv[3], real_T NLGuidance_U_r, real_T
                     NLGuidance_Y_yout[3])
{
  real_T rtb_Divide4;
  real_T rtb_MathFunction1_m;
  real_T rtb_MathFunction_idx_0;
  real_T rtb_MathFunction_idx_1;
  real_T rtb_Product2;
  real_T rtb_Sum;
  real_T rtb_Sum4;
  real_T rtb_Xr_idx_0;
  real_T rtb_Xr_idx_1;

  /* Sum: '<S1>/Sum' incorporates:
   *  Inport: '<Root>/Xtarg'
   *  Inport: '<Root>/Xv'
   */
  rtb_Sum = NLGuidance_U_Xtarg[0] - NLGuidance_U_Xv[0];

  /* Math: '<S4>/Math Function' */
  rtb_MathFunction_idx_0 = rtb_Sum * rtb_Sum;

  /* Sum: '<S1>/Sum' incorporates:
   *  Inport: '<Root>/Xtarg'
   *  Inport: '<Root>/Xv'
   */
  rtb_Xr_idx_0 = rtb_Sum;
  rtb_Sum = NLGuidance_U_Xtarg[1] - NLGuidance_U_Xv[1];

  /* Math: '<S4>/Math Function' */
  rtb_MathFunction_idx_1 = rtb_Sum * rtb_Sum;

  /* Sum: '<S1>/Sum' incorporates:
   *  Inport: '<Root>/Xtarg'
   *  Inport: '<Root>/Xv'
   */
  rtb_Xr_idx_1 = rtb_Sum;
  rtb_Sum = NLGuidance_U_Xtarg[2] - NLGuidance_U_Xv[2];

  /* Sum: '<S4>/Sum of Elements' incorporates:
   *  Math: '<S4>/Math Function'
   */
  rtb_MathFunction1_m = (rtb_MathFunction_idx_0 + rtb_MathFunction_idx_1) +
    rtb_Sum * rtb_Sum;

  /* DotProduct: '<S1>/Dot Product' incorporates:
   *  Inport: '<Root>/Vv'
   */
  rtb_Sum4 = (rtb_Xr_idx_0 * NLGuidance_U_Vv[0] + rtb_Xr_idx_1 *
              NLGuidance_U_Vv[1]) + rtb_Sum * NLGuidance_U_Vv[2];

  /* Math: '<S4>/Math Function1' incorporates:
   *  Sum: '<S4>/Sum of Elements'
   *
   * About '<S4>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_MathFunction1_m < 0.0) {
    rtb_MathFunction_idx_0 = -sqrt(fabs(rtb_MathFunction1_m));
  } else {
    rtb_MathFunction_idx_0 = sqrt(rtb_MathFunction1_m);
  }

  /* End of Math: '<S4>/Math Function1' */

  /* Outputs for IfAction SubSystem: '<S1>/Outer' incorporates:
   *  ActionPort: '<S3>/Action Port'
   */
  /* If: '<S1>/If' incorporates:
   *  Math: '<S15>/Math Function2'
   *  Math: '<S1>/Math Function1'
   *  Math: '<S1>/Math Function3'
   */
  rtb_Divide4 = rtb_MathFunction_idx_0 * rtb_MathFunction_idx_0;

  /* End of Outputs for SubSystem: '<S1>/Outer' */

  /* Sum: '<S1>/Sum2' incorporates:
   *  Inport: '<Root>/r'
   *  Math: '<S1>/Math Function3'
   *  Math: '<S1>/Math Function4'
   */
  rtb_MathFunction_idx_1 = rtb_Divide4 - NLGuidance_U_r * NLGuidance_U_r;

  /* Sum: '<S5>/Sum of Elements' incorporates:
   *  Inport: '<Root>/Vv'
   *  Math: '<S5>/Math Function'
   */
  rtb_MathFunction1_m = (NLGuidance_U_Vv[0] * NLGuidance_U_Vv[0] +
    NLGuidance_U_Vv[1] * NLGuidance_U_Vv[1]) + NLGuidance_U_Vv[2] *
    NLGuidance_U_Vv[2];

  /* Math: '<S5>/Math Function1' incorporates:
   *  Sum: '<S5>/Sum of Elements'
   *
   * About '<S5>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_MathFunction1_m < 0.0) {
    rtb_MathFunction1_m = -sqrt(fabs(rtb_MathFunction1_m));
  } else {
    rtb_MathFunction1_m = sqrt(rtb_MathFunction1_m);
  }

  /* End of Math: '<S5>/Math Function1' */

  /* Sum: '<S1>/Sum1' incorporates:
   *  DotProduct: '<S1>/Dot Product'
   *  Math: '<S1>/Math Function'
   *  Math: '<S1>/Math Function2'
   *  Product: '<S1>/Product'
   */
  rtb_MathFunction1_m = rtb_MathFunction1_m * rtb_MathFunction1_m * rtb_Divide4
    - rtb_Sum4 * rtb_Sum4;

  /* If: '<S1>/If' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant2'
   *  Logic: '<S1>/Logical Operator'
   *  RelationalOperator: '<S1>/Relational Operator'
   *  RelationalOperator: '<S1>/Relational Operator1'
   */
  if ((rtb_MathFunction_idx_1 <= 0.0) || (rtb_MathFunction1_m <= 0.0)) {
    /* Outputs for IfAction SubSystem: '<S1>/Inner' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* Product: '<S2>/Divide' incorporates:
     *  Inport: '<Root>/r'
     */
    rtb_Product2 = NLGuidance_U_r / rtb_MathFunction_idx_0;

    /* Sum: '<S8>/Sum' incorporates:
     *  Inport: '<Root>/Xtarg'
     *  Product: '<S8>/Product'
     */
    rtb_Sum = rtb_Product2 * rtb_Xr_idx_0 + NLGuidance_U_Xtarg[0];

    /* Sum: '<S8>/Sum1' incorporates:
     *  Inport: '<Root>/Xtarg'
     *  Product: '<S8>/Product1'
     */
    rtb_Sum4 = rtb_Xr_idx_1 * rtb_Product2 + NLGuidance_U_Xtarg[1];

    /* Sum: '<S8>/Sum2' incorporates:
     *  Inport: '<Root>/Xv'
     */
    rtb_MathFunction_idx_0 = rtb_Sum - NLGuidance_U_Xv[0];
    rtb_MathFunction_idx_1 = rtb_Sum4 - NLGuidance_U_Xv[1];

    /* Math: '<S10>/Math Function' incorporates:
     *  Constant: '<S8>/Constant1'
     *  Inport: '<Root>/Xv'
     *  Math: '<S11>/Math Function'
     *  Sum: '<S8>/Sum2'
     */
    rtb_MathFunction1_m = (0.0 - NLGuidance_U_Xv[2]) * (0.0 - NLGuidance_U_Xv[2]);

    /* Sum: '<S10>/Sum of Elements' incorporates:
     *  Math: '<S10>/Math Function'
     */
    rtb_Divide4 = (rtb_MathFunction_idx_0 * rtb_MathFunction_idx_0 +
                   rtb_MathFunction_idx_1 * rtb_MathFunction_idx_1) +
      rtb_MathFunction1_m;

    /* Sum: '<S9>/Sum' incorporates:
     *  Gain: '<S2>/Gain'
     *  Inport: '<Root>/Xtarg'
     *  Product: '<S9>/Product'
     */
    rtb_Xr_idx_0 = -rtb_Product2 * rtb_Xr_idx_0 + NLGuidance_U_Xtarg[0];

    /* Sum: '<S9>/Sum1' incorporates:
     *  Gain: '<S2>/Gain'
     *  Inport: '<Root>/Xtarg'
     *  Product: '<S9>/Product1'
     */
    rtb_Xr_idx_1 = rtb_Xr_idx_1 * -rtb_Product2 + NLGuidance_U_Xtarg[1];

    /* Sum: '<S9>/Sum2' incorporates:
     *  Inport: '<Root>/Xv'
     */
    rtb_MathFunction_idx_0 = rtb_Xr_idx_0 - NLGuidance_U_Xv[0];
    rtb_MathFunction_idx_1 = rtb_Xr_idx_1 - NLGuidance_U_Xv[1];

    /* Sum: '<S11>/Sum of Elements' incorporates:
     *  Math: '<S11>/Math Function'
     */
    rtb_MathFunction1_m += rtb_MathFunction_idx_0 * rtb_MathFunction_idx_0 +
      rtb_MathFunction_idx_1 * rtb_MathFunction_idx_1;

    /* Math: '<S10>/Math Function1' incorporates:
     *  Sum: '<S10>/Sum of Elements'
     *
     * About '<S10>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_Divide4 < 0.0) {
      rtb_Divide4 = -sqrt(fabs(rtb_Divide4));
    } else {
      rtb_Divide4 = sqrt(rtb_Divide4);
    }

    /* End of Math: '<S10>/Math Function1' */

    /* Math: '<S11>/Math Function1' incorporates:
     *  Sum: '<S11>/Sum of Elements'
     *
     * About '<S11>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_MathFunction1_m < 0.0) {
      rtb_MathFunction1_m = -sqrt(fabs(rtb_MathFunction1_m));
    } else {
      rtb_MathFunction1_m = sqrt(rtb_MathFunction1_m);
    }

    /* End of Math: '<S11>/Math Function1' */

    /* If: '<S2>/If' incorporates:
     *  Constant: '<S8>/Constant1'
     *  Inport: '<S6>/cmd1'
     *  Inport: '<S7>/cmd2'
     *  Outport: '<Root>/yout'
     *  RelationalOperator: '<S2>/Relational Operator1'
     *  Sum: '<S14>/Sum'
     */
    if (rtb_Divide4 < rtb_MathFunction1_m) {
      /* Outputs for IfAction SubSystem: '<S2>/Act1' incorporates:
       *  ActionPort: '<S6>/Action Port'
       */
      NLGuidance_Y_yout[0] = rtb_Sum;
      NLGuidance_Y_yout[1] = rtb_Sum4;

      /* End of Outputs for SubSystem: '<S2>/Act1' */
    } else {
      /* Outputs for IfAction SubSystem: '<S2>/Act2' incorporates:
       *  ActionPort: '<S7>/Action Port'
       */
      NLGuidance_Y_yout[0] = rtb_Xr_idx_0;
      NLGuidance_Y_yout[1] = rtb_Xr_idx_1;

      /* End of Outputs for SubSystem: '<S2>/Act2' */
    }

    /* Outputs for IfAction SubSystem: '<S2>/Act2' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    /* Outputs for IfAction SubSystem: '<S2>/Act1' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    NLGuidance_Y_yout[2] = 0.0;

    /* End of If: '<S2>/If' */
    /* End of Outputs for SubSystem: '<S2>/Act1' */
    /* End of Outputs for SubSystem: '<S2>/Act2' */
    /* End of Outputs for SubSystem: '<S1>/Inner' */
  } else {
    /* Outputs for IfAction SubSystem: '<S1>/Outer' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    /* Sqrt: '<S3>/Sqrt' incorporates:
     *  Product: '<S3>/Divide1'
     */
    rtb_Product2 = sqrt(rtb_MathFunction_idx_1 / rtb_MathFunction1_m);

    /* Product: '<S15>/Product7' incorporates:
     *  Inport: '<Root>/Vv'
     */
    rtb_MathFunction_idx_0 = rtb_Product2 * NLGuidance_U_Vv[0];
    rtb_MathFunction_idx_1 = rtb_Product2 * NLGuidance_U_Vv[1];
    rtb_MathFunction1_m = rtb_Product2 * NLGuidance_U_Vv[2];

    /* Product: '<S15>/Divide4' */
    rtb_Divide4 = 1.0 / rtb_Divide4;

    /* Product: '<S15>/Product2' incorporates:
     *  DotProduct: '<S1>/Dot Product'
     */
    rtb_Product2 *= rtb_Sum4;

    /* Sum: '<S15>/Sum4' incorporates:
     *  Inport: '<Root>/r'
     */
    rtb_Sum4 = NLGuidance_U_r + rtb_Product2;

    /* Sum: '<S15>/Sum7' incorporates:
     *  Gain: '<S15>/Gain2'
     *  Inport: '<Root>/r'
     *  Product: '<S15>/Product3'
     *  Product: '<S15>/Product5'
     *  Product: '<S15>/Product8'
     *  Sum: '<S14>/Sum'
     *  Sum: '<S15>/Sum'
     */
    NLGuidance_Y_yout[0] = (rtb_Sum4 * rtb_Xr_idx_0 * -rtb_Divide4 +
      rtb_MathFunction_idx_0) * NLGuidance_U_r + rtb_Xr_idx_0;
    NLGuidance_Y_yout[1] = (rtb_Sum4 * rtb_Xr_idx_1 * -rtb_Divide4 +
      rtb_MathFunction_idx_1) * NLGuidance_U_r + rtb_Xr_idx_1;
    NLGuidance_Y_yout[2] = (rtb_Sum4 * rtb_Sum * -rtb_Divide4 +
      rtb_MathFunction1_m) * NLGuidance_U_r + rtb_Sum;

    /* Sum: '<S14>/Sum' incorporates:
     *  Product: '<S16>/i x j'
     *  Product: '<S17>/i x j'
     */
    rtb_Sum4 = rtb_Xr_idx_0 * NLGuidance_Y_yout[1];

    /* Sum: '<S15>/Sum5' incorporates:
     *  Inport: '<Root>/r'
     */
    rtb_Product2 -= NLGuidance_U_r;

    /* If: '<S3>/If' incorporates:
     *  Constant: '<S3>/Constant1'
     *  Product: '<S17>/i x j'
     *  RelationalOperator: '<S3>/Relational Operator'
     *  Sum: '<S14>/Sum'
     */
    if (rtb_Sum4 - rtb_Sum4 < 0.0) {
      /* Outputs for IfAction SubSystem: '<S3>/CW' incorporates:
       *  ActionPort: '<S13>/Action Port'
       */
      /* Outport: '<Root>/yout' incorporates:
       *  Inport: '<Root>/Xv'
       *  Inport: '<S13>/Xap1'
       *  Sum: '<S14>/Sum'
       *  Sum: '<S3>/Sum8'
       */
      NLGuidance_Y_yout[0] += NLGuidance_U_Xv[0];
      NLGuidance_Y_yout[1] += NLGuidance_U_Xv[1];
      NLGuidance_Y_yout[2] += NLGuidance_U_Xv[2];

      /* End of Outputs for SubSystem: '<S3>/CW' */
    } else {
      /* Outputs for IfAction SubSystem: '<S3>/CCW' incorporates:
       *  ActionPort: '<S12>/Action Port'
       */
      /* Outport: '<Root>/yout' incorporates:
       *  Inport: '<Root>/Xv'
       *  Inport: '<Root>/r'
       *  Inport: '<S12>/Xap1'
       *  Product: '<S15>/Product4'
       *  Product: '<S15>/Product6'
       *  Product: '<S15>/Product9'
       *  Sum: '<S14>/Sum'
       *  Sum: '<S15>/Sum1'
       *  Sum: '<S15>/Sum6'
       *  Sum: '<S3>/Sum4'
       *  Sum: '<S3>/Sum8'
       */
      NLGuidance_Y_yout[0] = ((rtb_Product2 * rtb_Xr_idx_0 * rtb_Divide4 -
        rtb_MathFunction_idx_0) * NLGuidance_U_r + rtb_Xr_idx_0) +
        NLGuidance_U_Xv[0];
      NLGuidance_Y_yout[1] = ((rtb_Product2 * rtb_Xr_idx_1 * rtb_Divide4 -
        rtb_MathFunction_idx_1) * NLGuidance_U_r + rtb_Xr_idx_1) +
        NLGuidance_U_Xv[1];
      NLGuidance_Y_yout[2] = ((rtb_Product2 * rtb_Sum * rtb_Divide4 -
        rtb_MathFunction1_m) * NLGuidance_U_r + rtb_Sum) + NLGuidance_U_Xv[2];

      /* End of Outputs for SubSystem: '<S3>/CCW' */
    }

    /* End of If: '<S3>/If' */
    /* End of Outputs for SubSystem: '<S1>/Outer' */
  }

  UNUSED_PARAMETER(NLGuidance_M);
}

/* Model initialize function */
void NLGuidance_initialize(RT_MODEL_NLGuidance_T *const NLGuidance_M, real_T
  NLGuidance_U_Xtarg[3], real_T NLGuidance_U_Xv[3], real_T NLGuidance_U_Vv[3],
  real_T NLGuidance_U_Vt[3], real_T *NLGuidance_U_r, real_T NLGuidance_Y_yout[3])
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(NLGuidance_M, (NULL));

  /* external inputs */
  (void)memset(&NLGuidance_U_Xtarg[0], 0, 3U * sizeof(real_T));
  (void)memset(&NLGuidance_U_Xv[0], 0, 3U * sizeof(real_T));
  (void)memset(&NLGuidance_U_Vv[0], 0, 3U * sizeof(real_T));
  (void)memset(&NLGuidance_U_Vt[0], 0, 3U * sizeof(real_T));
  *NLGuidance_U_r = 0.0;

  /* external outputs */
  (void)memset(&NLGuidance_Y_yout[0], 0, 3U * sizeof(real_T));
  UNUSED_PARAMETER(NLGuidance_M);
}

/* Model terminate function */
void NLGuidance_terminate(RT_MODEL_NLGuidance_T *const NLGuidance_M)
{
  /* (no terminate code required) */
  UNUSED_PARAMETER(NLGuidance_M);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
