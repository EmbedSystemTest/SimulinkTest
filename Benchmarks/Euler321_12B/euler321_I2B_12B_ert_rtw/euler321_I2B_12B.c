#include "euler321_I2B_12B.h"
#include "euler321_I2B_12B_private.h"

void euler321_I2B_12B_step(RT_MODEL_euler321_I2B_12B_T *const euler321_I2B_12B_M,
  real_T euler321_I2B_12B_U_phi, real_T euler321_I2B_12B_U_theta, real_T
  euler321_I2B_12B_U_psi, real_T euler321_I2B_12B_U_Vi[3], real_T
  euler321_I2B_12B_U_Inport, real_T euler321_I2B_12B_Y_DCM321[9], real_T
  euler321_I2B_12B_Y_Vb[3], real_T euler321_I2B_12B_Y_outTheta[3], real_T
  euler321_I2B_12B_Y_outGamma[3], boolean_T *euler321_I2B_12B_Y_outR1)
{
  real_T rtb_Product[9];
  real_T rtb_Product1_b[9];
  real_T rtb_Product1_i0[9];
  real_T rtb_VectorConcatenate[9];
  real_T rtb_Product2_m[3];
  real_T rtb_TrigonometricFunction2;
  real_T rtb_TrigonometricFunction2_tm_0;
  real_T rtb_TrigonometricFunction2_tm_1;
  real_T rtb_TrigonometricFunction2_tmp;
  real_T rtb_TrigonometricFunction4;
  real_T rtb_TrigonometricFunction4_tm_0;
  real_T rtb_TrigonometricFunction4_tm_1;
  real_T rtb_TrigonometricFunction4_tmp;
  int32_T i;
  int32_T i_0;
  int32_T rtb_Product1_c_tmp;
  rtb_TrigonometricFunction4_tmp = sin(euler321_I2B_12B_U_theta);
  rtb_TrigonometricFunction2_tmp = cos(euler321_I2B_12B_U_theta);
  euler321_I2B_12B_Y_DCM321[0] = rtb_TrigonometricFunction2_tmp;
  euler321_I2B_12B_Y_DCM321[1] = 0.0;
  euler321_I2B_12B_Y_DCM321[2] = rtb_TrigonometricFunction4_tmp;
  euler321_I2B_12B_Y_DCM321[3] = 0.0;
  euler321_I2B_12B_Y_DCM321[4] = 1.0;
  euler321_I2B_12B_Y_DCM321[5] = 0.0;
  euler321_I2B_12B_Y_DCM321[6] = -rtb_TrigonometricFunction4_tmp;
  euler321_I2B_12B_Y_DCM321[7] = 0.0;
  euler321_I2B_12B_Y_DCM321[8] = rtb_TrigonometricFunction2_tmp;
  rtb_TrigonometricFunction2_tm_0 = sin(euler321_I2B_12B_U_psi);
  rtb_TrigonometricFunction4_tm_0 = cos(euler321_I2B_12B_U_psi);
  rtb_Product1_i0[0] = rtb_TrigonometricFunction4_tm_0;
  rtb_Product1_i0[1] = -rtb_TrigonometricFunction2_tm_0;
  rtb_Product1_i0[2] = 0.0;
  rtb_Product1_i0[3] = rtb_TrigonometricFunction2_tm_0;
  rtb_Product1_i0[4] = rtb_TrigonometricFunction4_tm_0;
  rtb_Product1_i0[5] = 0.0;
  rtb_Product1_i0[6] = 0.0;
  rtb_Product1_i0[7] = 0.0;
  rtb_Product1_i0[8] = 1.0;
  for (i_0 = 0; i_0 < 3; i_0++) {
    for (i = 0; i < 3; i++) {
      rtb_Product1_c_tmp = 3 * i_0 + i;
      rtb_Product1_b[rtb_Product1_c_tmp] = 0.0;
      rtb_Product1_b[rtb_Product1_c_tmp] += rtb_Product1_i0[3 * i_0] *
        euler321_I2B_12B_Y_DCM321[i];
      rtb_Product1_b[rtb_Product1_c_tmp] += rtb_Product1_i0[3 * i_0 + 1] *
        euler321_I2B_12B_Y_DCM321[i + 3];
      rtb_Product1_b[rtb_Product1_c_tmp] += rtb_Product1_i0[3 * i_0 + 2] *
        euler321_I2B_12B_Y_DCM321[i + 6];
    }
  }

  rtb_TrigonometricFunction2_tm_1 = sin(euler321_I2B_12B_U_phi);
  rtb_TrigonometricFunction4_tm_1 = cos(euler321_I2B_12B_U_phi);
  rtb_Product1_i0[0] = 1.0;
  rtb_Product1_i0[1] = 0.0;
  rtb_Product1_i0[2] = 0.0;
  rtb_Product1_i0[3] = 0.0;
  rtb_Product1_i0[4] = rtb_TrigonometricFunction4_tm_1;
  rtb_Product1_i0[5] = -rtb_TrigonometricFunction2_tm_1;
  rtb_Product1_i0[6] = 0.0;
  rtb_Product1_i0[7] = rtb_TrigonometricFunction2_tm_1;
  rtb_Product1_i0[8] = rtb_TrigonometricFunction4_tm_1;
  for (i_0 = 0; i_0 < 3; i_0++) {
    for (i = 0; i < 3; i++) {
      rtb_Product1_c_tmp = 3 * i_0 + i;
      euler321_I2B_12B_Y_DCM321[rtb_Product1_c_tmp] = 0.0;
      euler321_I2B_12B_Y_DCM321[rtb_Product1_c_tmp] += rtb_Product1_b[3 * i_0] *
        rtb_Product1_i0[i];
      euler321_I2B_12B_Y_DCM321[rtb_Product1_c_tmp] += rtb_Product1_b[3 * i_0 +
        1] * rtb_Product1_i0[i + 3];
      euler321_I2B_12B_Y_DCM321[rtb_Product1_c_tmp] += rtb_Product1_b[3 * i_0 +
        2] * rtb_Product1_i0[i + 6];
    }
  }

  rtb_Product1_b[0] = rtb_TrigonometricFunction2_tmp;
  rtb_Product1_b[1] = 0.0;
  rtb_Product1_b[2] = rtb_TrigonometricFunction4_tmp;
  rtb_Product1_b[3] = 0.0;
  rtb_Product1_b[4] = 1.0;
  rtb_Product1_b[5] = 0.0;
  rtb_Product1_b[6] = -rtb_TrigonometricFunction4_tmp;
  rtb_Product1_b[7] = 0.0;
  rtb_Product1_b[8] = rtb_TrigonometricFunction2_tmp;
  rtb_Product1_i0[0] = rtb_TrigonometricFunction4_tm_0;
  rtb_Product1_i0[1] = -rtb_TrigonometricFunction2_tm_0;
  rtb_Product1_i0[2] = 0.0;
  rtb_Product1_i0[3] = rtb_TrigonometricFunction2_tm_0;
  rtb_Product1_i0[4] = rtb_TrigonometricFunction4_tm_0;
  rtb_Product1_i0[5] = 0.0;
  rtb_Product1_i0[6] = 0.0;
  rtb_Product1_i0[7] = 0.0;
  rtb_Product1_i0[8] = 1.0;
  for (i_0 = 0; i_0 < 3; i_0++) {
    for (i = 0; i < 3; i++) {
      rtb_Product1_c_tmp = 3 * i_0 + i;
      rtb_VectorConcatenate[rtb_Product1_c_tmp] = 0.0;
      rtb_VectorConcatenate[rtb_Product1_c_tmp] += rtb_Product1_i0[3 * i_0] *
        rtb_Product1_b[i];
      rtb_VectorConcatenate[rtb_Product1_c_tmp] += rtb_Product1_i0[3 * i_0 + 1] *
        rtb_Product1_b[i + 3];
      rtb_VectorConcatenate[rtb_Product1_c_tmp] += rtb_Product1_i0[3 * i_0 + 2] *
        rtb_Product1_b[i + 6];
    }
  }

  rtb_Product1_b[0] = 1.0;
  rtb_Product1_b[1] = 0.0;
  rtb_Product1_b[2] = 0.0;
  rtb_Product1_b[3] = 0.0;
  rtb_Product1_b[4] = rtb_TrigonometricFunction4_tm_1;
  rtb_Product1_b[5] = -rtb_TrigonometricFunction2_tm_1;
  rtb_Product1_b[6] = 0.0;
  rtb_Product1_b[7] = rtb_TrigonometricFunction2_tm_1;
  rtb_Product1_b[8] = rtb_TrigonometricFunction4_tm_1;
  for (i_0 = 0; i_0 < 3; i_0++) {
    for (i = 0; i < 3; i++) {
      rtb_Product1_c_tmp = 3 * i_0 + i;
      rtb_Product1_i0[rtb_Product1_c_tmp] = 0.0;
      rtb_Product1_i0[rtb_Product1_c_tmp] += rtb_VectorConcatenate[3 * i_0] *
        rtb_Product1_b[i];
      rtb_Product1_i0[rtb_Product1_c_tmp] += rtb_VectorConcatenate[3 * i_0 + 1] *
        rtb_Product1_b[i + 3];
      rtb_Product1_i0[rtb_Product1_c_tmp] += rtb_VectorConcatenate[3 * i_0 + 2] *
        rtb_Product1_b[i + 6];
    }
  }

  rtb_TrigonometricFunction2 = sin(euler321_I2B_12B_U_Inport);
  rtb_TrigonometricFunction4 = cos(euler321_I2B_12B_U_Inport);
  rtb_VectorConcatenate[0] = rtb_TrigonometricFunction4;
  rtb_VectorConcatenate[1] = 0.0;
  rtb_VectorConcatenate[2] = rtb_TrigonometricFunction2;
  rtb_VectorConcatenate[3] = 0.0;
  rtb_VectorConcatenate[4] = 1.0;
  rtb_VectorConcatenate[5] = 0.0;
  rtb_VectorConcatenate[6] = -rtb_TrigonometricFunction2;
  rtb_VectorConcatenate[7] = 0.0;
  rtb_VectorConcatenate[8] = rtb_TrigonometricFunction4;
  rtb_Product1_b[0] = rtb_TrigonometricFunction4_tm_0;
  rtb_Product1_b[1] = -rtb_TrigonometricFunction2_tm_0;
  rtb_Product1_b[2] = 0.0;
  rtb_Product1_b[3] = rtb_TrigonometricFunction2_tm_0;
  rtb_Product1_b[4] = rtb_TrigonometricFunction4_tm_0;
  rtb_Product1_b[5] = 0.0;
  rtb_Product1_b[6] = 0.0;
  rtb_Product1_b[7] = 0.0;
  rtb_Product1_b[8] = 1.0;
  for (i_0 = 0; i_0 < 3; i_0++) {
    for (i = 0; i < 3; i++) {
      rtb_Product1_c_tmp = 3 * i_0 + i;
      rtb_Product[rtb_Product1_c_tmp] = 0.0;
      rtb_Product[rtb_Product1_c_tmp] += rtb_Product1_b[3 * i_0] *
        rtb_VectorConcatenate[i];
      rtb_Product[rtb_Product1_c_tmp] += rtb_Product1_b[3 * i_0 + 1] *
        rtb_VectorConcatenate[i + 3];
      rtb_Product[rtb_Product1_c_tmp] += rtb_Product1_b[3 * i_0 + 2] *
        rtb_VectorConcatenate[i + 6];
    }
  }

  rtb_VectorConcatenate[0] = 1.0;
  rtb_VectorConcatenate[1] = 0.0;
  rtb_VectorConcatenate[2] = 0.0;
  rtb_VectorConcatenate[3] = 0.0;
  rtb_VectorConcatenate[4] = rtb_TrigonometricFunction4_tm_1;
  rtb_VectorConcatenate[5] = -rtb_TrigonometricFunction2_tm_1;
  rtb_VectorConcatenate[6] = 0.0;
  rtb_VectorConcatenate[7] = rtb_TrigonometricFunction2_tm_1;
  rtb_VectorConcatenate[8] = rtb_TrigonometricFunction4_tm_1;
  for (i_0 = 0; i_0 < 3; i_0++) {
    rtb_Product2_m[i_0] = 0.0;
    euler321_I2B_12B_Y_Vb[i_0] = 0.0;
    euler321_I2B_12B_Y_outGamma[i_0] = 0.0;
    for (i = 0; i < 3; i++) {
      rtb_Product1_c_tmp = 3 * i + i_0;
      rtb_Product1_b[rtb_Product1_c_tmp] = 0.0;
      rtb_Product1_b[rtb_Product1_c_tmp] += rtb_Product[3 * i] *
        rtb_VectorConcatenate[i_0];
      rtb_Product1_b[rtb_Product1_c_tmp] += rtb_Product[3 * i + 1] *
        rtb_VectorConcatenate[i_0 + 3];
      rtb_Product1_b[rtb_Product1_c_tmp] += rtb_Product[3 * i + 2] *
        rtb_VectorConcatenate[i_0 + 6];
      euler321_I2B_12B_Y_Vb[i_0] += euler321_I2B_12B_Y_DCM321[rtb_Product1_c_tmp]
        * euler321_I2B_12B_U_Vi[i];
      euler321_I2B_12B_Y_outGamma[i_0] += rtb_Product1_i0[rtb_Product1_c_tmp] *
        euler321_I2B_12B_U_Vi[i];
      rtb_Product2_m[i_0] += rtb_Product1_b[rtb_Product1_c_tmp] *
        euler321_I2B_12B_U_Vi[i];
    }
  }

  euler321_I2B_12B_Y_outTheta[0] = euler321_I2B_12B_Y_Vb[0] -
    euler321_I2B_12B_Y_outGamma[0];
  euler321_I2B_12B_Y_outTheta[1] = euler321_I2B_12B_Y_Vb[1] -
    euler321_I2B_12B_Y_outGamma[1];
  euler321_I2B_12B_Y_outTheta[2] = euler321_I2B_12B_Y_Vb[2] -
    euler321_I2B_12B_Y_outGamma[2];
  euler321_I2B_12B_Y_outGamma[0] = euler321_I2B_12B_Y_Vb[0] - rtb_Product2_m[0];
  euler321_I2B_12B_Y_outGamma[1] = euler321_I2B_12B_Y_Vb[1] - rtb_Product2_m[1];
  euler321_I2B_12B_Y_outGamma[2] = euler321_I2B_12B_Y_Vb[2] - rtb_Product2_m[2];
  rtb_TrigonometricFunction2 = rtb_TrigonometricFunction4_tm_0 *
    rtb_TrigonometricFunction4_tmp;
  rtb_TrigonometricFunction4 = rtb_TrigonometricFunction2_tm_0 *
    rtb_TrigonometricFunction4_tmp;
  *euler321_I2B_12B_Y_outR1 = ((rtb_TrigonometricFunction4_tm_0 *
    rtb_TrigonometricFunction2_tmp == euler321_I2B_12B_Y_DCM321[0]) &&
    (rtb_TrigonometricFunction2 * rtb_TrigonometricFunction2_tm_1 +
     -rtb_TrigonometricFunction4_tm_1 * rtb_TrigonometricFunction2_tm_0 ==
     euler321_I2B_12B_Y_DCM321[1]) && (rtb_TrigonometricFunction2 *
    rtb_TrigonometricFunction4_tm_1 + rtb_TrigonometricFunction2_tm_1 *
    rtb_TrigonometricFunction2_tm_0 == euler321_I2B_12B_Y_DCM321[2]) &&
    (rtb_TrigonometricFunction2_tm_0 * rtb_TrigonometricFunction2_tmp ==
     euler321_I2B_12B_Y_DCM321[3]) && (rtb_TrigonometricFunction4 *
    rtb_TrigonometricFunction2_tm_1 + rtb_TrigonometricFunction4_tm_0 *
    rtb_TrigonometricFunction4_tm_1 == euler321_I2B_12B_Y_DCM321[4]) &&
    (rtb_TrigonometricFunction4 * rtb_TrigonometricFunction4_tm_1 +
     -rtb_TrigonometricFunction2_tm_1 * rtb_TrigonometricFunction4_tm_0 ==
     euler321_I2B_12B_Y_DCM321[5]) && (-rtb_TrigonometricFunction4_tmp ==
    euler321_I2B_12B_Y_DCM321[6]) && (rtb_TrigonometricFunction2_tm_1 *
    rtb_TrigonometricFunction2_tmp == euler321_I2B_12B_Y_DCM321[7]) &&
    (rtb_TrigonometricFunction4_tm_1 * rtb_TrigonometricFunction2_tmp ==
     euler321_I2B_12B_Y_DCM321[8]));
  UNUSED_PARAMETER(euler321_I2B_12B_M);
}

