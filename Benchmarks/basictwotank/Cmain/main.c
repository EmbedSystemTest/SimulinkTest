#include "define.h"
#include <stdio.h>
/* Main State variable define */
RT_MODEL_basictwotanks_T mainState;
/* Main Function of model */
int main(int argc, char *argv[]) {
    real_T init_basictwotanks_Y_t1_h;
    real_T init_basictwotanks_Y_t2_h;
    real_T init_basictwotanks_Y_t1_sh;
    real_T init_basictwotanks_Y_t1_sl;
    real_T init_basictwotanks_Y_t2_sh;
    real_T init_basictwotanks_Y_t2_sm;
    real_T init_basictwotanks_Y_t2_sl;
    real_T init_basictwotanks_Y_pump_state;
    real_T init_basictwotanks_Y_valve_state;
    real_T init_basictwotanks_Y_p_valve_state;
    real_T init_basictwotanks_Y_e_valve_state;
    basictwotanks_init(&mainState, &init_basictwotanks_Y_t1_h, &init_basictwotanks_Y_t2_h, &init_basictwotanks_Y_t1_sh, &init_basictwotanks_Y_t1_sl, &init_basictwotanks_Y_t2_sh, &init_basictwotanks_Y_t2_sm, &init_basictwotanks_Y_t2_sl, &init_basictwotanks_Y_pump_state, &init_basictwotanks_Y_valve_state, &init_basictwotanks_Y_p_valve_state, &init_basictwotanks_Y_e_valve_state);
    /* Main Loop of model */
    for (int i = 0; i < 1; i++) {
        real_T * exec_basictwotanks_Y_t1_h;
        real_T * exec_basictwotanks_Y_t2_h;
        real_T exec_basictwotanks_Y_t1_sh;
        real_T exec_basictwotanks_Y_t1_sl;
        real_T exec_basictwotanks_Y_t2_sh;
        real_T exec_basictwotanks_Y_t2_sm;
        real_T exec_basictwotanks_Y_t2_sl;
        real_T exec_basictwotanks_Y_pump_state;
        real_T exec_basictwotanks_Y_valve_state;
        real_T exec_basictwotanks_Y_p_valve_state;
        real_T exec_basictwotanks_Y_e_valve_state;
        basictwotanks_step(&mainState, exec_basictwotanks_Y_t1_h, exec_basictwotanks_Y_t2_h, &exec_basictwotanks_Y_t1_sh, &exec_basictwotanks_Y_t1_sl, &exec_basictwotanks_Y_t2_sh, &exec_basictwotanks_Y_t2_sm, &exec_basictwotanks_Y_t2_sl, &exec_basictwotanks_Y_pump_state, &exec_basictwotanks_Y_valve_state, &exec_basictwotanks_Y_p_valve_state, &exec_basictwotanks_Y_e_valve_state);
    }
}