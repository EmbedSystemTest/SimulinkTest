/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: basictwotanks.h
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

#ifndef RTW_HEADER_basictwotanks_h_
#define RTW_HEADER_basictwotanks_h_
#include <string.h>
#ifndef basictwotanks_COMMON_INCLUDES_
#define basictwotanks_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* basictwotanks_COMMON_INCLUDES_ */

#include "basictwotanks_types.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Pump_State_Delay_DSTATE;      /* '<S4>/Pump_State_Delay' */
  real_T Valve_State_Delay_DSTATE;     /* '<S4>/Valve_State_Delay' */
  real_T UnitDelay_DSTATE_j;           /* '<S33>/Unit Delay' */
  real_T Emergency_Valve_State_Delay_DST;/* '<S4>/Emergency_Valve_State_Delay' */
  real_T Production_Valve_State_Delay_DS;/* '<S4>/Production_Valve_State_Delay' */
  real_T UnitDelay_DSTATE_c;           /* '<S32>/Unit Delay' */
} DW_basictwotanks_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Product;                /* '<S19>/Product' */
  const real_T Product_g;              /* '<S20>/Product' */
  const real_T Product_p;              /* '<S21>/Product' */
  const real_T Product_h;              /* '<S29>/Product' */
} ConstB_basictwotanks_T;

/* Real-time Model Data Structure */
struct tag_RTM_basictwotanks_T {
  const char_T * volatile errorStatus;
  DW_basictwotanks_T *dwork;
};

extern const ConstB_basictwotanks_T basictwotanks_ConstB;/* constant block i/o */

/* Model entry point functions */
extern void basictwotanks_initialize(RT_MODEL_basictwotanks_T *const
  basictwotanks_M, real_T *basictwotanks_Y_t1_h, real_T *basictwotanks_Y_t2_h,
  real_T *basictwotanks_Y_t1_sh, real_T *basictwotanks_Y_t1_sl, real_T
  *basictwotanks_Y_t2_sh, real_T *basictwotanks_Y_t2_sm, real_T
  *basictwotanks_Y_t2_sl, real_T *basictwotanks_Y_pump_state, real_T
  *basictwotanks_Y_valve_state, real_T *basictwotanks_Y_p_valve_state, real_T
  *basictwotanks_Y_e_valve_state);
extern void basictwotanks_step(RT_MODEL_basictwotanks_T *const basictwotanks_M,
  real_T *basictwotanks_Y_t1_h, real_T *basictwotanks_Y_t2_h, real_T
  *basictwotanks_Y_t1_sh, real_T *basictwotanks_Y_t1_sl, real_T
  *basictwotanks_Y_t2_sh, real_T *basictwotanks_Y_t2_sm, real_T
  *basictwotanks_Y_t2_sl, real_T *basictwotanks_Y_pump_state, real_T
  *basictwotanks_Y_valve_state, real_T *basictwotanks_Y_p_valve_state, real_T
  *basictwotanks_Y_e_valve_state);
extern void basictwotanks_terminate(RT_MODEL_basictwotanks_T *const
  basictwotanks_M);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Emergency Valve State' : Unused code path elimination
 * Block '<S2>/Production Valve State' : Unused code path elimination
 * Block '<S2>/Pump State ' : Unused code path elimination
 * Block '<S2>/Valve State' : Unused code path elimination
 * Block '<Root>/Emergency' : Unused code path elimination
 * Block '<S4>/Scope for Tank1 Height ' : Unused code path elimination
 * Block '<S4>/Scope for Tank2 Height' : Unused code path elimination
 * Block '<Root>/Liquid Height' : Unused code path elimination
 * Block '<Root>/Pre emergency ' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'basictwotanks'
 * '<S1>'   : 'basictwotanks/Constants'
 * '<S2>'   : 'basictwotanks/Controller'
 * '<S3>'   : 'basictwotanks/Environment'
 * '<S4>'   : 'basictwotanks/Initializer_and_Updater'
 * '<S5>'   : 'basictwotanks/Controller/Compare To Constant'
 * '<S6>'   : 'basictwotanks/Controller/Compare To Constant1'
 * '<S7>'   : 'basictwotanks/Controller/Compare To Constant4'
 * '<S8>'   : 'basictwotanks/Controller/Compare To Constant5'
 * '<S9>'   : 'basictwotanks/Controller/Compare To Constant6'
 * '<S10>'  : 'basictwotanks/Controller/Tank1_Controller'
 * '<S11>'  : 'basictwotanks/Controller/Tank2_Controller'
 * '<S12>'  : 'basictwotanks/Controller/Tank2_Controller/Compare To Constant1'
 * '<S13>'  : 'basictwotanks/Controller/Tank2_Controller/Compare To Constant2'
 * '<S14>'  : 'basictwotanks/Controller/Tank2_Controller/Compare To Constant3'
 * '<S15>'  : 'basictwotanks/Controller/Tank2_Controller/Compare To Constant4'
 * '<S16>'  : 'basictwotanks/Controller/Tank2_Controller/Compare To Constant5'
 * '<S17>'  : 'basictwotanks/Controller/Tank2_Controller/Compare To Constant6'
 * '<S18>'  : 'basictwotanks/Controller/Tank2_Controller/Compare To Constant7'
 * '<S19>'  : 'basictwotanks/Environment/EmergencyValve'
 * '<S20>'  : 'basictwotanks/Environment/ProductionValve'
 * '<S21>'  : 'basictwotanks/Environment/Pump'
 * '<S22>'  : 'basictwotanks/Environment/Sensor_HI_Tank2'
 * '<S23>'  : 'basictwotanks/Environment/Sensor_High_Tank1'
 * '<S24>'  : 'basictwotanks/Environment/Sensor_LO_Tank2'
 * '<S25>'  : 'basictwotanks/Environment/Sensor_Low_Tank1'
 * '<S26>'  : 'basictwotanks/Environment/Sensor_MD_Tank2'
 * '<S27>'  : 'basictwotanks/Environment/Tank1'
 * '<S28>'  : 'basictwotanks/Environment/Tank2'
 * '<S29>'  : 'basictwotanks/Environment/Valve'
 * '<S30>'  : 'basictwotanks/Initializer_and_Updater/E_Valve_Initial_State'
 * '<S31>'  : 'basictwotanks/Initializer_and_Updater/Initial Conditions'
 * '<S32>'  : 'basictwotanks/Initializer_and_Updater/Initial_Height_Tank _2'
 * '<S33>'  : 'basictwotanks/Initializer_and_Updater/Initial_Height_Tank_1'
 * '<S34>'  : 'basictwotanks/Initializer_and_Updater/P_Valve_Initial_State'
 * '<S35>'  : 'basictwotanks/Initializer_and_Updater/Pump_Initial_State'
 * '<S36>'  : 'basictwotanks/Initializer_and_Updater/Valve_Initial_State'
 */
#endif                                 /* RTW_HEADER_basictwotanks_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
