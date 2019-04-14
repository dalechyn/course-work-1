//
#ifndef COURSE_WORK_COMMON_H
#define COURSE_WORK_COMMON_H

#include <malloc.h>
#include <stdlib.h>

extern int *vector;
extern int ***Arr3D;
extern int P;//перерізи
extern int M;//рядки
extern int N;//стовбці

void Vector();
void FillVector(int b);
void FreeVector();
void Array3D();
void FreeArray3D();
void FillArray3D(int b);

#endif //COURSE_WORK_COMMON_H
