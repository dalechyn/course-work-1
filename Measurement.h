//
// Created by leshik on 25.03.19.
//

#ifndef COURSE_WORK_MEASUREMENT_H
#define COURSE_WORK_MEASUREMENT_H

#include <time.h>
#include <stdio.h>
#include "Common.h"
#include "SortingVector.h"
#include "SortingArray3D.h"


#define measurements_number 28
#define rejected_number 2
#define min_max_number 3

extern clock_t Res[measurements_number];

float MeasurementProcessing();
void Select1_Vector_Measurement(int x);
void Select3_Vector_Measurement(int x);
void Exchange3_Vector_Measurement(int x);
void Select1_Array3D_Measurement(int x);
void Select3_Array3D_Measurement(int x);
void Exchange3_Array3D_Measurement(int x);

#endif //COURSE_WORK_MEASUREMENT_H
