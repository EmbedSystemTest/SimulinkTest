#ifndef RTW_HEADER_heat25830_staliro_01_2018a_private_h_
#define RTW_HEADER_heat25830_staliro_01_2018a_private_h_
#include "rtwtypes.h"

#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

extern void heat25830_staliro_01_2018a_derivatives(void);

#endif

