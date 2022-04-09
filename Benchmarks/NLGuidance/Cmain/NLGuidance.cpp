#include "define.h"
/* Code of NLGuidance */
/* Update function of "NLGuidance.Func" */
void NLGuidance_step(RT_MODEL_NLGuidance_T* NLGuidance_M, real_T NLGuidance_U_Xtarg[3], real_T NLGuidance_U_Xv[3], real_T NLGuidance_U_Vv[3], real_T NLGuidance_U_r, real_T NLGuidance_Y_yout[3]) {
    BitmapCov::munitBitmap[0] = 1;
    /* Calculate code of  */
    real_T rtb_Divide4;
    real_T rtb_MathFunction1_m;
    real_T rtb_MathFunction_idx_0;
    real_T rtb_MathFunction_idx_1;
    real_T rtb_Product2;
    real_T rtb_Sum;
    real_T rtb_Sum4;
    real_T rtb_Xr_idx_0;
    real_T rtb_Xr_idx_1;
    rtb_Sum = NLGuidance_U_Xtarg[0] - NLGuidance_U_Xv[0];
    rtb_MathFunction_idx_0 = rtb_Sum * rtb_Sum;
    rtb_Xr_idx_0 = rtb_Sum;
    rtb_Sum = NLGuidance_U_Xtarg[1] - NLGuidance_U_Xv[1];
    rtb_MathFunction_idx_1 = rtb_Sum * rtb_Sum;
    rtb_Xr_idx_1 = rtb_Sum;
    rtb_Sum = NLGuidance_U_Xtarg[2] - NLGuidance_U_Xv[2];
    rtb_MathFunction1_m = (rtb_MathFunction_idx_0 + rtb_MathFunction_idx_1) + rtb_Sum * rtb_Sum;
    rtb_Sum4 = (rtb_Xr_idx_0 * NLGuidance_U_Vv[0] + rtb_Xr_idx_1 * NLGuidance_U_Vv[1]) + rtb_Sum * NLGuidance_U_Vv[2];
    if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(rtb_MathFunction1_m < 0.0, 0, 1, 0), -1, 0, 0)) {
        BitmapCov::branchBitmap[0] = 1;
        rtb_MathFunction_idx_0 = -sqrt(fabs(rtb_MathFunction1_m));
    }
    else
    {
        BitmapCov::branchBitmap[1] = 1;
        rtb_MathFunction_idx_0 = sqrt(rtb_MathFunction1_m);
    }
    rtb_Divide4 = rtb_MathFunction_idx_0 * rtb_MathFunction_idx_0;
    rtb_MathFunction_idx_1 = rtb_Divide4 - NLGuidance_U_r * NLGuidance_U_r;
    rtb_MathFunction1_m = (NLGuidance_U_Vv[0] * NLGuidance_U_Vv[0] + NLGuidance_U_Vv[1] * NLGuidance_U_Vv[1]) + NLGuidance_U_Vv[2] * NLGuidance_U_Vv[2];
    if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(rtb_MathFunction1_m < 0.0, 2, 1, 1), -3, 0, 1)) {
        BitmapCov::branchBitmap[2] = 1;
        rtb_MathFunction1_m = -sqrt(fabs(rtb_MathFunction1_m));
    }
    else
    {
        BitmapCov::branchBitmap[3] = 1;
        rtb_MathFunction1_m = sqrt(rtb_MathFunction1_m);
    }
    rtb_MathFunction1_m = rtb_MathFunction1_m * rtb_MathFunction1_m * rtb_Divide4 - rtb_Sum4 * rtb_Sum4;
    if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord((rtb_MathFunction_idx_1 <= 0.0), 4, 1, 2)||BitmapCov::CondAndMCDCRecord((rtb_MathFunction1_m <= 0.0), 6, 2, 2), -5, 0, 2)) {
        BitmapCov::branchBitmap[4] = 1;
        rtb_Product2 = NLGuidance_U_r / rtb_MathFunction_idx_0;
        rtb_Sum = rtb_Product2 * rtb_Xr_idx_0 + NLGuidance_U_Xtarg[0];
        rtb_Sum4 = rtb_Xr_idx_1 * rtb_Product2 + NLGuidance_U_Xtarg[1];
        rtb_MathFunction_idx_0 = rtb_Sum - NLGuidance_U_Xv[0];
        rtb_MathFunction_idx_1 = rtb_Sum4 - NLGuidance_U_Xv[1];
        rtb_MathFunction1_m = (0.0 - NLGuidance_U_Xv[2]) * (0.0 - NLGuidance_U_Xv[2]);
        rtb_Divide4 = (rtb_MathFunction_idx_0 * rtb_MathFunction_idx_0 + rtb_MathFunction_idx_1 * rtb_MathFunction_idx_1) + rtb_MathFunction1_m;
        rtb_Xr_idx_0 = -rtb_Product2 * rtb_Xr_idx_0 + NLGuidance_U_Xtarg[0];
        rtb_Xr_idx_1 = rtb_Xr_idx_1 * -rtb_Product2 + NLGuidance_U_Xtarg[1];
        rtb_MathFunction_idx_0 = rtb_Xr_idx_0 - NLGuidance_U_Xv[0];
        rtb_MathFunction_idx_1 = rtb_Xr_idx_1 - NLGuidance_U_Xv[1];
        rtb_MathFunction1_m += rtb_MathFunction_idx_0 * rtb_MathFunction_idx_0 + rtb_MathFunction_idx_1 * rtb_MathFunction_idx_1;
        if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(rtb_Divide4 < 0.0, 8, 1, 3), -7, 0, 3)) {
            BitmapCov::branchBitmap[5] = 1;
            rtb_Divide4 = -sqrt(fabs(rtb_Divide4));
        }
        else
        {
            BitmapCov::branchBitmap[6] = 1;
            rtb_Divide4 = sqrt(rtb_Divide4);
        }
        if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(rtb_MathFunction1_m < 0.0, 10, 1, 4), -9, 0, 4)) {
            BitmapCov::branchBitmap[7] = 1;
            rtb_MathFunction1_m = -sqrt(fabs(rtb_MathFunction1_m));
        }
        else
        {
            BitmapCov::branchBitmap[8] = 1;
            rtb_MathFunction1_m = sqrt(rtb_MathFunction1_m);
        }
        if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(rtb_Divide4 < rtb_MathFunction1_m, 12, 1, 5), -11, 0, 5)) {
            BitmapCov::branchBitmap[9] = 1;
            NLGuidance_Y_yout[0] = rtb_Sum;
            NLGuidance_Y_yout[1] = rtb_Sum4;
        }
        else
        {
            BitmapCov::branchBitmap[10] = 1;
            NLGuidance_Y_yout[0] = rtb_Xr_idx_0;
            NLGuidance_Y_yout[1] = rtb_Xr_idx_1;
        }
        NLGuidance_Y_yout[2] = 0.0;
    }
    else
    {
        BitmapCov::branchBitmap[11] = 1;
        rtb_Product2 = sqrt(rtb_MathFunction_idx_1 / rtb_MathFunction1_m);
        rtb_MathFunction_idx_0 = rtb_Product2 * NLGuidance_U_Vv[0];
        rtb_MathFunction_idx_1 = rtb_Product2 * NLGuidance_U_Vv[1];
        rtb_MathFunction1_m = rtb_Product2 * NLGuidance_U_Vv[2];
        rtb_Divide4 = 1.0 / rtb_Divide4;
        rtb_Product2 *= rtb_Sum4;
        rtb_Sum4 = NLGuidance_U_r + rtb_Product2;
        NLGuidance_Y_yout[0] = (rtb_Sum4 * rtb_Xr_idx_0 * -rtb_Divide4 + rtb_MathFunction_idx_0) * NLGuidance_U_r + rtb_Xr_idx_0;
        NLGuidance_Y_yout[1] = (rtb_Sum4 * rtb_Xr_idx_1 * -rtb_Divide4 + rtb_MathFunction_idx_1) * NLGuidance_U_r + rtb_Xr_idx_1;
        NLGuidance_Y_yout[2] = (rtb_Sum4 * rtb_Sum * -rtb_Divide4 + rtb_MathFunction1_m) * NLGuidance_U_r + rtb_Sum;
        rtb_Sum4 = rtb_Xr_idx_0 * NLGuidance_Y_yout[1];
        rtb_Product2 -= NLGuidance_U_r;
        if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(rtb_Sum4 - rtb_Sum4 < 0.0, 14, 1, 6), -13, 0, 6)) {
            BitmapCov::branchBitmap[12] = 1;
            NLGuidance_Y_yout[0] += NLGuidance_U_Xv[0];
            NLGuidance_Y_yout[1] += NLGuidance_U_Xv[1];
            NLGuidance_Y_yout[2] += NLGuidance_U_Xv[2];
        }
        else
        {
            BitmapCov::branchBitmap[13] = 1;
            NLGuidance_Y_yout[0] = ((rtb_Product2 * rtb_Xr_idx_0 * rtb_Divide4 - rtb_MathFunction_idx_0) * NLGuidance_U_r + rtb_Xr_idx_0) + NLGuidance_U_Xv[0];
            NLGuidance_Y_yout[1] = ((rtb_Product2 * rtb_Xr_idx_1 * rtb_Divide4 - rtb_MathFunction_idx_1) * NLGuidance_U_r + rtb_Xr_idx_1) + NLGuidance_U_Xv[1];
            NLGuidance_Y_yout[2] = ((rtb_Product2 * rtb_Sum * rtb_Divide4 - rtb_MathFunction1_m) * NLGuidance_U_r + rtb_Sum) + NLGuidance_U_Xv[2];
        }
    }
    UNUSED_PARAMETER(NLGuidance_M);
}
/* Init function of "NLGuidance.Func" */
void NLGuidance_init(RT_MODEL_NLGuidance_T* NLGuidance_M, real_T NLGuidance_U_Xtarg[3], real_T NLGuidance_U_Xv[3], real_T NLGuidance_U_Vv[3], real_T NLGuidance_U_Vt[3], real_T NLGuidance_Y_yout[3], real_T* NLGuidance_U_r) {
    BitmapCov::munitBitmap[1] = 1;
    /* Calculate code of  */
    rtmSetErrorStatus(NLGuidance_M, (NULL));
    (void)memset(&NLGuidance_U_Xtarg[0], 0, 3U * sizeof(real_T));
    (void)memset(&NLGuidance_U_Xv[0], 0, 3U * sizeof(real_T));
    (void)memset(&NLGuidance_U_Vv[0], 0, 3U * sizeof(real_T));
    (void)memset(&NLGuidance_U_Vt[0], 0, 3U * sizeof(real_T));
    *NLGuidance_U_r = 0.0;
    (void)memset(&NLGuidance_Y_yout[0], 0, 3U * sizeof(real_T));
    UNUSED_PARAMETER(NLGuidance_M);
}