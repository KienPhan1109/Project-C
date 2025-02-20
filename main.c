#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#include "datatype.h"

#define MAX_CATEGORY 100
#define MAX_PRODUCT 100
#define MAX_ADMIN 100

int main() {
    
    Category categories[MAX_CATEGORY]; // Mang chua thong tin Danh Muc
    Admin admin[MAX_ADMIN]; // Mang chua thong tin Admin
    Product products[MAX_PRODUCT]; // Mang chua thong tin San Pham
    
    int countProduct = 0; // So luong San Pham
    int countAdmin = 0; // So luong Admin
    int countCategory = 0; // So luong Danh Muc

    int checkAdmin = 0; // Kiem tra da dang nhap admin chua

    // Doc File Admin
    readFileAdmin(admin, &countAdmin);

    // Neu danh sach Admin la rong thi tao tai khoan mac dinh
    if (countAdmin == 0) {
        strcpy(admin[0].Account, "KienPhan");
        strcpy(admin[0].Password, "11092006");
        countAdmin++;
        writeFileAdmin(admin, countAdmin);
    }

    // Doc File danh muc
    readFileCategory(categories, &countCategory);

    // Doc File san pham
    readFileProduct(products, &countProduct);

    // Hien thi menu chinh
    while (1)
    {
        mainMenu();

        int c = choice();
        switch (c)
        {
            case 1:
                // Dang nhap Admin
                LoginAdmin(admin, countAdmin);
                checkAdmin = 1;
                break;

            case 2:
                // Hien thi Menu Danh Muc
                menuCategory(categories, &countCategory, products, &countProduct, &checkAdmin);
                break;
            
            case 3:
                // Hien thi Menu San Pham
                menuProduct(products, &countProduct, categories, &countCategory, &checkAdmin);
                break;

            case 0:
                // Thoat he thong
                checkAdmin = 0;
                printf("\n\t========= Thank You =========\n");
                printf("\t======= See You Soon ========\n");
                printf("\n\t-----------------------------\n");
                system("pause");
                exit(0);
            default:
                printf("\n\tInvalid option. Please try again.\n");
                break;
        }
    }

    system("pause");
    return 0;
}
