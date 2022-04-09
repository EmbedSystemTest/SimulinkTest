/*
 * AbstractFuelControl_M1_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "AbstractFuelControl_M1".
 *
 * Model version              : 1.388
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Tue Mar 15 00:25:39 2022
 *
 * Target selection: rsim.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(int32_T),
  sizeof(uint64_T),
  sizeof(int64_T),
  sizeof(char_T),
  sizeof(uchar_T),
  sizeof(time_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "physical_connection",
  "uint64_T",
  "int64_T",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&rtB.ControllerMode), 0, 0, 15 },

  { (char_T *)(&rtB.Sum3), 1, 0, 1 },

  { (char_T *)(&rtB.RelationalOperator), 8, 0, 2 }
  ,

  { (char_T *)(&rtDW.fuelsystemtransportdelay_RWORK.modelTStart), 0, 0, 1 },

  { (char_T *)(&rtDW.Monitor_PWORK.LoggedData[0]), 11, 0, 10 },

  { (char_T *)(&rtDW.UnitDelay2_DSTATE), 1, 0, 9 },

  { (char_T *)(&rtDW.clockTickCounter), 6, 0, 1 },

  { (char_T *)(&rtDW.fuelsystemtransportdelay_IWORK.Tail), 10, 0, 1 },

  { (char_T *)(&rtDW.UnitDelay_DSTATE), 8, 0, 3 },

  { (char_T *)(&rtDW.SwitchCase_ActiveSubsystem), 2, 0, 1 },

  { (char_T *)(&rtDW.controller_mode), 8, 0, 2 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  11U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&rtP.AF_sensor_tol), 0, 0, 6 },

  { (char_T *)(&rtP.spec_num), 3, 0, 1 },

  { (char_T *)(&rtP.Pwon_Time), 0, 0, 134 },

  { (char_T *)(&rtP.Constant3_Value), 1, 0, 35 },

  { (char_T *)(&rtP.uKappa_maxIndex[0]), 7, 0, 6 },

  { (char_T *)(&rtP.UnitDelay1_InitialCondition_c), 8, 0, 4 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  6U,
  rtPTransitions
};

/* [EOF] AbstractFuelControl_M1_dt.h */
