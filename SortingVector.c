#include <time.h>
#include <math.h>
#include "Common.h"
#include "SortingVector.h"

clock_t sortVectorExchange3() {
    int R, k, tmp;
    clock_t time_start, time_stop;
    time_start = clock();
    R = N - 1;
    while (R > 0) {
        k = 0;
        for (int i = 0; i < R; i++)
            if (vector[i] > vector[i + 1]) {
                tmp = vector[i];
                vector[i] = vector[i + 1];
                vector[i + 1] = tmp;
                k = i;
            }
        R = k;
    }
    time_stop = clock();
    return time_stop - time_start;
}

clock_t sortVectorSelect1() {
    int Min, imin;
    clock_t time_start, time_stop;
    time_start = clock();
    for (int s = 0; s < N - 1; s++) {
        Min = vector[s];
        imin = s;
        for (int i = s + 1; i < N; i++)
            if (vector[i] < Min) {
                Min = vector[i];
                imin = i;
            }
        vector[imin] = vector[s];
        vector[s] = Min;
    }
    time_stop = clock();
    return time_stop - time_start;
}

clock_t sortVectorSelect3() {
    int Min, Max;
    int L, R, imin, imax;
    clock_t time_start, time_stop;
    time_start = clock();
    L = 0;
    R = N - 1;
    while (L < R) {
        Min = vector[L];
        imin = L;
        Max = vector[L];
        imax = L;
        for (int i = L + 1; i < R + 1; i++) {
            if (vector[i] < Min) {
                Min = vector[i];
                imin = i;
            } else if (vector[i] > Max) {
                Max = vector[i];
                imax = i;
            }
        }
        vector[imin] = vector[L];
        vector[L] = Min;
        if (imax == L) vector[imin] = vector[R];
        else
            vector[imax] = vector[R];
        vector[R] = Max;
        L = L + 1;
        R = R - 1;
    }
    time_stop = clock();
    return time_stop - time_start;
}
