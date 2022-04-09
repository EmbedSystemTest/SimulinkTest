/*
 * EB_12B.c
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

/* Block states (default storage) */
DW_EB_12B_T EB_12B_DW;

/* External inputs (root inport signals with default storage) */
ExtU_EB_12B_T EB_12B_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_EB_12B_T EB_12B_Y;

/* Real-time model */
RT_MODEL_EB_12B_T EB_12B_M_;
RT_MODEL_EB_12B_T *const EB_12B_M = &EB_12B_M_;
void rt_invd5x5_snf(const real_T u[25], real_T y[25])
{
  int8_T p[5];
  real_T A[25];
  int8_T ipiv[5];
  int32_T pipk;
  int32_T jj;
  int32_T jBcol;
  int32_T kAcol;
  int32_T ix;
  real_T smax;
  real_T s;
  int32_T iy;
  int32_T jA;
  int32_T ijA;
  int32_T ipiv_tmp;
  for (ipiv_tmp = 0; ipiv_tmp < 25; ipiv_tmp++) {
    y[ipiv_tmp] = 0.0;
    A[ipiv_tmp] = u[ipiv_tmp];
  }

  for (ipiv_tmp = 0; ipiv_tmp < 5; ipiv_tmp++) {
    ipiv[ipiv_tmp] = (int8_T)(ipiv_tmp + 1);
  }

  for (pipk = 0; pipk < 4; pipk++) {
    jBcol = pipk * 6 + 2;
    jj = pipk * 6;
    kAcol = 5 - pipk;
    iy = 1;
    ix = jBcol - 2;
    smax = fabs(A[jj]);
    for (jA = 2; jA <= kAcol; jA++) {
      ix++;
      s = fabs(A[ix]);
      if (s > smax) {
        iy = jA;
        smax = s;
      }
    }

    if (A[(jBcol + iy) - 3] != 0.0) {
      if (iy - 1 != 0) {
        ipiv_tmp = pipk + iy;
        ipiv[pipk] = (int8_T)ipiv_tmp;
        ix = pipk;
        iy = ipiv_tmp - 1;
        for (jA = 0; jA < 5; jA++) {
          smax = A[ix];
          A[ix] = A[iy];
          A[iy] = smax;
          ix += 5;
          iy += 5;
        }
      }

      iy = jBcol - pipk;
      for (ix = jBcol; ix <= iy + 3; ix++) {
        A[ix - 1] /= A[jj];
      }
    }

    kAcol = 3 - pipk;
    jA = jj;
    jj += 5;
    for (iy = 0; iy <= kAcol; iy++) {
      if (A[jj] != 0.0) {
        smax = -A[jj];
        ix = jBcol - 1;
        ipiv_tmp = jA - pipk;
        for (ijA = jA + 7; ijA <= ipiv_tmp + 10; ijA++) {
          A[ijA - 1] += A[ix] * smax;
          ix++;
        }
      }

      jj += 5;
      jA += 5;
    }
  }

  for (ipiv_tmp = 0; ipiv_tmp < 5; ipiv_tmp++) {
    p[ipiv_tmp] = (int8_T)(ipiv_tmp + 1);
  }

  if (ipiv[0] > 1) {
    ix = ipiv[0] - 1;
    pipk = p[ix];
    p[ix] = p[0];
    p[0] = (int8_T)pipk;
  }

  if (ipiv[1] > 2) {
    ix = ipiv[1] - 1;
    pipk = p[ix];
    p[ix] = p[1];
    p[1] = (int8_T)pipk;
  }

  if (ipiv[2] > 3) {
    ix = ipiv[2] - 1;
    pipk = p[ix];
    p[ix] = p[2];
    p[2] = (int8_T)pipk;
  }

  if (ipiv[3] > 4) {
    ix = ipiv[3] - 1;
    pipk = p[ix];
    p[ix] = p[3];
    p[3] = (int8_T)pipk;
  }

  for (jA = 0; jA < 5; jA++) {
    jBcol = p[jA] - 1;
    y[jA + 5 * jBcol] = 1.0;
    for (pipk = jA + 1; pipk < 6; pipk++) {
      ipiv_tmp = (5 * jBcol + pipk) - 1;
      if (y[ipiv_tmp] != 0.0) {
        for (ix = pipk + 1; ix < 6; ix++) {
          jj = (5 * jBcol + ix) - 1;
          y[jj] -= A[((pipk - 1) * 5 + ix) - 1] * y[ipiv_tmp];
        }
      }
    }
  }

  for (pipk = 0; pipk < 5; pipk++) {
    jBcol = 5 * pipk;
    for (jA = 4; jA >= 0; jA--) {
      kAcol = 5 * jA;
      ipiv_tmp = jA + jBcol;
      if (y[ipiv_tmp] != 0.0) {
        y[ipiv_tmp] /= A[jA + kAcol];
        iy = jA - 1;
        for (ix = 0; ix <= iy; ix++) {
          jj = ix + jBcol;
          y[jj] -= y[ipiv_tmp] * A[ix + kAcol];
        }
      }
    }
  }
}

