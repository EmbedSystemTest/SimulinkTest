/*
 * AbstractFuelControl_M1_private.h
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

#ifndef RTW_HEADER_AbstractFuelControl_M1_private_h_
#define RTW_HEADER_AbstractFuelControl_M1_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#if !defined(rt_VALIDATE_MEMORY)
#define rt_VALIDATE_MEMORY(S, ptr)     if(!(ptr)) {\
 ssSetErrorStatus(rtS, RT_MEMORY_ALLOCATION_ERROR);\
 }
#endif

#if !defined(rt_FREE)
#if !defined(_WIN32)
#define rt_FREE(ptr)                   if((ptr) != (NULL)) {\
 free((ptr));\
 (ptr) = (NULL);\
 }
#else

/* Visual and other windows compilers declare free without const */
#define rt_FREE(ptr)                   if((ptr) != (NULL)) {\
 free((void *)(ptr));\
 (ptr) = (NULL);\
 }
#endif
#endif

#ifndef __RTW_UTFREE__

extern void * utMalloc(size_t);
extern void utFree(void *);

#endif

void * rt_TDelayCreateBuf(
  int_T numBuffer,
  int_T bufSz,
  int_T elemSz)
  ;
boolean_T rt_TDelayUpdateTailOrGrowBuf(
  int_T *bufSzPtr,           /* in/out - circular buffer size                 */
  int_T *tailPtr,            /* in/out - tail of circular buffer              */
  int_T *headPtr,            /* in/out - head of circular buffer              */
  int_T *lastPtr,            /* in/out - same logical 'last' referenced index */
  real_T tMinusDelay,              /* in     - last point we are looking at   */
  real_T **uBufPtr,                /* in/out - larger buffer for input        */
  boolean_T isfixedbuf,            /* in     - fixed buffer size enable       */
  boolean_T istransportdelay,      /* in     - block acts as transport dela y */
  int_T *maxNewBufSzPtr);
real_T rt_VTDelayfindtDInterpolate(
  real_T x,real_T* uBuf,int_T bufSz,int_T head,int_T tail,int_T* pLast,real_T t,
  real_T tStart,boolean_T discrete,boolean_T minorStepAndTAtLastMajorOutput,
  real_T initOutput,real_T* appliedDelay);
extern real_T look2_binlxpw(real_T u0, real_T u1, const real_T bp0[], const
  real_T bp1[], const real_T table[], const uint32_T maxIndex[], uint32_T stride);
void rt_TDelayFreeBuf(
                      void * buf)
  ;

#if defined(MULTITASKING)
#  error Model (AbstractFuelControl_M1) was built in \
SingleTasking solver mode, however the MULTITASKING define is \
present. If you have multitasking (e.g. -DMT or -DMULTITASKING) \
defined on the Code Generation page of Simulation parameter dialog, please \
remove it and on the Solver page, select solver mode \
MultiTasking. If the Simulation parameter dialog is configured \
correctly, please verify that your template makefile is \
configured correctly.
#endif
#endif                        /* RTW_HEADER_AbstractFuelControl_M1_private_h_ */
