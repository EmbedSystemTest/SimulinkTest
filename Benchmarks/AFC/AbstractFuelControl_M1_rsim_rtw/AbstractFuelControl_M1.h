/*
 * AbstractFuelControl_M1.h
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

#ifndef RTW_HEADER_AbstractFuelControl_M1_h_
#define RTW_HEADER_AbstractFuelControl_M1_h_
#include <stddef.h>
#include <math.h>
#include <string.h>
#ifndef AbstractFuelControl_M1_COMMON_INCLUDES_
#define AbstractFuelControl_M1_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rsim.h"
#include "rt_logging.h"
#include "dt_info.h"
#endif                             /* AbstractFuelControl_M1_COMMON_INCLUDES_ */

#include "AbstractFuelControl_M1_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_zcfcn.h"
#include "rtGetInf.h"
#include "rt_defines.h"
#define MODEL_NAME                     AbstractFuelControl_M1
#define NSAMPLE_TIMES                  (2)                       /* Number of sample times */
#define NINPUTS                        (2)                       /* Number of model inputs */
#define NOUTPUTS                       (3)                       /* Number of model outputs */
#define NBLOCKIO                       (24)                      /* Number of data output port signals */
#define NUM_ZC_EVENTS                  (3)                       /* Number of zero-crossing events */
#ifndef NCSTATES
#define NCSTATES                       (7)                       /* Number of continuous states */
#elif NCSTATES != 7
# error Invalid specification of NCSTATES defined in compiler command
#endif

#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm)         (NULL)
#endif

