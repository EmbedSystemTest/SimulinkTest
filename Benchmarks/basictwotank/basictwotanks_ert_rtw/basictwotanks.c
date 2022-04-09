/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: basictwotanks.c
 *
 * Code generated for Simulink model 'basictwotanks'.
 *
 * Model version                  : 1.170
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Mon Apr  4 06:19:26 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "basictwotanks.h"
#include "basictwotanks_private.h"

/* Model step function */
void basictwotanks_step(RT_MODEL_basictwotanks_T *const basictwotanks_M, real_T *
  basictwotanks_Y_t1_h, real_T *basictwotanks_Y_t2_h, real_T
  *basictwotanks_Y_t1_sh, real_T *basictwotanks_Y_t1_sl, real_T
  *basictwotanks_Y_t2_sh, real_T *basictwotanks_Y_t2_sm, real_T
  *basictwotanks_Y_t2_sl, real_T *basictwotanks_Y_pump_state, real_T
  *basictwotanks_Y_valve_state, real_T *basictwotanks_Y_p_valve_state, real_T
  *basictwotanks_Y_e_valve_state)
{
  DW_basictwotanks_T *basictwotanks_DW = basictwotanks_M->dwork;
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

  /* Switch: '<S33>/Switch' incorporates:
   *  Constant: '<S31>/tank1_init_height_m'
   *  Constant: '<S33>/Constant'
   *  UnitDelay: '<S33>/Unit Delay'
   */
  if (basictwotanks_DW->UnitDelay_DSTATE_j > 0.0) {
    rtb_Switch_i = 1.2647;
  } else {
    rtb_Switch_i = 0.0;
  }

  /* End of Switch: '<S33>/Switch' */

  /* Sum: '<S4>/Sum' incorporates:
   *  Delay: '<S4>/Liquid_Height_Delay_Tank1'
   */
  rtb_tank1_previous_height_m = rtb_Switch_i + *basictwotanks_Y_t1_h;

  /* Switch: '<S25>/Switch' incorporates:
   *  Constant: '<S1>/tank1_sensor_lo_height_m_constant'
   *  RelationalOperator: '<S25>/Relational Operator'
   */
  rtb_Switch_k = !(2.0 > rtb_tank1_previous_height_m);

  /* Switch: '<S23>/Switch' incorporates:
   *  Constant: '<S1>/tank1_sensor_hi_height_m_constant'
   *  RelationalOperator: '<S23>/Relational Operator'
   */
  rtb_Switch = !(5.0 > rtb_tank1_previous_height_m);

  /* Switch: '<S10>/Switch3' incorporates:
   *  Constant: '<S10>/Constant2'
   *  Constant: '<S10>/Constant3'
   *  Constant: '<S5>/Constant'
   *  Constant: '<S6>/Constant'
   *  Logic: '<S10>/Logical Operator2'
   *  RelationalOperator: '<S5>/Compare'
   *  RelationalOperator: '<S6>/Compare'
   *  Switch: '<S10>/Switch2'
   */
  if (rtb_Switch_k != 1) {
    basictwotanks_DW->Pump_State_Delay_DSTATE = 1.0;
    *basictwotanks_Y_valve_state = 0.0;
  } else if (rtb_Switch == 1) {
    /* Switch: '<S10>/Switch2' incorporates:
     *  Constant: '<S10>/Constant'
     *  Constant: '<S10>/Constant1'
     */
    basictwotanks_DW->Pump_State_Delay_DSTATE = 0.0;
    *basictwotanks_Y_valve_state = 1.0;
  } else {
    /* Switch: '<S10>/Switch' incorporates:
     *  Switch: '<S10>/Switch2'
     */
    *basictwotanks_Y_valve_state = basictwotanks_DW->Valve_State_Delay_DSTATE;
  }

  /* End of Switch: '<S10>/Switch3' */

  /* Outport: '<Root>/pump_state' */
  *basictwotanks_Y_pump_state = basictwotanks_DW->Pump_State_Delay_DSTATE;

  /* Switch: '<S32>/Switch' incorporates:
   *  Constant: '<S31>/tank2_init_height_m'
   *  Constant: '<S32>/Constant'
   *  UnitDelay: '<S32>/Unit Delay'
   */
  if (basictwotanks_DW->UnitDelay_DSTATE_c > 0.0) {
    rtb_Switch_i = 0.09754;
  } else {
    rtb_Switch_i = 0.0;
  }

  /* End of Switch: '<S32>/Switch' */

  /* Sum: '<S4>/Sum1' incorporates:
   *  Delay: '<S4>/Liquid_Height_Delay_Tank2'
   */
  rtb_tank2_previous_height_m = rtb_Switch_i + *basictwotanks_Y_t2_h;

  /* Switch: '<S26>/Switch' incorporates:
   *  Constant: '<S1>/tank2_sensor_md_height_m_constant'
   *  RelationalOperator: '<S26>/Relational Operator'
   */
  rtb_Switch_j = !(2.0 > rtb_tank2_previous_height_m);

  /* Switch: '<S22>/Switch' incorporates:
   *  Constant: '<S1>/tank2_sensor_hi_height_m_constant'
   *  RelationalOperator: '<S22>/Relational Operator'
   */
  rtb_Switch_m = !(3.0 > rtb_tank2_previous_height_m);

  /* Switch: '<S24>/Switch' incorporates:
   *  Constant: '<S1>/tank2_sensor_lo_height_m_constant'
   *  RelationalOperator: '<S24>/Relational Operator'
   */
  rtb_Switch_b = !(1.0 > rtb_tank2_previous_height_m);

  /* Switch: '<S11>/Switch4' incorporates:
   *  Constant: '<S17>/Constant'
   *  Constant: '<S18>/Constant'
   *  Constant: '<S9>/Constant'
   *  Logic: '<S11>/Logical Operator12'
   *  Logic: '<S11>/Logical Operator13'
   *  Logic: '<S11>/Logical Operator14'
   *  Logic: '<S11>/Logical Operator15'
   *  RelationalOperator: '<S17>/Compare'
   *  RelationalOperator: '<S18>/Compare'
   *  RelationalOperator: '<S9>/Compare'
   *  Switch: '<S11>/Switch1'
   */
  if (rtb_Switch_b != 1) {
    /* Sum: '<S4>/Sum6' incorporates:
     *  Constant: '<S11>/Constant8'
     */
    basictwotanks_DW->Production_Valve_State_Delay_DS = 0.0;

    /* Sum: '<S4>/Sum7' incorporates:
     *  Constant: '<S11>/Constant9'
     */
    basictwotanks_DW->Emergency_Valve_State_Delay_DST = 0.0;
  } else if ((!(basictwotanks_DW->Emergency_Valve_State_Delay_DST == 1.0)) &&
             (!(basictwotanks_DW->Production_Valve_State_Delay_DS == 1.0))) {
    /* Sum: '<S4>/Sum6' incorporates:
     *  Constant: '<S11>/Constant6'
     *  Switch: '<S11>/Switch1'
     */
    basictwotanks_DW->Production_Valve_State_Delay_DS = 1.0;

    /* Sum: '<S4>/Sum7' incorporates:
     *  Constant: '<S11>/Constant7'
     *  Switch: '<S11>/Switch1'
     */
    basictwotanks_DW->Emergency_Valve_State_Delay_DST = 0.0;
  } else {
    /* RelationalOperator: '<S7>/Compare' incorporates:
     *  Constant: '<S7>/Constant'
     *  Switch: '<S11>/Switch1'
     */
    rtb_Compare_dl = (rtb_Switch_m == 1);

    /* Switch: '<S11>/Switch3' incorporates:
     *  Constant: '<S15>/Constant'
     *  Constant: '<S16>/Constant'
     *  Logic: '<S11>/Logical Operator10'
     *  Logic: '<S11>/Logical Operator8'
     *  Logic: '<S11>/Logical Operator9'
     *  RelationalOperator: '<S15>/Compare'
     *  RelationalOperator: '<S16>/Compare'
     *  Switch: '<S11>/Switch1'
     */
    if (rtb_Compare_dl && ((!(basictwotanks_DW->Emergency_Valve_State_Delay_DST ==
           1.0)) && (basictwotanks_DW->Production_Valve_State_Delay_DS == 1.0)))
    {
      /* Sum: '<S4>/Sum6' incorporates:
       *  Constant: '<S11>/Constant2'
       */
      basictwotanks_DW->Production_Valve_State_Delay_DS = 1.0;

      /* Sum: '<S4>/Sum7' incorporates:
       *  Constant: '<S11>/Constant3'
       */
      basictwotanks_DW->Emergency_Valve_State_Delay_DST = 1.0;
    } else {
      /* Logic: '<S11>/Logical Operator3' incorporates:
       *  Constant: '<S13>/Constant'
       *  Constant: '<S14>/Constant'
       *  RelationalOperator: '<S13>/Compare'
       *  RelationalOperator: '<S14>/Compare'
       */
      rtb_LogicalOperator3 = ((basictwotanks_DW->Emergency_Valve_State_Delay_DST
        == 1.0) && (basictwotanks_DW->Production_Valve_State_Delay_DS == 1.0));

      /* Switch: '<S11>/Switch2' incorporates:
       *  Constant: '<S12>/Constant'
       *  Constant: '<S8>/Constant'
       *  Logic: '<S11>/Logical Operator1'
       *  Logic: '<S11>/Logical Operator2'
       *  Logic: '<S11>/Logical Operator4'
       *  Logic: '<S11>/Logical Operator5'
       *  Logic: '<S11>/Logical Operator6'
       *  Logic: '<S11>/Logical Operator7'
       *  RelationalOperator: '<S12>/Compare'
       *  RelationalOperator: '<S8>/Compare'
       *  Switch: '<S11>/Switch'
       */
      if ((!(basictwotanks_DW->Valve_State_Delay_DSTATE == 1.0)) &&
          ((!rtb_Compare_dl) && rtb_LogicalOperator3)) {
        /* Sum: '<S4>/Sum6' incorporates:
         *  Constant: '<S11>/Constant'
         */
        basictwotanks_DW->Production_Valve_State_Delay_DS = 1.0;

        /* Sum: '<S4>/Sum7' incorporates:
         *  Constant: '<S11>/Constant1'
         */
        basictwotanks_DW->Emergency_Valve_State_Delay_DST = 0.0;
      } else if (rtb_LogicalOperator3 && (rtb_Switch_j != 1)) {
        /* Sum: '<S4>/Sum6' incorporates:
         *  Constant: '<S11>/Constant4'
         *  Switch: '<S11>/Switch'
         */
        basictwotanks_DW->Production_Valve_State_Delay_DS = 1.0;

        /* Sum: '<S4>/Sum7' incorporates:
         *  Constant: '<S11>/Constant5'
         *  Switch: '<S11>/Switch'
         */
        basictwotanks_DW->Emergency_Valve_State_Delay_DST = 0.0;
      }

      /* End of Switch: '<S11>/Switch2' */
    }

    /* End of Switch: '<S11>/Switch3' */
  }

  /* End of Switch: '<S11>/Switch4' */

  /* Outport: '<Root>/p_valve_state' */
  *basictwotanks_Y_p_valve_state =
    basictwotanks_DW->Production_Valve_State_Delay_DS;

  /* Outport: '<Root>/e_valve_state' */
  *basictwotanks_Y_e_valve_state =
    basictwotanks_DW->Emergency_Valve_State_Delay_DST;

  /* Switch: '<S29>/Switch' incorporates:
   *  Constant: '<S29>/Constant1'
   *  Constant: '<S29>/Constant2'
   *  RelationalOperator: '<S29>/Relational Operator'
   */
  if (*basictwotanks_Y_valve_state > 0.5) {
    rtb_Switch_i = basictwotanks_ConstB.Product_h;
  } else {
    rtb_Switch_i = 0.0;
  }

  /* End of Switch: '<S29>/Switch' */

  /* Switch: '<S20>/Switch' incorporates:
   *  Constant: '<S20>/Constant1'
   *  Constant: '<S20>/Constant2'
   *  RelationalOperator: '<S20>/Relational Operator'
   */
  if (basictwotanks_DW->Production_Valve_State_Delay_DS > 0.5) {
    rtb_Switch4_idx_0 = basictwotanks_ConstB.Product_g;
  } else {
    rtb_Switch4_idx_0 = 0.0;
  }

  /* End of Switch: '<S20>/Switch' */

  /* Switch: '<S19>/Switch' incorporates:
   *  Constant: '<S19>/Constant1'
   *  Constant: '<S19>/Constant2'
   *  RelationalOperator: '<S19>/Relational Operator'
   */
  if (basictwotanks_DW->Emergency_Valve_State_Delay_DST > 0.5) {
    rtb_Switch4_idx_1 = basictwotanks_ConstB.Product;
  } else {
    rtb_Switch4_idx_1 = 0.0;
  }

  /* End of Switch: '<S19>/Switch' */

  /* Sum: '<S28>/Sum' incorporates:
   *  Constant: '<S1>/tank2_cross_section_area_m2_constant'
   *  Delay: '<S4>/Liquid_Height_Delay_Tank2'
   *  Product: '<S28>/Divide'
   *  Sum: '<S28>/Sum1'
   *  Sum: '<S28>/Sum2'
   */
  *basictwotanks_Y_t2_h = ((rtb_Switch_i - rtb_Switch4_idx_0) -
    rtb_Switch4_idx_1) / 2.0 + rtb_tank2_previous_height_m;

  /* Switch: '<S21>/Switch' incorporates:
   *  Constant: '<S21>/Constant1'
   *  Constant: '<S21>/Constant2'
   *  RelationalOperator: '<S21>/Relational Operator'
   */
  if (basictwotanks_DW->Pump_State_Delay_DSTATE > 0.5) {
    rtb_tank2_previous_height_m = basictwotanks_ConstB.Product_p;
  } else {
    rtb_tank2_previous_height_m = 0.0;
  }

  /* End of Switch: '<S21>/Switch' */

  /* Sum: '<S27>/Sum' incorporates:
   *  Delay: '<S4>/Liquid_Height_Delay_Tank1'
   *  Sum: '<S27>/Sum1'
   */
  *basictwotanks_Y_t1_h = (rtb_tank2_previous_height_m - rtb_Switch_i) +
    rtb_tank1_previous_height_m;

  /* Outport: '<Root>/t2_sl' */
  *basictwotanks_Y_t2_sl = rtb_Switch_b;

  /* Outport: '<Root>/t2_sh' */
  *basictwotanks_Y_t2_sh = rtb_Switch_m;

  /* Outport: '<Root>/t2_sm' */
  *basictwotanks_Y_t2_sm = rtb_Switch_j;

  /* Outport: '<Root>/t1_sh' */
  *basictwotanks_Y_t1_sh = rtb_Switch;

  /* Outport: '<Root>/t1_sl' */
  *basictwotanks_Y_t1_sl = rtb_Switch_k;

  /* Update for Sum: '<S4>/Sum9' incorporates:
   *  Delay: '<S4>/Valve_State_Delay'
   */
  basictwotanks_DW->Valve_State_Delay_DSTATE = *basictwotanks_Y_valve_state;

  /* Update for UnitDelay: '<S33>/Unit Delay' incorporates:
   *  Constant: '<S33>/Constant'
   */
  basictwotanks_DW->UnitDelay_DSTATE_j = 0.0;

  /* Update for UnitDelay: '<S32>/Unit Delay' incorporates:
   *  Constant: '<S32>/Constant'
   */
  basictwotanks_DW->UnitDelay_DSTATE_c = 0.0;
}

