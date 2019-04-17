#include <stdio.h>
#include "common.h"
#include "measurement.h"
#include "sortingVector.h"
#include "sortingArray3D.h"
#include "menu.h"

/*
 *  МОДУЛЬ menu:
 *
 *  Опис роботи функцій з закінченням *Menu(..)
 *
 *  Такі функції займаються прорисовкою окремого кадра меню
 *
 *  Повертаєме значення res є результатом вибору користувачем пункта меню.
 *  При виборі користувачем будь-якого пункта меню окрім нульового (вихід),
 *  запускається цикл прорисовки наступного меню, яке повертатиме результат
 *  вибору наступного пункту меню.
 *
 */

void clear() {
    // Очищення екрану консолі
    printf("\033[H\033[J");
}

void printExit(const char *text) {
    // Вивід на екран консолі кнопки виходу
    printf("0. %s\n", text);
    printf("\nChoose: ");
}

void printErr() {
    // Вивід на екран консолі повідомлення про помилку вибору
    printf("\nWrong input. Please print correct menu number\n");
    printf("\nChoose: ");
}

int resultsMenu(int isVector, int sort, int order) {
    /*
     *  Точка запуску алгоритмів сортування.
     */
    int res;
    if (isVector) {
        initVector();
        fillVector(order);
        printf("Vector before sorting:\n");
        printVector();
        switch (sort) {
            case 1: sortVectorSelect1(); break;
            case 2: sortVectorSelect3(); break;
            case 3: sortVectorExchange3(); break;
            default: break;
        }
        printf("Vector after sorting:\n");
        printVector();
        freeVector();
    } else {
        initArray3D();
        fillArray3D(order);
        printf("Array3D before sorting:\n");
        printArray3D();
        switch (sort) {
            case 1: sortArr3DSelect1(); break;
            case 2: sortArr3DSelect3(); break;
            case 3: sortArr3DExchange3(); break;
            default: break;
        }
        printf("Array3D after sorting:\n");
        printArray3D();
        freeArray3D();
    }

    printExit("Exit to order menu");
    scanf("%d", &res);
    while (res != 0) {
        printErr();
        scanf("%d", &res);
    }
    clear();

    return res;
}

int orderMenu(int isVector, int sort) {
    /*
     *  Виклик меню вибору порядку заповнення данних.
    */
    int res;
    const int menuLength = 4;
    const char menu[4][23] = {
            "Exit to Sort Menu",
            "Ordered",
            "Reverse-ordered",
            "Randomized",
    };

    for (int i = 1; i < menuLength; i++)
        printf("%d. %s\n", i, menu[i]);

    printExit(menu[0]);

    scanf("%d", &res);
    while (res < 0 || res > menuLength - 1) {
        printErr();
        scanf("%d", &res);
    }
    clear();

    if (res != 0) while(resultsMenu(isVector, sort, res));

    return res;
}

int sortMenu(int isVector) {
    /*
        Точка запуску вимірювання алгоритмів сортування.
    */
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
    while (res < 0 || res > menuLength - 1) {
        printErr();
        scanf("%d", &res);
    }

    clear();
    if (res != 0) while (orderMenu(isVector, res));
    return res;
}

int measurementMenu(int isVector) {
    /*
     *  Виклик меню виміру алгоритму сортування.
     *  Просить користувача ввести розмір вектору/масиву
     *
     *  Отримує і рисує таблицю з результатами вимірів
    */
    int res;
    measurement_s m;

    if(isVector) {
        printf("N = ");
        scanf("%d", &N);
        printf("\n");
    } else {
        printf("P = ");
        scanf("%d", &P);
        printf("\nM = ");
        scanf("%d", &M);
        printf("\nN = ");
        scanf("%d", &N);
    }

    clear();

    printf("%-20s%-19s%-18s%-20s\n", "", "|Ordered|", "|Reversed|", "|Randomized|");
    m = measure(isVector, 1);
    printf("%-9s%20f%20f%20f\n", "Select1", m.ordered, m.reversed, m.randomized);
    m = measure(isVector, 2);
    printf("%-9s%20f%20f%20f\n", "Select3", m.ordered, m.reversed, m.randomized);
    m = measure(isVector, 3);
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

int selectVectorSizeMenu() {
    /*
     * Меню вибору розміру вектора
     */
    printf("N = ");
    scanf("%d", &N);
    clear();
    return 0;
}

int selectArray3DSizeMenu() {
    /*
     * Меню вибору розміру масиву
     */
    printf("P = ");
    scanf("%d", &P);
    printf("\nM = ");
    scanf("%d", &M);
    printf("\nN = ");
    scanf("%d", &N);
    clear();
    return 0;
}

int mainMenu() {
    /*
     * Головне меню програми
     *
     * В залежності від вибору пункту користувача стартує цикл відрисовки меню
     */
    int res;
    const int menuLength = 7;
    const char menu[7][28] = {
            "Exit",
            "Vector Sorting Measurement",
            "Array3D Sorting Measurement",
            "Vector Sorting Test",
            "Array3D Sorting Test",
            "Select Vector size",
            "Select Array3D size"
    };

    for (int i = 1; i < menuLength; i++)
        printf("%d. %s\n", i, menu[i]);

    printExit(menu[0]);
    scanf("%d", &res);
    while (res < 0 || res > menuLength - 1) {
        printErr();
        scanf("%d", &res);
    }

    clear();
    switch (res) {
        case 1: while (measurementMenu(1)); break;
        case 2: while (measurementMenu(0)); break;
        case 3: while (sortMenu(1)); break;
        case 4: while (sortMenu(0)); break;
        case 5: while (selectVectorSizeMenu()); break;
        case 6: while (selectArray3DSizeMenu()); break;
        default: break;
    }

    return res;
}

int startMenu() {
    /*
     * Стартове меню програми.
     *
     * Показує данні автора роботи
     */
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
    /*
     * Точка запуску стартового меню
     */
    clear();
    while (startMenu());
}