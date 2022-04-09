#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string.h>
#define bool char
#define false 0
#define true 1
#define PI 3.1415926535897932384626
struct Parameters_Struct;
struct A1_state;
struct A0_state;
struct Parameters_Struct {
    int A1_P1;
    int A1_P2;
    int A1_P3;
    int A1_P4;
    int A1_P5;
    int A1_P6;
    int A1_P7;
    int A1_P8;
    int A1_P9;
    int A1_P10;
};
struct A1_state {
    int Ramp_lastValue;
};
struct A0_state {
    int Ramp_lastValue;
    struct A1_state CompositeActor;
};
struct Parameters_Struct globalParams;
void A0_Update(struct A0_state* self);
void A0_Init(struct A0_state* self);
void A1_Update(struct A1_state* self, unsigned char in1, int in2, int* out1, int* out2);
void A1_Init(struct A1_state* self);
void A0_Update(struct A0_state* self) {
    int Ramp_output = self->Ramp_lastValue;
    self->Ramp_lastValue = self->Ramp_lastValue + 1;
    int Expression_in = Ramp_output;
    bool Expression_output = ((Expression_in % 7655) == 5763);
    int CompositeActor_out1;
    int CompositeActor_out2;
    A1_Update(&self->CompositeActor, Expression_output, Ramp_output, &CompositeActor_out1, &CompositeActor_out2);
    printf("\"ComplexBranch.Display\" output as follows: \n");
    printf("%d\n", CompositeActor_out1);
    printf("\"ComplexBranch.Display_1\" output as follows: \n");
    printf("%d\n", CompositeActor_out2);
}
void A0_Init(struct A0_state* self) {
    self->Ramp_lastValue = 0;
    A1_Init(&self->CompositeActor);
}
void A1_Update(struct A1_state* self, unsigned char in1, int in2, int* out1, int* out2) {
    int BooleanMultiplexor_1_output;
    int BooleanMultiplexor_2_output;
    int BooleanMultiplexor_output;
    int BooleanMultiplexor_6_output;
    int BooleanMultiplexor_1_2_output;
    int BooleanMultiplexor_9_output;
    int BooleanMultiplexor_10_output;
    int BooleanMultiplexor_1_1_output;
    int Expression_in = in2;
    bool Expression_output = ((Expression_in % 153) == 0);
    bool Expression_1_in = in1;
    bool Expression_1_output = (Expression_1_in == true);
    if (Expression_1_output) {
        int Ramp_output = self->Ramp_lastValue;
        self->Ramp_lastValue = self->Ramp_lastValue + 1;
        int Expression_7_in = Ramp_output;
        bool Expression_7_output = ((Expression_7_in % 5) == 0);
        if (Expression_7_output) {
            int Expression_8_in = Ramp_output;
            bool Expression_8_output = (Expression_8_output > 0.9);
            if (Expression_8_output) {
                int Expression_9_in = Ramp_output;
                int Expression_9_output = globalParams.A1_P3;
                BooleanMultiplexor_1_output = Expression_9_output;
            } else {
                int Expression_5_in = Ramp_output;
                int Expression_5_output = globalParams.A1_P4;
                BooleanMultiplexor_1_output = Expression_5_output;
            }
            BooleanMultiplexor_2_output = BooleanMultiplexor_1_output;
        } else {
            int Expression_6_in = Ramp_output;
            int Expression_6_output = globalParams.A1_P2;
            BooleanMultiplexor_2_output = Expression_6_output;
        }
        BooleanMultiplexor_output = BooleanMultiplexor_2_output;
    } else {
        bool Expression_2_in = Expression_1_output;
        int Expression_2_output = globalParams.A1_P1;
        BooleanMultiplexor_output = Expression_2_output;
    }
    if (Expression_output) {
        int Expression_3_in = in2;
        bool Expression_3_output = ((Expression_3_in % 83) == 0);
        if (Expression_3_output) {
            int Expression_8_1_in = in2;
            double Expression_8_1_output = 0;
            double MultiplyDivide_output = in2 / (Expression_8_1_output);
            double Expression_3_1_in = Expression_8_1_output;
            bool Expression_3_1_output = (Expression_3_1_in > 0.9);
            if (Expression_3_1_output) {
                double Expression_11_in = MultiplyDivide_output;
                int Expression_11_output = globalParams.A1_P5;
                BooleanMultiplexor_6_output = Expression_11_output;
            } else {
                double Expression_11_1_in = MultiplyDivide_output;
                int Expression_11_1_output = globalParams.A1_P6;
                BooleanMultiplexor_6_output = Expression_11_1_output;
            }
            BooleanMultiplexor_1_2_output = BooleanMultiplexor_6_output;
        } else {
            int Expression_13_in = in2;
            int Expression_13_output = globalParams.A1_P7;
            BooleanMultiplexor_1_2_output = Expression_13_output;
        }
        BooleanMultiplexor_1_1_output = BooleanMultiplexor_1_2_output;
    } else {
        int Expression_4_in = in2;
        bool Expression_4_output = ((Expression_4_in % 123) == 0);
        if (Expression_4_output) {
            int Scale_1_output = 123 * in2;
            int Expression_4_1_in = Scale_1_output;
            bool Expression_4_1_output = ((Expression_4_1_in % 243) == 0);
            if (Expression_4_1_output) {
                int Expression_14_in = Scale_1_output;
                int Expression_14_output = globalParams.A1_P9;
                BooleanMultiplexor_9_output = Expression_14_output;
            } else {
                int Expression_15_in = Scale_1_output;
                int Expression_15_output = globalParams.A1_P10;
                BooleanMultiplexor_9_output = Expression_15_output;
            }
            BooleanMultiplexor_10_output = BooleanMultiplexor_9_output;
        } else {
            int Expression_16_in = in2;
            int Expression_16_output = globalParams.A1_P8;
            BooleanMultiplexor_10_output = Expression_16_output;
        }
        int Scale_output = 3 * BooleanMultiplexor_10_output;
        int AddSubtract_output = Scale_output - (BooleanMultiplexor_10_output);
        int MultiplyDivide_1_output = Scale_output / (AddSubtract_output);
        BooleanMultiplexor_1_1_output = BooleanMultiplexor_10_output;
    }
}
void A1_Init(struct A1_state* self) {
    globalParams.A1_P1 = 123;
    globalParams.A1_P2 = 453;
    globalParams.A1_P3 = 1853;
    globalParams.A1_P4 = 8653;
    globalParams.A1_P5 = 1123;
    globalParams.A1_P6 = 2223;
    globalParams.A1_P7 = 3333;
    globalParams.A1_P8 = 991;
    globalParams.A1_P9 = 992;
    globalParams.A1_P10 = 993;
}