/* Model initialize function */
void basictwotanks_initialize(RT_MODEL_basictwotanks_T *const basictwotanks_M,
  real_T *basictwotanks_Y_t1_h, real_T *basictwotanks_Y_t2_h, real_T
  *basictwotanks_Y_t1_sh, real_T *basictwotanks_Y_t1_sl, real_T
  *basictwotanks_Y_t2_sh, real_T *basictwotanks_Y_t2_sm, real_T
  *basictwotanks_Y_t2_sl, real_T *basictwotanks_Y_pump_state, real_T
  *basictwotanks_Y_valve_state, real_T *basictwotanks_Y_p_valve_state, real_T
  *basictwotanks_Y_e_valve_state)
{
  DW_basictwotanks_T *basictwotanks_DW = basictwotanks_M->dwork;

  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)basictwotanks_DW, 0,
                sizeof(DW_basictwotanks_T));

  /* external outputs */
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

  /* InitializeConditions for UnitDelay: '<S33>/Unit Delay' */
  basictwotanks_DW->UnitDelay_DSTATE_j = 1.0;

  /* InitializeConditions for UnitDelay: '<S32>/Unit Delay' */
  basictwotanks_DW->UnitDelay_DSTATE_c = 1.0;
}

/* Model terminate function */
void basictwotanks_terminate(RT_MODEL_basictwotanks_T *const basictwotanks_M)
{
  /* (no terminate code required) */
  UNUSED_PARAMETER(basictwotanks_M);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