void rt_invd3x3_snf(const real_T u[9], real_T y[9])
{
  real_T x[9];
  int32_T p1;
  int32_T p2;
  int32_T p3;
  real_T absx11;
  real_T absx21;
  real_T absx31;
  int32_T itmp;
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
  } else {
    if (absx31 > absx11) {
      p1 = 7;
      p3 = 0;
      x[2] = x[0];
      x[0] = u[2];
      x[5] = x[3];
      x[3] = u[5];
      x[8] = x[6];
      x[6] = u[8];
    }
  }

  absx31 = x[1] / x[0];
  x[1] = absx31;
  absx11 = x[2] / x[0];
  x[2] = absx11;
  x[4] -= absx31 * x[3];
  x[5] -= absx11 * x[3];
  x[7] -= absx31 * x[6];
  x[8] -= absx11 * x[6];
  if (fabs(x[5]) > fabs(x[4])) {
    itmp = p2;
    p2 = p3;
    p3 = itmp;
    x[1] = absx11;
    x[2] = absx31;
    absx11 = x[4];
    x[4] = x[5];
    x[5] = absx11;
    absx11 = x[7];
    x[7] = x[8];
    x[8] = absx11;
  }

  absx31 = x[5] / x[4];
  x[8] -= absx31 * x[7];
  absx11 = (absx31 * x[1] - x[2]) / x[8];
  absx21 = -(x[7] * absx11 + x[1]) / x[4];
  y[p1 - 1] = ((1.0 - x[3] * absx21) - x[6] * absx11) / x[0];
  y[p1] = absx21;
  y[p1 + 1] = absx11;
  absx11 = -absx31 / x[8];
  absx21 = (1.0 - x[7] * absx11) / x[4];
  y[p2] = -(x[3] * absx21 + x[6] * absx11) / x[0];
  y[p2 + 1] = absx21;
  y[p2 + 2] = absx11;
  absx11 = 1.0 / x[8];
  absx21 = -x[7] * absx11 / x[4];
  y[p3] = -(x[3] * absx21 + x[6] * absx11) / x[0];
  y[p3 + 1] = absx21;
  y[p3 + 2] = absx11;
}

