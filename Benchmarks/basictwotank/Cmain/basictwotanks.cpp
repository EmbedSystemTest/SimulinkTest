#include "define.h"
/* Code of basictwotanks */
/* Update function of "basictwotanks.Func" */
void basictwotanks_step(RT_MODEL_basictwotanks_T* basictwotanks_M, real_T* basictwotanks_Y_t1_h, real_T* basictwotanks_Y_t2_h, real_T* basictwotanks_Y_t1_sh, real_T* basictwotanks_Y_t1_sl, real_T* basictwotanks_Y_t2_sh, real_T* basictwotanks_Y_t2_sm, real_T* basictwotanks_Y_t2_sl, real_T* basictwotanks_Y_pump_state, real_T* basictwotanks_Y_valve_state, real_T* basictwotanks_Y_p_valve_state, real_T* basictwotanks_Y_e_valve_state) {
    BitmapCov::munitBitmap[0] = 1;
    /* Calculate code of  */
    struct DW_basictwotanks_T * basictwotanks_DW = basictwotanks_M->dwork;
    real_T rtb_Switch4_idx_0;
    real_T rtb_Switch4_idx_1;
    real_T rtb_Switch_i;
    real_T rtb_tank1_previous_height_m;
    real_T rtb_tank2_previous_height_m;
    int32_T rtb_Switch;
    int32_T rtb_Switch_b;
    int32_T rtb_Switch_j;
    int32_T rtb_Switch_k;
    int32_T rtb_Switch_m;
    boolean_T rtb_Compare_dl;
    boolean_T rtb_LogicalOperator3;
    if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(basictwotanks_DW->UnitDelay_DSTATE_j > 0.0, 0, 1, 0), -1, 0, 0)) {
        BitmapCov::branchBitmap[0] = 1;
        rtb_Switch_i = 1.2647;
    }
    else
    {
        BitmapCov::branchBitmap[1] = 1;
        rtb_Switch_i = 0.0;
    }
    rtb_tank1_previous_height_m = rtb_Switch_i + *basictwotanks_Y_t1_h;
    rtb_Switch_k = !(2.0 > rtb_tank1_previous_height_m);
    rtb_Switch = !(5.0 > rtb_tank1_previous_height_m);
    if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(rtb_Switch_k != 1, 2, 1, 1), -3, 0, 1)) {
        BitmapCov::branchBitmap[2] = 1;
        basictwotanks_DW->Pump_State_Delay_DSTATE = 1.0;
        *basictwotanks_Y_valve_state = 0.0;
    }
    else if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(rtb_Switch == 1, 4, 1, 2), -5, 0, 2)) {
        BitmapCov::branchBitmap[3] = 1;
        basictwotanks_DW->Pump_State_Delay_DSTATE = 0.0;
        *basictwotanks_Y_valve_state = 1.0;
    }
    else
    {
        BitmapCov::branchBitmap[4] = 1;
        *basictwotanks_Y_valve_state = basictwotanks_DW->Valve_State_Delay_DSTATE;
    }
    *basictwotanks_Y_pump_state = basictwotanks_DW->Pump_State_Delay_DSTATE;
    if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(basictwotanks_DW->UnitDelay_DSTATE_c > 0.0, 6, 1, 3), -7, 0, 3)) {
        BitmapCov::branchBitmap[5] = 1;
        rtb_Switch_i = 0.09754;
    }
    else
    {
        BitmapCov::branchBitmap[6] = 1;
        rtb_Switch_i = 0.0;
    }
    rtb_tank2_previous_height_m = rtb_Switch_i + *basictwotanks_Y_t2_h;
    rtb_Switch_j = !(2.0 > rtb_tank2_previous_height_m);
    rtb_Switch_m = !(3.0 > rtb_tank2_previous_height_m);
    rtb_Switch_b = !(1.0 > rtb_tank2_previous_height_m);
    if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(rtb_Switch_b != 1, 8, 1, 4), -9, 0, 4)) {
        BitmapCov::branchBitmap[7] = 1;
        basictwotanks_DW->Production_Valve_State_Delay_DS = 0.0;
        basictwotanks_DW->Emergency_Valve_State_Delay_DST = 0.0;
    }
    else if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord((!(basictwotanks_DW->Emergency_Valve_State_Delay_DST == 1.0)), 10, 1, 5)&&BitmapCov::CondAndMCDCRecord((!(basictwotanks_DW->Production_Valve_State_Delay_DS == 1.0)), 12, 2, 5), -11, 0, 5)) {
        BitmapCov::branchBitmap[8] = 1;
        basictwotanks_DW->Production_Valve_State_Delay_DS = 1.0;
        basictwotanks_DW->Emergency_Valve_State_Delay_DST = 0.0;
    }
    else
    {
        BitmapCov::branchBitmap[9] = 1;
        rtb_Compare_dl = (rtb_Switch_m == 1);
        if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(rtb_Compare_dl, 14, 1, 6)&&BitmapCov::CondAndMCDCRecord(((!(basictwotanks_DW->Emergency_Valve_State_Delay_DST == 1.0)) && (basictwotanks_DW->Production_Valve_State_Delay_DS == 1.0)), 16, 2, 6), -13, 0, 6)) {
            BitmapCov::branchBitmap[10] = 1;
            basictwotanks_DW->Production_Valve_State_Delay_DS = 1.0;
            basictwotanks_DW->Emergency_Valve_State_Delay_DST = 1.0;
        }
        else
        {
            BitmapCov::branchBitmap[11] = 1;
            rtb_LogicalOperator3 = ((basictwotanks_DW->Emergency_Valve_State_Delay_DST == 1.0) && (basictwotanks_DW->Production_Valve_State_Delay_DS == 1.0));
            if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord((!(basictwotanks_DW->Valve_State_Delay_DSTATE == 1.0)), 18, 1, 7)&&BitmapCov::CondAndMCDCRecord(((!rtb_Compare_dl) && rtb_LogicalOperator3), 20, 2, 7), -15, 0, 7)) {
                BitmapCov::branchBitmap[12] = 1;
                basictwotanks_DW->Production_Valve_State_Delay_DS = 1.0;
                basictwotanks_DW->Emergency_Valve_State_Delay_DST = 0.0;
            }
            else if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(rtb_LogicalOperator3, 22, 1, 8)&&BitmapCov::CondAndMCDCRecord((rtb_Switch_j != 1), 24, 2, 8), -17, 0, 8)) {
                BitmapCov::branchBitmap[13] = 1;
                basictwotanks_DW->Production_Valve_State_Delay_DS = 1.0;
                basictwotanks_DW->Emergency_Valve_State_Delay_DST = 0.0;
            }
            BitmapCov::branchBitmap[14] = 1;
        }
    }
    *basictwotanks_Y_p_valve_state = basictwotanks_DW->Production_Valve_State_Delay_DS;
    *basictwotanks_Y_e_valve_state = basictwotanks_DW->Emergency_Valve_State_Delay_DST;
    if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(*basictwotanks_Y_valve_state > 0.5, 26, 1, 9), -19, 0, 9)) {
        BitmapCov::branchBitmap[15] = 1;
        rtb_Switch_i = basictwotanks_ConstB.Product_h;
    }
    else
    {
        BitmapCov::branchBitmap[16] = 1;
        rtb_Switch_i = 0.0;
    }
    if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(basictwotanks_DW->Production_Valve_State_Delay_DS > 0.5, 28, 1, 10), -21, 0, 10)) {
        BitmapCov::branchBitmap[17] = 1;
        rtb_Switch4_idx_0 = basictwotanks_ConstB.Product_g;
    }
    else
    {
        BitmapCov::branchBitmap[18] = 1;
        rtb_Switch4_idx_0 = 0.0;
    }
    if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(basictwotanks_DW->Emergency_Valve_State_Delay_DST > 0.5, 30, 1, 11), -23, 0, 11)) {
        BitmapCov::branchBitmap[19] = 1;
        rtb_Switch4_idx_1 = basictwotanks_ConstB.Product;
    }
    else
    {
        BitmapCov::branchBitmap[20] = 1;
        rtb_Switch4_idx_1 = 0.0;
    }
    *basictwotanks_Y_t2_h = ((rtb_Switch_i - rtb_Switch4_idx_0) - rtb_Switch4_idx_1) / 2.0 + rtb_tank2_previous_height_m;
    if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(basictwotanks_DW->Pump_State_Delay_DSTATE > 0.5, 32, 1, 12), -25, 0, 12)) {
        BitmapCov::branchBitmap[21] = 1;
        rtb_tank2_previous_height_m = basictwotanks_ConstB.Product_p;
    }
    else
    {
        BitmapCov::branchBitmap[22] = 1;
        rtb_tank2_previous_height_m = 0.0;
    }
    *basictwotanks_Y_t1_h = (rtb_tank2_previous_height_m - rtb_Switch_i) + rtb_tank1_previous_height_m;
    *basictwotanks_Y_t2_sl = rtb_Switch_b;
    *basictwotanks_Y_t2_sh = rtb_Switch_m;
    *basictwotanks_Y_t2_sm = rtb_Switch_j;
    *basictwotanks_Y_t1_sh = rtb_Switch;
    *basictwotanks_Y_t1_sl = rtb_Switch_k;
    basictwotanks_DW->Valve_State_Delay_DSTATE = *basictwotanks_Y_valve_state;
    basictwotanks_DW->UnitDelay_DSTATE_j = 0.0;
    basictwotanks_DW->UnitDelay_DSTATE_c = 0.0;
}
/* Init function of "basictwotanks.Func" */
void basictwotanks_init(RT_MODEL_basictwotanks_T* basictwotanks_M, real_T* basictwotanks_Y_t1_h, real_T* basictwotanks_Y_t2_h, real_T* basictwotanks_Y_t1_sh, real_T* basictwotanks_Y_t1_sl, real_T* basictwotanks_Y_t2_sh, real_T* basictwotanks_Y_t2_sm, real_T* basictwotanks_Y_t2_sl, real_T* basictwotanks_Y_pump_state, real_T* basictwotanks_Y_valve_state, real_T* basictwotanks_Y_p_valve_state, real_T* basictwotanks_Y_e_valve_state) {
    BitmapCov::munitBitmap[1] = 1;
    /* Calculate code of  */
    struct DW_basictwotanks_T * basictwotanks_DW = basictwotanks_M->dwork;
    (void)memset((void*)basictwotanks_DW, 0, sizeof(DW_basictwotanks_T));
    *basictwotanks_Y_t1_h = 0.0;
    *basictwotanks_Y_t2_h = 0.0;
    *basictwotanks_Y_t1_sh = 0.0;
    *basictwotanks_Y_t1_sl = 0.0;
    *basictwotanks_Y_t2_sh = 0.0;
    *basictwotanks_Y_t2_sm = 0.0;
    *basictwotanks_Y_t2_sl = 0.0;
    *basictwotanks_Y_pump_state = 0.0;
    *basictwotanks_Y_valve_state = 0.0;
    *basictwotanks_Y_p_valve_state = 0.0;
    *basictwotanks_Y_e_valve_state = 0.0;
    basictwotanks_DW->UnitDelay_DSTATE_j = 1.0;
    basictwotanks_DW->UnitDelay_DSTATE_c = 1.0;
}