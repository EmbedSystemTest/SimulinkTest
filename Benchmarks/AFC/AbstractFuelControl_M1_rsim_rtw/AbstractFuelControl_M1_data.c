/*
 * AbstractFuelControl_M1_data.c
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

#include "AbstractFuelControl_M1.h"
#include "AbstractFuelControl_M1_private.h"

/* Block parameters (default storage) */
P rtP = {
  /* Variable: AF_sensor_tol
   * Referenced by: '<S1>/A//F sensor tolerance [0.99 1.01]'
   */
  1.0,

  /* Variable: MAF_sensor_tol
   * Referenced by: '<S1>/MAF sensor tolerance [0.95 1.05]'
   */
  1.0,

  /* Variable: fault_time
   * Referenced by: '<S1>/A//F Sensor Fault Injection'
   */
  60.0,

  /* Variable: fuel_inj_tol
   * Referenced by: '<S1>/fuel injector tolerance [0.95 1.05]'
   */
  1.0,

  /* Variable: measureTime
   * Referenced by: '<S2>/MeasureOn'
   */
  1.0,

  /* Variable: simTime
   * Referenced by: '<S22>/Constant'
   */
  50.0,

  /* Variable: spec_num
   * Referenced by: '<S2>/spec_num'
   */
  1U,

  /* Expression: 0.001
   * Referenced by: '<S3>/Pwon'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<S3>/Pwon'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S3>/Pwon'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S3>/PulseGenerator_10ms'
   */
  1.0,

  /* Computed Parameter: PulseGenerator_10ms_Period
   * Referenced by: '<S3>/PulseGenerator_10ms'
   */
  200.0,

  /* Computed Parameter: PulseGenerator_10ms_Duty
   * Referenced by: '<S3>/PulseGenerator_10ms'
   */
  100.0,

  /* Expression: 0.01
   * Referenced by: '<S3>/PulseGenerator_10ms'
   */
  0.01,

  /* Expression: 14.7
   * Referenced by: '<S20>/Integrator'
   */
  14.7,

  /* Expression: 1
   * Referenced by: '<S18>/A//F_sensor'
   */
  1.0,

  /* Computed Parameter: Throttledelay_A
   * Referenced by: '<S1>/Throttle delay'
   */
  -10.0,

  /* Computed Parameter: Throttledelay_C
   * Referenced by: '<S1>/Throttle delay'
   */
  10.0,

  /* Expression: 8.8
   * Referenced by: '<S1>/Base opening angle'
   */
  8.8,

  /* Expression: 90
   * Referenced by: '<S1>/theta [0 90]'
   */
  90.0,

  /* Expression: 0
   * Referenced by: '<S1>/theta [0 90]'
   */
  0.0,

  /* Expression: 1100
   * Referenced by: '<S1>/Engine Speed [900 1100]'
   */
  1100.0,

  /* Expression: 900
   * Referenced by: '<S1>/Engine Speed [900 1100]'
   */
  900.0,

  /* Expression: pi/30
   * Referenced by: '<S1>/(rpm) to (rad//s)'
   */
  0.10471975511965977,

  /* Expression: 0
   * Referenced by: '<S1>/A//F Sensor Fault Injection'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1>/A//F Sensor Fault Injection'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S4>/FaultySensorOutput'
   */
  -1.0,

  /* Expression: 0.5
   * Referenced by: '<S4>/Switch'
   */
  0.5,

  /* Expression: 0.982
   * Referenced by: '<S5>/p0 = 0.543 (bar)'
   */
  0.982,

  /* Expression: 1
   * Referenced by: '<S1>/Atmospheric Pressure (bar)'
   */
  1.0,

  /* Expression: 1.0
   * Referenced by: '<S6>/Sonic Flow '
   */
  1.0,

  /* Expression: 0.5
   * Referenced by: '<S6>/Switch'
   */
  0.5,

  /* Expression: 14.7
   * Referenced by: '<S19>/Integrator'
   */
  14.7,

  /* Expression: 50
   * Referenced by: '<S20>/Gain'
   */
  50.0,

  /* Expression: 60/(2*pi)
   * Referenced by: '<S7>/rad//s to rpm'
   */
  9.5492965855137211,

  /* Expression: 4*pi/4
   * Referenced by: '<S4>/Gain'
   */
  3.1415926535897931,

  /* Expression: reshape([0.8,.7,.7,.8,.9,.7,.66,.65,.73,.85,.66,.66,.63,.66,.8,.6,.6,.6,.6,.7],5,4)
   * Referenced by: '<S7>/1-Kappa'
   */
  { 0.8, 0.7, 0.7, 0.8, 0.9, 0.7, 0.66, 0.65, 0.73, 0.85, 0.66, 0.66, 0.63, 0.66,
    0.8, 0.6, 0.6, 0.6, 0.6, 0.7 },

  /* Expression: [1000,1500,2000,2500,3000]
   * Referenced by: '<S7>/1-Kappa'
   */
  { 1000.0, 1500.0, 2000.0, 2500.0, 3000.0 },

  /* Expression: [.1,.2,.3,.4]
   * Referenced by: '<S7>/1-Kappa'
   */
  { 0.1, 0.2, 0.3, 0.4 },

  /* Expression: 1
   * Referenced by: '<S7>/Kappa tolerance [0.9 1.1]'
   */
  1.0,

  /* Expression: .0112
   * Referenced by: '<S7>/Integrator'
   */
  0.0112,

  /* Expression: reshape([.4,.3,.35,.3,.2,.22,.22,.4,.35,.5,.20,.22,.5,.4,.35,.35,.3,.45,.5,.4],5,4)
   * Referenced by: '<S7>/tau_ww'
   */
  { 0.4, 0.3, 0.35, 0.3, 0.2, 0.22, 0.22, 0.4, 0.35, 0.5, 0.2, 0.22, 0.5, 0.4,
    0.35, 0.35, 0.3, 0.45, 0.5, 0.4 },

  /* Expression: [1000,1500,2000,2500,3000]
   * Referenced by: '<S7>/tau_ww'
   */
  { 1000.0, 1500.0, 2000.0, 2500.0, 3000.0 },

  /* Expression: [0.1,0.2,0.3,0.4]
   * Referenced by: '<S7>/tau_ww'
   */
  { 0.1, 0.2, 0.3, 0.4 },

  /* Expression: 1
   * Referenced by: '<S7>/tau_ww tolerance [0.9 1.1]'
   */
  1.0,

  /* Expression: 10
   * Referenced by: '<S4>/fuel system transport delay'
   */
  10.0,

  /* Expression: 14.7
   * Referenced by: '<S4>/fuel system transport delay'
   */
  14.7,

  /* Expression: 10
   * Referenced by: '<S19>/Gain1'
   */
  10.0,

  /* Expression: 60/(2*pi)
   * Referenced by: '<S4>/rad//s to rpm'
   */
  9.5492965855137211,

  /* Expression: reshape([0.8,0.6,0.4,0.3,0.2,0.4,0.3,0.2,0.2,0.2,0.3,0.25,0.2,0.2,0.2,0.25,0.2,0.2,0.2,0.2],5,4)
   * Referenced by: '<S4>/delay (s)'
   */
  { 0.8, 0.6, 0.4, 0.3, 0.2, 0.4, 0.3, 0.2, 0.2, 0.2, 0.3, 0.25, 0.2, 0.2, 0.2,
    0.25, 0.2, 0.2, 0.2, 0.2 },

  /* Expression: [800,1000,1500,2000,3000]
   * Referenced by: '<S4>/delay (s)'
   */
  { 800.0, 1000.0, 1500.0, 2000.0, 3000.0 },

  /* Expression: [0.05,0.15,0.2,0.25]
   * Referenced by: '<S4>/delay (s)'
   */
  { 0.05, 0.15, 0.2, 0.25 },

  /* Expression: 0.41328
   * Referenced by: '<S5>/RT//Vm'
   */
  0.41328,

  /* Expression: -1
   * Referenced by: '<S7>/Gain'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S7>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S23>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S22>/Integrator'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<S22>/MeasureOn'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<S22>/MeasureOn'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S22>/MeasureOn'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S2>/MeasureOn'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S2>/MeasureOn'
   */
  1.0,

  /* Expression: 0.5
   * Referenced by: '<S2>/Constant'
   */
  0.5,

  /* Computed Parameter: Constant3_Value
   * Referenced by: '<S9>/Constant3'
   */
  1.0F,

  /* Computed Parameter: Constant2_Value
   * Referenced by: '<S9>/Constant2'
   */
  1.0F,

  /* Computed Parameter: fb_fuel_saturation_UpperSat
   * Referenced by: '<S9>/fb_fuel_saturation'
   */
  0.0F,

  /* Computed Parameter: fb_fuel_saturation_LowerSat
   * Referenced by: '<S9>/fb_fuel_saturation'
   */
  0.0F,

  /* Computed Parameter: Constant1_Value
   * Referenced by: '<S12>/Constant1'
   */
  0.01F,

  /* Computed Parameter: Constant2_Value_d
   * Referenced by: '<S12>/Constant2'
   */
  -0.366F,

  /* Computed Parameter: Constant3_Value_c
   * Referenced by: '<S12>/Constant3'
   */
  0.08979F,

  /* Computed Parameter: Constant4_Value
   * Referenced by: '<S12>/Constant4'
   */
  -0.0337F,

  /* Computed Parameter: Constant5_Value
   * Referenced by: '<S12>/Constant5'
   */
  0.0001F,

  /* Computed Parameter: UnitDelay1_InitialCondition
   * Referenced by: '<S12>/UnitDelay1'
   */
  0.982F,

  /* Computed Parameter: Gain_Gain_j
   * Referenced by: '<S12>/Gain'
   */
  0.41328F,

  /* Computed Parameter: Constant1_Value_h
   * Referenced by: '<S13>/Constant1'
   */
  0.01F,

  /* Computed Parameter: Gain_Gain_c
   * Referenced by: '<S13>/Gain'
   */
  0.04F,

  /* Computed Parameter: Gain1_Gain_a
   * Referenced by: '<S13>/Gain1'
   */
  0.14F,

  /* Computed Parameter: UnitDelay1_InitialCondition_l
   * Referenced by: '<S13>/UnitDelay1'
   */
  0.0F,

  /* Computed Parameter: fuel_saturation_UpperSat
   * Referenced by: '<S9>/fuel_saturation'
   */
  1.66F,

  /* Computed Parameter: fuel_saturation_LowerSat
   * Referenced by: '<S9>/fuel_saturation'
   */
  0.13F,

  /* Computed Parameter: airbyfuel_reference_power_Value
   * Referenced by: '<S10>/airbyfuel_reference_power'
   */
  12.5F,

  /* Computed Parameter: airbyfuel_reference_Value
   * Referenced by: '<S10>/airbyfuel_reference'
   */
  14.7F,

  /* Computed Parameter: UnitDelay2_InitialCondition
   * Referenced by: '<S15>/Unit Delay2'
   */
  0.0F,

  /* Computed Parameter: sampling_sec_Value
   * Referenced by: '<S15>/sampling_sec'
   */
  0.01F,

  /* Computed Parameter: normal_mode_start_sec_Value
   * Referenced by: '<S15>/normal_mode_start_sec'
   */
  10.0F,

  /* Computed Parameter: Constant1_Value_f
   * Referenced by: '<S16>/Constant1'
   */
  20.0F,

  /* Computed Parameter: Constant_Value_d
   * Referenced by: '<S16>/Constant'
   */
  50.0F,

  /* Computed Parameter: threshold_Value
   * Referenced by: '<S17>/threshold'
   */
  -1.0F,

  /* Computed Parameter: Constant1_Value_l
   * Referenced by: '<S11>/Constant1'
   */
  1.0F,

  /* Computed Parameter: Constant2_Value_k
   * Referenced by: '<S11>/Constant2'
   */
  0.1726F,

  /* Computed Parameter: Constant3_Value_o
   * Referenced by: '<S11>/Constant3'
   */
  14.7F,

  /* Computed Parameter: DataStoreMemory_InitialValue
   * Referenced by: '<S8>/DataStoreMemory'
   */
  0.0F,

  /* Computed Parameter: DataStoreMemory1_InitialValue
   * Referenced by: '<S8>/DataStoreMemory1'
   */
  0.0F,

  /* Computed Parameter: DataStoreMemory2_InitialValue
   * Referenced by: '<S8>/DataStoreMemory2'
   */
  0.0F,

  /* Computed Parameter: DataStoreMemory3_InitialValue
   * Referenced by: '<S8>/DataStoreMemory3'
   */
  0.0F,

  /* Computed Parameter: commanded_fuel_InitialValue
   * Referenced by: '<S3>/commanded_fuel'
   */
  0.1726F,

  /* Computed Parameter: mode_fb1_InitialValue
   * Referenced by: '<S3>/mode_fb1'
   */
  0.0F,

  /* Computed Parameter: Gain2_Gain
   * Referenced by: '<S5>/Gain2'
   */
  0.9F,

  /* Computed Parameter: uKappa_maxIndex
   * Referenced by: '<S7>/1-Kappa'
   */
  { 4U, 3U },

  /* Computed Parameter: tau_ww_maxIndex
   * Referenced by: '<S7>/tau_ww'
   */
  { 4U, 3U },

  /* Computed Parameter: delays_maxIndex
   * Referenced by: '<S4>/delay (s)'
   */
  { 4U, 3U },

  /* Computed Parameter: UnitDelay1_InitialCondition_c
   * Referenced by: '<S15>/Unit Delay1'
   */
  false,

  /* Computed Parameter: UnitDelay1_InitialCondition_f
   * Referenced by: '<S16>/Unit Delay1'
   */
  false,

  /* Computed Parameter: UnitDelay_InitialCondition
   * Referenced by: '<S17>/Unit Delay'
   */
  false,

  /* Computed Parameter: mode_fb_InitialValue
   * Referenced by: '<S3>/mode_fb'
   */
  false
};