// Add head file code
// Add declaration code
// Add Function code
int main()
{
    // Add init code
    struct A1_state* self = (struct A1_state*) malloc(sizeof(struct A1_state) * 10);
    unsigned char in1[10];
    int in2[10];
    int out1[10];
    int out2[10];
    // Add init buffer code
    for (int i = 0; i < 10; i++) {
        A1_Init(&self[i]);
    }
    self[0].Ramp_lastValue = nondet_int();
    __CPROVER_input("int", self[0].Ramp_lastValue);
    self[1].Ramp_lastValue = nondet_int();
    __CPROVER_input("int", self[1].Ramp_lastValue);
    self[2].Ramp_lastValue = nondet_int();
    __CPROVER_input("int", self[2].Ramp_lastValue);
    self[3].Ramp_lastValue = nondet_int();
    __CPROVER_input("int", self[3].Ramp_lastValue);
    self[4].Ramp_lastValue = nondet_int();
    __CPROVER_input("int", self[4].Ramp_lastValue);
    self[5].Ramp_lastValue = nondet_int();
    __CPROVER_input("int", self[5].Ramp_lastValue);
    self[6].Ramp_lastValue = nondet_int();
    __CPROVER_input("int", self[6].Ramp_lastValue);
    self[7].Ramp_lastValue = nondet_int();
    __CPROVER_input("int", self[7].Ramp_lastValue);
    self[8].Ramp_lastValue = nondet_int();
    __CPROVER_input("int", self[8].Ramp_lastValue);
    self[9].Ramp_lastValue = nondet_int();
    __CPROVER_input("int", self[9].Ramp_lastValue);
    in1[0] = nondet_unsigned_char();
    __CPROVER_input("unsigned char", in1[0]);
    in1[1] = nondet_unsigned_char();
    __CPROVER_input("unsigned char", in1[1]);
    in1[2] = nondet_unsigned_char();
    __CPROVER_input("unsigned char", in1[2]);
    in1[3] = nondet_unsigned_char();
    __CPROVER_input("unsigned char", in1[3]);
    in1[4] = nondet_unsigned_char();
    __CPROVER_input("unsigned char", in1[4]);
    in1[5] = nondet_unsigned_char();
    __CPROVER_input("unsigned char", in1[5]);
    in1[6] = nondet_unsigned_char();
    __CPROVER_input("unsigned char", in1[6]);
    in1[7] = nondet_unsigned_char();
    __CPROVER_input("unsigned char", in1[7]);
    in1[8] = nondet_unsigned_char();
    __CPROVER_input("unsigned char", in1[8]);
    in1[9] = nondet_unsigned_char();
    __CPROVER_input("unsigned char", in1[9]);
    in2[0] = nondet_int();
    __CPROVER_input("int", in2[0]);
    in2[1] = nondet_int();
    __CPROVER_input("int", in2[1]);
    in2[2] = nondet_int();
    __CPROVER_input("int", in2[2]);
    in2[3] = nondet_int();
    __CPROVER_input("int", in2[3]);
    in2[4] = nondet_int();
    __CPROVER_input("int", in2[4]);
    in2[5] = nondet_int();
    __CPROVER_input("int", in2[5]);
    in2[6] = nondet_int();
    __CPROVER_input("int", in2[6]);
    in2[7] = nondet_int();
    __CPROVER_input("int", in2[7]);
    in2[8] = nondet_int();
    __CPROVER_input("int", in2[8]);
    in2[9] = nondet_int();
    __CPROVER_input("int", in2[9]);
    // Add target function code
    for (int i = 0; i < 10; i++) {
        A1_Update(&self[i],in1[i],in2[i],&(out1[i]),&(out2[i]));
    }
    // Add code after execute
    // Add release code
    return 0;
}
