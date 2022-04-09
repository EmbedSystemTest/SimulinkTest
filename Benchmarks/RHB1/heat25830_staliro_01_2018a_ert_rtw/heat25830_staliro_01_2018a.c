#include "heat25830_staliro_01_2018a.h"
#include "heat25830_staliro_01_2018a_private.h"

B_heat25830_staliro_01_2018a_T heat25830_staliro_01_2018a_B;
X_heat25830_staliro_01_2018a_T heat25830_staliro_01_2018a_X;
DW_heat25830_staliro_01_2018a_T heat25830_staliro_01_2018a_DW;
ExtU_heat25830_staliro_01_201_T heat25830_staliro_01_2018a_U;
ExtY_heat25830_staliro_01_201_T heat25830_staliro_01_2018a_Y;
static RT_MODEL_heat25830_staliro_01_T heat25830_staliro_01_2018a_M_;
RT_MODEL_heat25830_staliro_01_T *const heat25830_staliro_01_2018a_M =
  &heat25830_staliro_01_2018a_M_;
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 10;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));
  rtsiSetdX(si, f0);
  heat25830_staliro_01_2018a_derivatives();
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  heat25830_staliro_01_2018a_step();
  heat25830_staliro_01_2018a_derivatives();
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  heat25830_staliro_01_2018a_step();
  heat25830_staliro_01_2018a_derivatives();
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