/* Model step function */
void EB_12B_step(void)
{
  real_T rtb_Sum1[5];
  boolean_T rtb_RelationalOperator;
  real_T rtb_Product2_g[15];
  real_T rtb_Product5[15];
  real_T rtb_Product1[9];
  real_T rtb_Divide1[9];
  int32_T i;
  real_T tmp[25];
  real_T tmp_0[25];
  real_T tmp_1[5];
  int32_T i_0;
  real_T rtb_Sum1_k;
  int32_T rtb_Product5_tmp;
  int32_T check_tmp;
  real_T rtb_Divide1_0[9];

  /* Outport: '<Root>/id' incorporates:
   *  Constant: '<S1>/ID'
   */
  memcpy(&EB_12B_Y.id[0], &EB_12B_P.ID_Value[0], 9U * sizeof(real_T));

  /* Math: '<S1>/Math Function' incorporates:
   *  Constant: '<Root>/Const'
   */
  for (i = 0; i < 5; i++) {
    for (i_0 = 0; i_0 < 5; i_0++) {
      tmp[i_0 + 5 * i] = EB_12B_P.Const_Value[5 * i_0 + i];
    }
  }

  /* Product: '<S1>/Divide' incorporates:
   *  Math: '<S1>/Math Function'
   */
  rt_invd5x5_snf(tmp, tmp_0);

  /* Product: '<S1>/Product5' incorporates:
   *  Inport: '<Root>/B'
   *  Math: '<S1>/Math Function1'
   */
  for (i = 0; i < 5; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      rtb_Product5_tmp = i + 5 * i_0;
      rtb_Product5[rtb_Product5_tmp] = 0.0;
      for (check_tmp = 0; check_tmp < 5; check_tmp++) {
        rtb_Product5[rtb_Product5_tmp] += tmp_0[5 * check_tmp + i] * EB_12B_U.B
          [3 * check_tmp + i_0];
      }
    }
  }

  /* End of Product: '<S1>/Product5' */

  /* Product: '<S1>/Product1' incorporates:
   *  Inport: '<Root>/B'
   */
  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      rtb_Product5_tmp = i_0 + 3 * i;
      rtb_Product1[rtb_Product5_tmp] = 0.0;
      for (check_tmp = 0; check_tmp < 5; check_tmp++) {
        rtb_Product1[rtb_Product5_tmp] += EB_12B_U.B[3 * check_tmp + i_0] *
          rtb_Product5[5 * i + check_tmp];
      }
    }
  }

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
  rtb_RelationalOperator = (((((rtb_Product1[0] * rtb_Product1[4] *
    rtb_Product1[8] - rtb_Product1[0] * rtb_Product1[5] * rtb_Product1[7]) -
    rtb_Product1[1] * rtb_Product1[3] * rtb_Product1[8]) + rtb_Product1[2] *
    rtb_Product1[3] * rtb_Product1[7]) + rtb_Product1[1] * rtb_Product1[5] *
    rtb_Product1[6]) - rtb_Product1[2] * rtb_Product1[4] * rtb_Product1[6] <=
    EB_12B_P.Constant1_Value);
  for (i = 0; i < 9; i++) {
    /* Switch: '<S3>/Switch1' incorporates:
     *  Constant: '<S3>/Constant4'
     *  Constant: '<S3>/fix_on'
     *  Sum: '<S3>/Sum4'
     */
    if (EB_12B_P.fix_on_Value >= EB_12B_P.Switch1_Threshold) {
      /* Switch: '<S3>/Switch' incorporates:
       *  Constant: '<S3>/Constant3'
       *  Constant: '<S3>/Constant4'
       */
      if (rtb_RelationalOperator) {
        rtb_Sum1_k = EB_12B_P.I[i] * 1.0E-12;
      } else {
        rtb_Sum1_k = EB_12B_P.I0[i];
      }

      /* End of Switch: '<S3>/Switch' */
    } else {
      rtb_Sum1_k = EB_12B_P.I[i] * 1.0E-12;
    }

    rtb_Divide1[i] = rtb_Product1[i] + rtb_Sum1_k;

    /* End of Switch: '<S3>/Switch1' */
  }

  /* Product: '<S1>/Divide1' */
  memcpy(&rtb_Divide1_0[0], &rtb_Divide1[0], 9U * sizeof(real_T));
  rt_invd3x3_snf(rtb_Divide1_0, rtb_Divide1);

  /* Outport: '<Root>/check' incorporates:
   *  Product: '<S1>/Product4'
   */
  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      /* Product: '<S1>/Product4' */
      check_tmp = i_0 + 3 * i;
      EB_12B_Y.check[check_tmp] = 0.0;
      EB_12B_Y.check[check_tmp] += rtb_Divide1[3 * i] * rtb_Product1[i_0];
      EB_12B_Y.check[check_tmp] += rtb_Divide1[3 * i + 1] * rtb_Product1[i_0 + 3];
      EB_12B_Y.check[check_tmp] += rtb_Divide1[3 * i + 2] * rtb_Product1[i_0 + 6];
    }
  }

  /* End of Outport: '<Root>/check' */

  /* Outport: '<Root>/yinv' */
  memcpy(&EB_12B_Y.yinv[0], &rtb_Divide1[0], 9U * sizeof(real_T));

  /* Product: '<S1>/Product2' */
  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 5; i_0++) {
      check_tmp = i_0 + 5 * i;
      rtb_Product2_g[check_tmp] = 0.0;
      rtb_Product2_g[check_tmp] += rtb_Divide1[3 * i] * rtb_Product5[i_0];
      rtb_Product2_g[check_tmp] += rtb_Divide1[3 * i + 1] * rtb_Product5[i_0 + 5];
      rtb_Product2_g[check_tmp] += rtb_Divide1[3 * i + 2] * rtb_Product5[i_0 +
        10];
    }
  }

  /* End of Product: '<S1>/Product2' */

  /* Outport: '<Root>/P' */
  memcpy(&EB_12B_Y.P[0], &rtb_Product2_g[0], 15U * sizeof(real_T));
  for (i = 0; i < 5; i++) {
    /* Product: '<S1>/Product3' incorporates:
     *  Constant: '<Root>/Const2'
     */
    rtb_Sum1_k = rtb_Product2_g[i + 10] * EB_12B_P.Const2_Value[2] +
      (rtb_Product2_g[i + 5] * EB_12B_P.Const2_Value[1] + rtb_Product2_g[i] *
       EB_12B_P.Const2_Value[0]);

    /* Outport: '<Root>/u' */
    EB_12B_Y.u[i] = rtb_Sum1_k;

    /* Product: '<S1>/Product3' */
    rtb_Sum1[i] = rtb_Sum1_k;
  }

  /* Outport: '<Root>/Buminusd' incorporates:
   *  Constant: '<Root>/Const2'
   *  Inport: '<Root>/B'
   *  Product: '<S1>/Product6'
   *  Sum: '<S1>/Sum'
   */
  for (i = 0; i < 3; i++) {
    rtb_Sum1_k = 0.0;
    for (i_0 = 0; i_0 < 5; i_0++) {
      rtb_Sum1_k += EB_12B_U.B[3 * i_0 + i] * rtb_Sum1[i_0];
    }

    EB_12B_Y.Buminusd[i] = rtb_Sum1_k - EB_12B_P.Const2_Value[i];
  }

  /* End of Outport: '<Root>/Buminusd' */

  /* Sum: '<S1>/Sum1' incorporates:
   *  Constant: '<Root>/Const3'
   */
  for (i = 0; i < 5; i++) {
    rtb_Sum1[i] -= EB_12B_P.Const3_Value[i];
  }

  /* End of Sum: '<S1>/Sum1' */

  /* Product: '<S1>/Product8' */
  rtb_Sum1_k = 0.0;
  for (i = 0; i < 5; i++) {
    /* Product: '<S1>/Product7' incorporates:
     *  Constant: '<Root>/Const'
     */
    tmp_1[i] = 0.0;
    for (i_0 = 0; i_0 < 5; i_0++) {
      tmp_1[i] += EB_12B_P.Const_Value[5 * i_0 + i] * rtb_Sum1[i_0];
    }

    /* End of Product: '<S1>/Product7' */

    /* Product: '<S1>/Product8' incorporates:
     *  Math: '<S1>/Math Function2'
     */
    rtb_Sum1_k += rtb_Sum1[i] * tmp_1[i];
  }

  /* Outport: '<Root>/J' incorporates:
   *  Product: '<S1>/Product8'
   */
  EB_12B_Y.J = rtb_Sum1_k;

  /* Outport: '<Root>/ridge_on' */
  EB_12B_Y.ridge_on = rtb_RelationalOperator;

  /* Matfile logging */
  rt_UpdateTXYLogVars(EB_12B_M->rtwLogInfo, (&EB_12B_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(EB_12B_M)!=-1) &&
        !((rtmGetTFinal(EB_12B_M)-EB_12B_M->Timing.taskTime0) >
          EB_12B_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(EB_12B_M, "Simulation finished");
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
  if (!(++EB_12B_M->Timing.clockTick0)) {
    ++EB_12B_M->Timing.clockTickH0;
  }

  EB_12B_M->Timing.taskTime0 = EB_12B_M->Timing.clockTick0 *
    EB_12B_M->Timing.stepSize0 + EB_12B_M->Timing.clockTickH0 *
    EB_12B_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void EB_12B_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)EB_12B_M, 0,
                sizeof(RT_MODEL_EB_12B_T));
  rtmSetTFinal(EB_12B_M, 0.0);
  EB_12B_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    EB_12B_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(EB_12B_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(EB_12B_M->rtwLogInfo, (NULL));
    rtliSetLogT(EB_12B_M->rtwLogInfo, "tout");
    rtliSetLogX(EB_12B_M->rtwLogInfo, "");
    rtliSetLogXFinal(EB_12B_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(EB_12B_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(EB_12B_M->rtwLogInfo, 2);
    rtliSetLogMaxRows(EB_12B_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(EB_12B_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &EB_12B_Y.id[0],
        &EB_12B_Y.check[0],
        &EB_12B_Y.yinv[0],
        &EB_12B_Y.P[0],
        &EB_12B_Y.u[0],
        &EB_12B_Y.Buminusd[0],
        &EB_12B_Y.J,
        &EB_12B_Y.ridge_on
      };

      rtliSetLogYSignalPtrs(EB_12B_M->rtwLogInfo, ((LogSignalPtrsType)
        rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        9,
        9,
        9,
        15,
        5,
        3,
        1,
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        2,
        2,
        2,
        2,
        1,
        1,
        1,
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        3, 3,
        3, 3,
        3, 3,
        5, 3,
        5,
        3,
        1,
        1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL), (NULL),
        (NULL), (NULL),
        (NULL), (NULL),
        (NULL), (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4, 4,
        4, 4,
        4, 4,
        4, 4,
        4,
        4,
        4,
        4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
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
        "",
        "",
        "",
        "" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "EB_12B/id",
        "EB_12B/check",
        "EB_12B/yinv",
        "EB_12B/P",
        "EB_12B/u",
        "EB_12B/Buminusd",
        "EB_12B/J",
        "EB_12B/ridge_on" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_BOOLEAN, SS_BOOLEAN, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          8,
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

      rtliSetLogYSignalInfo(EB_12B_M->rtwLogInfo, rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[2] = &rt_LoggedOutputWidths[1];
      rt_LoggedCurrentSignalDimensions[3] = &rt_LoggedOutputWidths[1];
      rt_LoggedCurrentSignalDimensions[4] = &rt_LoggedOutputWidths[2];
      rt_LoggedCurrentSignalDimensions[5] = &rt_LoggedOutputWidths[2];
      rt_LoggedCurrentSignalDimensions[6] = &rt_LoggedOutputWidths[3];
      rt_LoggedCurrentSignalDimensions[7] = &rt_LoggedOutputWidths[3];
      rt_LoggedCurrentSignalDimensions[8] = &rt_LoggedOutputWidths[4];
      rt_LoggedCurrentSignalDimensions[9] = &rt_LoggedOutputWidths[5];
      rt_LoggedCurrentSignalDimensions[10] = &rt_LoggedOutputWidths[6];
      rt_LoggedCurrentSignalDimensions[11] = &rt_LoggedOutputWidths[7];
    }

    rtliSetLogY(EB_12B_M->rtwLogInfo, "yout");
  }

  /* states (dwork) */
  (void) memset((void *)&EB_12B_DW, 0,
                sizeof(DW_EB_12B_T));

  /* external inputs */
  (void)memset(&EB_12B_U, 0, sizeof(ExtU_EB_12B_T));

  /* external outputs */
  (void) memset((void *)&EB_12B_Y, 0,
                sizeof(ExtY_EB_12B_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(EB_12B_M->rtwLogInfo, 0.0, rtmGetTFinal
    (EB_12B_M), EB_12B_M->Timing.stepSize0, (&rtmGetErrorStatus(EB_12B_M)));
}

/* Model terminate function */
void EB_12B_terminate(void)
{
  /* (no terminate code required) */
}
