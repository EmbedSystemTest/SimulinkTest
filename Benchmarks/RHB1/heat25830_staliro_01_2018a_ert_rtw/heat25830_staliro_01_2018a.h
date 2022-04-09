#ifndef RTW_HEADER_heat25830_staliro_01_2018a_h_
#define RTW_HEADER_heat25830_staliro_01_2018a_h_
#include <string.h>
#ifndef heat25830_staliro_01_2018a_COMMON_INCLUDES_
#define heat25830_staliro_01_2018a_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif

#include "heat25830_staliro_01_2018a_types.h"

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

typedef struct {
  real_T Gain2[10];
  real_T Sum[10];
  real_T h[10];
} B_heat25830_staliro_01_2018a_T;

typedef struct {
  uint8_T is_active_c1_heat25830_staliro_;
  boolean_T Relay_Mode[10];
} DW_heat25830_staliro_01_2018a_T;

typedef struct {
  real_T Integrator_CSTATE[10];
} X_heat25830_staliro_01_2018a_T;

typedef struct {
  real_T Integrator_CSTATE[10];
} XDot_heat25830_staliro_01_201_T;

typedef struct {
  boolean_T Integrator_CSTATE[10];
} XDis_heat25830_staliro_01_201_T;

typedef struct {
  const real_T Gain4[100];
  const boolean_T RelationalOperator2[100];
} ConstB_heat25830_staliro_01_2_T;

#ifndef ODE3_INTG
#define ODE3_INTG

typedef struct {
  real_T *y;
  real_T *f[3];
} ODE3_IntgData;

#endif

typedef struct {
  real_T Constant1_Value[10];
  real_T Integrator_IC[10];
  real_T Gain2_Gain[10];
  real_T pooled3[100];
  real_T Diag_Gain[10];
  real_T Gain_Gain[10];
} ConstP_heat25830_staliro_01_2_T;

typedef struct {
  real_T In1;
} ExtU_heat25830_staliro_01_201_T;

typedef struct {
  real_T Out1[10];
} ExtY_heat25830_staliro_01_201_T;

struct tag_RTM_heat25830_staliro_01__T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_heat25830_staliro_01_2018a_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[10];
  real_T odeF[3][10];
  ODE3_IntgData intgData;
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

extern B_heat25830_staliro_01_2018a_T heat25830_staliro_01_2018a_B;
extern X_heat25830_staliro_01_2018a_T heat25830_staliro_01_2018a_X;
extern DW_heat25830_staliro_01_2018a_T heat25830_staliro_01_2018a_DW;
extern ExtU_heat25830_staliro_01_201_T heat25830_staliro_01_2018a_U;
extern ExtY_heat25830_staliro_01_201_T heat25830_staliro_01_2018a_Y;
extern const ConstB_heat25830_staliro_01_2_T heat25830_staliro_01_201_ConstB;
extern const ConstP_heat25830_staliro_01_2_T heat25830_staliro_01_201_ConstP;
extern void heat25830_staliro_01_2018a_initialize(void);
extern void heat25830_staliro_01_2018a_step(void);
extern void heat25830_staliro_01_2018a_terminate(void);
extern RT_MODEL_heat25830_staliro_01_T *const heat25830_staliro_01_2018a_M;

#endif

