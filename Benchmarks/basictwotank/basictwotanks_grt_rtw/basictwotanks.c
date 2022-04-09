/*
 * basictwotanks.c
 *
 * Code generation for model "basictwotanks".
 *
 * Model version              : 1.170
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Fri Aug 27 11:03:15 2021
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "basictwotanks.h"
#include "basictwotanks_private.h"

/* Block states (default storage) */
DW_basictwotanks_T basictwotanks_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_basictwotanks_T basictwotanks_Y;

/* Real-time model */
RT_MODEL_basictwotanks_T basictwotanks_M_;
RT_MODEL_basictwotanks_T *const basictwotanks_M = &basictwotanks_M_;

/* Model step function */
void basictwotanks_step(void)
{
  /* local block i/o variables */
  real_T rtb_Switch3[2];
  real_T rtb_Sum;
  real_T rtb_pre_E_Valve_State;
  real_T rtb_Switch_b;
  real_T rtb_Switch_m;
  real_T rtb_Switch4[2];
  real_T rtb_Sum_k;
  real_T rtb_Switch_ee;
  int32_T rtb_Switch_l;
  boolean_T rtb_Compare;
  real_T rtb_Switch_i;
  real_T rtb_tank2_previous_height_m;
  int32_T rtb_Switch;
  boolean_T rtb_Compare_hg;
  real_T rtb_pre_P_Valve_State;
  real_T rtb_pre_Valve_State;

  /* Switch: '<S33>/Switch' incorporates:
   *  Constant: '<S31>/tank1_init_height_m'
   *  Constant: '<S33>/Constant'
   *  UnitDelay: '<S33>/Unit Delay'
   */
  if (basictwotanks_DW.UnitDelay_DSTATE > 0.0) {
    rtb_pre_P_Valve_State = 1.2647;
  } else {
    rtb_pre_P_Valve_State = 0.0;
  }

  /* End of Switch: '<S33>/Switch' */

  /* Sum: '<S4>/Sum' incorporates:
   *  Delay: '<S4>/Liquid_Height_Delay_Tank1'
   */
  rtb_Switch_ee = rtb_pre_P_Valve_State +
    basictwotanks_DW.Liquid_Height_Delay_Tank1_DSTAT;

  /* Switch: '<S25>/Switch' incorporates:
   *  Constant: '<S1>/tank1_sensor_lo_height_m_constant'
   *  RelationalOperator: '<S25>/Relational Operator'
   */
  rtb_Switch_l = !(2.0 > rtb_Switch_ee);

  /* Switch: '<S23>/Switch' incorporates:
   *  Constant: '<S1>/tank1_sensor_hi_height_m_constant'
   *  RelationalOperator: '<S23>/Relational Operator'
   */
  rtb_Switch = !(5.0 > rtb_Switch_ee);

  /* Sum: '<S4>/Sum9' incorporates:
   *  Delay: '<S4>/Valve_State_Delay'
   */
  rtb_pre_Valve_State = basictwotanks_DW.Valve_State_Delay_DSTATE;

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
  if (rtb_Switch_l != 1) {
    rtb_Switch3[0] = 1.0;
    rtb_Switch3[1] = 0.0;
  } else if (rtb_Switch == 1) {
    /* Switch: '<S10>/Switch2' incorporates:
     *  Constant: '<S10>/Constant'
     *  Constant: '<S10>/Constant1'
     */
    rtb_Switch3[0] = 0.0;
    rtb_Switch3[1] = 1.0;
  } else {
    /* Switch: '<S10>/Switch' incorporates:
     *  Delay: '<S4>/Pump_State_Delay'
     *  Switch: '<S10>/Switch2'
     */
    rtb_Switch3[0] = basictwotanks_DW.Pump_State_Delay_DSTATE;
    rtb_Switch3[1] = rtb_pre_Valve_State;
  }

  /* End of Switch: '<S10>/Switch3' */

  /* Switch: '<S29>/Switch' incorporates:
   *  Constant: '<S29>/Constant1'
   *  Constant: '<S29>/Constant2'
   *  RelationalOperator: '<S29>/Relational Operator'
   */
  if (rtb_Switch3[1] > 0.5) {
    rtb_Switch_i = basictwotanks_ConstB.Product_h;
  } else {
    rtb_Switch_i = 0.0;
  }

  /* End of Switch: '<S29>/Switch' */

  /* Switch: '<S21>/Switch' incorporates:
   *  Constant: '<S21>/Constant1'
   *  Constant: '<S21>/Constant2'
   *  RelationalOperator: '<S21>/Relational Operator'
   */
  if (rtb_Switch3[0] > 0.5) {
    rtb_pre_P_Valve_State = basictwotanks_ConstB.Product_p;
  } else {
    rtb_pre_P_Valve_State = 0.0;
  }

  /* End of Switch: '<S21>/Switch' */

  /* Sum: '<S27>/Sum' incorporates:
   *  Sum: '<S27>/Sum1'
   */
  rtb_Sum = (rtb_pre_P_Valve_State - rtb_Switch_i) + rtb_Switch_ee;

  /* Outport: '<Root>/t1_h' */
  basictwotanks_Y.t1_h = rtb_Sum;

  /* Switch: '<S32>/Switch' incorporates:
   *  Constant: '<S31>/tank2_init_height_m'
   *  Constant: '<S32>/Constant'
   *  UnitDelay: '<S32>/Unit Delay'
   */
  if (basictwotanks_DW.UnitDelay_DSTATE_c > 0.0) {
    rtb_pre_P_Valve_State = 0.09754;
  } else {
    rtb_pre_P_Valve_State = 0.0;
  }

  /* End of Switch: '<S32>/Switch' */

  /* Sum: '<S4>/Sum1' incorporates:
   *  Delay: '<S4>/Liquid_Height_Delay_Tank2'
   */
  rtb_tank2_previous_height_m = rtb_pre_P_Valve_State +
    basictwotanks_DW.Liquid_Height_Delay_Tank2_DSTAT;

  /* Switch: '<S24>/Switch' incorporates:
   *  Constant: '<S1>/tank2_sensor_lo_height_m_constant'
   *  RelationalOperator: '<S24>/Relational Operator'
   */
  rtb_Switch_ee = !(1.0 > rtb_tank2_previous_height_m);

  /* Sum: '<S4>/Sum7' incorporates:
   *  Delay: '<S4>/Emergency_Valve_State_Delay'
   */
  rtb_pre_E_Valve_State = basictwotanks_DW.Emergency_Valve_State_Delay_DST;

  /* Switch: '<S22>/Switch' incorporates:
   *  Constant: '<S1>/tank2_sensor_hi_height_m_constant'
   *  RelationalOperator: '<S22>/Relational Operator'
   */
  rtb_Switch_b = !(3.0 > rtb_tank2_previous_height_m);

  /* Switch: '<S26>/Switch' incorporates:
   *  Constant: '<S1>/tank2_sensor_md_height_m_constant'
   *  RelationalOperator: '<S26>/Relational Operator'
   */
  rtb_Switch_m = !(2.0 > rtb_tank2_previous_height_m);

  /* Switch: '<S11>/Switch4' incorporates:
   *  Constant: '<S11>/Constant8'
   *  Constant: '<S11>/Constant9'
   *  Constant: '<S9>/Constant'
   *  Logic: '<S11>/Logical Operator15'
   *  RelationalOperator: '<S9>/Compare'
   */
  if (!(rtb_Switch_ee == 1.0)) {
    rtb_Switch4[0] = 0.0;
    rtb_Switch4[1] = 0.0;
  } else {
    /* Sum: '<S4>/Sum6' incorporates:
     *  Delay: '<S4>/Production_Valve_State_Delay'
     */
    rtb_pre_P_Valve_State = basictwotanks_DW.Production_Valve_State_Delay_DS;

    /* Switch: '<S11>/Switch1' incorporates:
     *  Constant: '<S11>/Constant6'
     *  Constant: '<S11>/Constant7'
     *  Constant: '<S17>/Constant'
     *  Constant: '<S18>/Constant'
     *  Logic: '<S11>/Logical Operator12'
     *  Logic: '<S11>/Logical Operator13'
     *  Logic: '<S11>/Logical Operator14'
     *  RelationalOperator: '<S17>/Compare'
     *  RelationalOperator: '<S18>/Compare'
     */
    if ((!(rtb_pre_E_Valve_State == 1.0)) && (!(rtb_pre_P_Valve_State == 1.0)))
    {
      rtb_Switch4[0] = 1.0;
      rtb_Switch4[1] = 0.0;
    } else {
      /* RelationalOperator: '<S7>/Compare' incorporates:
       *  Constant: '<S7>/Constant'
       */
      rtb_Compare = (rtb_Switch_b == 1.0);

      /* Switch: '<S11>/Switch3' incorporates:
       *  Constant: '<S11>/Constant2'
       *  Constant: '<S11>/Constant3'
       *  Constant: '<S15>/Constant'
       *  Constant: '<S16>/Constant'
       *  Logic: '<S11>/Logical Operator10'
       *  Logic: '<S11>/Logical Operator8'
       *  Logic: '<S11>/Logical Operator9'
       *  RelationalOperator: '<S15>/Compare'
       *  RelationalOperator: '<S16>/Compare'
       */
      if (rtb_Compare && ((!(rtb_pre_E_Valve_State == 1.0)) &&
                          (rtb_pre_P_Valve_State == 1.0))) {
        rtb_Switch4[0] = 1.0;
        rtb_Switch4[1] = 1.0;
      } else {
        /* Logic: '<S11>/Logical Operator3' incorporates:
         *  Constant: '<S13>/Constant'
         *  Constant: '<S14>/Constant'
         *  RelationalOperator: '<S13>/Compare'
         *  RelationalOperator: '<S14>/Compare'
         */
        rtb_Compare_hg = ((rtb_pre_E_Valve_State == 1.0) &&
                          (rtb_pre_P_Valve_State == 1.0));

        /* Switch: '<S11>/Switch2' incorporates:
         *  Constant: '<S11>/Constant'
         *  Constant: '<S11>/Constant1'
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
        if ((!(rtb_pre_Valve_State == 1.0)) && ((!rtb_Compare) && rtb_Compare_hg))
        {
          rtb_Switch4[0] = 1.0;
          rtb_Switch4[1] = 0.0;
        } else if (rtb_Compare_hg && (!(rtb_Switch_m == 1.0))) {
          /* Switch: '<S11>/Switch' incorporates:
           *  Constant: '<S11>/Constant4'
           *  Constant: '<S11>/Constant5'
           */
          rtb_Switch4[0] = 1.0;
          rtb_Switch4[1] = 0.0;
        } else {
          rtb_Switch4[0] = rtb_pre_P_Valve_State;
          rtb_Switch4[1] = rtb_pre_E_Valve_State;
        }

        /* End of Switch: '<S11>/Switch2' */
      }

      /* End of Switch: '<S11>/Switch3' */
    }

    /* End of Switch: '<S11>/Switch1' */
  }

  /* End of Switch: '<S11>/Switch4' */

  /* Switch: '<S20>/Switch' incorporates:
   *  Constant: '<S20>/Constant1'
   *  Constant: '<S20>/Constant2'
   *  RelationalOperator: '<S20>/Relational Operator'
   */
  if (rtb_Switch4[0] > 0.5) {
    rtb_pre_P_Valve_State = basictwotanks_ConstB.Product_g;
  } else {
    rtb_pre_P_Valve_State = 0.0;
  }

  /* End of Switch: '<S20>/Switch' */

  /* Switch: '<S19>/Switch' incorporates:
   *  Constant: '<S19>/Constant1'
   *  Constant: '<S19>/Constant2'
   *  RelationalOperator: '<S19>/Relational Operator'
   */
  if (rtb_Switch4[1] > 0.5) {
    rtb_pre_Valve_State = basictwotanks_ConstB.Product;
  } else {
    rtb_pre_Valve_State = 0.0;
  }

  /* End of Switch: '<S19>/Switch' */

  /* Sum: '<S28>/Sum' incorporates:
   *  Constant: '<S1>/tank2_cross_section_area_m2_constant'
   *  Product: '<S28>/Divide'
   *  Sum: '<S28>/Sum1'
   *  Sum: '<S28>/Sum2'
   */
  rtb_Sum_k = ((rtb_Switch_i - rtb_pre_P_Valve_State) - rtb_pre_Valve_State) /
    2.0 + rtb_tank2_previous_height_m;

  /* Outport: '<Root>/t2_h' */
  basictwotanks_Y.t2_h = rtb_Sum_k;

  /* Outport: '<Root>/t1_sh' */
  basictwotanks_Y.t1_sh = rtb_Switch;

  /* Outport: '<Root>/t1_sl' */
  basictwotanks_Y.t1_sl = rtb_Switch_l;

  /* Outport: '<Root>/t2_sh' */
  basictwotanks_Y.t2_sh = rtb_Switch_b;

  /* Outport: '<Root>/t2_sm' */
  basictwotanks_Y.t2_sm = rtb_Switch_m;

  /* Outport: '<Root>/t2_sl' */
  basictwotanks_Y.t2_sl = rtb_Switch_ee;

  /* Outport: '<Root>/pump_state' */
  basictwotanks_Y.pump_state = rtb_Switch3[0];

  /* Outport: '<Root>/valve_state' */
  basictwotanks_Y.valve_state = rtb_Switch3[1];

  /* Outport: '<Root>/p_valve_state' */
  basictwotanks_Y.p_valve_state = rtb_Switch4[0];

  /* Outport: '<Root>/e_valve_state' */
  basictwotanks_Y.e_valve_state = rtb_Switch4[1];

  /* Update for UnitDelay: '<S33>/Unit Delay' incorporates:
   *  Constant: '<S33>/Constant'
   */
  basictwotanks_DW.UnitDelay_DSTATE = 0.0;

  /* Update for Delay: '<S4>/Liquid_Height_Delay_Tank1' */
  basictwotanks_DW.Liquid_Height_Delay_Tank1_DSTAT = rtb_Sum;

  /* Update for Delay: '<S4>/Pump_State_Delay' */
  basictwotanks_DW.Pump_State_Delay_DSTATE = rtb_Switch3[0];

  /* Update for Delay: '<S4>/Valve_State_Delay' */
  basictwotanks_DW.Valve_State_Delay_DSTATE = rtb_Switch3[1];

  /* Update for UnitDelay: '<S32>/Unit Delay' incorporates:
   *  Constant: '<S32>/Constant'
   */
  basictwotanks_DW.UnitDelay_DSTATE_c = 0.0;

  /* Update for Delay: '<S4>/Liquid_Height_Delay_Tank2' */
  basictwotanks_DW.Liquid_Height_Delay_Tank2_DSTAT = rtb_Sum_k;

  /* Update for Delay: '<S4>/Emergency_Valve_State_Delay' */
  basictwotanks_DW.Emergency_Valve_State_Delay_DST = rtb_Switch4[1];

  /* Update for Delay: '<S4>/Production_Valve_State_Delay' */
  basictwotanks_DW.Production_Valve_State_Delay_DS = rtb_Switch4[0];

  /* Matfile logging */
  rt_UpdateTXYLogVars(basictwotanks_M->rtwLogInfo,
                      (&basictwotanks_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.1s, 0.0s] */
    if ((rtmGetTFinal(basictwotanks_M)!=-1) &&
        !((rtmGetTFinal(basictwotanks_M)-basictwotanks_M->Timing.taskTime0) >
          basictwotanks_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(basictwotanks_M, "Simulation finished");
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
  if (!(++basictwotanks_M->Timing.clockTick0)) {
    ++basictwotanks_M->Timing.clockTickH0;
  }

  basictwotanks_M->Timing.taskTime0 = basictwotanks_M->Timing.clockTick0 *
    basictwotanks_M->Timing.stepSize0 + basictwotanks_M->Timing.clockTickH0 *
    basictwotanks_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void basictwotanks_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)basictwotanks_M, 0,
                sizeof(RT_MODEL_basictwotanks_T));
  rtmSetTFinal(basictwotanks_M, 12500.0);
  basictwotanks_M->Timing.stepSize0 = 0.1;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    basictwotanks_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(basictwotanks_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(basictwotanks_M->rtwLogInfo, (NULL));
    rtliSetLogT(basictwotanks_M->rtwLogInfo, "tout");
    rtliSetLogX(basictwotanks_M->rtwLogInfo, "");
    rtliSetLogXFinal(basictwotanks_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(basictwotanks_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(basictwotanks_M->rtwLogInfo, 2);
    rtliSetLogMaxRows(basictwotanks_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(basictwotanks_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &basictwotanks_Y.t1_h,
        &basictwotanks_Y.t2_h,
        &basictwotanks_Y.t1_sh,
        &basictwotanks_Y.t1_sl,
        &basictwotanks_Y.t2_sh,
        &basictwotanks_Y.t2_sm,
        &basictwotanks_Y.t2_sl,
        &basictwotanks_Y.pump_state,
        &basictwotanks_Y.valve_state,
        &basictwotanks_Y.p_valve_state,
        &basictwotanks_Y.e_valve_state
      };

      rtliSetLogYSignalPtrs(basictwotanks_M->rtwLogInfo, ((LogSignalPtrsType)
        rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
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
        0,
        0,
        0,
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4,
        4,
        4,
        4,
        4,
        4,
        4,
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
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0,
        0,
        0,
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
        (NULL),
        (NULL),
        (NULL),
        (NULL)
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "tank1_liquid_height_m",
        "tank2_liquid_height_m",
        "tank1_SH_value",
        "tank1_SL_value",
        "tank2_SH_value",
        "tank2_SM_value",
        "tank2_SL_value",
        "Pump_State",
        "Valve_State",
        "Production_Valve_State",
        "Emergency_Valve_State" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "basictwotanks/t1_h",
        "basictwotanks/t2_h",
        "basictwotanks/t1_sh",
        "basictwotanks/t1_sl",
        "basictwotanks/t2_sh",
        "basictwotanks/t2_sm",
        "basictwotanks/t2_sl",
        "basictwotanks/pump_state",
        "basictwotanks/valve_state",
        "basictwotanks/p_valve_state",
        "basictwotanks/e_valve_state" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          11,
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

      rtliSetLogYSignalInfo(basictwotanks_M->rtwLogInfo,
                            rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[1];
      rt_LoggedCurrentSignalDimensions[2] = &rt_LoggedOutputWidths[2];
      rt_LoggedCurrentSignalDimensions[3] = &rt_LoggedOutputWidths[3];
      rt_LoggedCurrentSignalDimensions[4] = &rt_LoggedOutputWidths[4];
      rt_LoggedCurrentSignalDimensions[5] = &rt_LoggedOutputWidths[5];
      rt_LoggedCurrentSignalDimensions[6] = &rt_LoggedOutputWidths[6];
      rt_LoggedCurrentSignalDimensions[7] = &rt_LoggedOutputWidths[7];
      rt_LoggedCurrentSignalDimensions[8] = &rt_LoggedOutputWidths[8];
      rt_LoggedCurrentSignalDimensions[9] = &rt_LoggedOutputWidths[9];
      rt_LoggedCurrentSignalDimensions[10] = &rt_LoggedOutputWidths[10];
    }

    rtliSetLogY(basictwotanks_M->rtwLogInfo, "varout");
  }

  /* states (dwork) */
  (void) memset((void *)&basictwotanks_DW, 0,
                sizeof(DW_basictwotanks_T));

  /* external outputs */
  (void) memset((void *)&basictwotanks_Y, 0,
                sizeof(ExtY_basictwotanks_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(basictwotanks_M->rtwLogInfo, 0.0,
    rtmGetTFinal(basictwotanks_M), basictwotanks_M->Timing.stepSize0,
    (&rtmGetErrorStatus(basictwotanks_M)));

  /* InitializeConditions for UnitDelay: '<S33>/Unit Delay' */
  basictwotanks_DW.UnitDelay_DSTATE = 1.0;

  /* InitializeConditions for Delay: '<S4>/Liquid_Height_Delay_Tank1' */
  basictwotanks_DW.Liquid_Height_Delay_Tank1_DSTAT = 0.0;

  /* InitializeConditions for Delay: '<S4>/Pump_State_Delay' */
  basictwotanks_DW.Pump_State_Delay_DSTATE = 0.0;

  /* InitializeConditions for Delay: '<S4>/Valve_State_Delay' */
  basictwotanks_DW.Valve_State_Delay_DSTATE = 0.0;

  /* InitializeConditions for UnitDelay: '<S32>/Unit Delay' */
  basictwotanks_DW.UnitDelay_DSTATE_c = 1.0;

  /* InitializeConditions for Delay: '<S4>/Liquid_Height_Delay_Tank2' */
  basictwotanks_DW.Liquid_Height_Delay_Tank2_DSTAT = 0.0;

  /* InitializeConditions for Delay: '<S4>/Emergency_Valve_State_Delay' */
  basictwotanks_DW.Emergency_Valve_State_Delay_DST = 0.0;

  /* InitializeConditions for Delay: '<S4>/Production_Valve_State_Delay' */
  basictwotanks_DW.Production_Valve_State_Delay_DS = 0.0;
}

/* Model terminate function */
void basictwotanks_terminate(void)
{
  /* (no terminate code required) */
}
