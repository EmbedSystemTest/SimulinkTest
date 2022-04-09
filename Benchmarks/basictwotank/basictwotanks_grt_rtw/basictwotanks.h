/*
 * basictwotanks.h
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

#ifndef RTW_HEADER_basictwotanks_h_
#define RTW_HEADER_basictwotanks_h_
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef basictwotanks_COMMON_INCLUDES_
# define basictwotanks_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* basictwotanks_COMMON_INCLUDES_ */

#include "basictwotanks_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S33>/Unit Delay' */
  real_T Liquid_Height_Delay_Tank1_DSTAT;/* '<S4>/Liquid_Height_Delay_Tank1' */
  real_T Pump_State_Delay_DSTATE;      /* '<S4>/Pump_State_Delay' */
  real_T Valve_State_Delay_DSTATE;     /* '<S4>/Valve_State_Delay' */
  real_T UnitDelay_DSTATE_c;           /* '<S32>/Unit Delay' */
  real_T Liquid_Height_Delay_Tank2_DSTAT;/* '<S4>/Liquid_Height_Delay_Tank2' */
  real_T Emergency_Valve_State_Delay_DST;/* '<S4>/Emergency_Valve_State_Delay' */
  real_T Production_Valve_State_Delay_DS;/* '<S4>/Production_Valve_State_Delay' */
} DW_basictwotanks_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Product;                /* '<S19>/Product' */
  const real_T Product_g;              /* '<S20>/Product' */
  const real_T Product_p;              /* '<S21>/Product' */
  const real_T Product_h;              /* '<S29>/Product' */
} ConstB_basictwotanks_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T t1_h;                         /* '<Root>/t1_h' */
  real_T t2_h;                         /* '<Root>/t2_h' */
  real_T t1_sh;                        /* '<Root>/t1_sh' */
  real_T t1_sl;                        /* '<Root>/t1_sl' */
  real_T t2_sh;                        /* '<Root>/t2_sh' */
  real_T t2_sm;                        /* '<Root>/t2_sm' */
  real_T t2_sl;                        /* '<Root>/t2_sl' */
  real_T pump_state;                   /* '<Root>/pump_state' */
  real_T valve_state;                  /* '<Root>/valve_state' */
  real_T p_valve_state;                /* '<Root>/p_valve_state' */
  real_T e_valve_state;                /* '<Root>/e_valve_state' */
} ExtY_basictwotanks_T;

/* Real-time Model Data Structure */
struct tag_RTM_basictwotanks_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block states (default storage) */
extern DW_basictwotanks_T basictwotanks_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_basictwotanks_T basictwotanks_Y;
extern const ConstB_basictwotanks_T basictwotanks_ConstB;/* constant block i/o */

/* Model entry point functions */
extern void basictwotanks_initialize(void);
extern void basictwotanks_step(void);
extern void basictwotanks_terminate(void);

/* Real-time Model object */
extern RT_MODEL_basictwotanks_T *const basictwotanks_M;

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
