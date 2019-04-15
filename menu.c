#include <stdio.h>
#include "common.h"
#include "measurement.h"
#include "sortingVector.h"
#include "sortingArray3D.h"
#include "menu.h"

void clear() {
    printf("\033[H\033[J");
}

void printExit(const char *text) {
    printf("0. %s\n", text);
    printf("\nChoose: ");
}

void printErr() {
    printf("\nWrong input. Please print correct menu number\n");
    printf("\nChoose: ");
}

int selectOrder(int isVector, int sort) {
    int res;
    const int menuLength = 4;
    const char menu[4][23] = {
            "Exit to Sort Menu",
            "Ordered Vector",
            "Reverse-ordered Vector",
            "Randomized Vector",
    };

    for (int i = 1; i < menuLength; i++)
        printf("%d. %s\n", i, menu[i]);

    printExit("Exit to Main Menu");

    scanf("%d", &res);
    while (res < 0 || res > menuLength) {
        printErr();
        scanf("%d", &res);
    }

    clear();
    if (isVector) {
        initVector();
        fillVector(res);
        printf("Vector before sorting:\n");
        printVector();
        switch (sort) {
            case 1:
                sortVectorSelect1();
            case 2:
                sortVectorSelect3();
            case 3:
                sortVectorExchange3();
            default:
                break;
        }
        printf("Vector after sorting:\n");
        printVector();
        freeVector();
    } else {
        initArray3D();
        fillArray3D(res);
        printf("Array3D before sorting:\n");
        printArray3D();
        switch (sort) {
            case 1:
                sortArr3DSelect1();
            case 2:
                sortArr3DSelect3();
            case 3:
                sortArr3DExchange3();
            default:
                break;
        }
        printf("Array3D after sorting:\n");
        printArray3D();
        freeArray3D();
    }
    printExit("Exit to Order menu");
    scanf("%d", &res);
    while (res != 0) {
        printErr();
        scanf("%d", &res);
    }
    return res;
}

int selectSort(int isVector) {
    int res;
    const int menuLength = 4;
    const char menu[4][20] = {
            "Exit to Main Menu",
            "Select1 algorithm",
            "Select3 algorithm",
            "Exchange3 algorithm",
    };

    for (int i = 1; i < menuLength; i++)
        printf("%d. %s\n", i, menu[i]);

    printExit(menu[0]);
    scanf("%d", &res);
    while (res < 0 || res > menuLength) {
        printErr();
        scanf("%d", &res);
    }

    clear();
    if (res != 0) while (selectOrder(isVector, res));
    return res;
}

int Measurement(int isVector) {
    int res;
    measurement_t m;

    if(isVector) {
        printf("N = ");
        scanf("%d", &N);
        printf("\n");
    } else {
        printf("P = ");
        scanf("%d", &P);
        printf("\nN = ");
        scanf("%d", &N);
        printf("\nM = ");
        scanf("%d", &M);
    }

    clear();

    printf("%-20s%-19s%-18s%-20s\n", "", "|Ordered|", "|Reversed|", "|Randomized|");
    m = measure(isVector, measurementSelect1);
    printf("%-9s%20f%20f%20f\n", "Select1", m.ordered, m.reversed, m.randomized);
    m = measure(isVector, measurementSelect3);
    printf("%-9s%20f%20f%20f\n", "Select3", m.ordered, m.reversed, m.randomized);
    m = measure(isVector, measurementExchange3);
    printf("%-9s%20f%20f%20f\n\n", "Exchange3", m.ordered, m.reversed, m.randomized);

    printExit("Exit to Main Menu");
    scanf("%d", &res);
    while (res != 0) {
        printErr();
        scanf("%d", &res);
    }
    clear();
    return res;
}

int mainMenu() {
    int res;
    const int menuLength = 5;
    const char menu[5][28] = {
            "Exit",
            "Vector Sorting Measurement",
            "Array3D Sorting Measurement",
            "Vector Sorting Test",
            "Array3D Sorting Test"
    };

    for (int i = 1; i < menuLength; i++)
        printf("%d. %s\n", i, menu[i]);

    printExit(menu[0]);
    scanf("%d", &res);
    while (res < 0 || res > menuLength) {
        printErr();
        scanf("%d", &res);
    }

    clear();
    switch (res) {
        case 1:
            while (Measurement(1));
            break;
        case 2:
            while (Measurement(0));
            break;
        case 3:
            while (selectSort(1));
            break;
        case 4:
            while (selectSort(0));
            break;
        default:
            break;
    }

    return res;
}

int startMenu() {
    int res;
    const int labelsLength = 5;
    const char labels[5][19] = {
            "Course Work SDA",
            "Written by",
            "Vladislav Dalechyn",
            "KV-81",
            "KPI 2018-2019"
    };
    const int menuLength = 2;
    const char menu[2][9] = {
            "Exit",
            "Continue"
    };

    for (int i = 0; i < labelsLength; i++)
        printf("%s\n", labels[i]);
    for (int i = 1; i < menuLength; i++)
        printf("%d. %s\n", i, menu[i]);

    printExit(menu[0]);
    scanf("%d", &res);
    while (res != 1 && res != 0) {
        printErr();
        scanf("%d", &res);
    }

    clear();
    if (res == 1) while (mainMenu());

    return res;
}

void menu() {
    clear();
    while (startMenu());
}