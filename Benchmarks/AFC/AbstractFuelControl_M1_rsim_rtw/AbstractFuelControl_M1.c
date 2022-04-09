/*
 * AbstractFuelControl_M1.c
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

#include <math.h>
#include "AbstractFuelControl_M1.h"
#include "AbstractFuelControl_M1_private.h"
#include "AbstractFuelControl_M1_dt.h"

/* user code (top of parameter file) */
const int_T gblNumToFiles = 0;
const int_T gblNumFrFiles = 0;
const int_T gblNumFrWksBlocks = 0;
const char *gblSlvrJacPatternFileName =
  "AbstractFuelControl_M1_rsim_rtw\\AbstractFuelControl_M1_Jpattern.mat";

/* Root inports information  */
const int_T gblNumRootInportBlks = 2;
const int_T gblNumModelInputs = 2;
extern rtInportTUtable *gblInportTUtables;
extern const char *gblInportFileName;
const int_T gblInportDataTypeIdx[] = { 0, 0 };

const int_T gblInportDims[] = { 1, 1, 1, 1 } ;

const int_T gblInportComplex[] = { 0, 0 };

const int_T gblInportInterpoFlag[] = { 1, 1 };

const int_T gblInportContinuous[] = { 1, 1 };

#include "simstruc.h"
#include "fixedpoint.h"

/* Block signals (default storage) */
B rtB;

/* Continuous states */
X rtX;

/* Block states (default storage) */
DW rtDW;

/* Previous zero-crossings (trigger) states */
PrevZCX rtPrevZCX;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Parent Simstruct */
static SimStruct model_S;
SimStruct *const rtS = &model_S;

#ifndef __RTW_UTFREE__

extern void * utMalloc(size_t);

#endif

/* Time delay buffer creation routine */
void * rt_TDelayCreateBuf(
  int_T numBuffer,
  int_T bufSz,
  int_T elemSz)
{
  return((void*)utMalloc(numBuffer*bufSz*elemSz));
}

#ifndef __RTW_UTFREE__

extern void * utMalloc(size_t);
extern void utFree(void *);

#endif

/* Buffer management routine for variable delay block */
boolean_T rt_TDelayUpdateTailOrGrowBuf(
  int_T *bufSzPtr,           /* in/out - circular buffer size                 */
  int_T *tailPtr,            /* in/out - tail of circular buffer              */
  int_T *headPtr,            /* in/out - head of circular buffer              */
  int_T *lastPtr,            /* in/out - same logical 'last' referenced index */
  real_T tMinusDelay,              /* in     - last point we are looking at   */
  real_T **uBufPtr,                /* in/out - larger buffer for input        */
  boolean_T isfixedbuf,            /* in     - fixed buffer size enable       */
  boolean_T istransportdelay,      /* in     - block acts as transport dela y */
  int_T *maxNewBufSzPtr)
{
  int_T testIdx;
  int_T tail = *tailPtr;
  int_T bufSz = *bufSzPtr;
  real_T *tBuf = *uBufPtr + bufSz;
  real_T *xBuf = (NULL);
  int_T numBuffer = 2;
  if (istransportdelay) {
    numBuffer = 3 ;
    xBuf= *uBufPtr + 2 * bufSz;
  }

  /*    Get testIdx, the index of the second oldest data point and
   *    see if this is older than current sim time minus applied delay,
   *    used to see if we can move tail forward
   */
  testIdx = (tail < (bufSz - 1)) ? (tail + 1) : 0;
  if ((tMinusDelay <= tBuf[testIdx]) && !isfixedbuf) {
    int_T j;
    real_T *tempT;
    real_T *tempU;
    real_T *tempX = (NULL);
    real_T *uBuf = *uBufPtr;
    int_T newBufSz = bufSz + 1024;
    if (newBufSz > *maxNewBufSzPtr) {
      *maxNewBufSzPtr = newBufSz;      /* save for warning*/
    }

    tempU = (real_T*)utMalloc(numBuffer*newBufSz*sizeof(real_T));
    if (tempU == (NULL)) {
      return (false);
    }

    tempT = tempU + newBufSz;
    if (istransportdelay)
      tempX = tempT + newBufSz;
    for (j = tail; j < bufSz; j++) {
      tempT[j - tail] = tBuf[j];
      tempU[j - tail] = uBuf[j];
      if (istransportdelay)
        tempX[j - tail] = xBuf[j];
    }

    for (j = 0; j < tail; j++) {
      tempT[j + bufSz - tail] = tBuf[j];
      tempU[j + bufSz - tail] = uBuf[j];
      if (istransportdelay)
        tempX[j + bufSz - tail] = xBuf[j];
    }

    if (*lastPtr> tail) {
      *lastPtr -= tail;
    } else {
      *lastPtr += (bufSz - tail);
    }

    *tailPtr= 0;
    *headPtr = bufSz;
    utFree(uBuf);
    *bufSzPtr = newBufSz;
    *uBufPtr = tempU;
  } else {
    *tailPtr = testIdx;                /* move tail forward */
  }

  return(true);
}

/* For variable transport delay block, find the real delay time */
real_T rt_VTDelayfindtDInterpolate(
  real_T x,real_T* uBuf,int_T bufSz,int_T head,int_T tail,int_T* pLast,real_T t,
  real_T tStart,boolean_T discrete,boolean_T minorStepAndTAtLastMajorOutput,
  real_T initOutput,real_T* appliedDelay)
{
  int_T n, k;
  real_T f;
  int_T kp1;
  real_T tminustD, tL, tR, uD, uL, uR, fU;
  real_T* tBuf = uBuf + bufSz;
  real_T* xBuf = uBuf + 2* bufSz;
  if (minorStepAndTAtLastMajorOutput) {
    /* pretend that the entry at head has not been added */
    if (*pLast == head) {
      *pLast = (*pLast == 0) ? bufSz-1 : *pLast-1;
    }

    head = (head == 0) ? bufSz-1 : head-1;
  }

  /*
   * The loop below finds k such that:
   *      x(t)-x(tminustD) =1 or
   *      x - xBuf[k+1] <= 1.0 < x - xBuf[k]
   *
   * Note that we have:
   *
   * tStart = tBuf[0] < tBuf[1] < ... < tBuf[tail] < ... tBuf[head] <= t
   *      0 = xBuf[0] < xBuf[1] < ... < xBuf[tail] < ... xBuf[head] <  x
   *
   * This is true if we assume the direction of transport is always positive
   * such as a flow goes through a pipe from one end to another. However, for
   * model such as convey belt, the transportation can change direction. For
   * this case, there will be more than one solution to x(t)-x(tminustD) = 1,
   * should found the minimum tminustD and tminustD > 0. The search will not
   * be as efficient as the following code.
   */

  /*
   * when x<=1, physically it means the flow didn't reach the output yet,
   * t-tD will be less then zero, so force output to be the initial output
   */
  if (x <= 1) {
    return initOutput;
  }

  /*
   * if the x is monoton increase, only one solution. use k=pLast for now
   */
  k= *pLast;
  n = 0;
  for (;;) {
    n++;
    if (n>bufSz)
      break;
    if (x - xBuf[k] > 1.0) {
      /* move k forward, unless k = head */
      if (k == head) {
        /* xxx this situation means tD= appliedDelay = 0
         *
         * linearly interpolate using (tBuf[head], xBuf[head])
         * and (t,x) to find (tD,xD) such that: x - xD = 1.0
         */
        int_T km1;
        f = (x - 1.0 - xBuf[k]) / (x - xBuf[k]);
        tminustD = (1.0-f)*tBuf[k] + f*t;
        km1 = k-1;
        if (km1 < 0)
          km1 = bufSz-1;
        tL = tBuf[km1];
        tR = tBuf[k];
        uL = uBuf[km1];
        uR = uBuf[k];
        break;
      }

      kp1 = k+1;
      if (kp1 == bufSz)
        kp1 = 0;
      if (x - xBuf[kp1] <= 1.0) {
        /*
         * linearly interpolate using (tBuf[k], xBuf[k])
         * and  (tBuf[k+1], xBuf[k+1]) to find (tminustD,xD)
         * such that: x - xD = 1.0
         */
        f = (x - 1.0 - xBuf[k]) / (xBuf[kp1] - xBuf[k]);
        tL = tBuf[k];
        tR = tBuf[kp1];
        uL = uBuf[k];
        uR = uBuf[kp1];
        tminustD = (1.0-f)*tL + f*tR;
        break;
      }

      k = kp1;
    } else {
      /* moved k backward, unless k = tail */
      if (k == tail) {
        /* This situation means tminustD <= Ttail*/
        f = (x - 1.0)/xBuf[k];
        if (discrete) {
          return(uBuf[tail]);
        }

        kp1 = k+1;
        if (kp1 == bufSz)
          kp1 = 0;

        /* * linearly interpolate using (tStart, 0)
         * and  (tBuf[tail], xBuf[tail]) to find (tminustD,xD)
         * such that: x - xD = 1.0
         */

        /* Here it is better to use Tstart because since x>1, tminustD
         * must > 0. Since x is monotone increase, its linearity is
         * better.
         */
        tminustD = (1-f)*tStart + f*tBuf[k];

        /* linearly interpolate using (t[tail], x[tail])
         * and  (tBuf[tail+1], xBuf[tail+1]) to find (tminustD,xD)
         * such that: x - xD = 1.0.
         * For time delay block, use t[tail] and t[tail+1], not good
         * for transport delay block since it may give tminstD < 0
         */

        /*  f = (tBuf[kp1]-tBuf[k])/(xBuf[kp1]-xBuf[k]);
         *  tminustD = tBuf[kp1]-f*(1+xBuf[kp1]-x);
         */
        tL = tBuf[k];
        tR = tBuf[kp1];
        uL = uBuf[k];
        uR = uBuf[kp1];
        break;
      }

      k = k - 1;
      if (k < 0)
        k = bufSz-1;
    }
  }

  *pLast = k;
  if (tR == tL) {
    fU = 1.0;
  } else {
    fU = (tminustD-tL)/(tR-tL);
  }

  /* for discrete signal, no interpolation, use either uL or uR
   * depend on wehre tminustD is.
   */
  if (discrete) {
    uD= (fU > (1.0-fU))? uR: uL;
  } else {
    uD = (1.0-fU)*uL + fU*uR;
  }

  /* we want return tD= t-(t-tD);*/
  *appliedDelay = t-tminustD;
  return uD;
}

