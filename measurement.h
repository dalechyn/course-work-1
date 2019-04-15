#ifndef COURSE_WORK_MEASUREMENT_H
#define COURSE_WORK_MEASUREMENT_H

#define measurements_number 28
#define rejected_number 2
#define min_max_number 3

extern clock_t Res[measurements_number];

typedef struct {
    float ordered;
    float reversed;
    float randomized;
} measurement_t;

float MeasurementProcessing();
measurement_t measure(int isVector, void (*cb)(int, int));
void measurementSelect1(int x, int isVector);
void measurementSelect3(int x, int isVector);
void measurementExchange3(int x, int isVector);

#endif //COURSE_WORK_MEASUREMENT_H