void euler321_I2B_12B_initialize(RT_MODEL_euler321_I2B_12B_T *const
  euler321_I2B_12B_M, real_T *euler321_I2B_12B_U_phi, real_T
  *euler321_I2B_12B_U_theta, real_T *euler321_I2B_12B_U_psi, real_T
  euler321_I2B_12B_U_Vi[3], real_T *euler321_I2B_12B_U_Inport, real_T
  euler321_I2B_12B_Y_DCM321[9], real_T euler321_I2B_12B_Y_Vb[3], real_T
  euler321_I2B_12B_Y_outTheta[3], real_T euler321_I2B_12B_Y_outGamma[3],
  boolean_T *euler321_I2B_12B_Y_outR1)
{
  rtmSetErrorStatus(euler321_I2B_12B_M, (NULL));
  (void)memset(&euler321_I2B_12B_U_Vi[0], 0, 3U * sizeof(real_T));
  *euler321_I2B_12B_U_phi = 0.0;
  *euler321_I2B_12B_U_theta = 0.0;
  *euler321_I2B_12B_U_psi = 0.0;
  *euler321_I2B_12B_U_Inport = 0.0;
  (void)memset(&euler321_I2B_12B_Y_DCM321[0], 0, 9U * sizeof(real_T));
  (void)memset(&euler321_I2B_12B_Y_Vb[0], 0, 3U * sizeof(real_T));
  (void)memset(&euler321_I2B_12B_Y_outTheta[0], 0, 3U * sizeof(real_T));
  (void)memset(&euler321_I2B_12B_Y_outGamma[0], 0, 3U * sizeof(real_T));
  *euler321_I2B_12B_Y_outR1 = false;
  UNUSED_PARAMETER(euler321_I2B_12B_M);
}

void euler321_I2B_12B_terminate(RT_MODEL_euler321_I2B_12B_T *const
  euler321_I2B_12B_M)
{
  UNUSED_PARAMETER(euler321_I2B_12B_M);
}
