#include "common.h"
#include "sortingArray3D.h"

/*
 * МОДУЛЬ sortingArray
 *
 * Всі функції описані в цьому модулі сортують тривимірний масив
 * і повертають час його роботи
 */

clock_t sortArr3DSelect1() {
    clock_t time_start, time_stop;
    time_start = clock();
    for (int k = 0; k < P; k++)
        for (int Lj = 0; Lj < N; Lj++)
            for (int Li = 0; Li < M; Li++) {
                int imin = Li, jmin = Lj, Min = Arr3D[k][Li][Lj];
                // переглядаємо лівий невідсортований стовпчик
                for (int i = Li + 1; i < M; i++)
                    if (Arr3D[k][i][Lj] < Min) {
                        Min = Arr3D[k][i][Lj];
                        imin = i;
                        jmin = Lj;
                    }
                // переглядаємо інші
                for (int j = Lj + 1; j < N; j++)
                    for (int i = 0; i < M; i++)
                        if (Arr3D[k][i][j] < Min) {
                            Min = Arr3D[k][i][j];
                            imin = i;
                            jmin = j;
                        }
                // виконуємо обмін
                Arr3D[k][imin][jmin] = Arr3D[k][Li][Lj];
                Arr3D[k][Li][Lj] = Min;
            }
    time_stop = clock();
    return time_stop - time_start;
}

clock_t sortArr3DSelect3() {
    clock_t time_start, time_stop;
    time_start = clock();
    for (int k = 0; k < P; k++) {
        int Li = 0, Lj = 0, Ri = M - 1, Rj = N - 1;
        //сортуємо елементи до центрального стовпчика
        while (Lj < Rj) {
            while (Li < M) {
                int imin = Li, jmin = Lj, Min = Arr3D[k][Li][Lj];
                int imax = Li, jmax = Lj, Max = Arr3D[k][Li][Lj];
                // переглядаємо лівий невідсортований стовпчик
                for (int i = Li + 1; i < M; i++)
                    if (Arr3D[k][i][Lj] < Min) {
                        Min = Arr3D[k][i][Lj];
                        imin = i;
                        jmin = Lj;
                    } else if (Arr3D[k][i][Lj] > Max) {
                        Max = Arr3D[k][i][Lj];
                        imax = i;
                        jmax = Lj;
                    }
                // переглядаємо інші
                for (int j = Lj + 1; j < Rj; j++)
                    for (int i = 0; i < M; i++)
                        if (Arr3D[k][i][j] < Min) {
                            Min = Arr3D[k][i][j];
                            imin = i;
                            jmin = j;
                        } else if (Arr3D[k][i][j] > Max) {
                            Max = Arr3D[k][i][j];
                            imax = i;
                            jmax = j;
                        }
                // переглядаємо правий невідсортований стовпчик
                for (int i = 0; i < Ri + 1; i++) {
                    if (Arr3D[k][i][Rj] < Min) {
                        Min = Arr3D[k][i][Rj];
                        imin = i;
                        jmin = Rj;
                    } else if (Arr3D[k][i][Rj] > Max) {
                        Max = Arr3D[k][i][Rj];
                        imax = i;
                        jmax = Rj;
                    }
                }
                // виконуємо обмін
                Arr3D[k][imin][jmin] = Arr3D[k][Li][Lj];
                Arr3D[k][Li][Lj] = Min;
                if (imax == Li && jmax == Lj) Arr3D[k][imin][jmin] = Arr3D[k][Ri][Rj];
                else Arr3D[k][imax][jmax] = Arr3D[k][Ri][Rj];
                Arr3D[k][Ri][Rj] = Max;

                Li++;
                Ri--;
            }
            Lj++;
            Rj--;
            Li = 0;
            Ri = M - 1;
        }
        // Окремо сортуємо центральний стовпчик, бо на цьому стовпці перетинаються ліві і праві відсортовані
        // частини масиву
        while (Li < Ri) {
            int imin = Li, Min = Arr3D[k][Li][Lj];
            int imax = Li, Max = Arr3D[k][Li][Lj];
            for (int i = Li + 1; i < Ri + 1; i++) {
                if (Arr3D[k][i][Lj] < Min) {
                    Min = Arr3D[k][i][Lj];
                    imin = i;
                } else if (Arr3D[k][i][Lj] > Max) {
                    Max = Arr3D[k][i][Lj];
                    imax = i;
                }
            }
            Arr3D[k][imin][Lj] = Arr3D[k][Li][Lj];
            Arr3D[k][Li][Lj] = Min;
            if (imax == Li) Arr3D[k][imin][Lj] = Arr3D[k][Ri][Lj];
            else Arr3D[k][imax][Lj] = Arr3D[k][Ri][Lj];
            Arr3D[k][Ri][Lj] = Max;
            Li++;
            Ri--;
        }
    }
    time_stop = clock();
    return time_stop - time_start;
}

clock_t sortArr3DExchange3() {
    int Ri, Rj, ki, kj, tmp;
    clock_t time_start, time_stop;
    time_start = clock();
    for (int k = 0; k < P; k++) {
        Ri = M - 1;
        Rj = N - 1;
        while (Rj > 0 || Ri > 0) {
            ki = 0;
            kj = 0;
            // Оброблюємо перший стовпець, щоб знайти найнижній елемент
            for (int i = 0; i < M - 1; i++) {
                if (Arr3D[k][i][0] > Arr3D[k][i + 1][0]) {
                        tmp = Arr3D[k][i][0];
                        Arr3D[k][i][0] = Arr3D[k][i + 1][0];
                        Arr3D[k][i + 1][0] = tmp;
                        ki = i;
                        kj = 0;
                }
            }
            // Оброблюємо всі стовпці до Rj
            for (int j = 1; j < Rj; j++) {
                if (Arr3D[k][M - 1][j - 1] > Arr3D[k][0][j]) {
                        tmp = Arr3D[k][0][j];
                        Arr3D[k][0][j] = Arr3D[k][M - 1][j - 1];
                        Arr3D[k][M - 1][j - 1] = tmp;
                        ki = 0;
                        kj = j;
                }
                for (int i = 0; i < M - 1; i++)
                    if (Arr3D[k][i][j] > Arr3D[k][i + 1][j]) {
                        tmp = Arr3D[k][i][j];
                        Arr3D[k][i][j] = Arr3D[k][i + 1][j];
                        Arr3D[k][i + 1][j] = tmp;
                        ki = i;
                        kj = j;
                    }
            }
            // Оброблюємо стовбець з відсортованою частиною масиву
            if (Arr3D[k][M - 1][Rj - 1] > Arr3D[k][0][Rj]) {
                tmp = Arr3D[k][0][Rj];
                Arr3D[k][0][Rj] = Arr3D[k][M - 1][Rj - 1];
                Arr3D[k][M - 1][Rj - 1] = tmp;
                ki = 0;
                kj = Rj;
            }
            for (int i = 0; i < Ri; i++) {
                if (Arr3D[k][i][Rj] > Arr3D[k][i + 1][Rj]) {
                    tmp = Arr3D[k][i][Rj];
                    Arr3D[k][i][Rj] = Arr3D[k][i + 1][Rj];
                    Arr3D[k][i + 1][Rj] = tmp;
                    ki = i;
                    kj = Rj;
                }
            }
            Ri = ki;
            Rj = kj;
        }
    }
    time_stop = clock();
    return time_stop - time_start;
}