#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T ControllerMode;               /* '<Root>/Data Type Conversion' */
  real_T MultiportSwitch;              /* '<S21>/Multiport Switch' */
  real_T Product;                      /* '<S22>/Product' */
  real_T Sqrt;                         /* '<S22>/Sqrt' */
  real_T Sum1;                         /* '<S23>/Sum1' */
  real_T AF_sensor;                    /* '<S18>/A//F_sensor' */
  real_T theta090;                     /* '<S1>/theta [0 90]' */
  real_T Gain;                         /* '<S20>/Gain' */
  real_T airbyfuel;                    /* '<S4>/Divide' */
  real_T Gain1;                        /* '<S19>/Gain1' */
  real_T delays;                       /* '<S4>/delay (s)' */
  real_T RTVm;                         /* '<S5>/RT//Vm' */
  real_T Sum;                          /* '<S7>/Sum' */
  real_T Pwon;                         /* '<S3>/Pwon' */
  real_T PulseGenerator_10ms;          /* '<S3>/PulseGenerator_10ms' */
  real32_T Sum3;                       /* '<S13>/Sum3' */
  real32_T Sum2_a;                     /* '<S13>/Sum2' */
  boolean_T RelationalOperator;        /* '<S2>/Relational Operator' */
  boolean_T HiddenBuf_InsertedFor_CalcuateE;/* '<S2>/Relational Operator' */
} B;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  struct {
    real_T modelTStart;
  } fuelsystemtransportdelay_RWORK;    /* '<S4>/fuel system transport delay' */

  struct {
    void *LoggedData[4];
  } Monitor_PWORK;                     /* '<Root>/Monitor ' */

  struct {
    void *LoggedData[3];
  } Monitor_PWORK_h;                   /* '<S1>/Monitor' */

  struct {
    void *TUbufferPtrs[3];
  } fuelsystemtransportdelay_PWORK;    /* '<S4>/fuel system transport delay' */

  real32_T UnitDelay2_DSTATE;          /* '<S15>/Unit Delay2' */
  real32_T UnitDelay1_DSTATE;          /* '<S13>/UnitDelay1' */
  real32_T UnitDelay1_DSTATE_d;        /* '<S12>/UnitDelay1' */
  real32_T commanded_fuel;             /* '<S3>/commanded_fuel' */
  real32_T airbyfuel_ref;              /* '<S3>/mode_fb1' */
  real32_T engine_speed;               /* '<S8>/DataStoreMemory' */
  real32_T throttle_flow;              /* '<S8>/DataStoreMemory1' */
  real32_T airbyfuel_meas;             /* '<S8>/DataStoreMemory2' */
  real32_T throttle_angle;             /* '<S8>/DataStoreMemory3' */
  int32_T clockTickCounter;            /* '<S3>/PulseGenerator_10ms' */
  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
    int_T MaxNewBufSize;
  } fuelsystemtransportdelay_IWORK;    /* '<S4>/fuel system transport delay' */

  boolean_T UnitDelay_DSTATE;          /* '<S17>/Unit Delay' */
  boolean_T UnitDelay1_DSTATE_a;       /* '<S16>/Unit Delay1' */
  boolean_T UnitDelay1_DSTATE_e;       /* '<S15>/Unit Delay1' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S21>/Switch Case' */
  boolean_T controller_mode;           /* '<S3>/mode_fb' */
  boolean_T CalcuateError_MODE;        /* '<S2>/Calcuate Error' */
} DW;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S22>/Integrator' */
  real_T Integrator_CSTATE_m;          /* '<S20>/Integrator' */
  real_T Throttledelay_CSTATE;         /* '<S1>/Throttle delay' */
  real_T p00543bar_CSTATE;             /* '<S5>/p0 = 0.543 (bar)' */
  real_T Integrator_CSTATE_h;          /* '<S19>/Integrator' */
  real_T Integrator_CSTATE_c;          /* '<S7>/Integrator' */
  real_T fuelsystemtransportdelay_CSTATE;/* '<S4>/fuel system transport delay' */
} X;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S22>/Integrator' */
  real_T Integrator_CSTATE_m;          /* '<S20>/Integrator' */
  real_T Throttledelay_CSTATE;         /* '<S1>/Throttle delay' */
  real_T p00543bar_CSTATE;             /* '<S5>/p0 = 0.543 (bar)' */
  real_T Integrator_CSTATE_h;          /* '<S19>/Integrator' */
  real_T Integrator_CSTATE_c;          /* '<S7>/Integrator' */
  real_T fuelsystemtransportdelay_CSTATE;/* '<S4>/fuel system transport delay' */
} XDot;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S22>/Integrator' */
  boolean_T Integrator_CSTATE_m;       /* '<S20>/Integrator' */
  boolean_T Throttledelay_CSTATE;      /* '<S1>/Throttle delay' */
  boolean_T p00543bar_CSTATE;          /* '<S5>/p0 = 0.543 (bar)' */
  boolean_T Integrator_CSTATE_h;       /* '<S19>/Integrator' */
  boolean_T Integrator_CSTATE_c;       /* '<S7>/Integrator' */
  boolean_T fuelsystemtransportdelay_CSTATE;/* '<S4>/fuel system transport delay' */
} XDis;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState fuel_controller_pwon_Trig_ZCE;/* '<S8>/fuel_controller_pwon' */
  ZCSigState fuel_controller_mode_10ms_Trig_;/* '<S8>/fuel_controller_mode_10ms' */
  ZCSigState fuel_controller_10ms_Trig_ZCE;/* '<S8>/fuel_controller_10ms' */
} PrevZCX;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T EngineSpeed;                  /* '<Root>/Engine Speed (rpm)' */
  real_T PedalAngle;                   /* '<Root>/Throttle angle' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T verificatonmeasurement;       /* '<Root>/verificaton measurement' */
  real_T mode;                         /* '<Root>/mode' */
  real_T pedalangle;                   /* '<Root>/pedal angle' */
} ExtY;

