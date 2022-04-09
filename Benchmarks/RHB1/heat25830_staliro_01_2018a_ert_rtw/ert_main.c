#include <stddef.h>
#include <stdio.h>
#include "heat25830_staliro_01_2018a.h"
#include "rtwtypes.h"

void rt_OneStep(void);
void rt_OneStep(void)
{
  static boolean_T OverrunFlag = false;
  if (OverrunFlag) {
    rtmSetErrorStatus(heat25830_staliro_01_2018a_M, "Overrun");
    return;
  }

  OverrunFlag = true;
  heat25830_staliro_01_2018a_step();
  OverrunFlag = false;
}

int_T main(int_T argc, const char *argv[])
{
  (void)(argc);
  (void)(argv);
  heat25830_staliro_01_2018a_initialize();
  while ((rtmGetErrorStatus(heat25830_staliro_01_2018a_M) == (NULL)) &&
         !rtmGetStopRequested(heat25830_staliro_01_2018a_M)) {
    rt_OneStep();
  }

  heat25830_staliro_01_2018a_terminate();
  return 0;
}
