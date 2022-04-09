#include "define.h"
#include <stdio.h>
/* Main State variable define */
RT_MODEL_NLGuidance_T mainState;
/* Main Function of model */
int main(int argc, char *argv[]) {
    real_T init_NLGuidance_U_Xtarg[3];
    real_T init_NLGuidance_U_Xv[3];
    real_T init_NLGuidance_U_Vv[3];
    real_T init_NLGuidance_U_Vt[3];
    real_T init_NLGuidance_Y_yout[3];
    real_T init_NLGuidance_U_r;
    NLGuidance_init(&mainState, init_NLGuidance_U_Xtarg, init_NLGuidance_U_Xv, init_NLGuidance_U_Vv, init_NLGuidance_U_Vt, init_NLGuidance_Y_yout, &init_NLGuidance_U_r);
    /* Main Loop of model */
    for (int i = 0; i < 1; i++) {
        real_T exec_NLGuidance_U_Xtarg[3];
        real_T exec_NLGuidance_U_Xv[3];
        real_T exec_NLGuidance_U_Vv[3];
        real_T exec_NLGuidance_U_r;
        real_T exec_NLGuidance_Y_yout[3];
        NLGuidance_step(&mainState, exec_NLGuidance_U_Xtarg, exec_NLGuidance_U_Xv, exec_NLGuidance_U_Vv, exec_NLGuidance_U_r, exec_NLGuidance_Y_yout);
    }
}