real_T look2_binlxpw(real_T u0, real_T u1, const real_T bp0[], const real_T bp1[],
                     const real_T table[], const uint32_T maxIndex[], uint32_T
                     stride)
{
  real_T fractions[2];
  real_T frac;
  real_T yL_0d0;
  real_T yL_0d1;
  uint32_T bpIndices[2];
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 2-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex[0U]]) {
    /* Binary Search */
    bpIdx = maxIndex[0U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[0U];
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex[0U] - 1U;
    frac = (u0 - bp0[maxIndex[0U] - 1U]) / (bp0[maxIndex[0U]] - bp0[maxIndex[0U]
      - 1U]);
  }

  fractions[0U] = frac;
  bpIndices[0U] = iLeft;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u1 <= bp1[0U]) {
    iLeft = 0U;
    frac = (u1 - bp1[0U]) / (bp1[1U] - bp1[0U]);
  } else if (u1 < bp1[maxIndex[1U]]) {
    /* Binary Search */
    bpIdx = maxIndex[1U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[1U];
    while (iRght - iLeft > 1U) {
      if (u1 < bp1[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u1 - bp1[iLeft]) / (bp1[iLeft + 1U] - bp1[iLeft]);
  } else {
    iLeft = maxIndex[1U] - 1U;
    frac = (u1 - bp1[maxIndex[1U] - 1U]) / (bp1[maxIndex[1U]] - bp1[maxIndex[1U]
      - 1U]);
  }

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  bpIdx = iLeft * stride + bpIndices[0U];
  yL_0d0 = table[bpIdx];
  yL_0d0 += (table[bpIdx + 1U] - yL_0d0) * fractions[0U];
  bpIdx += stride;
  yL_0d1 = table[bpIdx];
  return (((table[bpIdx + 1U] - yL_0d1) * fractions[0U] + yL_0d1) - yL_0d0) *
    frac + yL_0d0;
}

#ifndef __RTW_UTFREE__

extern void utFree(void *);

#endif

/* Time delay buffer deletion routine */
void rt_TDelayFreeBuf(
                      void * buf)
{
  utFree(buf);
}

/* System initialize for root system: '<Root>' */
void MdlInitialize(void)
{
  /* SystemInitialize for Atomic SubSystem: '<Root>/Model 1' */
  /* InitializeConditions for Integrator: '<S20>/Integrator' */
  rtX.Integrator_CSTATE_m = rtP.Integrator_IC;

  /* InitializeConditions for TransferFcn: '<S1>/Throttle delay' */
  rtX.Throttledelay_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S5>/p0 = 0.543 (bar)' */
  rtX.p00543bar_CSTATE = rtP.p00543bar_IC;

  /* InitializeConditions for Integrator: '<S19>/Integrator' */
  rtX.Integrator_CSTATE_h = rtP.Integrator_IC_l;

  /* InitializeConditions for Integrator: '<S7>/Integrator' */
  rtX.Integrator_CSTATE_c = rtP.Integrator_IC_m;

  /* InitializeConditions for VariableTransportDelay: '<S4>/fuel system transport delay' */
  rtX.fuelsystemtransportdelay_CSTATE = 0.0;

  /* SystemInitialize for Atomic SubSystem: '<S1>/AF_Controller' */
  /* SystemInitialize for Atomic SubSystem: '<S3>/fuel_controller' */
  /* SystemInitialize for Triggered SubSystem: '<S8>/fuel_controller_mode_10ms' */
  /* SystemInitialize for Atomic SubSystem: '<S10>/sensor_failure_detection' */
  /* InitializeConditions for UnitDelay: '<S17>/Unit Delay' */
  rtDW.UnitDelay_DSTATE = rtP.UnitDelay_InitialCondition;

  /* End of SystemInitialize for SubSystem: '<S10>/sensor_failure_detection' */

  /* SystemInitialize for Atomic SubSystem: '<S10>/normal_mode_detection' */
  /* InitializeConditions for UnitDelay: '<S15>/Unit Delay2' */
  rtDW.UnitDelay2_DSTATE = rtP.UnitDelay2_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S15>/Unit Delay1' */
  rtDW.UnitDelay1_DSTATE_e = rtP.UnitDelay1_InitialCondition_c;

  /* End of SystemInitialize for SubSystem: '<S10>/normal_mode_detection' */

  /* SystemInitialize for Atomic SubSystem: '<S10>/power_mode_detection' */
  /* InitializeConditions for UnitDelay: '<S16>/Unit Delay1' */
  rtDW.UnitDelay1_DSTATE_a = rtP.UnitDelay1_InitialCondition_f;

  /* End of SystemInitialize for SubSystem: '<S10>/power_mode_detection' */
  /* End of SystemInitialize for SubSystem: '<S8>/fuel_controller_mode_10ms' */

  /* SystemInitialize for Triggered SubSystem: '<S8>/fuel_controller_10ms' */
  /* SystemInitialize for Atomic SubSystem: '<S9>/air_estimation' */
  /* InitializeConditions for UnitDelay: '<S12>/UnitDelay1' */
  rtDW.UnitDelay1_DSTATE_d = rtP.UnitDelay1_InitialCondition;

  /* End of SystemInitialize for SubSystem: '<S9>/air_estimation' */

  /* SystemInitialize for Enabled SubSystem: '<S9>/feedback_PI_controller' */
  /* InitializeConditions for UnitDelay: '<S13>/UnitDelay1' */
  rtDW.UnitDelay1_DSTATE = rtP.UnitDelay1_InitialCondition_l;

  /* End of SystemInitialize for SubSystem: '<S9>/feedback_PI_controller' */
  /* End of SystemInitialize for SubSystem: '<S8>/fuel_controller_10ms' */
  /* End of SystemInitialize for SubSystem: '<S3>/fuel_controller' */
  /* End of SystemInitialize for SubSystem: '<S1>/AF_Controller' */
  /* End of SystemInitialize for SubSystem: '<Root>/Model 1' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/V&V stub system' */
  /* SystemInitialize for Enabled SubSystem: '<S2>/Calcuate Error' */
  /* SystemInitialize for IfAction SubSystem: '<S21>/RMS error' */
  /* InitializeConditions for Integrator: '<S22>/Integrator' */
  rtX.Integrator_CSTATE = rtP.Integrator_IC_b;

  /* End of SystemInitialize for SubSystem: '<S21>/RMS error' */
  /* End of SystemInitialize for SubSystem: '<S2>/Calcuate Error' */
  /* End of SystemInitialize for SubSystem: '<Root>/V&V stub system' */
}

/* Start for root system: '<Root>' */
void MdlStart(void)
{
  /* Start for Atomic SubSystem: '<Root>/Model 1' */
  /* Start for Atomic SubSystem: '<S1>/AF_Controller' */
  /* Start for DiscretePulseGenerator: '<S3>/PulseGenerator_10ms' */
  rtDW.clockTickCounter = -200;

  /* Start for Atomic SubSystem: '<S3>/fuel_controller' */
  /* Start for DataStoreMemory: '<S8>/DataStoreMemory' */
  rtDW.engine_speed = rtP.DataStoreMemory_InitialValue;

  /* Start for DataStoreMemory: '<S8>/DataStoreMemory1' */
  rtDW.throttle_flow = rtP.DataStoreMemory1_InitialValue;

  /* Start for DataStoreMemory: '<S8>/DataStoreMemory2' */
  rtDW.airbyfuel_meas = rtP.DataStoreMemory2_InitialValue;

  /* Start for DataStoreMemory: '<S8>/DataStoreMemory3' */
  rtDW.throttle_angle = rtP.DataStoreMemory3_InitialValue;

  /* End of Start for SubSystem: '<S3>/fuel_controller' */

  /* Start for DataStoreMemory: '<S3>/commanded_fuel' */
  rtDW.commanded_fuel = rtP.commanded_fuel_InitialValue;

  /* Start for DataStoreMemory: '<S3>/mode_fb' */
  rtDW.controller_mode = rtP.mode_fb_InitialValue;

  /* Start for DataStoreMemory: '<S3>/mode_fb1' */
  rtDW.airbyfuel_ref = rtP.mode_fb1_InitialValue;

  /* End of Start for SubSystem: '<S1>/AF_Controller' */

  /* Start for VariableTransportDelay: '<S4>/fuel system transport delay' */
  {
    int_T j;

    {
      real_T *pBuffer = (real_T *)rt_TDelayCreateBuf(3, 20480, sizeof(real_T));
      if (pBuffer == (NULL)) {
        ssSetErrorStatus(rtS, "vtdelay memory allocation error");
        return;
      }

      rtDW.fuelsystemtransportdelay_IWORK.Tail = 0;
      rtDW.fuelsystemtransportdelay_IWORK.Head = 0;
      rtDW.fuelsystemtransportdelay_IWORK.Last = 0;
      rtDW.fuelsystemtransportdelay_IWORK.CircularBufSize = 20480;
      for (j=0; j < 20480; j++) {
        pBuffer[j] = rtP.fuelsystemtransportdelay_InitOu;
        pBuffer[20480 + j] = ssGetT(rtS);
      }

      pBuffer[2*20480] = 0.0;
      rtDW.fuelsystemtransportdelay_PWORK.TUbufferPtrs[0] = (void *) &pBuffer[0];
    }
  }

  /* End of Start for SubSystem: '<Root>/Model 1' */

  /* Start for Atomic SubSystem: '<Root>/V&V stub system' */
  /* Start for Enabled SubSystem: '<S2>/Calcuate Error' */
  rtDW.CalcuateError_MODE = false;
  ssSetBlockStateForSolverChangedAtMajorStep(rtS);

  /* Start for SwitchCase: '<S21>/Switch Case' */
  rtDW.SwitchCase_ActiveSubsystem = -1;

  /* End of Start for SubSystem: '<S2>/Calcuate Error' */
  /* End of Start for SubSystem: '<Root>/V&V stub system' */
  MdlInitialize();
}

/* Outputs for root system: '<Root>' */
void MdlOutputs(int_T tid)
{
  /* local block i/o variables */
  real_T rtb_fuelsystemtransportdelay;
  real_T rtb_Gain2;
  real_T rtb_Integrator;
  real_T rtb_Kappatolerance0911;
  real_T rtb_MeasureOn_m;
  real_T rtb_fuel_puddle_evap;
  real_T rtb_fuelinjectortolerance095105;
  real_T rtb_pratio;
  real_T rtb_radstorpm;
  real_T u0;
  real32_T Sum2;
  real32_T rtb_Sum3;
  real32_T rtb_fuel_saturation;
  int8_T rtAction;
  boolean_T LogicalOperator;
  boolean_T LogicalOperator_a;
  boolean_T RelationalOperator1;
  ZCEventType zcEvent;

  /* Read data from the mat file of inport block */
  if (gblInportFileName != (NULL)) {
    int_T currTimeIdx;
    int_T i;

    /*
     *  Read in data from mat file for root inport EngineSpeed
     */
    if (gblInportTUtables[0].nTimePoints > 0) {
      if (1) {
        {
          real_T time = ssGetTaskTime(rtS,0);
          int k = 1;
          if (gblInportTUtables[0].nTimePoints == 1) {
            k = 0;
          }

          currTimeIdx = rt_getTimeIdx(gblInportTUtables[0].time, time,
            gblInportTUtables[0].nTimePoints,
            *(gblInportTUtables[0].currTimeIdx),
            1,
            0);
          (*gblInportTUtables[0].currTimeIdx) = currTimeIdx;
          for (i = 0; i < 1; i++) {
            real_T* realPtr1 = (real_T*)gblInportTUtables[0].ur +
              i*gblInportTUtables[0].nTimePoints +currTimeIdx;
            real_T* realPtr2 = realPtr1 + 1*k;
            (void)rt_Interpolate_Datatype(
              realPtr1,
              realPtr2,
              &rtU.EngineSpeed,
              time,
              gblInportTUtables[0].time[currTimeIdx],
              gblInportTUtables[0].time[currTimeIdx + k],
              gblInportTUtables[0].uDataType);
          }
        }
      }
    }

    /*
     *  Read in data from mat file for root inport PedalAngle
     */
    if (gblInportTUtables[1].nTimePoints > 0) {
      if (1) {
        {
          real_T time = ssGetTaskTime(rtS,0);
          int k = 1;
          if (gblInportTUtables[1].nTimePoints == 1) {
            k = 0;
          }

          currTimeIdx = rt_getTimeIdx(gblInportTUtables[1].time, time,
            gblInportTUtables[1].nTimePoints,
            *(gblInportTUtables[1].currTimeIdx),
            1,
            0);
          (*gblInportTUtables[1].currTimeIdx) = currTimeIdx;
          for (i = 0; i < 1; i++) {
            real_T* realPtr1 = (real_T*)gblInportTUtables[1].ur +
              i*gblInportTUtables[1].nTimePoints +currTimeIdx;
            real_T* realPtr2 = realPtr1 + 1*k;
            (void)rt_Interpolate_Datatype(
              realPtr1,
              realPtr2,
              &rtU.PedalAngle,
              time,
              gblInportTUtables[1].time[currTimeIdx],
              gblInportTUtables[1].time[currTimeIdx + k],
              gblInportTUtables[1].uDataType);
          }
        }
      }
    }
  }

  /* end read inport data from file */

  /* Outputs for Atomic SubSystem: '<Root>/Model 1' */
  /* Integrator: '<S20>/Integrator' */
  rtb_MeasureOn_m = rtX.Integrator_CSTATE_m;

  /* Gain: '<S18>/A//F_sensor' incorporates:
   *  Integrator: '<S20>/Integrator'
   */
  rtB.AF_sensor = rtP.AF_sensor_Gain * rtX.Integrator_CSTATE_m;

  /* Sum: '<S1>/Sum' incorporates:
   *  Constant: '<S1>/Base opening angle'
   *  TransferFcn: '<S1>/Throttle delay'
   */
  u0 = rtP.Throttledelay_C * rtX.Throttledelay_CSTATE +
    rtP.Baseopeningangle_Value;

  /* Saturate: '<S1>/theta [0 90]' */
  if (u0 > rtP.theta090_UpperSat) {
    /* Saturate: '<S1>/theta [0 90]' */
    rtB.theta090 = rtP.theta090_UpperSat;
  } else if (u0 < rtP.theta090_LowerSat) {
    /* Saturate: '<S1>/theta [0 90]' */
    rtB.theta090 = rtP.theta090_LowerSat;
  } else {
    /* Saturate: '<S1>/theta [0 90]' */
    rtB.theta090 = u0;
  }

  /* End of Saturate: '<S1>/theta [0 90]' */
  if (ssIsSampleHit(rtS, 1, 0)) {
  }

  /* Saturate: '<S1>/Engine Speed [900 1100]' incorporates:
   *  Inport: '<Root>/Engine Speed (rpm)'
   */
  if (rtU.EngineSpeed > rtP.EngineSpeed9001100_UpperSat) {
    u0 = rtP.EngineSpeed9001100_UpperSat;
  } else if (rtU.EngineSpeed < rtP.EngineSpeed9001100_LowerSat) {
    u0 = rtP.EngineSpeed9001100_LowerSat;
  } else {
    u0 = rtU.EngineSpeed;
  }

  /* End of Saturate: '<S1>/Engine Speed [900 1100]' */

  /* Gain: '<S1>/(rpm) to (rad//s)' */
  rtb_radstorpm = rtP.rpmtorads_Gain * u0;

  /* VariableTransportDelay: '<S4>/fuel system transport delay' incorporates:
   *  Integrator: '<S5>/p0 = 0.543 (bar)'
   */
  rtb_fuelsystemtransportdelay = rtX.p00543bar_CSTATE;

  /* Product: '<S6>/Product1' incorporates:
   *  Constant: '<S1>/Atmospheric Pressure (bar)'
   */
  u0 = rtb_fuelsystemtransportdelay / rtP.AtmosphericPressurebar_Value;

  /* Product: '<S6>/Product2' incorporates:
   *  Constant: '<S1>/Atmospheric Pressure (bar)'
   */
  rtb_pratio = 1.0 / rtb_fuelsystemtransportdelay *
    rtP.AtmosphericPressurebar_Value;

  /* MinMax: '<S6>/MinMax' */
  if ((u0 <= rtb_pratio) || rtIsNaN(rtb_pratio)) {
    rtb_pratio = u0;
  }

  /* End of MinMax: '<S6>/MinMax' */

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S6>/Sonic Flow '
   *  Fcn: '<S6>/g(pratio)'
   */
  if (rtb_pratio >= rtP.Switch_Threshold_g) {
    /* Fcn: '<S6>/g(pratio)' */
    rtb_pratio -= rtb_pratio * rtb_pratio;
    if (rtb_pratio < 0.0) {
      rtb_pratio = -sqrt(-rtb_pratio);
    } else {
      rtb_pratio = sqrt(rtb_pratio);
    }

    rtb_pratio *= 2.0;
  } else {
    rtb_pratio = rtP.SonicFlow_Value;
  }

  /* End of Switch: '<S6>/Switch' */

  /* Sum: '<S6>/Sum' incorporates:
   *  Constant: '<S1>/Atmospheric Pressure (bar)'
   */
  u0 = rtP.AtmosphericPressurebar_Value - rtb_fuelsystemtransportdelay;

  /* Signum: '<S6>/flow direction' */
  if (u0 < 0.0) {
    u0 = -1.0;
  } else if (u0 > 0.0) {
    u0 = 1.0;
  } else if (u0 == 0.0) {
    u0 = 0.0;
  } else {
    u0 = (rtNaN);
  }

  /* End of Signum: '<S6>/flow direction' */

  /* Product: '<S6>/Product' incorporates:
   *  Fcn: '<S6>/f(theta)'
   */
  rtb_pratio = (((2.821 - 0.05231 * rtB.theta090) + 0.10299 * rtB.theta090 *
                 rtB.theta090) - 0.00063 * rtB.theta090 * rtB.theta090 *
                rtB.theta090) * rtb_pratio * u0;

  /* Outputs for Atomic SubSystem: '<Root>/V&V stub system' */
  /* Outputs for Enabled SubSystem: '<S2>/Calcuate Error' incorporates:
   *  EnablePort: '<S21>/Enable'
   */
  /* Outputs for IfAction SubSystem: '<S21>/RMS error' incorporates:
   *  ActionPort: '<S22>/Action Port'
   */
  /* Outputs for Atomic SubSystem: '<S1>/AF_Controller' */
  /* SwitchCase: '<S21>/Switch Case' incorporates:
   *  Step: '<S1>/A//F Sensor Fault Injection'
   *  Step: '<S22>/MeasureOn'
   *  Step: '<S2>/MeasureOn'
   *  Step: '<S3>/Pwon'
   */
  u0 = ssGetTaskTime(rtS,0);

  /* End of Outputs for SubSystem: '<S21>/RMS error' */
  /* End of Outputs for SubSystem: '<S2>/Calcuate Error' */
  /* End of Outputs for SubSystem: '<Root>/V&V stub system' */

  /* Step: '<S3>/Pwon' */
  if (u0 < rtP.Pwon_Time) {
    /* Step: '<S3>/Pwon' */
    rtB.Pwon = rtP.Pwon_Y0;
  } else {
    /* Step: '<S3>/Pwon' */
    rtB.Pwon = rtP.Pwon_YFinal;
  }

  if (ssIsSampleHit(rtS, 1, 0)) {
    /* DiscretePulseGenerator: '<S3>/PulseGenerator_10ms' */
    rtB.PulseGenerator_10ms = (rtDW.clockTickCounter <
      rtP.PulseGenerator_10ms_Duty) && (rtDW.clockTickCounter >= 0) ?
      rtP.PulseGenerator_10ms_Amp : 0.0;

    /* DiscretePulseGenerator: '<S3>/PulseGenerator_10ms' */
    if (rtDW.clockTickCounter >= rtP.PulseGenerator_10ms_Period - 1.0) {
      rtDW.clockTickCounter = 0;
    } else {
      rtDW.clockTickCounter++;
    }
  }

  /* Outputs for Atomic SubSystem: '<S3>/fuel_controller' */
  /* DataStoreWrite: '<S8>/DataStoreWrite' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion1'
   */
  rtDW.engine_speed = (real32_T)rtb_radstorpm;

  /* DataStoreWrite: '<S8>/DataStoreWrite3' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion4'
   */
  rtDW.throttle_angle = (real32_T)rtB.theta090;

  /* DataStoreWrite: '<S8>/DataStoreWrite1' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion2'
   *  Gain: '<S1>/MAF sensor tolerance [0.95 1.05]'
   */
  rtDW.throttle_flow = (real32_T)(rtP.MAF_sensor_tol * rtb_pratio);

  /* End of Outputs for SubSystem: '<S3>/fuel_controller' */
  /* End of Outputs for SubSystem: '<S1>/AF_Controller' */

  /* Step: '<S1>/A//F Sensor Fault Injection' */
  if (u0 < rtP.fault_time) {
    rtb_Integrator = rtP.AFSensorFaultInjection_Y0;
  } else {
    rtb_Integrator = rtP.AFSensorFaultInjection_YFinal;
  }

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/FaultySensorOutput'
   */
  if (rtb_Integrator >= rtP.Switch_Threshold) {
    rtb_Integrator = rtP.FaultySensorOutput_Value;
  } else {
    rtb_Integrator = rtB.AF_sensor;
  }

  /* End of Switch: '<S4>/Switch' */

  /* Outputs for Atomic SubSystem: '<S1>/AF_Controller' */
  /* Outputs for Atomic SubSystem: '<S3>/fuel_controller' */
  /* DataStoreWrite: '<S8>/DataStoreWrite2' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion3'
   *  Gain: '<S1>/A//F sensor tolerance [0.99 1.01]'
   */
  rtDW.airbyfuel_meas = (real32_T)(rtP.AF_sensor_tol * rtb_Integrator);
  if (ssIsSampleHit(rtS, 1, 0)) {
    /* Outputs for Triggered SubSystem: '<S8>/fuel_controller_10ms' incorporates:
     *  TriggerPort: '<S9>/Function'
     */
    /* Outputs for Triggered SubSystem: '<S8>/fuel_controller_mode_10ms' incorporates:
     *  TriggerPort: '<S10>/Function'
     */
    /* Outputs for Triggered SubSystem: '<S8>/fuel_controller_pwon' incorporates:
     *  TriggerPort: '<S11>/Function'
     */
    if (ssIsMajorTimeStep(rtS)) {
      zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                         &rtPrevZCX.fuel_controller_pwon_Trig_ZCE,
                         (rtB.Pwon));
      if (zcEvent != NO_ZCEVENT) {
        /* DataStoreWrite: '<S11>/DataStoreWrite1' incorporates:
         *  Constant: '<S11>/Constant1'
         *  DataTypeConversion: '<S11>/Data Type Conversion'
         */
        rtDW.controller_mode = (rtP.Constant1_Value_l != 0.0F);

        /* DataStoreWrite: '<S11>/DataStoreWrite' incorporates:
         *  Constant: '<S11>/Constant2'
         */
        rtDW.commanded_fuel = rtP.Constant2_Value_k;
        if (ssIsMajorTimeStep(rtS)) {
          ssSetBlockStateForSolverChangedAtMajorStep(rtS);
          ssSetContTimeOutputInconsistentWithStateAtMajorStep(rtS);
        }

        /* End of DataStoreWrite: '<S11>/DataStoreWrite' */

        /* DataStoreWrite: '<S11>/DataStoreWrite2' incorporates:
         *  Constant: '<S11>/Constant3'
         */
        rtDW.airbyfuel_ref = rtP.Constant3_Value_o;
        if (ssIsMajorTimeStep(rtS)) {
          ssSetBlockStateForSolverChangedAtMajorStep(rtS);
          ssSetContTimeOutputInconsistentWithStateAtMajorStep(rtS);
        }

        /* End of DataStoreWrite: '<S11>/DataStoreWrite2' */
      }

      zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                         &rtPrevZCX.fuel_controller_mode_10ms_Trig_,
                         (rtB.PulseGenerator_10ms));
      if (zcEvent != NO_ZCEVENT) {
        /* Outputs for Atomic SubSystem: '<S10>/sensor_failure_detection' */
        /* Logic: '<S17>/Logical Operator' incorporates:
         *  Constant: '<S17>/threshold'
         *  DataStoreRead: '<S10>/DataStoreRead2'
         *  RelationalOperator: '<S17>/Relational Operator'
         *  UnitDelay: '<S17>/Unit Delay'
         */
        LogicalOperator = ((rtDW.airbyfuel_meas <= rtP.threshold_Value) ||
                           rtDW.UnitDelay_DSTATE);

        /* End of Outputs for SubSystem: '<S10>/sensor_failure_detection' */

        /* Outputs for Atomic SubSystem: '<S10>/normal_mode_detection' */
        /* Sum: '<S13>/Sum2' incorporates:
         *  Constant: '<S15>/sampling_sec'
         *  Sum: '<S15>/Sum'
         *  UnitDelay: '<S15>/Unit Delay2'
         */
        rtB.Sum2_a = rtDW.UnitDelay2_DSTATE + rtP.sampling_sec_Value;

        /* Logic: '<S15>/Logical Operator' incorporates:
         *  Constant: '<S15>/normal_mode_start_sec'
         *  RelationalOperator: '<S15>/Relational Operator'
         *  UnitDelay: '<S15>/Unit Delay1'
         */
        LogicalOperator_a = ((rtB.Sum2_a >= rtP.normal_mode_start_sec_Value) ||
                             rtDW.UnitDelay1_DSTATE_e);

        /* End of Outputs for SubSystem: '<S10>/normal_mode_detection' */

        /* Outputs for Atomic SubSystem: '<S10>/power_mode_detection' */
        /* Switch: '<S16>/Switch' incorporates:
         *  Constant: '<S16>/Constant'
         *  Constant: '<S16>/Constant1'
         *  Sum: '<S16>/Sum'
         *  UnitDelay: '<S16>/Unit Delay1'
         */
        if (rtDW.UnitDelay1_DSTATE_a) {
          Sum2 = rtP.Constant_Value_d;
        } else {
          Sum2 = rtP.Constant_Value_d + rtP.Constant1_Value_f;
        }

        /* End of Switch: '<S16>/Switch' */

        /* RelationalOperator: '<S16>/Relational Operator1' incorporates:
         *  DataStoreRead: '<S10>/DataStoreRead4'
         */
        RelationalOperator1 = (rtDW.throttle_angle >= Sum2);

        /* End of Outputs for SubSystem: '<S10>/power_mode_detection' */

        /* DataStoreWrite: '<S10>/DataStoreWrite' incorporates:
         *  Logic: '<S10>/Logical Operator1'
         *  Logic: '<S10>/Logical Operator2'
         */
        rtDW.controller_mode = (LogicalOperator || (!LogicalOperator_a) ||
          RelationalOperator1);

        /* Switch: '<S10>/Switch' incorporates:
         *  Logic: '<S10>/Logical Operator3'
         */
        if (LogicalOperator_a && RelationalOperator1) {
          /* DataStoreWrite: '<S10>/DataStoreWrite1' incorporates:
           *  Constant: '<S10>/airbyfuel_reference_power'
           */
          rtDW.airbyfuel_ref = rtP.airbyfuel_reference_power_Value;
        } else {
          /* DataStoreWrite: '<S10>/DataStoreWrite1' incorporates:
           *  Constant: '<S10>/airbyfuel_reference'
           */
          rtDW.airbyfuel_ref = rtP.airbyfuel_reference_Value;
        }

        /* End of Switch: '<S10>/Switch' */

        /* DataStoreWrite: '<S10>/DataStoreWrite1' */
        if (ssIsMajorTimeStep(rtS)) {
          ssSetBlockStateForSolverChangedAtMajorStep(rtS);
          ssSetContTimeOutputInconsistentWithStateAtMajorStep(rtS);
        }

        /* Update for Atomic SubSystem: '<S10>/sensor_failure_detection' */
        /* Update for UnitDelay: '<S17>/Unit Delay' */
        rtDW.UnitDelay_DSTATE = LogicalOperator;

        /* End of Update for SubSystem: '<S10>/sensor_failure_detection' */

        /* Update for Atomic SubSystem: '<S10>/normal_mode_detection' */
        /* Update for UnitDelay: '<S15>/Unit Delay2' */
        rtDW.UnitDelay2_DSTATE = rtB.Sum2_a;

        /* Update for UnitDelay: '<S15>/Unit Delay1' */
        rtDW.UnitDelay1_DSTATE_e = LogicalOperator_a;

        /* End of Update for SubSystem: '<S10>/normal_mode_detection' */

        /* Update for Atomic SubSystem: '<S10>/power_mode_detection' */
        /* Update for UnitDelay: '<S16>/Unit Delay1' */
        rtDW.UnitDelay1_DSTATE_a = RelationalOperator1;

        /* End of Update for SubSystem: '<S10>/power_mode_detection' */
      }

      zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                         &rtPrevZCX.fuel_controller_10ms_Trig_ZCE,
                         (rtB.PulseGenerator_10ms));
      if (zcEvent != NO_ZCEVENT) {
        /* Outputs for Atomic SubSystem: '<S9>/air_estimation' */
        /* Sum: '<S12>/Sum3' incorporates:
         *  Constant: '<S12>/Constant2'
         *  Constant: '<S12>/Constant3'
         *  Constant: '<S12>/Constant4'
         *  Constant: '<S12>/Constant5'
         *  DataStoreRead: '<S9>/DataStoreRead1'
         *  Product: '<S12>/Prod2'
         *  Product: '<S12>/Prod3'
         *  Product: '<S12>/Prod4'
         *  UnitDelay: '<S12>/UnitDelay1'
         */
        rtb_Sum3 = ((rtDW.UnitDelay1_DSTATE_d * rtDW.engine_speed *
                     rtP.Constant3_Value_c + rtP.Constant2_Value_d) +
                    rtDW.UnitDelay1_DSTATE_d * rtDW.UnitDelay1_DSTATE_d *
                    rtDW.engine_speed * rtP.Constant4_Value) + rtDW.engine_speed
          * rtDW.engine_speed * rtDW.UnitDelay1_DSTATE_d * rtP.Constant5_Value;

        /* Sum: '<S12>/Sum2' incorporates:
         *  Constant: '<S12>/Constant1'
         *  DataStoreRead: '<S9>/DataStoreRead'
         *  Gain: '<S12>/Gain'
         *  Product: '<S12>/Prod1'
         *  Sum: '<S12>/Sum1'
         *  UnitDelay: '<S12>/UnitDelay1'
         */
        Sum2 = (rtDW.throttle_flow - rtb_Sum3) * rtP.Gain_Gain_j *
          rtP.Constant1_Value + rtDW.UnitDelay1_DSTATE_d;

        /* End of Outputs for SubSystem: '<S9>/air_estimation' */

        /* Logic: '<S9>/Logical Operator2' incorporates:
         *  DataStoreRead: '<S9>/DataStoreRead3'
         */
        LogicalOperator = !rtDW.controller_mode;

        /* Outputs for Enabled SubSystem: '<S9>/feedback_PI_controller' incorporates:
         *  EnablePort: '<S13>/Enable'
         */
        if (LogicalOperator) {
          /* Sum: '<S13>/Sum1' incorporates:
           *  DataStoreRead: '<S9>/DataStoreRead2'
           *  DataStoreRead: '<S9>/DataStoreRead4'
           */
          rtb_fuel_saturation = rtDW.airbyfuel_meas - rtDW.airbyfuel_ref;

          /* Sum: '<S13>/Sum2' incorporates:
           *  Constant: '<S13>/Constant1'
           *  Gain: '<S13>/Gain1'
           *  Product: '<S13>/Prod1'
           *  UnitDelay: '<S13>/UnitDelay1'
           */
          rtB.Sum2_a = rtP.Gain1_Gain_a * rtb_fuel_saturation *
            rtP.Constant1_Value_h + rtDW.UnitDelay1_DSTATE;

          /* Sum: '<S13>/Sum3' incorporates:
           *  Gain: '<S13>/Gain'
           */
          rtB.Sum3 = rtP.Gain_Gain_c * rtb_fuel_saturation + rtB.Sum2_a;
        }

        /* End of Outputs for SubSystem: '<S9>/feedback_PI_controller' */

        /* Switch: '<S9>/Switch' incorporates:
         *  Constant: '<S9>/Constant3'
         *  DataStoreRead: '<S9>/DataStoreRead3'
         */
        if (rtDW.controller_mode) {
          rtb_fuel_saturation = rtP.Constant3_Value;
        } else {
          /* Sum: '<S9>/Sum1' incorporates:
           *  Constant: '<S9>/Constant2'
           */
          rtb_fuel_saturation = rtP.Constant2_Value + rtB.Sum3;

          /* Saturate: '<S9>/fb_fuel_saturation' */
          if (rtb_fuel_saturation > rtP.fb_fuel_saturation_UpperSat) {
            rtb_fuel_saturation = rtP.fb_fuel_saturation_UpperSat;
          } else if (rtb_fuel_saturation < rtP.fb_fuel_saturation_LowerSat) {
            rtb_fuel_saturation = rtP.fb_fuel_saturation_LowerSat;
          }

          /* End of Saturate: '<S9>/fb_fuel_saturation' */
        }

        /* End of Switch: '<S9>/Switch' */

        /* Outputs for Atomic SubSystem: '<S9>/feedforward_controller' */
        /* Product: '<S9>/Prod1' incorporates:
         *  DataStoreRead: '<S9>/DataStoreRead4'
         *  Product: '<S14>/Product'
         */
        rtb_Sum3 = rtb_Sum3 / rtDW.airbyfuel_ref * rtb_fuel_saturation;

        /* End of Outputs for SubSystem: '<S9>/feedforward_controller' */

        /* Saturate: '<S9>/fuel_saturation' */
        if (rtb_Sum3 > rtP.fuel_saturation_UpperSat) {
          /* DataStoreWrite: '<S9>/DataStoreWrite' */
          rtDW.commanded_fuel = rtP.fuel_saturation_UpperSat;
        } else if (rtb_Sum3 < rtP.fuel_saturation_LowerSat) {
          /* DataStoreWrite: '<S9>/DataStoreWrite' */
          rtDW.commanded_fuel = rtP.fuel_saturation_LowerSat;
        } else {
          /* DataStoreWrite: '<S9>/DataStoreWrite' */
          rtDW.commanded_fuel = rtb_Sum3;
        }

        /* End of Saturate: '<S9>/fuel_saturation' */

        /* DataStoreWrite: '<S9>/DataStoreWrite' */
        if (ssIsMajorTimeStep(rtS)) {
          ssSetBlockStateForSolverChangedAtMajorStep(rtS);
          ssSetContTimeOutputInconsistentWithStateAtMajorStep(rtS);
        }

        /* Update for Atomic SubSystem: '<S9>/air_estimation' */
        /* Update for UnitDelay: '<S12>/UnitDelay1' */
        rtDW.UnitDelay1_DSTATE_d = Sum2;

        /* End of Update for SubSystem: '<S9>/air_estimation' */

        /* Update for Enabled SubSystem: '<S9>/feedback_PI_controller' incorporates:
         *  EnablePort: '<S13>/Enable'
         */
        if (LogicalOperator) {
          /* Update for UnitDelay: '<S13>/UnitDelay1' */
          rtDW.UnitDelay1_DSTATE = rtB.Sum2_a;
        }

        /* End of Update for SubSystem: '<S9>/feedback_PI_controller' */
      }
    }

    /* End of Outputs for SubSystem: '<S8>/fuel_controller_pwon' */
    /* End of Outputs for SubSystem: '<S8>/fuel_controller_mode_10ms' */
    /* End of Outputs for SubSystem: '<S8>/fuel_controller_10ms' */
  }

  /* End of Outputs for SubSystem: '<S3>/fuel_controller' */

  /* DataStoreRead: '<S3>/DataStoreRead1' */
  LogicalOperator = rtDW.controller_mode;

  /* DataStoreRead: '<S3>/DataStoreRead2' */
  rtb_fuel_saturation = rtDW.airbyfuel_ref;

  /* End of Outputs for SubSystem: '<S1>/AF_Controller' */

  /* Integrator: '<S19>/Integrator' */
  rtb_Integrator = rtX.Integrator_CSTATE_h;

  /* Gain: '<S20>/Gain' incorporates:
   *  Integrator: '<S19>/Integrator'
   *  Sum: '<S20>/Sum'
   */
  rtB.Gain = (rtX.Integrator_CSTATE_h - rtb_MeasureOn_m) * rtP.Gain_Gain;

  /* VariableTransportDelay: '<S4>/fuel system transport delay' incorporates:
   *  Fcn: '<S5>/Pumping'
   */
  rtb_fuelsystemtransportdelay = ((0.08979 * rtb_fuelsystemtransportdelay *
    rtb_radstorpm + -0.366) - 0.0337 * rtb_radstorpm *
    rtb_fuelsystemtransportdelay * rtb_fuelsystemtransportdelay) + 0.0001 *
    rtb_fuelsystemtransportdelay * rtb_radstorpm * rtb_radstorpm;

  /* Gain: '<S5>/Gain2' */
  rtb_Gain2 = rtP.Gain2_Gain * rtb_fuelsystemtransportdelay;

  /* VariableTransportDelay: '<S4>/fuel system transport delay' incorporates:
   *  Gain: '<S7>/rad//s to rpm'
   */
  rtb_fuelsystemtransportdelay = rtP.radstorpm_Gain * rtb_radstorpm;

  /* Gain: '<S4>/Gain' incorporates:
   *  Product: '<S4>/Product1'
   */
  rtb_MeasureOn_m = rtb_Gain2 / rtb_radstorpm * rtP.Gain_Gain_l;

  /* Gain: '<S7>/Kappa tolerance [0.9 1.1]' incorporates:
   *  Lookup_n-D: '<S7>/1-Kappa'
   *  Step: '<S2>/MeasureOn'
   *  VariableTransportDelay: '<S4>/fuel system transport delay'
   */
  rtb_Kappatolerance0911 = rtP.Kappatolerance0911_Gain * look2_binlxpw
    (rtb_fuelsystemtransportdelay, rtb_MeasureOn_m, rtP.uKappa_bp01Data,
     rtP.uKappa_bp02Data, rtP.uKappa_tableData, rtP.uKappa_maxIndex, 5U);

  /* Outputs for Atomic SubSystem: '<S1>/AF_Controller' */
  /* Gain: '<S1>/fuel injector tolerance [0.95 1.05]' incorporates:
   *  DataStoreRead: '<S3>/DataStoreRead'
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   */
  rtb_fuelinjectortolerance095105 = rtP.fuel_inj_tol * rtDW.commanded_fuel;

  /* End of Outputs for SubSystem: '<S1>/AF_Controller' */

  /* VariableTransportDelay: '<S4>/fuel system transport delay' incorporates:
   *  Lookup_n-D: '<S7>/tau_ww'
   *  Step: '<S2>/MeasureOn'
   */
  rtb_fuelsystemtransportdelay = look2_binlxpw(rtb_fuelsystemtransportdelay,
    rtb_MeasureOn_m, rtP.tau_ww_bp01Data, rtP.tau_ww_bp02Data,
    rtP.tau_ww_tableData, rtP.tau_ww_maxIndex, 5U);

  /* Product: '<S7>/Divide2' incorporates:
   *  Gain: '<S7>/tau_ww tolerance [0.9 1.1]'
   *  Integrator: '<S7>/Integrator'
   */
  rtb_fuel_puddle_evap = rtX.Integrator_CSTATE_c / (rtP.tau_wwtolerance0911_Gain
    * rtb_fuelsystemtransportdelay);

  /* Product: '<S4>/Divide' incorporates:
   *  Product: '<S7>/Divide'
   *  Sum: '<S7>/Add'
   */
  rtB.airbyfuel = rtb_Gain2 / (rtb_Kappatolerance0911 *
    rtb_fuelinjectortolerance095105 + rtb_fuel_puddle_evap);

  /* VariableTransportDelay: '<S4>/fuel system transport delay' */
  {
    real_T **uBuffer = (real_T**)
      &rtDW.fuelsystemtransportdelay_PWORK.TUbufferPtrs[0];
    real_T simTime = ssGetT(rtS);
    real_T appliedDelay;

    /* For variable transport dealy, find the real applied dealy
     * here and then output
     */
    rtb_fuelsystemtransportdelay= rt_VTDelayfindtDInterpolate
      (rtX.fuelsystemtransportdelay_CSTATE, *uBuffer,
       rtDW.fuelsystemtransportdelay_IWORK.CircularBufSize,
       rtDW.fuelsystemtransportdelay_IWORK.Head,
       rtDW.fuelsystemtransportdelay_IWORK.Tail,
       &rtDW.fuelsystemtransportdelay_IWORK.Last, simTime, 0.0,0,
       (boolean_T) (ssIsMinorTimeStep(rtS) && (ssGetTimeOfLastOutput(rtS) ==
         ssGetT(rtS))), rtP.fuelsystemtransportdelay_InitOu,
       &appliedDelay);
  }

  /* Gain: '<S19>/Gain1' incorporates:
   *  Sum: '<S19>/Sum'
   */
  rtB.Gain1 = (rtb_fuelsystemtransportdelay - rtb_Integrator) * rtP.Gain1_Gain;

  /* Lookup_n-D: '<S4>/delay (s)' incorporates:
   *  Gain: '<S4>/rad//s to rpm'
   *  Step: '<S2>/MeasureOn'
   */
  rtB.delays = look2_binlxpw(rtP.radstorpm_Gain_p * rtb_radstorpm,
    rtb_MeasureOn_m, rtP.delays_bp01Data, rtP.delays_bp02Data,
    rtP.delays_tableData, rtP.delays_maxIndex, 5U);

  /* Gain: '<S5>/RT//Vm' incorporates:
   *  Sum: '<S5>/Sum'
   */
  rtB.RTVm = (rtb_pratio - rtb_Gain2) * rtP.RTVm_Gain;

  /* Sum: '<S7>/Sum' incorporates:
   *  Constant: '<S7>/Constant'
   *  Gain: '<S7>/Gain'
   *  Product: '<S7>/Divide1'
   *  Sum: '<S7>/Add2'
   */
  rtB.Sum = (rtP.Gain_Gain_m * rtb_Kappatolerance0911 + rtP.Constant_Value) *
    rtb_fuelinjectortolerance095105 - rtb_fuel_puddle_evap;

  /* End of Outputs for SubSystem: '<Root>/Model 1' */

  /* Outputs for Atomic SubSystem: '<Root>/V&V stub system' */
  /* Step: '<S2>/MeasureOn' */
  if (u0 < rtP.measureTime) {
    rtb_Integrator = rtP.MeasureOn_Y0_m;
  } else {
    rtb_Integrator = rtP.MeasureOn_YFinal_n;
  }

  /* RelationalOperator: '<S2>/Relational Operator' incorporates:
   *  Constant: '<S2>/Constant'
   */
  rtB.RelationalOperator = (rtb_Integrator > rtP.Constant_Value_l);
  if (ssIsSampleHit(rtS, 1, 0)) {
    /* SignalConversion generated from: '<S21>/Enable' */
    rtB.HiddenBuf_InsertedFor_CalcuateE = rtB.RelationalOperator;

    /* Outputs for Enabled SubSystem: '<S2>/Calcuate Error' incorporates:
     *  EnablePort: '<S21>/Enable'
     */
    if (ssIsMajorTimeStep(rtS)) {
      if (rtB.HiddenBuf_InsertedFor_CalcuateE) {
        if (!rtDW.CalcuateError_MODE) {
          if (ssGetTaskTime(rtS,1) != ssGetTStart(rtS)) {
            ssSetBlockStateForSolverChangedAtMajorStep(rtS);
          }

          rtDW.CalcuateError_MODE = true;
        }
      } else if (rtDW.CalcuateError_MODE) {
        ssSetBlockStateForSolverChangedAtMajorStep(rtS);

        /* Disable for SwitchCase: '<S21>/Switch Case' */
        rtDW.SwitchCase_ActiveSubsystem = -1;
        rtDW.CalcuateError_MODE = false;
      }
    }

    /* End of Outputs for SubSystem: '<S2>/Calcuate Error' */
  }

  /* Outputs for Enabled SubSystem: '<S2>/Calcuate Error' incorporates:
   *  EnablePort: '<S21>/Enable'
   */
  if (rtDW.CalcuateError_MODE) {
    /* SwitchCase: '<S21>/Switch Case' incorporates:
     *  Constant: '<S2>/spec_num'
     */
    if (ssIsMajorTimeStep(rtS)) {
      switch (rtP.spec_num) {
       case 1:
        rtAction = 0;
        break;

       case 2:
        rtAction = 1;
        break;

       default:
        rtAction = 2;
        break;
      }

      rtDW.SwitchCase_ActiveSubsystem = rtAction;
    } else {
      rtAction = rtDW.SwitchCase_ActiveSubsystem;
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S21>/over(under)shoot' incorporates:
       *  ActionPort: '<S23>/Action Port'
       */
      /* Sum: '<S23>/Sum1' incorporates:
       *  Constant: '<S23>/Constant'
       *  DataTypeConversion: '<S2>/Data Type Conversion'
       *  Product: '<S23>/Divide'
       */
      rtB.Sum1 = rtB.AF_sensor / rtb_fuel_saturation - rtP.Constant_Value_i;

      /* End of Outputs for SubSystem: '<S21>/over(under)shoot' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S21>/RMS error' incorporates:
       *  ActionPort: '<S22>/Action Port'
       */
      /* Sum: '<S22>/Sum1' incorporates:
       *  DataTypeConversion: '<S2>/Data Type Conversion'
       */
      rtb_MeasureOn_m = rtB.AF_sensor - rtb_fuel_saturation;

      /* Step: '<S22>/MeasureOn' */
      if (u0 < rtP.MeasureOn_Time) {
        u0 = rtP.MeasureOn_Y0;
      } else {
        u0 = rtP.MeasureOn_YFinal;
      }

      /* Product: '<S22>/Product' incorporates:
       *  Math: '<S22>/Math Function'
       */
      rtB.Product = rtb_MeasureOn_m * rtb_MeasureOn_m * u0;

      /* Sqrt: '<S22>/Sqrt' incorporates:
       *  Constant: '<S22>/Constant'
       *  Integrator: '<S22>/Integrator'
       *  Product: '<S22>/Divide'
       */
      rtB.Sqrt = sqrt(rtX.Integrator_CSTATE / (rtP.simTime - 10.0));

      /* End of Outputs for SubSystem: '<S21>/RMS error' */
      break;

     case 2:
      break;
    }

    /* MultiPortSwitch: '<S21>/Multiport Switch' incorporates:
     *  Constant: '<S2>/spec_num'
     */
    if (rtP.spec_num == 1) {
      /* MultiPortSwitch: '<S21>/Multiport Switch' */
      rtB.MultiportSwitch = rtB.Sum1;
    } else {
      /* MultiPortSwitch: '<S21>/Multiport Switch' */
      rtB.MultiportSwitch = rtB.Sqrt;
    }

    /* End of MultiPortSwitch: '<S21>/Multiport Switch' */
  }

  /* End of Outputs for SubSystem: '<S2>/Calcuate Error' */
  /* End of Outputs for SubSystem: '<Root>/V&V stub system' */

  /* Outport: '<Root>/verificaton measurement' */
  rtY.verificatonmeasurement = rtB.MultiportSwitch;

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  rtB.ControllerMode = LogicalOperator;

  /* Outport: '<Root>/mode' */
  rtY.mode = rtB.ControllerMode;

  /* Outport: '<Root>/pedal angle' incorporates:
   *  Inport: '<Root>/Throttle angle'
   */
  rtY.pedalangle = rtU.PedalAngle;
  if (ssIsSampleHit(rtS, 1, 0)) {
  }

  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
