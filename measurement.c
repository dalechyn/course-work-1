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

measurement_t measure(int isVector, void (*cb)(int, int)) {
    measurement_t res = {0.f, 0.f, 0.f};
    if(isVector) {
        initVector();

        cb(1, isVector);
        res.ordered = MeasurementProcessing();

        cb(2, isVector);
        res.reversed = MeasurementProcessing();

        cb(3, isVector);

        res.randomized = MeasurementProcessing();

        freeVector();
    } else {
        initArray3D();
        initVector(); //TODO: DELETE

        cb(1, isVector);
        res.ordered = MeasurementProcessing();

        cb(2, isVector);
        res.reversed = MeasurementProcessing();

        cb(3, isVector);
        res.randomized = MeasurementProcessing();

        freeArray3D();
        freeVector(); //TODO: DELETE
    }
    return res;
}

void measurementSelect1(int x, int isVector) {
    if(isVector) for (int i = 0; i < measurements_number; i++) {
        fillVector(x);
        Res[i] = sortVectorSelect1();
    } else for(int i = 0; i < measurements_number; i++) {
        fillArray3D(x);
        Res[i] = sortArr3DSelect1();
    }
}

void measurementSelect3(int x, int isVector) {
    if(isVector) for (int i = 0; i < measurements_number; i++) {
        fillVector(x);
        Res[i] = sortVectorSelect3();
    } else for(int i = 0; i < measurements_number; i++) {
        fillArray3D(x);
        Res[i] = sortArr3DSelect3();
    }
}

void measurementExchange3(int x, int isVector) {
    if(isVector) for (int i = 0; i < measurements_number; i++) {
        fillVector(x);
        Res[i] = sortVectorExchange3();
    } else for(int i = 0; i < measurements_number; i++) {
        fillArray3D(x);
        Res[i] = sortArr3DExchange3();
    }
}
