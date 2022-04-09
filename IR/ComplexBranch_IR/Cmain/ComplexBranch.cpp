#include "define.h"
/* Code of ComplexBranch */
/* Global Variable define of  */
struct Parameters_Struct globalParams;
/* Update function of "ComplexBranch" */
void A0_Update(struct A0_state* self) {
    BitmapCov::munitBitmap[0] = 1;
    /* Calculate code of "ComplexBranch.Ramp" */
    int Ramp_output = self->Ramp_lastValue;
    self->Ramp_lastValue = self->Ramp_lastValue + 1;
    BitmapCov::munitBitmap[1] = 1;
    /* Calculate code of "ComplexBranch.Expression" */
    int Expression_in = Ramp_output;
    bool Expression_output = ((Expression_in % 7655) == 5763);
    BitmapCov::munitBitmap[2] = 1;
    /* Calculate code of "ComplexBranch.CompositeActor" */
    int CompositeActor_out1;
    int CompositeActor_out2;
    A1_Update(&self->CompositeActor, Expression_output, Ramp_output, &CompositeActor_out1, &CompositeActor_out2);
    BitmapCov::munitBitmap[3] = 1;
    /* Calculate code of "ComplexBranch.Display" */
    printf("\"ComplexBranch.Display\" output as follows: \n");
    printf("%d\n", CompositeActor_out1);
    BitmapCov::munitBitmap[4] = 1;
    /* Calculate code of "ComplexBranch.Display_1" */
    printf("\"ComplexBranch.Display_1\" output as follows: \n");
    printf("%d\n", CompositeActor_out2);
}
/* Init function of "ComplexBranch" */
void A0_Init(struct A0_state* self) {
    BitmapCov::munitBitmap[5] = 1;
    /* Calculate code of "ComplexBranch" */
    BitmapCov::munitBitmap[6] = 1;
    /* Calculate code of "ComplexBranch.Ramp" */
    self->Ramp_lastValue = 0;
    BitmapCov::munitBitmap[7] = 1;
    /* Calculate code of "ComplexBranch.CompositeActor" */
    A1_Init(&self->CompositeActor);
}
/* Update function of "ComplexBranch.CompositeActor" */
void A1_Update(struct A1_state* self, unsigned char in1, int in2, int* out1, int* out2) {
    /* Local Variable define of "ComplexBranch.CompositeActor.BooleanMultiplexor_1.output" */
    int BooleanMultiplexor_1_output;
    /* Local Variable define of "ComplexBranch.CompositeActor.BooleanMultiplexor_2.output" */
    int BooleanMultiplexor_2_output;
    /* Local Variable define of "ComplexBranch.CompositeActor.BooleanMultiplexor.output" */
    int BooleanMultiplexor_output;
    /* Local Variable define of "ComplexBranch.CompositeActor.BooleanMultiplexor_6.output" */
    int BooleanMultiplexor_6_output;
    /* Local Variable define of "ComplexBranch.CompositeActor.BooleanMultiplexor_1_2.output" */
    int BooleanMultiplexor_1_2_output;
    /* Local Variable define of "ComplexBranch.CompositeActor.BooleanMultiplexor_9.output" */
    int BooleanMultiplexor_9_output;
    /* Local Variable define of "ComplexBranch.CompositeActor.BooleanMultiplexor_10.output" */
    int BooleanMultiplexor_10_output;
    /* Local Variable define of "ComplexBranch.CompositeActor.BooleanMultiplexor_1_1.output" */
    int BooleanMultiplexor_1_1_output;
    BitmapCov::munitBitmap[8] = 1;
    /* Calculate code of "ComplexBranch.CompositeActor.Expression" */
    int Expression_in = in2;
    bool Expression_output = ((Expression_in % 153) == 0);
    BitmapCov::munitBitmap[9] = 1;
    /* Calculate code of "ComplexBranch.CompositeActor.Expression_1" */
    bool Expression_1_in = in1;
    bool Expression_1_output = (Expression_1_in == true);
    if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(Expression_1_output, 0, 1, 0), -1, 0, 0)) {
        BitmapCov::branchBitmap[0] = 1;
        /* Branch of  */
        BitmapCov::munitBitmap[10] = 1;
        /* Calculate code of "ComplexBranch.CompositeActor.Ramp" */
        int Ramp_output = self->Ramp_lastValue;
        self->Ramp_lastValue = self->Ramp_lastValue + 1;
        BitmapCov::munitBitmap[11] = 1;
        /* Calculate code of "ComplexBranch.CompositeActor.Expression_7" */
        int Expression_7_in = Ramp_output;
        bool Expression_7_output = ((Expression_7_in % 5) == 0);
        if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(Expression_7_output, 2, 1, 1), -3, 0, 1)) {
            BitmapCov::branchBitmap[1] = 1;
            /* Branch of  */
            BitmapCov::munitBitmap[12] = 1;
            /* Calculate code of "ComplexBranch.CompositeActor.Expression_8" */
            int Expression_8_in = Ramp_output;
            bool Expression_8_output = (Expression_8_output > 0.9);
            if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(Expression_8_output, 4, 1, 2), -5, 0, 2)) {
                BitmapCov::branchBitmap[2] = 1;
                /* Branch of  */
                BitmapCov::munitBitmap[13] = 1;
                /* Calculate code of "ComplexBranch.CompositeActor.Expression_9" */
                int Expression_9_in = Ramp_output;
                int Expression_9_output = globalParams.A1_P3;
                BitmapCov::munitBitmap[14] = 1;
                /* Calculate code of "ComplexBranch.CompositeActor.BooleanMultiplexor_1" */
                BooleanMultiplexor_1_output = Expression_9_output;
            }
            else {
                BitmapCov::branchBitmap[3] = 1; BitmapCov::munitBitmap[15] = 1;
                /* Calculate code of "ComplexBranch.CompositeActor.Expression_5" */
                int Expression_5_in = Ramp_output;
                int Expression_5_output = globalParams.A1_P4;
                BitmapCov::munitBitmap[16] = 1;
                /* Calculate code of "ComplexBranch.CompositeActor.BooleanMultiplexor_1" */
                BooleanMultiplexor_1_output = Expression_5_output;
            }
            BitmapCov::munitBitmap[17] = 1;
            /* Calculate code of "ComplexBranch.CompositeActor.BooleanMultiplexor_2" */
            BooleanMultiplexor_2_output = BooleanMultiplexor_1_output;
        }
        else {
            BitmapCov::branchBitmap[4] = 1; BitmapCov::munitBitmap[18] = 1;
            /* Calculate code of "ComplexBranch.CompositeActor.Expression_6" */
            int Expression_6_in = Ramp_output;
            int Expression_6_output = globalParams.A1_P2;
            BitmapCov::munitBitmap[19] = 1;
            /* Calculate code of "ComplexBranch.CompositeActor.BooleanMultiplexor_2" */
            BooleanMultiplexor_2_output = Expression_6_output;
        }
        BitmapCov::munitBitmap[20] = 1;
        /* Calculate code of "ComplexBranch.CompositeActor.BooleanMultiplexor" */
        BooleanMultiplexor_output = BooleanMultiplexor_2_output;
    }
    else {
        BitmapCov::branchBitmap[5] = 1; BitmapCov::munitBitmap[21] = 1;
        /* Calculate code of "ComplexBranch.CompositeActor.Expression_2" */
        bool Expression_2_in = Expression_1_output;
        int Expression_2_output = globalParams.A1_P1;
        BitmapCov::munitBitmap[22] = 1;
        /* Calculate code of "ComplexBranch.CompositeActor.BooleanMultiplexor" */
        BooleanMultiplexor_output = Expression_2_output;
    }
    if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(Expression_output, 6, 1, 3), -7, 0, 3)) {
        BitmapCov::branchBitmap[6] = 1;
        /* Branch of  */
        BitmapCov::munitBitmap[23] = 1;
        /* Calculate code of "ComplexBranch.CompositeActor.Expression_3" */
        int Expression_3_in = in2;
        bool Expression_3_output = ((Expression_3_in % 83) == 0);
        if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(Expression_3_output, 8, 1, 4), -9, 0, 4)) {
            BitmapCov::branchBitmap[7] = 1;
            /* Branch of  */
            BitmapCov::munitBitmap[24] = 1;
            /* Calculate code of "ComplexBranch.CompositeActor.Expression_8_1" */
            int Expression_8_1_in = in2;
            double Expression_8_1_output = 0;
            BitmapCov::munitBitmap[25] = 1;
            /* Calculate code of "ComplexBranch.CompositeActor.MultiplyDivide" */
            double MultiplyDivide_output = in2 / (Expression_8_1_output);
            BitmapCov::munitBitmap[26] = 1;
            /* Calculate code of "ComplexBranch.CompositeActor.Expression_3_1" */
            double Expression_3_1_in = Expression_8_1_output;
            bool Expression_3_1_output = (Expression_3_1_in > 0.9);
            if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(Expression_3_1_output, 10, 1, 5), -11, 0, 5)) {
                BitmapCov::branchBitmap[8] = 1;
                /* Branch of  */
                BitmapCov::munitBitmap[27] = 1;
                /* Calculate code of "ComplexBranch.CompositeActor.Expression_11" */
                double Expression_11_in = MultiplyDivide_output;
                int Expression_11_output = globalParams.A1_P5;
                BitmapCov::munitBitmap[28] = 1;
                /* Calculate code of "ComplexBranch.CompositeActor.BooleanMultiplexor_6" */
                BooleanMultiplexor_6_output = Expression_11_output;
            }
            else {
                BitmapCov::branchBitmap[9] = 1; BitmapCov::munitBitmap[29] = 1;
                /* Calculate code of "ComplexBranch.CompositeActor.Expression_11_1" */
                double Expression_11_1_in = MultiplyDivide_output;
                int Expression_11_1_output = globalParams.A1_P6;
                BitmapCov::munitBitmap[30] = 1;
                /* Calculate code of "ComplexBranch.CompositeActor.BooleanMultiplexor_6" */
                BooleanMultiplexor_6_output = Expression_11_1_output;
            }
            BitmapCov::munitBitmap[31] = 1;
            /* Calculate code of "ComplexBranch.CompositeActor.BooleanMultiplexor_1_2" */
            BooleanMultiplexor_1_2_output = BooleanMultiplexor_6_output;
        }
        else {
            BitmapCov::branchBitmap[10] = 1; BitmapCov::munitBitmap[32] = 1;
            /* Calculate code of "ComplexBranch.CompositeActor.Expression_13" */
            int Expression_13_in = in2;
            int Expression_13_output = globalParams.A1_P7;
            BitmapCov::munitBitmap[33] = 1;
            /* Calculate code of "ComplexBranch.CompositeActor.BooleanMultiplexor_1_2" */
            BooleanMultiplexor_1_2_output = Expression_13_output;
        }
        BitmapCov::munitBitmap[34] = 1;
        /* Calculate code of "ComplexBranch.CompositeActor.BooleanMultiplexor_1_1" */
        BooleanMultiplexor_1_1_output = BooleanMultiplexor_1_2_output;
    }
    else {
        BitmapCov::branchBitmap[11] = 1; BitmapCov::munitBitmap[35] = 1;
        /* Calculate code of "ComplexBranch.CompositeActor.Expression_4" */
        int Expression_4_in = in2;
        bool Expression_4_output = ((Expression_4_in % 123) == 0);
        if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(Expression_4_output, 12, 1, 6), -13, 0, 6)) {
            BitmapCov::branchBitmap[12] = 1;
            /* Branch of  */
            BitmapCov::munitBitmap[36] = 1;
            /* Calculate code of "ComplexBranch.CompositeActor.Scale_1" */
            int Scale_1_output = 123 * in2;
            BitmapCov::munitBitmap[37] = 1;
            /* Calculate code of "ComplexBranch.CompositeActor.Expression_4_1" */
            int Expression_4_1_in = Scale_1_output;
            bool Expression_4_1_output = ((Expression_4_1_in % 243) == 0);
            if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(Expression_4_1_output, 14, 1, 7), -15, 0, 7)) {
                BitmapCov::branchBitmap[13] = 1;
                /* Branch of  */
                BitmapCov::munitBitmap[38] = 1;
                /* Calculate code of "ComplexBranch.CompositeActor.Expression_14" */
                int Expression_14_in = Scale_1_output;
                int Expression_14_output = globalParams.A1_P9;
                BitmapCov::munitBitmap[39] = 1;
                /* Calculate code of "ComplexBranch.CompositeActor.BooleanMultiplexor_9" */
                BooleanMultiplexor_9_output = Expression_14_output;
            }
            else {
                BitmapCov::branchBitmap[14] = 1; BitmapCov::munitBitmap[40] = 1;
                /* Calculate code of "ComplexBranch.CompositeActor.Expression_15" */
                int Expression_15_in = Scale_1_output;
                int Expression_15_output = globalParams.A1_P10;
                BitmapCov::munitBitmap[41] = 1;
                /* Calculate code of "ComplexBranch.CompositeActor.BooleanMultiplexor_9" */
                BooleanMultiplexor_9_output = Expression_15_output;
            }
            BitmapCov::munitBitmap[42] = 1;
            /* Calculate code of "ComplexBranch.CompositeActor.BooleanMultiplexor_10" */
            BooleanMultiplexor_10_output = BooleanMultiplexor_9_output;
        }
        else {
            BitmapCov::branchBitmap[15] = 1; BitmapCov::munitBitmap[43] = 1;
            /* Calculate code of "ComplexBranch.CompositeActor.Expression_16" */
            int Expression_16_in = in2;
            int Expression_16_output = globalParams.A1_P8;
            BitmapCov::munitBitmap[44] = 1;
            /* Calculate code of "ComplexBranch.CompositeActor.BooleanMultiplexor_10" */
            BooleanMultiplexor_10_output = Expression_16_output;
        }
        BitmapCov::munitBitmap[45] = 1;
        /* Calculate code of "ComplexBranch.CompositeActor.Scale" */
        int Scale_output = 3 * BooleanMultiplexor_10_output;
        BitmapCov::munitBitmap[46] = 1;
        /* Calculate code of "ComplexBranch.CompositeActor.AddSubtract" */
        int AddSubtract_output = Scale_output - (BooleanMultiplexor_10_output);
        BitmapCov::munitBitmap[47] = 1;
        /* Calculate code of "ComplexBranch.CompositeActor.MultiplyDivide_1" */
        int MultiplyDivide_1_output = Scale_output / (AddSubtract_output);
        BitmapCov::munitBitmap[48] = 1;
        /* Calculate code of "ComplexBranch.CompositeActor.BooleanMultiplexor_1_1" */
        BooleanMultiplexor_1_1_output = BooleanMultiplexor_10_output;
    }
}
/* Init function of "ComplexBranch.CompositeActor" */
void A1_Init(struct A1_state* self) {
    BitmapCov::munitBitmap[49] = 1;
    /* Calculate code of "ComplexBranch.CompositeActor" */
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