#include <time.h>
#include <stdio.h>
#include "Common.h"
#include "SortingVector.h"
#include "SortingArray3D.h"
#include "Measurement.h"

clock_t Res[measurements_number];

float MeasurementProcessing() {
    long int Sum;
    float AverageValue;

    clock_t buf;
    int L = rejected_number, R = measurements_number - 1;
    int k = rejected_number;
    for (int j = 0; j < min_max_number; j++) {
        for (int i = L; i < R; i++) {
            if (Res[i] > Res[i + 1]) {
                buf = Res[i];
                Res[i] = Res[i + 1];
                Res[i + 1] = buf;
                k = i;
            }
        }
        R = k;
        for (int i = R - 1; i >= L; i--) {
            if (Res[i] > Res[i + 1]) {
                buf = Res[i];
                Res[i] = Res[i + 1];
                Res[i + 1] = buf;
                k = i;
            }
        }
        L = k + 1;
    }

    Sum = 0;
    for (int i = rejected_number + min_max_number; i < measurements_number - min_max_number; i++)
        Sum = Sum + Res[i];

    AverageValue = (float) Sum / (float) (measurements_number - 2 * min_max_number - rejected_number);

    return AverageValue;
}

void Select1_Vector_Measurement(int x) {
    for (int i = 0; i < measurements_number; i++) {
        fillVector(x);
        Res[i] = sortVectorSelect1();
    }
}

void Select3_Vector_Measurement(int x) {
    for (int i = 0; i < measurements_number; i++) {
        fillVector(x);
        Res[i] = sortVectorSelect3();
    }
}

void Exchange3_Vector_Measurement(int x) {
    for (int i = 0; i < measurements_number; i++) {
        fillVector(x);
 //       Res[i] = sortVectorExchange3();
    }
}


void Select1_Array3D_Measurement(int x) {
    for (int i = 0; i < measurements_number; i++) {
        fillArray3D(x);
        Res[i] = sortArr3DSelect1();
    }
}

void Select3_Array3D_Measurement(int x) {
    for (int i = 0; i < measurements_number; i++) {
        fillArray3D(x);
        Res[i] = sortArr3DSelect3();
    }
}

void Exchange3_Array3D_Measurement(int x) {
    for (int i = 0; i < measurements_number; i++) {
        fillArray3D(x);
 //       Res[i] = sortArr3DExchange3();
    }
}