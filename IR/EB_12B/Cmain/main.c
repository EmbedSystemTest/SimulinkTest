#include "define.h"
#include <stdio.h>
/* Main State variable define */
RT_MODEL_EB_12B_T mainState;
/* Main Function of model */
int main(int argc, char *argv[]) {
    real_T init_EB_12B_U_B[15];
    real_T init_EB_12B_Y_id[9];
    real_T init_EB_12B_Y_check[9];
    real_T init_EB_12B_Y_yinv[9];
    real_T init_EB_12B_Y_P[15];
    real_T init_EB_12B_Y_u[5];
    real_T init_EB_12B_Y_Buminusd[3];
    real_T init_EB_12B_Y_J;
    boolean_T init_EB_12B_Y_ridge_on;
    EB_12B_init(&mainState, init_EB_12B_U_B, init_EB_12B_Y_id, init_EB_12B_Y_check, init_EB_12B_Y_yinv, init_EB_12B_Y_P, init_EB_12B_Y_u, init_EB_12B_Y_Buminusd, &init_EB_12B_Y_J, &init_EB_12B_Y_ridge_on);
    /* Main Loop of model */
    for (int i = 0; i < 1; i++) {
        real_T exec_EB_12B_U_B[15];
        real_T exec_EB_12B_Y_check[9];
        real_T exec_EB_12B_Y_yinv[9];
        real_T exec_EB_12B_Y_P[15];
        real_T exec_EB_12B_Y_u[5];
        real_T exec_EB_12B_Y_Buminusd[3];
        real_T exec_EB_12B_Y_J;
        boolean_T exec_EB_12B_Y_ridge_on;
        EB_12B_step(&mainState, exec_EB_12B_U_B, exec_EB_12B_Y_check, exec_EB_12B_Y_yinv, exec_EB_12B_Y_P, exec_EB_12B_Y_u, exec_EB_12B_Y_Buminusd, &exec_EB_12B_Y_J, &exec_EB_12B_Y_ridge_on);
    }
}