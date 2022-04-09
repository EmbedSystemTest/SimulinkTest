#ifndef _DEFINE_H_
#define _DEFINE_H_
#include "BitmapCov.h"
#include <cstring>
/* Head File define of "ComplexBranch" */
#include <stdlib.h>
/* Head File define of "ComplexBranch" */
#include <stdio.h>
/* Head File define of "ComplexBranch" */
#include <string.h>
#define bool char


#define PI 3.1415926535897932384626
struct Parameters_Struct;
struct A1_state;
struct A0_state;
/* Struct define of "ComplexBranch" */
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
/* Struct define of "ComplexBranch.CompositeActor" */
struct A1_state {
    int Ramp_lastValue;
};
/* Struct define of "ComplexBranch" */
struct A0_state {
    int Ramp_lastValue;
    struct A1_state CompositeActor;
};
/* Global Variable define of  */
extern struct Parameters_Struct globalParams;
/* Update function of "ComplexBranch" */
void A0_Update(struct A0_state* self);
/* Init function of "ComplexBranch" */
void A0_Init(struct A0_state* self);
/* Update function of "ComplexBranch.CompositeActor" */
void A1_Update(struct A1_state* self, unsigned char in1, int in2, int* out1, int* out2);
/* Init function of "ComplexBranch.CompositeActor" */
void A1_Init(struct A1_state* self);
#endif