void MdlUpdate(int_T tid)
{
  /* Update for Atomic SubSystem: '<Root>/Model 1' */

  /* Update for VariableTransportDelay: '<S4>/fuel system transport delay' */
  {
    real_T **uBuffer = (real_T**)
      &rtDW.fuelsystemtransportdelay_PWORK.TUbufferPtrs[0];
    real_T simTime = ssGetT(rtS);
    rtDW.fuelsystemtransportdelay_IWORK.Head =
      ((rtDW.fuelsystemtransportdelay_IWORK.Head <
        (rtDW.fuelsystemtransportdelay_IWORK.CircularBufSize-1)) ?
       (rtDW.fuelsystemtransportdelay_IWORK.Head+1) : 0);
    if (rtDW.fuelsystemtransportdelay_IWORK.Head ==
        rtDW.fuelsystemtransportdelay_IWORK.Tail) {
      if (!rt_TDelayUpdateTailOrGrowBuf
          ( &rtDW.fuelsystemtransportdelay_IWORK.CircularBufSize,
           &rtDW.fuelsystemtransportdelay_IWORK.Tail,
           &rtDW.fuelsystemtransportdelay_IWORK.Head,
           &rtDW.fuelsystemtransportdelay_IWORK.Last, simTime -
           rtP.fuelsystemtransportdelay_MaxDel, uBuffer,(boolean_T)0, (boolean_T)
           1,
           &rtDW.fuelsystemtransportdelay_IWORK.MaxNewBufSize) ) {
        ssSetErrorStatus(rtS, "vtdelay memory allocation error");
        return;
      }
    }

    (*uBuffer + rtDW.fuelsystemtransportdelay_IWORK.CircularBufSize)
      [rtDW.fuelsystemtransportdelay_IWORK.Head] = simTime;
    (*uBuffer + 2 * rtDW.fuelsystemtransportdelay_IWORK.CircularBufSize)
      [rtDW.fuelsystemtransportdelay_IWORK.Head] =
      rtX.fuelsystemtransportdelay_CSTATE;
    (*uBuffer)[rtDW.fuelsystemtransportdelay_IWORK.Head] = rtB.airbyfuel;

    /* when use fixed buffer, reset solver at when buffer is updated
     * to avoid output consistency fail.
     */
  }

  /* End of Update for SubSystem: '<Root>/Model 1' */
  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
void MdlDerivatives(void)
{
  XDot *_rtXdot;
  _rtXdot = ((XDot *) ssGetdX(rtS));

  /* Derivatives for Atomic SubSystem: '<Root>/Model 1' */
  /* Derivatives for Integrator: '<S20>/Integrator' */
  _rtXdot->Integrator_CSTATE_m = rtB.Gain;

  /* Derivatives for TransferFcn: '<S1>/Throttle delay' incorporates:
   *  Inport: '<Root>/Throttle angle'
   */
  _rtXdot->Throttledelay_CSTATE = 0.0;
  _rtXdot->Throttledelay_CSTATE += rtP.Throttledelay_A *
    rtX.Throttledelay_CSTATE;
  _rtXdot->Throttledelay_CSTATE += rtU.PedalAngle;

  /* Derivatives for Integrator: '<S5>/p0 = 0.543 (bar)' */
  _rtXdot->p00543bar_CSTATE = rtB.RTVm;

  /* Derivatives for Integrator: '<S19>/Integrator' */
  _rtXdot->Integrator_CSTATE_h = rtB.Gain1;

  /* Derivatives for Integrator: '<S7>/Integrator' */
  _rtXdot->Integrator_CSTATE_c = rtB.Sum;

  /* Derivatives for VariableTransportDelay: '<S4>/fuel system transport delay' */
  {
    real_T instantDelay;
    instantDelay = rtB.delays;
    if (instantDelay > rtP.fuelsystemtransportdelay_MaxDel) {
      instantDelay = rtP.fuelsystemtransportdelay_MaxDel;
    }

    if (instantDelay < 0.0) {
      ((XDot *) ssGetdX(rtS))->fuelsystemtransportdelay_CSTATE = 0;
    } else {
      ((XDot *) ssGetdX(rtS))->fuelsystemtransportdelay_CSTATE = 1.0/
        instantDelay;
    }
  }

  /* End of Derivatives for SubSystem: '<Root>/Model 1' */

  /* Derivatives for Atomic SubSystem: '<Root>/V&V stub system' */
  /* Derivatives for Enabled SubSystem: '<S2>/Calcuate Error' */
  if (rtDW.CalcuateError_MODE) {
    /* Derivatives for SwitchCase: '<S21>/Switch Case' */
    ((XDot *) ssGetdX(rtS))->Integrator_CSTATE = 0.0;
    if (rtDW.SwitchCase_ActiveSubsystem == 1) {
      /* Derivatives for IfAction SubSystem: '<S21>/RMS error' incorporates:
       *  ActionPort: '<S22>/Action Port'
       */
      /* Derivatives for Integrator: '<S22>/Integrator' */
      _rtXdot->Integrator_CSTATE = rtB.Product;

      /* End of Derivatives for SubSystem: '<S21>/RMS error' */
    }

    /* End of Derivatives for SwitchCase: '<S21>/Switch Case' */
  } else {
    ((XDot *) ssGetdX(rtS))->Integrator_CSTATE = 0.0;
  }

  /* End of Derivatives for SubSystem: '<S2>/Calcuate Error' */
  /* End of Derivatives for SubSystem: '<Root>/V&V stub system' */
}

/* Projection for root system: '<Root>' */
void MdlProjection(void)
{
}

/* Termination for root system: '<Root>' */
void MdlTerminate(void)
{
  /* Terminate for Atomic SubSystem: '<Root>/Model 1' */

  /* Terminate for VariableTransportDelay: '<S4>/fuel system transport delay' */
  rt_TDelayFreeBuf(rtDW.fuelsystemtransportdelay_PWORK.TUbufferPtrs[0]);

  /* End of Terminate for SubSystem: '<Root>/Model 1' */
}

/* Function to initialize sizes */
void MdlInitializeSizes(void)
{
  ssSetNumContStates(rtS, 7);          /* Number of continuous states */
  ssSetNumPeriodicContStates(rtS, 0); /* Number of periodic continuous states */
  ssSetNumY(rtS, 3);                   /* Number of model outputs */
  ssSetNumU(rtS, 2);                   /* Number of model inputs */
  ssSetDirectFeedThrough(rtS, 1);      /* The model is direct feedthrough */
  ssSetNumSampleTimes(rtS, 2);         /* Number of sample times */
  ssSetNumBlocks(rtS, 194);            /* Number of blocks */
  ssSetNumBlockIO(rtS, 24);            /* Number of block outputs */
  ssSetNumBlockParams(rtS, 186);       /* Sum of parameter "widths" */
}

/* Function to initialize sample times. */
void MdlInitializeSampleTimes(void)
{
  /* task periods */
  ssSetSampleTime(rtS, 0, 0.0);
  ssSetSampleTime(rtS, 1, 5.0E-5);

  /* task offsets */
  ssSetOffsetTime(rtS, 0, 0.0);
  ssSetOffsetTime(rtS, 1, 0.0);
}

/* Function to register the model */
/* Turns off all optimizations on Windows because of issues with VC 2015 compiler.
   This function is not performance-critical, hence this is not a problem.
 */
#if defined(_MSC_VER)

#pragma optimize( "", off )

#endif

SimStruct * AbstractFuelControl_M1(void)
{
  static struct _ssMdlInfo mdlInfo;
  (void) memset((char *)rtS, 0,
                sizeof(SimStruct));
  (void) memset((char *)&mdlInfo, 0,
                sizeof(struct _ssMdlInfo));
  ssSetMdlInfoPtr(rtS, &mdlInfo);

  /* timing info */
  {
    static time_T mdlPeriod[NSAMPLE_TIMES];
    static time_T mdlOffset[NSAMPLE_TIMES];
    static time_T mdlTaskTimes[NSAMPLE_TIMES];
    static int_T mdlTsMap[NSAMPLE_TIMES];
    static int_T mdlSampleHits[NSAMPLE_TIMES];

    {
      int_T i;
      for (i = 0; i < NSAMPLE_TIMES; i++) {
        mdlPeriod[i] = 0.0;
        mdlOffset[i] = 0.0;
        mdlTaskTimes[i] = 0.0;
        mdlTsMap[i] = i;
        mdlSampleHits[i] = 1;
      }
    }

    ssSetSampleTimePtr(rtS, &mdlPeriod[0]);
    ssSetOffsetTimePtr(rtS, &mdlOffset[0]);
    ssSetSampleTimeTaskIDPtr(rtS, &mdlTsMap[0]);
    ssSetTPtr(rtS, &mdlTaskTimes[0]);
    ssSetSampleHitPtr(rtS, &mdlSampleHits[0]);
  }

  ssSetSolverMode(rtS, SOLVER_MODE_SINGLETASKING);

  /*
   * initialize model vectors and cache them in SimStruct
   */

  /* block I/O */
  {
    ssSetBlockIO(rtS, ((void *) &rtB));
    (void) memset(((void *) &rtB), 0,
                  sizeof(B));

    {
      rtB.ControllerMode = 0.0;
      rtB.MultiportSwitch = 0.0;
      rtB.Product = 0.0;
      rtB.Sqrt = 0.0;
      rtB.Sum1 = 0.0;
      rtB.AF_sensor = 0.0;
      rtB.theta090 = 0.0;
      rtB.Gain = 0.0;
      rtB.airbyfuel = 0.0;
      rtB.Gain1 = 0.0;
      rtB.delays = 0.0;
      rtB.RTVm = 0.0;
      rtB.Sum = 0.0;
      rtB.Pwon = 0.0;
      rtB.PulseGenerator_10ms = 0.0;
      rtB.Sum3 = 0.0F;
      rtB.Sum2_a = 0.0F;
    }
  }

  /* external inputs */
  {
    ssSetU(rtS, ((void*) &rtU));
    rtU.EngineSpeed = 0.0;
    rtU.PedalAngle = 0.0;
  }

  /* external outputs */
  {
    ssSetY(rtS, &rtY);
    rtY.verificatonmeasurement = 0.0;
    rtY.mode = 0.0;
    rtY.pedalangle = 0.0;
  }

  /* states (continuous)*/
  {
    real_T *x = (real_T *) &rtX;
    ssSetContStates(rtS, x);
    (void) memset((void *)x, 0,
                  sizeof(X));
  }

  /* states (dwork) */
  {
    void *dwork = (void *) &rtDW;
    ssSetRootDWork(rtS, dwork);
    (void) memset(dwork, 0,
                  sizeof(DW));
    rtDW.fuelsystemtransportdelay_RWORK.modelTStart = 0.0;
    rtDW.UnitDelay2_DSTATE = 0.0F;
    rtDW.UnitDelay1_DSTATE = 0.0F;
    rtDW.UnitDelay1_DSTATE_d = 0.0F;
    rtDW.commanded_fuel = 0.0F;
    rtDW.airbyfuel_ref = 0.0F;
    rtDW.engine_speed = 0.0F;
    rtDW.throttle_flow = 0.0F;
    rtDW.airbyfuel_meas = 0.0F;
    rtDW.throttle_angle = 0.0F;
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    ssSetModelMappingInfo(rtS, &dtInfo);
    dtInfo.numDataTypes = 20;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Model specific registration */
  ssSetRootSS(rtS, rtS);
  ssSetVersion(rtS, SIMSTRUCT_VERSION_LEVEL2);
  ssSetModelName(rtS, "AbstractFuelControl_M1");
  ssSetPath(rtS, "AbstractFuelControl_M1");
  ssSetTStart(rtS, 0.0);
  ssSetTFinal(rtS, 50.0);
  ssSetStepSize(rtS, 5.0E-5);
  ssSetFixedStepSize(rtS, 5.0E-5);

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    ssSetRTWLogInfo(rtS, &rt_DataLoggingInfo);
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(ssGetRTWLogInfo(rtS), (NULL));
    rtliSetLogXSignalPtrs(ssGetRTWLogInfo(rtS), (NULL));
    rtliSetLogT(ssGetRTWLogInfo(rtS), "");
    rtliSetLogX(ssGetRTWLogInfo(rtS), "");
    rtliSetLogXFinal(ssGetRTWLogInfo(rtS), "");
    rtliSetLogVarNameModifier(ssGetRTWLogInfo(rtS), "rt_");
    rtliSetLogFormat(ssGetRTWLogInfo(rtS), 0);
    rtliSetLogMaxRows(ssGetRTWLogInfo(rtS), 0);
    rtliSetLogDecimation(ssGetRTWLogInfo(rtS), 1);
    rtliSetLogY(ssGetRTWLogInfo(rtS), "");
    rtliSetLogYSignalInfo(ssGetRTWLogInfo(rtS), (NULL));
    rtliSetLogYSignalPtrs(ssGetRTWLogInfo(rtS), (NULL));
  }

  {
    static struct _ssStatesInfo2 statesInfo2;
    ssSetStatesInfo2(rtS, &statesInfo2);
  }

  {
    static ssPeriodicStatesInfo periodicStatesInfo;
    ssSetPeriodicStatesInfo(rtS, &periodicStatesInfo);
  }

  {
    static ssJacobianPerturbationBounds jacobianPerturbationBounds;
    ssSetJacobianPerturbationBounds(rtS, &jacobianPerturbationBounds);
  }

  /* previous zero-crossing states */
  {
    ZCSigState *zc = (ZCSigState *) &rtPrevZCX;
    ssSetPrevZCSigState(rtS, zc);
  }

  /* previous zero-crossing states */
  {
    rtPrevZCX.fuel_controller_10ms_Trig_ZCE = UNINITIALIZED_ZCSIG;
    rtPrevZCX.fuel_controller_mode_10ms_Trig_ = UNINITIALIZED_ZCSIG;
    rtPrevZCX.fuel_controller_pwon_Trig_ZCE = UNINITIALIZED_ZCSIG;
  }

  ssSetChecksumVal(rtS, 0, 4076513015U);
  ssSetChecksumVal(rtS, 1, 3904825432U);
  ssSetChecksumVal(rtS, 2, 2873462105U);
  ssSetChecksumVal(rtS, 3, 247738668U);

  /* non-finite (run-time) assignments */
  rtP.fb_fuel_saturation_UpperSat = rtInfF;
  return rtS;
}

/* When you use the on parameter, it resets the optimizations to those that you
   specified with the /O compiler option. */
#if defined(_MSC_VER)

#pragma optimize( "", on )

#endif
