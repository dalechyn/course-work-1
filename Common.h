#ifndef COURSE_WORK_COMMON_H
#define COURSE_WORK_COMMON_H

extern int * Vector;
extern int *** Arr3D;
extern int P;
extern int M;
extern int N;

void initVector();
void fillVector(int b);
void freeVector();
void initArray3D();
void freeArray3D();
void fillArray3D(int b);
void printVector();
void printArray3D();

#endif //COURSE_WORK_COMMON_H
