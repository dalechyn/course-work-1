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
        FillVector(x);
        Res[i] = Select1_Vector();
    }
}

void Select3_Vector_Measurement(int x) {
    for (int i = 0; i < measurements_number; i++) {
        FillVector(x);
        Res[i] = Select3_Vector();
    }
}

void Exchange3_Vector_Measurement(int x) {
    for (int i = 0; i < measurements_number; i++) {
        FillVector(x);
 //       Res[i] = Exchange3_Vector();
    }
}


void Select1_Array3D_Measurement(int x) {
    for (int i = 0; i < measurements_number; i++) {
        FillArray3D(x);
        Res[i] = Select1_Arr3D();
    }
}

void Select3_Array3D_Measurement(int x) {
    for (int i = 0; i < measurements_number; i++) {
        FillArray3D(x);
        Res[i] = Select3_Arr3D();
    }
}

void Exchange3_Array3D_Measurement(int x) {
    for (int i = 0; i < measurements_number; i++) {
        FillArray3D(x);
 //       Res[i] = Exchange3_Arr3D();
    }
}