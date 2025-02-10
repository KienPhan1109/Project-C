#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#include "datatype.h"

int main() {
    Category categories[100];
    int count;
    int c;

    readFile(categories, &count);

    while (1)
    {
        nameSystem();
        c = menuCategory();
        switch (c) 
        {
            case 1: // Hien thi toan bo danh muc
                displayCategories(categories, count);
                break;

            case 2: // Them danh muc
                addCategory(categories, &count);
                break;

            case 3: // Sua danh muc
                editCategory(categories, count);
                break;

            case 4: // Xoa danh muc
                deleteCategory(categories, &count);
                break;

            case 5: // Tim kiem danh muc theo ten
                searchCategory(categories, count);
                break;

            case 6: // Sap xep danh muc theo ten
                {
                    printf("Nhap vao lua chon sap xep.\n");
                    printf("1 : Tang dan, 2 : Giam dan\n");
                    int c = choice();
                    switch (c)
                    {
                        case 1: // Sap xep danh muc theo ten tang dan
                            sortCategoriesUp(categories, count);
                            break;
                        
                        case 2: // Sap xep danh muc theo ten giam dan
                            sortCategoriesDown(categories, count);
                            break;

                        default:
                            printf("Lua chon khong hop le.\n");
                            break;
                    }
                    break;
                }
                
            case 0: // Thoat chuong trinh
                exitSystem();
                system("pause");
                return 0;
                break;

            default:
                printf("Invalid option. Try again.\n");
                break;
        }
    }
    system("pause");
    return 0;
}
