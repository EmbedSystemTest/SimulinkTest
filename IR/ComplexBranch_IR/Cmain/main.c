#include "define.h"
#include <stdio.h>
/* Main State variable define */
struct A0_state mainState;
/* Main Function of model */
int main(int argc, char *argv[]) {
    A0_Init(&mainState);
    /* Main Loop of model */
    for (int i = 0; i < 10; i++) {
        A0_Update(&mainState);
    }
}