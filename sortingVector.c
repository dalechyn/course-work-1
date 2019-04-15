#include <math.h>
#include "common.h"
#include "sortingVector.h"

clock_t sortVectorExchange3() {
    int R, k, tmp;
    clock_t time_start, time_stop;
    time_start = clock();
    R = N - 1;
    while (R > 0) {
        k = 0;
        for (int i = 0; i < R; i++)
            if (Vector[i] > Vector[i + 1]) {
                tmp = Vector[i];
                Vector[i] = Vector[i + 1];
                Vector[i + 1] = tmp;
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
        Min = Vector[s];
        imin = s;
        for (int i = s + 1; i < N; i++)
            if (Vector[i] < Min) {
                Min = Vector[i];
                imin = i;
            }
        Vector[imin] = Vector[s];
        Vector[s] = Min;
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
        Min = Vector[L];
        imin = L;
        Max = Vector[L];
        imax = L;
        for (int i = L + 1; i < R + 1; i++) {
            if (Vector[i] < Min) {
                Min = Vector[i];
                imin = i;
            } else if (Vector[i] > Max) {
                Max = Vector[i];
                imax = i;
            }
        }
        Vector[imin] = Vector[L];
        Vector[L] = Min;
        if (imax == L) Vector[imin] = Vector[R];
        else
            Vector[imax] = Vector[R];
        Vector[R] = Max;
        L = L + 1;
        R = R - 1;
    }
    time_stop = clock();
    return time_stop - time_start;
}
