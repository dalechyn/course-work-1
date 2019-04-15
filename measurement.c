#include <time.h>
#include <stdio.h>
#include "common.h"
#include "sortingVector.h"
#include "sortingArray3D.h"
#include "measurement.h"

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

measurement_s measure(int isVector, int sort) {
    measurement_s res = {0.f, 0.f, 0.f};
    if(isVector) initVector();
    else initArray3D();
    switch (sort) {
        case 1:
            measurementSelect1(1, isVector);
            res.ordered = MeasurementProcessing();
            measurementSelect1(2, isVector);
            res.reversed = MeasurementProcessing();
            measurementSelect1(3, isVector);
            res.randomized = MeasurementProcessing();
            break;
        case 2:
            measurementSelect3(1, isVector);
            res.ordered = MeasurementProcessing();
            measurementSelect3(2, isVector);
            res.reversed = MeasurementProcessing();
            measurementSelect3(3, isVector);
            res.randomized = MeasurementProcessing();
            break;
        case 3:
            measurementExchange3(1, isVector);
            res.ordered = MeasurementProcessing();
            measurementExchange3(2, isVector);
            res.reversed = MeasurementProcessing();
            measurementExchange3(3, isVector);
            res.randomized = MeasurementProcessing();
            break;
        default: break;
    }
    if(isVector) freeVector();
    else freeArray3D();
    return res;
}

void measurementSelect1(int order, int isVector) {
    if(isVector) for (int i = 0; i < measurements_number; i++) {
        fillVector(order);
        Res[i] = sortVectorSelect1();
    } else for(int i = 0; i < measurements_number; i++) {
        fillArray3D(order);
        Res[i] = sortArr3DSelect1();
    }
}

void measurementSelect3(int order, int isVector) {
    if(isVector) for (int i = 0; i < measurements_number; i++) {
        fillVector(order);
        Res[i] = sortVectorSelect3();
    } else for(int i = 0; i < measurements_number; i++) {
        fillArray3D(order);
        Res[i] = sortArr3DSelect3();
    }
}

void measurementExchange3(int order, int isVector) {
    if(isVector) for (int i = 0; i < measurements_number; i++) {
        fillVector(order);
        Res[i] = sortVectorExchange3();
    } else for(int i = 0; i < measurements_number; i++) {
        fillArray3D(order);
        Res[i] = sortArr3DExchange3();
    }
}
