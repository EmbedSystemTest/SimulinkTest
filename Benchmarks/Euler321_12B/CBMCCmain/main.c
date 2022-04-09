#include "define.h"
#include <stdio.h>
/* Main State variable define */
RT_MODEL_euler321_I2B_12B_T mainState;
/* Main Function of model */
int main(int argc, char *argv[]) {
    real_T init_euler321_I2B_12B_U_Vi[3];
    real_T init_euler321_I2B_12B_Y_DCM321[9];
    real_T init_euler321_I2B_12B_Y_Vb[3];
    real_T init_euler321_I2B_12B_Y_outTheta[3];
    real_T init_euler321_I2B_12B_Y_outGamma[3];
    real_T init_euler321_I2B_12B_U_phi;
    real_T init_euler321_I2B_12B_U_theta;
    real_T init_euler321_I2B_12B_U_psi;
    real_T init_euler321_I2B_12B_U_Inport;
    boolean_T init_euler321_I2B_12B_Y_outR1;
    euler321_I2B_12B_init(&mainState, init_euler321_I2B_12B_U_Vi, init_euler321_I2B_12B_Y_DCM321, init_euler321_I2B_12B_Y_Vb, init_euler321_I2B_12B_Y_outTheta, init_euler321_I2B_12B_Y_outGamma, &init_euler321_I2B_12B_U_phi, &init_euler321_I2B_12B_U_theta, &init_euler321_I2B_12B_U_psi, &init_euler321_I2B_12B_U_Inport, &init_euler321_I2B_12B_Y_outR1);
    /* Main Loop of model */
    for (int i = 0; i < 1; i++) {
        real_T exec_euler321_I2B_12B_U_phi;
        real_T exec_euler321_I2B_12B_U_theta;
        real_T exec_euler321_I2B_12B_U_psi;
        real_T exec_euler321_I2B_12B_U_Vi[3];
        real_T exec_euler321_I2B_12B_U_Inport;
        real_T exec_euler321_I2B_12B_Y_DCM321[9];
        real_T exec_euler321_I2B_12B_Y_Vb[3];
        real_T exec_euler321_I2B_12B_Y_outTheta[3];
        real_T exec_euler321_I2B_12B_Y_outGamma[3];
        boolean_T exec_euler321_I2B_12B_Y_outR1;
        euler321_I2B_12B_step(&mainState, exec_euler321_I2B_12B_U_phi, exec_euler321_I2B_12B_U_theta, exec_euler321_I2B_12B_U_psi, exec_euler321_I2B_12B_U_Vi, exec_euler321_I2B_12B_U_Inport, exec_euler321_I2B_12B_Y_DCM321, exec_euler321_I2B_12B_Y_Vb, exec_euler321_I2B_12B_Y_outTheta, exec_euler321_I2B_12B_Y_outGamma, &exec_euler321_I2B_12B_Y_outR1);
    }
}