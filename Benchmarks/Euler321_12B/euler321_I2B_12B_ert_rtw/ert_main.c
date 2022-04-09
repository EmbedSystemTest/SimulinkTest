#include <stddef.h>
#include <stdio.h>
#include "euler321_I2B_12B.h"

static RT_MODEL_euler321_I2B_12B_T euler321_I2B_12B_M_;
static RT_MODEL_euler321_I2B_12B_T *const euler321_I2B_12B_MPtr =
  &euler321_I2B_12B_M_;
static real_T euler321_I2B_12B_U_phi;
static real_T euler321_I2B_12B_U_theta;
static real_T euler321_I2B_12B_U_psi;
static real_T euler321_I2B_12B_U_Vi[3];
static real_T euler321_I2B_12B_U_Inport;
static real_T euler321_I2B_12B_Y_DCM321[9];
static real_T euler321_I2B_12B_Y_Vb[3];
static real_T euler321_I2B_12B_Y_outTheta[3];
static real_T euler321_I2B_12B_Y_outGamma[3];
static boolean_T euler321_I2B_12B_Y_outR1;
void rt_OneStep(RT_MODEL_euler321_I2B_12B_T *const euler321_I2B_12B_M);
void rt_OneStep(RT_MODEL_euler321_I2B_12B_T *const euler321_I2B_12B_M)
{
  static boolean_T OverrunFlag = false;
  if (OverrunFlag) {
    rtmSetErrorStatus(euler321_I2B_12B_M, "Overrun");
    return;
  }

  OverrunFlag = true;
  euler321_I2B_12B_step(euler321_I2B_12B_M, euler321_I2B_12B_U_phi,
                        euler321_I2B_12B_U_theta, euler321_I2B_12B_U_psi,
                        euler321_I2B_12B_U_Vi, euler321_I2B_12B_U_Inport,
                        euler321_I2B_12B_Y_DCM321, euler321_I2B_12B_Y_Vb,
                        euler321_I2B_12B_Y_outTheta, euler321_I2B_12B_Y_outGamma,
                        &euler321_I2B_12B_Y_outR1);
  OverrunFlag = false;
}

int_T main(int_T argc, const char *argv[])
{
  RT_MODEL_euler321_I2B_12B_T *const euler321_I2B_12B_M = euler321_I2B_12B_MPtr;
  (void)(argc);
  (void)(argv);
  euler321_I2B_12B_initialize(euler321_I2B_12B_M, &euler321_I2B_12B_U_phi,
    &euler321_I2B_12B_U_theta, &euler321_I2B_12B_U_psi, euler321_I2B_12B_U_Vi,
    &euler321_I2B_12B_U_Inport, euler321_I2B_12B_Y_DCM321, euler321_I2B_12B_Y_Vb,
    euler321_I2B_12B_Y_outTheta, euler321_I2B_12B_Y_outGamma,
    &euler321_I2B_12B_Y_outR1);
  printf("Warning: The simulation will run forever. "
         "Generated ERT main won't simulate model step behavior. "
         "To change this behavior select the 'MAT-file logging' option.\n");
  fflush((NULL));
  while (rtmGetErrorStatus(euler321_I2B_12B_M) == (NULL)) {
  }

  euler321_I2B_12B_terminate(euler321_I2B_12B_M);
  return 0;
}
