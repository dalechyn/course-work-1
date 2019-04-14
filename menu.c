#include "stdio.h"
#include "menu.h"
#include "SortingArray3D.h"
#include "SortingVector.h"

typedef struct {
    char *text;
    unsigned int flag;
} flagItem;

void clear() {
    printf("\033c");
}

void printExit(char *text) {
    printf("0. %s\n", text);
    printf("\nChoose: ");
}

unsigned int startMenu() {
    int res = 0;
    const int labelsLength = 5;
    const char labels[5][18] = {
            "Course Work SDA",
            "Written by",
            "Vladislav Dalechyn",
            "KV-81",
            "KPI 2018-2019"
    };
    const int menuLength = 2;
    const flagItem menu[2] = {
            {"Exit",     FLAG_EXIT},
            {"Continue", FLAG_MAIN_MENU}
    };

    for (int i = 0; i < labelsLength; i++)
        printf("%s\n", labels[i]);
    for (int i = 1; i < menuLength; i++)
        printf("%d. %s\n", i, menu[i].text);

    printExit("Exit program");

    scanf("%d", &res);
    while (res != 1 && res != 0) {
        printf("\nWrong input. Please print 1 to continue\n");
        scanf("%d", &res);
    }

    clear();

    return menu[res].flag;
}

unsigned int mainMenu() {
    int res;
    const int menuLength = 6;
    const flagItem menu[6] = {
            {"Exit",                        FLAG_EXIT},
            {"Vector Sorting Measurement",  FLAG_VECTOR_MEASUREMENT},
            {"Array3D Sorting Measurement", FLAG_ARRAY3D_MEASUREMENT},
            {"Vector Sorting Test",         FLAG_VECTOR_SORT},
            {"Array3D Sorting Test",        FLAG_ARRAY3D_SORT},
            {"Help",                        FLAG_HELP},
    };

    for (int i = 1; i < menuLength; i++)
        printf("%d. %s\n", i, menu[i].text);

    printExit(menu[0].text);

    scanf("%d", &res);
    while (res < 0 || res > 6) {
        printf("\nWrong input. Please print correct menu number\n");
        scanf("%d", &res);
    }

    clear();

    return menu[res].flag;
}

unsigned int selectFillMenu() {
    int res;
    const int menuLength = 3;
    const flagItem menu[4] = {
            {"Exit to Sort Menu",      FLAG_EXIT},
            {"Ordered vector",         FLAG_ORDER1},
            {"Reverse-ordered vector", FLAG_ORDER2},
            {"Randomized vector",      FLAG_ORDER3},
    };

    for (int i = 1; i < menuLength; i++)
        printf("%d. %s\n", i, menu[i].text);

    printExit("Exit to Main Menu");

    scanf("%d", &res);
    while (res < 0 || res > 4) {
        printf("\nWrong input. Please print correct menu number\n");
        scanf("%d", &res);
    }

    clear();

    return menu[res].flag;
}

unsigned int selectSortMenu() {
    int res;
    const int menuLength = 4;
    const flagItem menu[4] = {
            {"Exit to Main Menu",   FLAG_EXIT},
            {"Select1 algorithm",   FLAG_SORT1},
            {"Select3 algorithm",   FLAG_SORT2},
            {"Exchange3 algorithm", FLAG_SORT3}
    };

    for (int i = 1; i < menuLength; i++)
        printf("%d. %s\n", i, menu[i].text);

    printExit(menu[0].text);

    scanf("%d", &res);
    while (res < 0 || res > 4) {
        printf("\nWrong input. Please print correct menu number\n");
        scanf("%d", &res);
    }

    clear();

    return menu[res].flag;
}

int helpMenu() {
    int res;
    printf("Author: Vladislav Dalechyn\n");

    printExit("Exit to Main Menu");

    scanf("%d", &res);
    while (res != 0) {
        printf("\nWrong input. Please print correct menu number\n");
        scanf("%d", &res);
    }

    clear();

    return res;
}

unsigned int menu(unsigned int flag) {
    clear();
    if (!(flag & FLAG_MAIN_MENU)) {
        flag |= startMenu();
    }
    switch (flag & MASK_MAIN_MENU) {
        case FLAG_MAIN_MENU:
            if (!(flag & MASK_LEVEL1_ITEMS)) {
                unsigned int t = mainMenu();
                flag = t == FLAG_EXIT ? FLAG_EXIT : flag | t;
            }
            switch (flag & MASK_LEVEL1_ITEMS) {
                case FLAG_VECTOR_MEASUREMENT:
                    break;
                case FLAG_ARRAY3D_MEASUREMENT:
                    break;
                case FLAG_VECTOR_SORT:
                case FLAG_ARRAY3D_SORT:
                    if (!(flag & MASK_LEVEL2_ITEMS)) {
                        unsigned int t = selectSortMenu();
                        if (t == FLAG_EXIT) {
                            flag &= MASK_MAIN_MENU;
                            break;
                        } else flag |= t;
                    }
                    if (!(flag & MASK_LEVEL3_ITEMS)) {
                        unsigned int t = selectFillMenu();
                        if (t == FLAG_EXIT) {
                            flag &= (MASK_MAIN_MENU | MASK_LEVEL1_ITEMS);
                            break;
                        } else flag |= t;
                    }
                    unsigned int t = flag & MASK_LEVEL1_ITEMS;
                    switch (flag & MASK_LEVEL3_ITEMS) {
                        case FLAG_ORDER1:
                            switch (t) {
                                case FLAG_VECTOR_SORT:
                                    // Select1_Vector()
                                    break;
                                case FLAG_ARRAY3D_SORT:
                                    // Select1_Arr3D()
                                    break;
                                default:
                                    break;
                            }
                            break;
                        case FLAG_ORDER2:
                            switch (t) {
                                case FLAG_VECTOR_SORT:
                                    // Select1_Vector()
                                    break;
                                case FLAG_ARRAY3D_SORT:
                                    // Select1_Arr3D()
                                    break;
                                default:
                                    break;
                            }
                            break;
                        case FLAG_ORDER3:
                            switch (t) {
                                case FLAG_VECTOR_SORT:
                                    // Select1_Vector()
                                    break;
                                case FLAG_ARRAY3D_SORT:
                                    // Select1_Arr3D()
                                    break;
                                default:
                                    break;
                            }
                            break;
                        default:
                            break;
                    }
                    break;
                case FLAG_HELP:
                    switch (helpMenu()) {
                        case 0:
                            flag = FLAG_MAIN_MENU;
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
    return flag;
}