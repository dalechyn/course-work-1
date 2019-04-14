#include "menu.h"

int main() {
    unsigned int menuFlag = menu(0);

    while((menuFlag = menu(menuFlag)) != FLAG_EXIT);

    return 0;
}