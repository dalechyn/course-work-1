#include <math.h>
#include "Common.h"
#include "SortingArray3D.h"

clock_t sortArr3DSelect1() {
    clock_t time_start, time_stop;
    time_start = clock();
    int Min, imin;
    for(int j = 0; j < N; j++)
        for(int k = 0; k < P; k++)
            for(int s = 0; s < M - 1; s++) {
                Min = Arr3D[k][s][j];
                imin = s;
                for(int i = s + 1; i < M; i++)
                    if(Arr3D[k][i][j] < Min) {
                        Min = Arr3D[k][i][j];
                        imin = i;
                    }
                Arr3D[k][imin][j] = Arr3D[k][s][j];
                Arr3D[k][s][j] = Min;
            }
    time_stop = clock();
    return time_stop - time_start;
}

clock_t sortArr3DSelect3() {
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

clock_t sortArr3DExchange3(){ //NOT CORRECT
    int L, R, imin, imax, tmp;
    clock_t time_start, time_stop;

    time_start = clock();

    for(int k = 0; k < P; k++) {

        L = 0;
        R = N - 1;

        while (L < R) {
            imin = L;
            imax = L;

            for (int i = L + 1; i < R + 1; i++)

                if (Arr3D[k][0][i] < Arr3D[k][0][imin]) imin = i;
                else if (Arr3D[k][0][i] > Arr3D[k][0][imax]) imax = i;

            for(int f = 0; f < M; f++) {
                tmp = Arr3D[k][f][imin];
                Arr3D[k][f][imin] = Arr3D[k][f][L];
                Arr3D[k][f][L] = tmp;
            }

            if (imax == L) {
                for(int f = 0; f < M; f++) {
                    tmp = Arr3D[k][f][imin];
                    Arr3D[k][f][imin] = Arr3D[k][f][R];
                    Arr3D[k][f][R] = tmp;
                }
            } else {
                for(int f = 0; f < M; f++) {
                    tmp = Arr3D[k][f][imax];
                    Arr3D[k][f][imax] = Arr3D[k][f][R];
                    Arr3D[k][f][R] = tmp;
                }
            }

            L = L + 1;
            R = R - 1;
        }

    }
    time_stop = clock();

    return time_stop - time_start;
}


clock_t Shell_1_Arr3D(){
    int t, j, k;
    int Elem[M];


    clock_t time_start, time_stop;

    time_start = clock();
    for(int x = 0; x < P; x++) {

        if (N < 4) {
            t = 1;
        } else {
            t = (int) ((log(N) / log(2)) - 1);
        }
        int Stages[t];

        Stages[t - 1] = 1;

        for (int i = t - 2; i >= 0; i--)
            Stages[i] = 2 * Stages[i + 1] + 1;

        for (int p = 0; p < t; p++) {
            k = Stages[p];

            for (int i = k; i < N; i++) {
                for(int f = 0; f < M; f++) {
                    Elem[f] = Arr3D[x][f][i];
                }
                j = i;

                while (j >= k && Elem[0] < Arr3D[x][0][j - k]) {
                    for(int f = 0; f < M; f++) {
                        Arr3D[x][f][j] = Arr3D[x][f][j - k];
                    }
                    j = j - k;

                }
                for(int f = 0; f < M; f++) {
                    Arr3D[x][f][j] = Elem[f];
                }
            }
        }
    }

    time_stop = clock();
    return time_stop - time_start;

}


clock_t InsertExchange_Arr3D() {
    int j, tmp;

    clock_t time_start, time_stop;
    time_start = clock();
    for (int k = 0; k < P; k++) {

        for (int i = 1; i < N; i++) {
            j = i;
            while (j > 0 && Arr3D[k][0][j] < Arr3D[k][0][j - 1]) {
                for (int f = 0; f < M; f++) {
                    tmp = Arr3D[k][f][j];
                    Arr3D[k][f][j] = Arr3D[k][f][j - 1];
                    Arr3D[k][f][j - 1] = tmp;
                }
                j = j - 1;
            }
        }
    }

        time_stop = clock();

        return time_stop - time_start;


}