#include "define.h"
/* Code of regs_12B */
/* Update function of "regs_12B.Func" */
void regs_12B_step(RT_MODEL_regs_12B_T* regs_12B_M, real_T regs_12B_U_beta_adc_deg, real_T regs_12B_U_vtas_adc_kts, real_T regs_12B_U_lcv_cmd_fcs_dps, real_T regs_12B_U_mcv_cmd_fcs_dps, real_T regs_12B_U_ncv_cmd_fcs_dps, real_T regs_12B_U_xcv_cmd_fcs_fps, real_T regs_12B_U_hcv_cmd_fcs_fps, real_T regs_12B_U_lcv_fps_dps, real_T regs_12B_U_mcv_fcs_dps, real_T regs_12B_U_ncv_fcs_dps, real_T regs_12B_U_dcv_fcs_fps, real_T regs_12B_U_zcv_fcs_fps, real_T regs_12B_U_beta_dot, real_T* regs_12B_Y_lcvdt_cmd_fcs_dps2, real_T* regs_12B_Y_mcvdt_cmd_fcs_dps2, real_T* regs_12B_Y_ncvdt_cmd_fcs_dps2, real_T* regs_12B_Y_xcvdt_cmd_fcs_fps2, real_T* regs_12B_Y_hcvdt_cmd_fcs_fps2) {
    BitmapCov::munitBitmap[0] = 1;
    /* Calculate code of  */
    struct DW_regs_12B_T * regs_12B_DW = ((DW_regs_12B_T*)regs_12B_M->dwork);
    real_T rtb_CVdt_cmd;
    real_T rtb_Sum3;
    *regs_12B_Y_lcvdt_cmd_fcs_dps2 = (regs_12B_U_lcv_cmd_fcs_dps - regs_12B_U_lcv_fps_dps) * 2.5;
    rtb_CVdt_cmd = rt_Lookup(regs_12B_ConstP.pooled4, 5, regs_12B_U_vtas_adc_kts, regs_12B_ConstP.pooled4);
    *regs_12B_Y_ncvdt_cmd_fcs_dps2 = ((regs_12B_U_ncv_cmd_fcs_dps * regs_12B_ConstB.Kcmd_Kbeta + regs_12B_ConstB.Kcmd_Kbeta * regs_12B_U_beta_adc_deg) + regs_12B_ConstB.Sum2 * regs_12B_U_beta_dot) * rtb_CVdt_cmd + (1.0 - rtb_CVdt_cmd) * (regs_12B_U_ncv_cmd_fcs_dps - regs_12B_U_ncv_fcs_dps);
    rtb_CVdt_cmd = regs_12B_U_hcv_cmd_fcs_fps - (-regs_12B_U_zcv_fcs_fps);
    if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(rtb_CVdt_cmd > 1.0, 0, 1, 0), -1, 0, 0)) {
        BitmapCov::branchBitmap[0] = 1;
        rtb_CVdt_cmd = 1.0;
    }
    else
    {
        BitmapCov::branchBitmap[1] = 1;
        if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(rtb_CVdt_cmd < -1.0, 2, 1, 1), -3, 0, 1)) {
            BitmapCov::branchBitmap[2] = 1;
            rtb_CVdt_cmd = -1.0;
        }
        BitmapCov::branchBitmap[3] = 1;
    }
    rtb_CVdt_cmd = 0.0 * regs_12B_DW->Memory_PreviousInput * -0.2 + rtb_CVdt_cmd * regs_12B_ConstB.Sum7;
    regs_12B_DW->UnitDelay1_DSTATE += (rtb_CVdt_cmd + regs_12B_DW->UnitDelay_DSTATE) * 0.5 * 2.0;
    if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(regs_12B_DW->UnitDelay1_DSTATE > regs_12B_ConstB.Switch1, 4, 1, 2), -5, 0, 2)) {
        BitmapCov::branchBitmap[4] = 1;
        regs_12B_DW->UnitDelay1_DSTATE = regs_12B_ConstB.Switch1;
    }
    else
    {
        BitmapCov::branchBitmap[5] = 1;
        if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(regs_12B_DW->UnitDelay1_DSTATE < regs_12B_ConstB.Switch2, 6, 1, 3), -7, 0, 3)) {
            BitmapCov::branchBitmap[6] = 1;
            regs_12B_DW->UnitDelay1_DSTATE = regs_12B_ConstB.Switch2;
        }
        BitmapCov::branchBitmap[7] = 1;
    }
    *regs_12B_Y_hcvdt_cmd_fcs_fps2 = 0.25 * regs_12B_DW->UnitDelay1_DSTATE + rtb_CVdt_cmd;
    rtb_Sum3 = regs_12B_U_mcv_cmd_fcs_dps - regs_12B_U_mcv_fcs_dps;
    regs_12B_DW->UnitDelay1_DSTATE_k += (rtb_Sum3 + regs_12B_DW->UnitDelay_DSTATE_o) * 0.5 * 2.0;
    if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(regs_12B_DW->UnitDelay1_DSTATE_k > regs_12B_ConstB.Switch1_p, 8, 1, 4), -9, 0, 4)) {
        BitmapCov::branchBitmap[8] = 1;
        regs_12B_DW->UnitDelay1_DSTATE_k = regs_12B_ConstB.Switch1_p;
    }
    else
    {
        BitmapCov::branchBitmap[9] = 1;
        if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(regs_12B_DW->UnitDelay1_DSTATE_k < regs_12B_ConstB.Switch2_d, 10, 1, 5), -11, 0, 5)) {
            BitmapCov::branchBitmap[10] = 1;
            regs_12B_DW->UnitDelay1_DSTATE_k = regs_12B_ConstB.Switch2_d;
        }
        BitmapCov::branchBitmap[11] = 1;
    }
    *regs_12B_Y_mcvdt_cmd_fcs_dps2 = rt_Lookup(regs_12B_ConstP.transition_bvr_XData, 2, regs_12B_U_vtas_adc_kts, regs_12B_ConstP.transition_bvr_YData) * rtb_Sum3 + 5.0 * regs_12B_DW->UnitDelay1_DSTATE_k;
    *regs_12B_Y_xcvdt_cmd_fcs_fps2 = (regs_12B_U_xcv_cmd_fcs_fps - (-regs_12B_U_dcv_fcs_fps)) * 0.5;
    regs_12B_DW->Memory_PreviousInput = regs_12B_DW->UnitDelay1_DSTATE;
    regs_12B_DW->UnitDelay_DSTATE = rtb_CVdt_cmd;
    regs_12B_DW->UnitDelay_DSTATE_o = rtb_Sum3;
}
/* Init function of "regs_12B.Func" */
void regs_12B_init(RT_MODEL_regs_12B_T* regs_12B_M, real_T* regs_12B_U_beta_adc_deg, real_T* regs_12B_U_vtas_adc_kts, real_T* regs_12B_U_lcv_cmd_fcs_dps, real_T* regs_12B_U_hdg_des_deg, real_T* regs_12B_U_mcv_cmd_fcs_dps, real_T* regs_12B_U_alt_des_ft, real_T* regs_12B_U_ncv_cmd_fcs_dps, real_T* regs_12B_U_xcv_cmd_fcs_fps, real_T* regs_12B_U_airspeed_des_fps, real_T* regs_12B_U_hcv_cmd_fcs_fps, real_T* regs_12B_U_lcv_fps_dps, real_T* regs_12B_U_mcv_fcs_dps, real_T* regs_12B_U_ncv_fcs_dps, real_T* regs_12B_U_dcv_fcs_fps, real_T* regs_12B_U_zcv_fcs_fps, real_T* regs_12B_U_beta_dot, real_T* regs_12B_Y_lcvdt_cmd_fcs_dps2, real_T* regs_12B_Y_mcvdt_cmd_fcs_dps2, real_T* regs_12B_Y_ncvdt_cmd_fcs_dps2, real_T* regs_12B_Y_xcvdt_cmd_fcs_fps2, real_T* regs_12B_Y_hcvdt_cmd_fcs_fps2) {
    BitmapCov::munitBitmap[1] = 1;
    /* Calculate code of  */
    struct DW_regs_12B_T * regs_12B_DW = ((DW_regs_12B_T*)regs_12B_M->dwork);
    (void)memset((void*)regs_12B_DW, 0, sizeof(DW_regs_12B_T));
    *regs_12B_U_beta_adc_deg = 0.0;
    *regs_12B_U_vtas_adc_kts = 0.0;
    *regs_12B_U_lcv_cmd_fcs_dps = 0.0;
    *regs_12B_U_hdg_des_deg = 0.0;
    *regs_12B_U_mcv_cmd_fcs_dps = 0.0;
    *regs_12B_U_alt_des_ft = 0.0;
    *regs_12B_U_ncv_cmd_fcs_dps = 0.0;
    *regs_12B_U_xcv_cmd_fcs_fps = 0.0;
    *regs_12B_U_airspeed_des_fps = 0.0;
    *regs_12B_U_hcv_cmd_fcs_fps = 0.0;
    *regs_12B_U_lcv_fps_dps = 0.0;
    *regs_12B_U_mcv_fcs_dps = 0.0;
    *regs_12B_U_ncv_fcs_dps = 0.0;
    *regs_12B_U_dcv_fcs_fps = 0.0;
    *regs_12B_U_zcv_fcs_fps = 0.0;
    *regs_12B_U_beta_dot = 0.0;
    (*regs_12B_Y_lcvdt_cmd_fcs_dps2) = 0.0;
    (*regs_12B_Y_mcvdt_cmd_fcs_dps2) = 0.0;
    (*regs_12B_Y_ncvdt_cmd_fcs_dps2) = 0.0;
    (*regs_12B_Y_xcvdt_cmd_fcs_fps2) = 0.0;
    (*regs_12B_Y_hcvdt_cmd_fcs_fps2) = 0.0;
}