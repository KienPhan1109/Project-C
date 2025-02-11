#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#include "datatype.h"

int main() {
    Category categories[100];

    // Tai khoan Admin
    Admin admin[100] = {
        {"KienPhan", "11092006"}
    };

    int countAdmin = 1;
    int count = 0;

    writeFileAdmin(admin, countAdmin);

    LoginAdmin(admin, countAdmin);

    readFile(categories, &count);

    mainMenu(categories, &count);

    system("pause");
    return 0;
}
