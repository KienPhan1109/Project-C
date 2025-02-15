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

    // Doc File Admin
    readFileAdmin(admin, &countAdmin);

    // Neu danh sach Admin là rong thi tao tai khoan mac dinh
    if (countAdmin == 0) {
        strcpy(admin[0].Account, "KienPhan");
        strcpy(admin[0].Password, "11092006");
        countAdmin++;
        writeFileAdmin(admin, countAdmin);
    }

    // Dang nhap Admin
    LoginAdmin(admin, countAdmin);

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
                // Hien thi Menu Danh Muc
                menuCategory(categories, &countCategory, products, &countProduct);
                break;
            
            case 2:
                // Hien thi Menu San Pham
                menuProduct(products, &countProduct, categories, &countCategory);
                break;

            case 3:
                // Thoat he thong
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