/* Parameters (default storage) */
struct P_ {
  real_T AF_sensor_tol;                /* Variable: AF_sensor_tol
                                        * Referenced by: '<S1>/A//F sensor tolerance [0.99 1.01]'
                                        */
  real_T MAF_sensor_tol;               /* Variable: MAF_sensor_tol
                                        * Referenced by: '<S1>/MAF sensor tolerance [0.95 1.05]'
                                        */
  real_T fault_time;                   /* Variable: fault_time
                                        * Referenced by: '<S1>/A//F Sensor Fault Injection'
                                        */
  real_T fuel_inj_tol;                 /* Variable: fuel_inj_tol
                                        * Referenced by: '<S1>/fuel injector tolerance [0.95 1.05]'
                                        */
  real_T measureTime;                  /* Variable: measureTime
                                        * Referenced by: '<S2>/MeasureOn'
                                        */
  real_T simTime;                      /* Variable: simTime
                                        * Referenced by: '<S22>/Constant'
                                        */
  uint8_T spec_num;                    /* Variable: spec_num
                                        * Referenced by: '<S2>/spec_num'
                                        */
  real_T Pwon_Time;                    /* Expression: 0.001
                                        * Referenced by: '<S3>/Pwon'
                                        */
  real_T Pwon_Y0;                      /* Expression: 0
                                        * Referenced by: '<S3>/Pwon'
                                        */
  real_T Pwon_YFinal;                  /* Expression: 1
                                        * Referenced by: '<S3>/Pwon'
                                        */
  real_T PulseGenerator_10ms_Amp;      /* Expression: 1
                                        * Referenced by: '<S3>/PulseGenerator_10ms'
                                        */
  real_T PulseGenerator_10ms_Period;
                               /* Computed Parameter: PulseGenerator_10ms_Period
                                * Referenced by: '<S3>/PulseGenerator_10ms'
                                */
  real_T PulseGenerator_10ms_Duty;
                                 /* Computed Parameter: PulseGenerator_10ms_Duty
                                  * Referenced by: '<S3>/PulseGenerator_10ms'
                                  */
  real_T PulseGenerator_10ms_PhaseDelay;/* Expression: 0.01
                                         * Referenced by: '<S3>/PulseGenerator_10ms'
                                         */
  real_T Integrator_IC;                /* Expression: 14.7
                                        * Referenced by: '<S20>/Integrator'
                                        */
  real_T AF_sensor_Gain;               /* Expression: 1
                                        * Referenced by: '<S18>/A//F_sensor'
                                        */
  real_T Throttledelay_A;              /* Computed Parameter: Throttledelay_A
                                        * Referenced by: '<S1>/Throttle delay'
                                        */
  real_T Throttledelay_C;              /* Computed Parameter: Throttledelay_C
                                        * Referenced by: '<S1>/Throttle delay'
                                        */
  real_T Baseopeningangle_Value;       /* Expression: 8.8
                                        * Referenced by: '<S1>/Base opening angle'
                                        */
  real_T theta090_UpperSat;            /* Expression: 90
                                        * Referenced by: '<S1>/theta [0 90]'
                                        */
  real_T theta090_LowerSat;            /* Expression: 0
                                        * Referenced by: '<S1>/theta [0 90]'
                                        */
  real_T EngineSpeed9001100_UpperSat;  /* Expression: 1100
                                        * Referenced by: '<S1>/Engine Speed [900 1100]'
                                        */
  real_T EngineSpeed9001100_LowerSat;  /* Expression: 900
                                        * Referenced by: '<S1>/Engine Speed [900 1100]'
                                        */
  real_T rpmtorads_Gain;               /* Expression: pi/30
                                        * Referenced by: '<S1>/(rpm) to (rad//s)'
                                        */
  real_T AFSensorFaultInjection_Y0;    /* Expression: 0
                                        * Referenced by: '<S1>/A//F Sensor Fault Injection'
                                        */
  real_T AFSensorFaultInjection_YFinal;/* Expression: 1
                                        * Referenced by: '<S1>/A//F Sensor Fault Injection'
                                        */
  real_T FaultySensorOutput_Value;     /* Expression: -1
                                        * Referenced by: '<S4>/FaultySensorOutput'
                                        */
  real_T Switch_Threshold;             /* Expression: 0.5
                                        * Referenced by: '<S4>/Switch'
                                        */
  real_T p00543bar_IC;                 /* Expression: 0.982
                                        * Referenced by: '<S5>/p0 = 0.543 (bar)'
                                        */
  real_T AtmosphericPressurebar_Value; /* Expression: 1
                                        * Referenced by: '<S1>/Atmospheric Pressure (bar)'
                                        */
  real_T SonicFlow_Value;              /* Expression: 1.0
                                        * Referenced by: '<S6>/Sonic Flow '
                                        */
  real_T Switch_Threshold_g;           /* Expression: 0.5
                                        * Referenced by: '<S6>/Switch'
                                        */
  real_T Integrator_IC_l;              /* Expression: 14.7
                                        * Referenced by: '<S19>/Integrator'
                                        */
  real_T Gain_Gain;                    /* Expression: 50
                                        * Referenced by: '<S20>/Gain'
                                        */
  real_T radstorpm_Gain;               /* Expression: 60/(2*pi)
                                        * Referenced by: '<S7>/rad//s to rpm'
                                        */
  real_T Gain_Gain_l;                  /* Expression: 4*pi/4
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T uKappa_tableData[20];
  /* Expression: reshape([0.8,.7,.7,.8,.9,.7,.66,.65,.73,.85,.66,.66,.63,.66,.8,.6,.6,.6,.6,.7],5,4)
   * Referenced by: '<S7>/1-Kappa'
   */
  real_T uKappa_bp01Data[5];           /* Expression: [1000,1500,2000,2500,3000]
                                        * Referenced by: '<S7>/1-Kappa'
                                        */
  real_T uKappa_bp02Data[4];           /* Expression: [.1,.2,.3,.4]
                                        * Referenced by: '<S7>/1-Kappa'
                                        */
  real_T Kappatolerance0911_Gain;      /* Expression: 1
                                        * Referenced by: '<S7>/Kappa tolerance [0.9 1.1]'
                                        */
  real_T Integrator_IC_m;              /* Expression: .0112
                                        * Referenced by: '<S7>/Integrator'
                                        */
  real_T tau_ww_tableData[20];
  /* Expression: reshape([.4,.3,.35,.3,.2,.22,.22,.4,.35,.5,.20,.22,.5,.4,.35,.35,.3,.45,.5,.4],5,4)
   * Referenced by: '<S7>/tau_ww'
   */
  real_T tau_ww_bp01Data[5];           /* Expression: [1000,1500,2000,2500,3000]
                                        * Referenced by: '<S7>/tau_ww'
                                        */
  real_T tau_ww_bp02Data[4];           /* Expression: [0.1,0.2,0.3,0.4]
                                        * Referenced by: '<S7>/tau_ww'
                                        */
  real_T tau_wwtolerance0911_Gain;     /* Expression: 1
                                        * Referenced by: '<S7>/tau_ww tolerance [0.9 1.1]'
                                        */
  real_T fuelsystemtransportdelay_MaxDel;/* Expression: 10
                                          * Referenced by: '<S4>/fuel system transport delay'
                                          */
  real_T fuelsystemtransportdelay_InitOu;/* Expression: 14.7
                                          * Referenced by: '<S4>/fuel system transport delay'
                                          */
  real_T Gain1_Gain;                   /* Expression: 10
                                        * Referenced by: '<S19>/Gain1'
                                        */
  real_T radstorpm_Gain_p;             /* Expression: 60/(2*pi)
                                        * Referenced by: '<S4>/rad//s to rpm'
                                        */
  real_T delays_tableData[20];
  /* Expression: reshape([0.8,0.6,0.4,0.3,0.2,0.4,0.3,0.2,0.2,0.2,0.3,0.25,0.2,0.2,0.2,0.25,0.2,0.2,0.2,0.2],5,4)
   * Referenced by: '<S4>/delay (s)'
   */
  real_T delays_bp01Data[5];           /* Expression: [800,1000,1500,2000,3000]
                                        * Referenced by: '<S4>/delay (s)'
                                        */
  real_T delays_bp02Data[4];           /* Expression: [0.05,0.15,0.2,0.25]
                                        * Referenced by: '<S4>/delay (s)'
                                        */
  real_T RTVm_Gain;                    /* Expression: 0.41328
                                        * Referenced by: '<S5>/RT//Vm'
                                        */
  real_T Gain_Gain_m;                  /* Expression: -1
                                        * Referenced by: '<S7>/Gain'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Constant_Value_i;             /* Expression: 1
                                        * Referenced by: '<S23>/Constant'
                                        */
  real_T Integrator_IC_b;              /* Expression: 0
                                        * Referenced by: '<S22>/Integrator'
                                        */
  real_T MeasureOn_Time;               /* Expression: 10
                                        * Referenced by: '<S22>/MeasureOn'
                                        */
  real_T MeasureOn_Y0;                 /* Expression: 0
                                        * Referenced by: '<S22>/MeasureOn'
                                        */
  real_T MeasureOn_YFinal;             /* Expression: 1
                                        * Referenced by: '<S22>/MeasureOn'
                                        */
  real_T MeasureOn_Y0_m;               /* Expression: 0
                                        * Referenced by: '<S2>/MeasureOn'
                                        */
  real_T MeasureOn_YFinal_n;           /* Expression: 1
                                        * Referenced by: '<S2>/MeasureOn'
                                        */
  real_T Constant_Value_l;             /* Expression: 0.5
                                        * Referenced by: '<S2>/Constant'
                                        */
  real32_T Constant3_Value;            /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S9>/Constant3'
                                        */
  real32_T Constant2_Value;            /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S9>/Constant2'
                                        */
  real32_T fb_fuel_saturation_UpperSat;
                              /* Computed Parameter: fb_fuel_saturation_UpperSat
                               * Referenced by: '<S9>/fb_fuel_saturation'
                               */
  real32_T fb_fuel_saturation_LowerSat;
                              /* Computed Parameter: fb_fuel_saturation_LowerSat
                               * Referenced by: '<S9>/fb_fuel_saturation'
                               */
  real32_T Constant1_Value;            /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S12>/Constant1'
                                        */
  real32_T Constant2_Value_d;          /* Computed Parameter: Constant2_Value_d
                                        * Referenced by: '<S12>/Constant2'
                                        */
  real32_T Constant3_Value_c;          /* Computed Parameter: Constant3_Value_c
                                        * Referenced by: '<S12>/Constant3'
                                        */
  real32_T Constant4_Value;            /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S12>/Constant4'
                                        */
  real32_T Constant5_Value;            /* Computed Parameter: Constant5_Value
                                        * Referenced by: '<S12>/Constant5'
                                        */
  real32_T UnitDelay1_InitialCondition;
                              /* Computed Parameter: UnitDelay1_InitialCondition
                               * Referenced by: '<S12>/UnitDelay1'
                               */
  real32_T Gain_Gain_j;                /* Computed Parameter: Gain_Gain_j
                                        * Referenced by: '<S12>/Gain'
                                        */
  real32_T Constant1_Value_h;          /* Computed Parameter: Constant1_Value_h
                                        * Referenced by: '<S13>/Constant1'
                                        */
  real32_T Gain_Gain_c;                /* Computed Parameter: Gain_Gain_c
                                        * Referenced by: '<S13>/Gain'
                                        */
  real32_T Gain1_Gain_a;               /* Computed Parameter: Gain1_Gain_a
                                        * Referenced by: '<S13>/Gain1'
                                        */
  real32_T UnitDelay1_InitialCondition_l;
                            /* Computed Parameter: UnitDelay1_InitialCondition_l
                             * Referenced by: '<S13>/UnitDelay1'
                             */
  real32_T fuel_saturation_UpperSat;
                                 /* Computed Parameter: fuel_saturation_UpperSat
                                  * Referenced by: '<S9>/fuel_saturation'
                                  */
  real32_T fuel_saturation_LowerSat;
                                 /* Computed Parameter: fuel_saturation_LowerSat
                                  * Referenced by: '<S9>/fuel_saturation'
                                  */
  real32_T airbyfuel_reference_power_Value;
                          /* Computed Parameter: airbyfuel_reference_power_Value
                           * Referenced by: '<S10>/airbyfuel_reference_power'
                           */
  real32_T airbyfuel_reference_Value;
                                /* Computed Parameter: airbyfuel_reference_Value
                                 * Referenced by: '<S10>/airbyfuel_reference'
                                 */
  real32_T UnitDelay2_InitialCondition;
                              /* Computed Parameter: UnitDelay2_InitialCondition
                               * Referenced by: '<S15>/Unit Delay2'
                               */
  real32_T sampling_sec_Value;         /* Computed Parameter: sampling_sec_Value
                                        * Referenced by: '<S15>/sampling_sec'
                                        */
  real32_T normal_mode_start_sec_Value;
                              /* Computed Parameter: normal_mode_start_sec_Value
                               * Referenced by: '<S15>/normal_mode_start_sec'
                               */
  real32_T Constant1_Value_f;          /* Computed Parameter: Constant1_Value_f
                                        * Referenced by: '<S16>/Constant1'
                                        */
  real32_T Constant_Value_d;           /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S16>/Constant'
                                        */
  real32_T threshold_Value;            /* Computed Parameter: threshold_Value
                                        * Referenced by: '<S17>/threshold'
                                        */
  real32_T Constant1_Value_l;          /* Computed Parameter: Constant1_Value_l
                                        * Referenced by: '<S11>/Constant1'
                                        */
  real32_T Constant2_Value_k;          /* Computed Parameter: Constant2_Value_k
                                        * Referenced by: '<S11>/Constant2'
                                        */
  real32_T Constant3_Value_o;          /* Computed Parameter: Constant3_Value_o
                                        * Referenced by: '<S11>/Constant3'
                                        */
  real32_T DataStoreMemory_InitialValue;
                             /* Computed Parameter: DataStoreMemory_InitialValue
                              * Referenced by: '<S8>/DataStoreMemory'
                              */
  real32_T DataStoreMemory1_InitialValue;
                            /* Computed Parameter: DataStoreMemory1_InitialValue
                             * Referenced by: '<S8>/DataStoreMemory1'
                             */
  real32_T DataStoreMemory2_InitialValue;
                            /* Computed Parameter: DataStoreMemory2_InitialValue
                             * Referenced by: '<S8>/DataStoreMemory2'
                             */
  real32_T DataStoreMemory3_InitialValue;
                            /* Computed Parameter: DataStoreMemory3_InitialValue
                             * Referenced by: '<S8>/DataStoreMemory3'
                             */
  real32_T commanded_fuel_InitialValue;
                              /* Computed Parameter: commanded_fuel_InitialValue
                               * Referenced by: '<S3>/commanded_fuel'
                               */
  real32_T mode_fb1_InitialValue;   /* Computed Parameter: mode_fb1_InitialValue
                                     * Referenced by: '<S3>/mode_fb1'
                                     */
  real32_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S5>/Gain2'
                                        */
  uint32_T uKappa_maxIndex[2];         /* Computed Parameter: uKappa_maxIndex
                                        * Referenced by: '<S7>/1-Kappa'
                                        */
  uint32_T tau_ww_maxIndex[2];         /* Computed Parameter: tau_ww_maxIndex
                                        * Referenced by: '<S7>/tau_ww'
                                        */
  uint32_T delays_maxIndex[2];         /* Computed Parameter: delays_maxIndex
                                        * Referenced by: '<S4>/delay (s)'
                                        */
  boolean_T UnitDelay1_InitialCondition_c;
                            /* Computed Parameter: UnitDelay1_InitialCondition_c
                             * Referenced by: '<S15>/Unit Delay1'
                             */
  boolean_T UnitDelay1_InitialCondition_f;
                            /* Computed Parameter: UnitDelay1_InitialCondition_f
                             * Referenced by: '<S16>/Unit Delay1'
                             */
  boolean_T UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S17>/Unit Delay'
                                */
  boolean_T mode_fb_InitialValue;    /* Computed Parameter: mode_fb_InitialValue
                                      * Referenced by: '<S3>/mode_fb'
                                      */
};

