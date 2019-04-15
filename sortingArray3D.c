#include <math.h>
#include "common.h"
#include "sortingArray3D.h"

clock_t sortArr3DSelect1() {
    int swapped, Elem;
    int L, R, j, i, ii, jj, k;
    clock_t time_start, time_stop;

    time_start = clock();

    //Підрахунок масиву сум
    for(i = 0; i < P; i++) {
        for(ii = 0; ii < M; ii++) {
            for(jj = 0; jj < N; jj++) {
                Vector[i] += Arr3D[i][ii][jj];
            }
        }
    }

    for (i = 1; i <= P - 1; i++)
    {
        Elem = Vector[i];
        L = 0;
        R = i;
        while (L < R)
        {
            j = (L + R) / 2;
            if (Vector[j] <= Elem)
            {
                L = j + 1;
            }
            else R = j;
        }
        for (k = i - 1; k >= R; k--)
        {
            //Обмін елементів  k+1 та k
            swapped = Vector[k + 1];
            Vector[k + 1] = Vector[k];
            Vector[k] = swapped;

            for(ii = 0; ii < M; ii++)
                for(jj = 0; jj < N; jj++)
                {
                    swapped = Arr3D[k + 1][ii][jj];
                    Arr3D[k + 1][ii][jj] = Arr3D[k][ii][jj];
                    Arr3D[k][ii][jj] = swapped;
                }

        }
    }
    time_stop = clock();

    return time_stop - time_start;
}

clock_t sortArr3DSelect3() {
    int L, R, imin, imax, i, ii, jj;
    int tmp;
    clock_t time_start, time_stop;

    time_start = clock();

    //Підрахунок масиву сум
    for(i = 0; i < P; i++) {
        for(ii = 0; ii < M; ii++) {
            for(jj = 0; jj < N; jj++) {
                Vector[i] += Arr3D[i][ii][jj];
            }
        }
    }

    L = 0;
    R = P - 1;
    while (L < R)
    {
        imin = L;
        imax = L;
        for (i = L + 1; i < R + 1; i++)
        {
            if (Vector[i] < Vector[imin]) imin = i;
            else if (Vector[i] > Vector[imax]) imax = i;
        }

        //Обмін елементів imin та L
        tmp = Vector[imin];
        Vector[imin] = Vector[L];
        Vector[L] = tmp;

        for(ii = 0; ii < M; ii++)
            for(jj = 0; jj < N; jj++)
            {
                tmp = Arr3D[imin][ii][jj];
                Arr3D[imin][ii][jj] = Arr3D[L][ii][jj];
                Arr3D[L][ii][jj] = tmp;
            }

        if (imax == L)
        {
            //Обмін елементів  imin та R
            tmp = Vector[imin];
            Vector[imin] = Vector[R];
            Vector[R] = tmp;

            for(ii = 0; ii < M; ii++)
                for(jj = 0; jj < N; jj++)
                {
                    tmp = Arr3D[imin][ii][jj];
                    Arr3D[imin][ii][jj] = Arr3D[R][ii][jj];
                    Arr3D[R][ii][jj] = tmp;
                }
        }
        else
        {
            //Обмін елементів  imax та R
            tmp = Vector[imax];
            Vector[imax] = Vector[R];
            Vector[R] = tmp;

            for(ii = 0; ii < M; ii++)
                for(jj = 0; jj < N; jj++)
                {
                    tmp = Arr3D[imax][ii][jj];
                    Arr3D[imax][ii][jj] = Arr3D[R][ii][jj];
                    Arr3D[R][ii][jj] = tmp;
                }
        }
        L = L + 1;
        R = R - 1;
    }
    time_stop = clock();

    return time_stop - time_start;
}

int Stages[65];

clock_t sortArr3DExchange3(){ //NOT CORRECT
    int t, j, k,  i, p, ii, jj;
    clock_t time_start, time_stop;
    int tmp;

    time_start = clock();

    //Підрахунок кроків алгоритму
    if (P < 4) {
        t = 1;
    }
    else {
        t = (int) log2f((float)P) - 1;
    }
    Stages[t - 1] = 1;
    for (i = t - 2; i >= 0; i--)
    {
        Stages[i] = 2 * Stages[i + 1] + 1;
    }

    //Підрахунок масиву сум
    for(i = 0; i < P; i++) {
        for(ii = 0; ii < M; ii++) {
            for(jj = 0; jj < N; jj++) {
                Vector[i] += Arr3D[i][ii][jj];
            }
        }
    }

    for (p = 0; p < t; p++)
    {
        k = Stages[p];
        for (i = k; i < P; i++)
        {
            j = i;
            while (j >= k && Vector[j] < Vector[j - k])
            {
                //Обмін елементів j та j - k
                tmp = Vector[j];
                Vector[j] = Vector[j - k];
                Vector[j - k] = tmp;

                for(ii = 0; ii < M; ii++)
                    for(jj = 0; jj < N; jj++)
                    {
                        tmp = Arr3D[j][ii][jj];
                        Arr3D[j][ii][jj] = Arr3D[j - k][ii][jj];
                        Arr3D[j - k][ii][jj] = tmp;
                    }

                j = j - k;
            }
        }
    }
    time_stop = clock();
    return time_stop - time_start;
}
