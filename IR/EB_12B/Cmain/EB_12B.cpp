#include "define.h"
/* Code of EB_12B */
/* Update function of "EB_12B.Func" */
void EB_12B_step(RT_MODEL_EB_12B_T* EB_12B_M, real_T EB_12B_U_B[15], real_T EB_12B_Y_check[9], real_T EB_12B_Y_yinv[9], real_T EB_12B_Y_P[15], real_T EB_12B_Y_u[5], real_T EB_12B_Y_Buminusd[3], real_T* EB_12B_Y_J, boolean_T* EB_12B_Y_ridge_on) {
    BitmapCov::munitBitmap[0] = 1;
    /* Calculate code of  */
    real_T rtb_MathFunction2[15];
    real_T rtb_Product1_f[15];
    real_T rtb_Product7[15];
    real_T rtb_Product1_a[9];
    real_T rtb_RelationalOperator_0;
    int32_T i;
    int32_T i_0;
    int32_T rtb_MathFunction2_tmp;
    int32_T rtb_Product7_tmp;
    for(i = 0;BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(i < 5, 0, 1, 0), -1, 0, 0);i++)
    {
        BitmapCov::branchBitmap[0] = 1;
        for(i_0 = 0;BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(i_0 < 3, 2, 1, 1), -3, 0, 1);i_0++)
        {
            BitmapCov::branchBitmap[1] = 1;
            rtb_Product7_tmp = 5 * i_0 + i;
            rtb_Product7[rtb_Product7_tmp] = 0.0;
            for(rtb_MathFunction2_tmp = 0;BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(rtb_MathFunction2_tmp < 5, 4, 1, 2), -5, 0, 2);rtb_MathFunction2_tmp++)
            {
                BitmapCov::branchBitmap[2] = 1;
                rtb_Product7[rtb_Product7_tmp] += EB_12B_ConstB.Divide[5 * rtb_MathFunction2_tmp + i] * EB_12B_U_B[3 * rtb_MathFunction2_tmp + i_0];
            }
            BitmapCov::branchBitmap[3] = 1;
        }
        BitmapCov::branchBitmap[4] = 1;
    }
    BitmapCov::branchBitmap[5] = 1;
    for(i = 0;BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(i < 3, 6, 1, 3), -7, 0, 3);i++)
    {
        BitmapCov::branchBitmap[6] = 1;
        for(i_0 = 0;BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(i_0 < 3, 8, 1, 4), -9, 0, 4);i_0++)
        {
            BitmapCov::branchBitmap[7] = 1;
            rtb_MathFunction2_tmp = 3 * i + i_0;
            rtb_Product1_a[rtb_MathFunction2_tmp] = 0.0;
            for(rtb_Product7_tmp = 0;BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(rtb_Product7_tmp < 5, 10, 1, 5), -11, 0, 5);rtb_Product7_tmp++)
            {
                BitmapCov::branchBitmap[8] = 1;
                rtb_Product1_a[rtb_MathFunction2_tmp] += EB_12B_U_B[3 * rtb_Product7_tmp + i_0] * rtb_Product7[5 * i + rtb_Product7_tmp];
            }
            BitmapCov::branchBitmap[9] = 1;
        }
        BitmapCov::branchBitmap[10] = 1;
    }
    BitmapCov::branchBitmap[11] = 1;
    memcpy(&rtb_Product1_f[0], &rtb_Product1_a[0], 9U * sizeof(real_T));
    *EB_12B_Y_ridge_on = (((((rtb_Product1_f[0] * rtb_Product1_f[4] * rtb_Product1_f[8] - rtb_Product1_f[0] * rtb_Product1_f[5] * rtb_Product1_f[7]) - rtb_Product1_f[1] * rtb_Product1_f[3] * rtb_Product1_f[8]) + rtb_Product1_f[2] * rtb_Product1_f[3] * rtb_Product1_f[7]) + rtb_Product1_f[1] * rtb_Product1_f[5] * rtb_Product1_f[6]) - rtb_Product1_f[2] * rtb_Product1_f[4] * rtb_Product1_f[6] <= 1.0E-12);
    for(i = 0;BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(i < 9, 12, 1, 6), -13, 0, 6);i++)
    {
        BitmapCov::branchBitmap[12] = 1;
        if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(*EB_12B_Y_ridge_on, 14, 1, 7), -15, 0, 7)) {
            BitmapCov::branchBitmap[13] = 1;
            rtb_RelationalOperator_0 = EB_12B_ConstP.Constant4_Value[i];
        }
        else
        {
            BitmapCov::branchBitmap[14] = 1;
            rtb_RelationalOperator_0 = 0.0;
        }
        rtb_Product1_a[i] = rtb_Product1_f[i] + rtb_RelationalOperator_0;
    }
    BitmapCov::branchBitmap[15] = 1;
    rt_invd3x3_snf(rtb_Product1_a, EB_12B_Y_yinv);
    for(i = 0;BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(i < 3, 16, 1, 8), -17, 0, 8);i++)
    {
        BitmapCov::branchBitmap[16] = 1;
        for(i_0 = 0;BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(i_0 < 5, 18, 1, 9), -19, 0, 9);i_0++)
        {
            BitmapCov::branchBitmap[17] = 1;
            rtb_MathFunction2_tmp = 5 * i + i_0;
            rtb_MathFunction2[rtb_MathFunction2_tmp] = 0.0;
            rtb_MathFunction2[rtb_MathFunction2_tmp] += EB_12B_Y_yinv[3 * i] * rtb_Product7[i_0];
            rtb_MathFunction2[rtb_MathFunction2_tmp] += EB_12B_Y_yinv[3 * i + 1] * rtb_Product7[i_0 + 5];
            rtb_MathFunction2[rtb_MathFunction2_tmp] += EB_12B_Y_yinv[3 * i + 2] * rtb_Product7[i_0 + 10];
        }
        BitmapCov::branchBitmap[18] = 1;
    }
    BitmapCov::branchBitmap[19] = 1;
    memcpy(&EB_12B_Y_P[0], &rtb_MathFunction2[0], 15U * sizeof(real_T));
    memcpy(&rtb_Product1_a[0], &rtb_Product1_f[0], 9U * sizeof(real_T));
    for(i = 0;BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(i < 3, 20, 1, 10), -21, 0, 10);i++)
    {
        BitmapCov::branchBitmap[20] = 1;
        for(i_0 = 0;BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(i_0 < 3, 22, 1, 11), -23, 0, 11);i_0++)
        {
            BitmapCov::branchBitmap[21] = 1;
            rtb_MathFunction2_tmp = 3 * i + i_0;
            EB_12B_Y_check[rtb_MathFunction2_tmp] = 0.0;
            EB_12B_Y_check[rtb_MathFunction2_tmp] += EB_12B_Y_yinv[3 * i] * rtb_Product1_a[i_0];
            EB_12B_Y_check[rtb_MathFunction2_tmp] += EB_12B_Y_yinv[3 * i + 1] * rtb_Product1_a[i_0 + 3];
            EB_12B_Y_check[rtb_MathFunction2_tmp] += EB_12B_Y_yinv[3 * i + 2] * rtb_Product1_a[i_0 + 6];
        }
        BitmapCov::branchBitmap[22] = 1;
    }
    BitmapCov::branchBitmap[23] = 1;
    for(i = 0;BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(i < 5, 24, 1, 12), -25, 0, 12);i++)
    {
        BitmapCov::branchBitmap[24] = 1;
        EB_12B_Y_u[i] = 0.0;
        EB_12B_Y_u[i] += rtb_MathFunction2[i] * 3.0;
        EB_12B_Y_u[i] += -rtb_MathFunction2[i + 5];
        EB_12B_Y_u[i] += rtb_MathFunction2[i + 10] * 2.0;
        rtb_MathFunction2[i] = EB_12B_Y_u[i];
    }
    BitmapCov::branchBitmap[25] = 1;
    for(i = 0;BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(i < 5, 26, 1, 13), -27, 0, 13);i++)
    {
        BitmapCov::branchBitmap[26] = 1;
        rtb_Product7[i] = 0.0;
        for(i_0 = 0;BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(i_0 < 5, 28, 1, 14), -29, 0, 14);i_0++)
        {
            BitmapCov::branchBitmap[27] = 1;
            rtb_Product7[i] += EB_12B_ConstP.Const_Value[5 * i_0 + i] * rtb_MathFunction2[i_0];
        }
        BitmapCov::branchBitmap[28] = 1;
    }
    BitmapCov::branchBitmap[29] = 1;
    for(i = 0;BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(i < 3, 30, 1, 15), -31, 0, 15);i++)
    {
        BitmapCov::branchBitmap[30] = 1;
        rtb_RelationalOperator_0 = 0.0;
        for(i_0 = 0;BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(i_0 < 5, 32, 1, 16), -33, 0, 16);i_0++)
        {
            BitmapCov::branchBitmap[31] = 1;
            rtb_RelationalOperator_0 += EB_12B_U_B[3 * i_0 + i] * EB_12B_Y_u[i_0];
        }
        BitmapCov::branchBitmap[32] = 1;
        EB_12B_Y_Buminusd[i] = rtb_RelationalOperator_0 - EB_12B_ConstP.Const2_Value[i];
    }
    BitmapCov::branchBitmap[33] = 1;
    *EB_12B_Y_J = 0.0;
    for(i = 0;BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(i < 5, 34, 1, 17), -35, 0, 17);i++)
    {
        BitmapCov::branchBitmap[34] = 1;
        *EB_12B_Y_J += rtb_MathFunction2[i] * rtb_Product7[i];
    }
    BitmapCov::branchBitmap[35] = 1;
    UNUSED_PARAMETER(EB_12B_M);
}
/* Init function of "EB_12B.Func" */
void EB_12B_init(RT_MODEL_EB_12B_T* EB_12B_M, real_T EB_12B_U_B[15], real_T EB_12B_Y_id[9], real_T EB_12B_Y_check[9], real_T EB_12B_Y_yinv[9], real_T EB_12B_Y_P[15], real_T EB_12B_Y_u[5], real_T EB_12B_Y_Buminusd[3], real_T* EB_12B_Y_J, boolean_T* EB_12B_Y_ridge_on) {
    BitmapCov::munitBitmap[1] = 1;
    /* Calculate code of  */
    struct DW_EB_12B_T * EB_12B_DW = EB_12B_M->dwork;
    rtmSetErrorStatus(EB_12B_M, (NULL));
    (void)memset((void*)EB_12B_DW, 0, sizeof(DW_EB_12B_T));
    (void)memset(&EB_12B_U_B[0], 0, 15U * sizeof(real_T));
    (void)memset(&EB_12B_Y_id[0], 0, 9U * sizeof(real_T));
    (void)memset(&EB_12B_Y_check[0], 0, 9U * sizeof(real_T));
    (void)memset(&EB_12B_Y_yinv[0], 0, 9U * sizeof(real_T));
    (void)memset(&EB_12B_Y_P[0], 0, 15U * sizeof(real_T));
    (void)memset(&EB_12B_Y_u[0], 0, 5U * sizeof(real_T));
    (void)memset(&EB_12B_Y_Buminusd[0], 0, 3U * sizeof(real_T));
    *EB_12B_Y_J = 0.0;
    *EB_12B_Y_ridge_on = false;
    memcpy(&EB_12B_Y_id[0], &EB_12B_ConstP.ID_Value[0], 9U * sizeof(real_T));
}
/* Update function of  */
void rt_invd3x3_snf(real_T u[9], real_T y[9]) {
    BitmapCov::munitBitmap[2] = 1;
    /* Calculate code of  */
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
    if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord((absx21 > absx11), 36, 1, 18)&&BitmapCov::CondAndMCDCRecord((absx21 > absx31), 38, 2, 18), -37, 0, 18)) {
        BitmapCov::branchBitmap[36] = 1;
        p1 = 4;
        p2 = 0;
        x[0] = u[1];
        x[1] = u[0];
        x[3] = u[4];
        x[4] = u[3];
        x[6] = u[7];
        x[7] = u[6];
    }
    else if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(absx31 > absx11, 40, 1, 19), -39, 0, 19)) {
        BitmapCov::branchBitmap[37] = 1;
        p1 = 7;
        p3 = 0;
        x[2] = x[0];
        x[0] = u[2];
        x[5] = x[3];
        x[3] = u[5];
        x[8] = x[6];
        x[6] = u[8];
    }
    BitmapCov::branchBitmap[38] = 1;
    absx11 = x[1] / x[0];
    x[1] = absx11;
    absx21 = x[2] / x[0];
    x[2] = absx21;
    x[4] -= absx11 * x[3];
    x[5] -= absx21 * x[3];
    x[7] -= absx11 * x[6];
    x[8] -= absx21 * x[6];
    if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(fabs(x[5]) > fabs(x[4]), 42, 1, 20), -41, 0, 20)) {
        BitmapCov::branchBitmap[39] = 1;
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
    BitmapCov::branchBitmap[40] = 1;
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