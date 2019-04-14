#include "stdio.h"
#include "menu.h"

typedef struct {
    char * text;
    unsigned int flag;
} flagItem;

void clear() {
    printf("\033c");
}

void printExit(char * text) {
    printf("0. %s\n", text);
    printf("\nChoose: ");
}

int startMenu() {
    int res = 0;
    const int menuLength = 5;
    const char menu[5][18] = {
            "Course Work SDA",
            "Written by",
            "Vladislav Dalechyn",
            "KV-81",
            "KPI 2018-2019"
    };

    for (int i = 0; i < menuLength; i++)
        printf("%s\n", menu[i]);

    printf("%s", "\n1. Continue\n");

    printExit("Exit program");

    scanf("%d", &res);
    while (res != 1 && res != 0) {
        printf("\nWrong input. Please print 1 to continue\n");
        scanf("%d", &res);
    }

    clear();

    return res;
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

int vectorSortingMenu() {
    int res;
    const int menuLength = 3;
    const char menu[3][30] = {
            "Ordered vector",
            "Reverse-ordered vector",
            "Randomized vector",
    };

    for (int i = 0; i < menuLength; i++)
        printf("%d. %s\n", i + 1, menu[i]);

    printExit("Exit to Main Menu");

    scanf("%d", &res);
    while (res < 0 || res > 4) {
        printf("\nWrong input. Please print correct menu number\n");
        scanf("%d", &res);
    }

    clear();

    return res;
}

unsigned int selectArr3DSortMenu() {
    int res;
    const int menuLength = 4;
    const flagItem menu[4] = {
            {"Exit to Main Menu",   FLAG_MAIN_MENU},
            {"Select1 algorithm",   FLAG_ARRAY3D_SORT1},
            {"Select3 algorithm",   FLAG_ARRAY3D_SORT2},
            {"Exchange3 algorithm", FLAG_ARRAY3D_SORT3}
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
unsigned int selectVecSortMenu() {
    int res;
    const int menuLength = 4;
    const flagItem menu[4] = {
            {"Exit to Main Menu",   FLAG_MAIN_MENU},
            {"Select1 algorithm",   FLAG_VECTOR_SORT1},
            {"Select3 algorithm",   FLAG_VECTOR_SORT2},
            {"Exchange3 algorithm", FLAG_VECTOR_SORT3}
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
    int startMenuRes = 1;
    if(!(flag & FLAG_MAIN_MENU)) {
        startMenuRes = startMenu();
    }
    switch (startMenuRes) {
        case 0:
            flag = FLAG_EXIT;
            break;
        case 1:
            if (!(flag & MASK_LEVEL1_ITEMS)) {
                unsigned int t = mainMenu();
                if(t == FLAG_EXIT) {
                    flag = FLAG_EXIT;
                    break;
                }
                flag |= t;
            };
            switch (flag & (MASK_MAIN_MENU | MASK_LEVEL1_ITEMS)) {
                case FLAG_VECTOR_MEASUREMENT:
                    break;
                case FLAG_ARRAY3D_MEASUREMENT:
                    break;
                case FLAG_VECTOR_SORT:
                    if (!(flag & MASK_LEVEL2_ITEMS)) {
                        unsigned int t = selectVecSortMenu();
                        if(t == FLAG_MAIN_MENU) {
                            flag = FLAG_MAIN_MENU;
                            break;
                        }
                        flag |= t;
                    }
                    switch (vectorSortingMenu()) {
                        case FLAG_VECTOR_SORT1:
                            break;
                        case FLAG_VECTOR_SORT2:
                            break;
                        case FLAG_VECTOR_SORT3:
                            break;
                        default:
                            break;
                    }
                    break;
                case FLAG_ARRAY3D_SORT:
                    if (!(flag & MASK_LEVEL2_ITEMS)) {
                        unsigned int t = selectArr3DSortMenu();
                        if(t == FLAG_MAIN_MENU) {
                            flag = FLAG_MAIN_MENU;
                            break;
                        }
                        flag |= t;
                    }
                    switch (flag & (MASK_MAIN_MENU | MASK_LEVEL1_ITEMS | MASK_LEVEL2_ITEMS)) {
                        case FLAG_ARRAY3D_SORT1:
                            break;
                        case FLAG_ARRAY3D_SORT2:
                            break;
                        case FLAG_ARRAY3D_SORT3:
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
                        default: break;
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