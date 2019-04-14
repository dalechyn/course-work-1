#include "Common.h"

int N = 10;
int P = 3;
int M = 10;
int *vector;
int ***Arr3D;

void Vector() {
    vector = (int *) malloc(N * sizeof(int *));
}

void FreeVector() {
    free(vector);
}

void FillVector(int b) {
    switch (b) {
        case 1: {
            for (int i = 0; i < N; i++) {
                vector[i] = i;
            }
            break;
        }
        case 2: {
            for (int i = 0; i < N; i++) {
                vector[i] = N - i;
            }
            break;
        }

        case 3: {
            for (int i = 0; i < N; i++) {
                vector[i] = rand() % 10;
            }
            break;
        }

        default:
            break;

    }
}


void Array3D() {

    Arr3D = (int ***) malloc(P * sizeof(int **));
    for (int k = 0; k < P; k++) {
        Arr3D[k] = (int **) malloc(M * sizeof(int *));
        for (int i = 0; i < M; i++)
            Arr3D[k][i] = (int *) malloc(N * sizeof(int));
    }
}

void FreeArray3D() {

    for (int k = 0; k < P; k++) {
        for (int i = 0; i < M; i++)
            free(Arr3D[k][i]);
        free(Arr3D[k]);
    }
    free(Arr3D);

}

void FillArray3D(int b) {
    switch (b) {
        case 1: {
            int number = 0;
            for (int k = 0; k < P; k++) {
                for (int j = 0; j < N; j++) {
                    for (int i = 0; i < M; i++) {
                        Arr3D[k][i][j] = number++;
                    }
                }
            }
            break;
        }
        case 2: {
            int number = M * N * P + 1;
            for (int k = 0; k < P; k++) {
                for (int j = 0; j < N; j++) {
                    for (int i = 0; i < M; i++) {
                        Arr3D[k][i][j] = number--;
                    }
                }
            }
            break;
        }

        case 3: {
            for (int k = 0; k < P; k++) {
                for (int j = 0; j < N; j++) {
                    for (int i = 0; i < M; i++) {
                        Arr3D[k][i][j] = rand() % 30;
                    }
                }
            }
            break;
        }

        default:
            break;

    }
}