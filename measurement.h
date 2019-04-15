#ifndef COURSE_WORK_MEASUREMENT_H
#define COURSE_WORK_MEASUREMENT_H

#define measurements_number 28
#define rejected_number 2
#define min_max_number 3

#include <time.h>

extern clock_t Res[measurements_number];

typedef struct {
    float ordered;
    float reversed;
    float randomized;
} measurement_s;

float MeasurementProcessing();
measurement_s measure(int isVector, int sort);
void measurementSelect1(int order, int isVector);
void measurementSelect3(int order, int isVector);
void measurementExchange3(int order, int isVector);

#endif //COURSE_WORK_MEASUREMENT_H
