#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include "common.h"

/*
 * МОДУЛЬ common:
 */

int N = 10;
int P = 3;
int M = 10;
int * Vector;
int *** Arr3D;

void initVector() {
    /*
     * Виділення пам'яті під вектор
     */
    Vector = (int *) malloc(N * sizeof(int *));
}

void initArray3D() {
    Arr3D = (int ***) malloc(P * sizeof(int **));
    for (int k = 0; k < P; k++) {
        Arr3D[k] = (int **) malloc(M * sizeof(int *));
        for (int i = 0; i < M; i++)
            Arr3D[k][i] = (int *) malloc(N * sizeof(int));
    }
}

void freeVector() {
    /*
     * Виділення пам'яті під масив
     */
    free(Vector);
}

void freeArray3D() {

    for (int k = 0; k < P; k++) {
        for (int i = 0; i < M; i++)
            free(Arr3D[k][i]);
        free(Arr3D[k]);
    }
    free(Arr3D);

}

void fillVector(int order) {
    /*
     * В залежності від змінної order заповнює вектор.
     *
     * 1 - впорядкований;
     * 2 - впорядкованний у зворотньому порядку;
     * 3 - заповнений випадковим порядком
     */
    switch (order) {
        case 1: {
            for (int i = 0; i < N; i++) {
                Vector[i] = i;
            }
            break;
        }
        case 2: {
            for (int i = 0; i < N; i++) {
                Vector[i] = N - i;
            }
            break;
        }

        case 3: {
            srand((unsigned int) time(NULL));
            for (int i = 0; i < N; i++) {
                Vector[i] = rand() % 10;
            }
            break;
        }

        default:
            break;

    }
}

void fillArray3D(int order) {
    /*
     * В залежності від змінної order заповнює вектор.
     *
     * 1 - впорядкований;
     * 2 - впорядкованний у зворотньому порядку;
     * 3 - заповнений випадковим порядком
     */
    switch (order) {
        case 1: {
            int it = 0;
            for (int k = 0; k < P; k++)
                for (int j = 0; j < N; j++)
                    for (int i = 0; i < M; i++)
                        Arr3D[k][i][j] = it++;
            break;
        }
        case 2: {
            int it = M * N * P + 1;
            for (int k = 0; k < P; k++)
                for (int j = 0; j < N; j++)
                    for (int i = 0; i < M; i++)
                        Arr3D[k][i][j] = it--;
            break;
        }

        case 3:
            srand((unsigned int) time(NULL));
            for (int k = 0; k < P; k++)
                for (int j = 0; j < N; j++)
                    for (int i = 0; i < M; i++)
                        Arr3D[k][i][j] = rand() % 30;
            break;

        default:
            break;

    }
}

void printVector() {
    /*
     * Красиво друкує вектор
     */
    printf("[ ");
    for(int i = 0; i < N - 1; i++) printf("%d, ", Vector[i]);
        printf("%d ]\n\n", Vector[N - 1]);
}

void printArray3D() {
    /*
     * Красиво друкує тривимірний масив
     */
    int i, j, k;
    printf("[\n\t[\n\t\t[ ");
    for(k = 0; k < P - 1; k++) {
        for(i = 0; i < M - 1; i++) {
            for(j = 0; j < N - 1; j++) {
                printf("%d, ", Arr3D[k][i][j]);
            }
            printf("%d ],\n\t\t[ ", Arr3D[k][i][N - 1]);
        }
        for(j = 0; j < N - 1; j++)
            printf("%d, ", Arr3D[k][j][N - 1]);
        printf("%d ]\n\t],\n\t\t[ ", Arr3D[k][M - 1][N - 1]);
    }
    for(i = 0; i < M - 1; i++) {
         for(j = 0; j < N - 1; j++) {
                printf("%d, ", Arr3D[P - 1][i][j]);
            }
            printf("%d ],\n\t\t[ ", Arr3D[P - 1][i][N - 1]);
    }
    for(j = 0; j < N - 1; j++)
            printf("%d, ", Arr3D[P - 1][j][N - 1]);
        printf("%d ]\n\t]\n]\n", Arr3D[P - 1][M - 1][N - 1]);
}