void heat25830_staliro_01_2018a_step(void)
{
  real_T tmp[100];
  real_T tmp_0[100];
  real_T tmp_1;
  int32_T exitg1;
  int32_T i;
  int32_T i_0;
  int16_T id1;
  int16_T id2;
  boolean_T LogicalOperator[100];
  boolean_T exitg2;
  if (rtmIsMajorTimeStep(heat25830_staliro_01_2018a_M)) {
    rtsiSetSolverStopTime(&heat25830_staliro_01_2018a_M->solverInfo,
                          ((heat25830_staliro_01_2018a_M->Timing.clockTick0+1)*
      heat25830_staliro_01_2018a_M->Timing.stepSize0));
  }

  if (rtmIsMinorTimeStep(heat25830_staliro_01_2018a_M)) {
    heat25830_staliro_01_2018a_M->Timing.t[0] = rtsiGetT
      (&heat25830_staliro_01_2018a_M->solverInfo);
  }

  for (i_0 = 0; i_0 < 10; i_0++) {
    memcpy(&tmp_0[i_0 * 10], &heat25830_staliro_01_2018a_X.Integrator_CSTATE[0],
           10U * sizeof(real_T));
    for (i = 0; i < 10; i++) {
      tmp[i + 10 * i_0] = heat25830_staliro_01_2018a_X.Integrator_CSTATE[i_0];
    }
  }

  for (i_0 = 0; i_0 < 100; i_0++) {
    LogicalOperator[i_0] = ((heat25830_staliro_01_201_ConstB.Gain4[i_0] <=
      tmp[i_0] - tmp_0[i_0]) &&
      heat25830_staliro_01_201_ConstB.RelationalOperator2[i_0]);
  }

  if (rtmIsMajorTimeStep(heat25830_staliro_01_2018a_M)) {
    if (heat25830_staliro_01_2018a_DW.is_active_c1_heat25830_staliro_ == 0U) {
      heat25830_staliro_01_2018a_DW.is_active_c1_heat25830_staliro_ = 1U;
    } else {
      id1 = 0;
      id2 = 0;
      exitg2 = false;
      while ((!exitg2) && (id1 < 10)) {
        if ((heat25830_staliro_01_2018a_X.Integrator_CSTATE[id1] <=
             heat25830_staliro_01_201_ConstP.Constant1_Value[id1]) &&
            (!(heat25830_staliro_01_2018a_B.h[id1] != 0.0))) {
          do {
            exitg1 = 0;
            if (id2 < 10) {
              if (LogicalOperator[10 * id2 + id1] &&
                  (heat25830_staliro_01_2018a_B.h[id2] != 0.0)) {
                heat25830_staliro_01_2018a_B.h[id1] = 1.0;
                heat25830_staliro_01_2018a_B.h[id2] = 0.0;
                exitg1 = 1;
              } else {
                id2++;
              }
            } else {
              id2 = 0;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          } else {
            id1++;
          }
        } else {
          id1++;
        }
      }
    }
  }

  if (rtmIsMajorTimeStep(heat25830_staliro_01_2018a_M)) {
    for (i = 0; i < 10; i++) {
      if (heat25830_staliro_01_2018a_X.Integrator_CSTATE[i] >= 23.0) {
        heat25830_staliro_01_2018a_DW.Relay_Mode[i] = true;
      } else if (heat25830_staliro_01_2018a_X.Integrator_CSTATE[i] <= 20.0) {
        heat25830_staliro_01_2018a_DW.Relay_Mode[i] = false;
      }
    }
  }

  if (rtmIsMajorTimeStep(heat25830_staliro_01_2018a_M)) {
    for (i = 0; i < 10; i++) {
      heat25830_staliro_01_2018a_B.Gain2[i] = (real_T)
        ((!heat25830_staliro_01_2018a_DW.Relay_Mode[i]) &&
         (heat25830_staliro_01_2018a_B.h[i] != 0.0)) *
        heat25830_staliro_01_201_ConstP.Gain2_Gain[i];
    }
  }

  for (i = 0; i < 10; i++) {
    tmp_1 = 0.0;
    for (i_0 = 0; i_0 < 10; i_0++) {
      tmp_1 += heat25830_staliro_01_201_ConstP.pooled3[10 * i_0 + i] *
        heat25830_staliro_01_2018a_X.Integrator_CSTATE[i_0];
    }

    heat25830_staliro_01_2018a_B.Sum[i] =
      ((heat25830_staliro_01_201_ConstP.Diag_Gain[i] *
        heat25830_staliro_01_2018a_X.Integrator_CSTATE[i] + tmp_1) +
       heat25830_staliro_01_2018a_B.Gain2[i]) +
      heat25830_staliro_01_201_ConstP.Gain_Gain[i] *
      heat25830_staliro_01_2018a_U.In1;
    heat25830_staliro_01_2018a_Y.Out1[i] =
      heat25830_staliro_01_2018a_X.Integrator_CSTATE[i];
  }

  if (rtmIsMajorTimeStep(heat25830_staliro_01_2018a_M)) {
    rt_ertODEUpdateContinuousStates(&heat25830_staliro_01_2018a_M->solverInfo);
    ++heat25830_staliro_01_2018a_M->Timing.clockTick0;
    heat25830_staliro_01_2018a_M->Timing.t[0] = rtsiGetSolverStopTime
      (&heat25830_staliro_01_2018a_M->solverInfo);

    {
      heat25830_staliro_01_2018a_M->Timing.clockTick1++;
    }
  }
}

void heat25830_staliro_01_2018a_derivatives(void)
{
  XDot_heat25830_staliro_01_201_T *_rtXdot;
  _rtXdot = ((XDot_heat25830_staliro_01_201_T *)
             heat25830_staliro_01_2018a_M->derivs);
  memcpy(&_rtXdot->Integrator_CSTATE[0], &heat25830_staliro_01_2018a_B.Sum[0],
         10U * sizeof(real_T));
}

void heat25830_staliro_01_2018a_initialize(void)
{
  {
    rtsiSetSimTimeStepPtr(&heat25830_staliro_01_2018a_M->solverInfo,
                          &heat25830_staliro_01_2018a_M->Timing.simTimeStep);
    rtsiSetTPtr(&heat25830_staliro_01_2018a_M->solverInfo, &rtmGetTPtr
                (heat25830_staliro_01_2018a_M));
    rtsiSetStepSizePtr(&heat25830_staliro_01_2018a_M->solverInfo,
                       &heat25830_staliro_01_2018a_M->Timing.stepSize0);
    rtsiSetdXPtr(&heat25830_staliro_01_2018a_M->solverInfo,
                 &heat25830_staliro_01_2018a_M->derivs);
    rtsiSetContStatesPtr(&heat25830_staliro_01_2018a_M->solverInfo, (real_T **)
                         &heat25830_staliro_01_2018a_M->contStates);
    rtsiSetNumContStatesPtr(&heat25830_staliro_01_2018a_M->solverInfo,
      &heat25830_staliro_01_2018a_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&heat25830_staliro_01_2018a_M->solverInfo,
      &heat25830_staliro_01_2018a_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&heat25830_staliro_01_2018a_M->solverInfo,
      &heat25830_staliro_01_2018a_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&heat25830_staliro_01_2018a_M->solverInfo,
      &heat25830_staliro_01_2018a_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&heat25830_staliro_01_2018a_M->solverInfo,
                          (&rtmGetErrorStatus(heat25830_staliro_01_2018a_M)));
    rtsiSetRTModelPtr(&heat25830_staliro_01_2018a_M->solverInfo,
                      heat25830_staliro_01_2018a_M);
  }

  rtsiSetSimTimeStep(&heat25830_staliro_01_2018a_M->solverInfo, MAJOR_TIME_STEP);
  heat25830_staliro_01_2018a_M->intgData.y = heat25830_staliro_01_2018a_M->odeY;
  heat25830_staliro_01_2018a_M->intgData.f[0] =
    heat25830_staliro_01_2018a_M->odeF[0];
  heat25830_staliro_01_2018a_M->intgData.f[1] =
    heat25830_staliro_01_2018a_M->odeF[1];
  heat25830_staliro_01_2018a_M->intgData.f[2] =
    heat25830_staliro_01_2018a_M->odeF[2];
  heat25830_staliro_01_2018a_M->contStates = ((X_heat25830_staliro_01_2018a_T *)
    &heat25830_staliro_01_2018a_X);
  rtsiSetSolverData(&heat25830_staliro_01_2018a_M->solverInfo, (void *)
                    &heat25830_staliro_01_2018a_M->intgData);
  rtsiSetSolverName(&heat25830_staliro_01_2018a_M->solverInfo,"ode3");
  rtmSetTPtr(heat25830_staliro_01_2018a_M,
             &heat25830_staliro_01_2018a_M->Timing.tArray[0]);
  heat25830_staliro_01_2018a_M->Timing.stepSize0 = 0.05;
  memcpy(&heat25830_staliro_01_2018a_X.Integrator_CSTATE[0],
         &heat25830_staliro_01_201_ConstP.Integrator_IC[0], 10U * sizeof(real_T));
  heat25830_staliro_01_2018a_B.h[0] = 0.0;
  heat25830_staliro_01_2018a_B.h[1] = 0.0;
  heat25830_staliro_01_2018a_B.h[2] = 1.0;
  heat25830_staliro_01_2018a_B.h[3] = 1.0;
  heat25830_staliro_01_2018a_B.h[4] = 1.0;
  heat25830_staliro_01_2018a_B.h[5] = 0.0;
  heat25830_staliro_01_2018a_B.h[6] = 0.0;
  heat25830_staliro_01_2018a_B.h[7] = 1.0;
  heat25830_staliro_01_2018a_B.h[8] = 0.0;
  heat25830_staliro_01_2018a_B.h[9] = 0.0;
}

void heat25830_staliro_01_2018a_terminate(void)
{
}