/* External data declarations for dependent source files */
extern const char *RT_MEMORY_ALLOCATION_ERROR;
extern B rtB;                          /* block i/o */
extern X rtX;                          /* states (continuous) */
extern DW rtDW;                        /* states (dwork) */
extern PrevZCX rtPrevZCX;              /* prev zc states*/
extern ExtU rtU;                       /* external inputs */
extern ExtY rtY;                       /* external outputs */
extern P rtP;                          /* parameters */

/* Simulation Structure */
extern SimStruct *const rtS;

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
 * '<Root>' : 'AbstractFuelControl_M1'
 * '<S1>'   : 'AbstractFuelControl_M1/Model 1'
 * '<S2>'   : 'AbstractFuelControl_M1/V&V stub system'
 * '<S3>'   : 'AbstractFuelControl_M1/Model 1/AF_Controller'
 * '<S4>'   : 'AbstractFuelControl_M1/Model 1/Cylinder and Exhaust'
 * '<S5>'   : 'AbstractFuelControl_M1/Model 1/Intake Manifold'
 * '<S6>'   : 'AbstractFuelControl_M1/Model 1/Throttle'
 * '<S7>'   : 'AbstractFuelControl_M1/Model 1/Wall wetting'
 * '<S8>'   : 'AbstractFuelControl_M1/Model 1/AF_Controller/fuel_controller'
 * '<S9>'   : 'AbstractFuelControl_M1/Model 1/AF_Controller/fuel_controller/fuel_controller_10ms'
 * '<S10>'  : 'AbstractFuelControl_M1/Model 1/AF_Controller/fuel_controller/fuel_controller_mode_10ms'
 * '<S11>'  : 'AbstractFuelControl_M1/Model 1/AF_Controller/fuel_controller/fuel_controller_pwon'
 * '<S12>'  : 'AbstractFuelControl_M1/Model 1/AF_Controller/fuel_controller/fuel_controller_10ms/air_estimation'
 * '<S13>'  : 'AbstractFuelControl_M1/Model 1/AF_Controller/fuel_controller/fuel_controller_10ms/feedback_PI_controller'
 * '<S14>'  : 'AbstractFuelControl_M1/Model 1/AF_Controller/fuel_controller/fuel_controller_10ms/feedforward_controller'
 * '<S15>'  : 'AbstractFuelControl_M1/Model 1/AF_Controller/fuel_controller/fuel_controller_mode_10ms/normal_mode_detection'
 * '<S16>'  : 'AbstractFuelControl_M1/Model 1/AF_Controller/fuel_controller/fuel_controller_mode_10ms/power_mode_detection'
 * '<S17>'  : 'AbstractFuelControl_M1/Model 1/AF_Controller/fuel_controller/fuel_controller_mode_10ms/sensor_failure_detection'
 * '<S18>'  : 'AbstractFuelControl_M1/Model 1/Cylinder and Exhaust/A//F_sensor'
 * '<S19>'  : 'AbstractFuelControl_M1/Model 1/Cylinder and Exhaust/Filter'
 * '<S20>'  : 'AbstractFuelControl_M1/Model 1/Cylinder and Exhaust/A//F_sensor/Filter'
 * '<S21>'  : 'AbstractFuelControl_M1/V&V stub system/Calcuate Error'
 * '<S22>'  : 'AbstractFuelControl_M1/V&V stub system/Calcuate Error/RMS error'
 * '<S23>'  : 'AbstractFuelControl_M1/V&V stub system/Calcuate Error/over(under)shoot'
 */

/* user code (bottom of header file) */
extern const int_T gblNumToFiles;
extern const int_T gblNumFrFiles;
extern const int_T gblNumFrWksBlocks;
extern rtInportTUtable *gblInportTUtables;
extern const char *gblInportFileName;
extern const int_T gblNumRootInportBlks;
extern const int_T gblNumModelInputs;
extern const int_T gblInportDataTypeIdx[];
extern const int_T gblInportDims[];
extern const int_T gblInportComplex[];
extern const int_T gblInportInterpoFlag[];
extern const int_T gblInportContinuous[];

#endif                                /* RTW_HEADER_AbstractFuelControl_M1_h_ */
