#include <stdio.h>
#include <string.h>
#include "function.h"
#include "datatype.h"

// Ham ghi File categories.bin
void writeFile(const Category categories[], int count) {
    FILE *f = fopen("categories.bin", "wb");

    if (f == NULL) {
        printf("\tError: Writing file categories.bin !!!\n");
        return;
    }

    fwrite(&count, sizeof(int), 1, f);
    fwrite(categories, sizeof(Category), count, f);

    fclose(f);
}

// Ham doc File categories.bin
void readFile(Category categories[], int *count) {
    FILE *f = fopen("categories.bin", "rb");
    
    if (f == NULL) {
        printf("\tError: Reading file categories.bin !!!\n");
        return;
    }

    fread(count, sizeof(int), 1, f);
    fread(categories, sizeof(Category), *count, f);

    fclose(f);
}

// Ham ghi File admin.bin
void writeFileAdmin(const Admin admin[], int countAmin) {
    FILE *fa = fopen("admin.bin", "wb");

    if (fa == NULL) {
        printf("\tError: Writing file admin.bin !!!\n");
        return;
    }

    fwrite(&countAmin, sizeof(int), 1, fa);
    fwrite(admin, sizeof(Admin), countAmin, fa);

    fclose(fa);
}

// Ham doc File admin.bin
void readFileAdmin(Admin admin[], int *countAdmin) {
    FILE *fa = fopen("admin.bin", "rb");
    
    if (fa == NULL) {
        printf("\tError: Reading file admin.bin !!!\n");
        return;
    }

    fread(countAdmin, sizeof(int), 1, fa);
    fread(admin, sizeof(Admin), *countAdmin, fa);

    fclose(fa);
}


// Ten he thong
void nameSystem()
{
    printf("\n   *** Store Management System Using C ***\n");
}

// Ham ten them danh muc
void nameAddCategory()
{
    printf("\n    *** Add A New Category***\n");
}

// Ham ten sua danh muc
void nameEditCategory()
{
    printf("\n    *** Edit A Category ***\n");
}

// Ham ten xoa danh muc
void nameDeleteCategory()
{
    printf("\n   *** Delete A Category ***\n");
}

// Ham ten hien thi danh muc
void nameShowCategory()
{
    printf("\n     *** All Category ***\n");
}
// Ham nhap lua chon
int choice()
{
    int c;
    printf("\tEnter The Choice: ");
    scanf("%d", &c);
    return c;
}

// Ham xoa bo nho dem
void clearCache()
{
    int c;
    while ((c = getchar() ) != '\n' && c != EOF);
}

// Ham hien thi menu quan ly danh muc
int menuCategory() {
    int c;
    printf("\n\t       CATEGORY MENU       \n");
    printf("\t============================\n");
    printf("\t| [1] Show All categories. |\n");
    printf("\t| [2] Add A New category.  |\n");
    printf("\t| [3] Edit A category.     |\n");
    printf("\t| [4] Delete A category.   |\n");
    printf("\t| [5] Search A category.   |\n");
    printf("\t| [6] Sort categories.     |\n");
    printf("\t| [0] Exit the Program.    |\n");
    printf("\t============================\n");
    c = choice();
    return c;
}

// Ham them danh muc
void addCategory(Category categories[], int *count) {
    if (*count >= 100) {
        printf("\tError: Category list is Full !!!\n");
        return;
    }

    Category newCategory;

    // Nhap ID danh muc
    do {
        printf("\n\tEnter Category ID: ");
        scanf("%s", newCategory.CategoryId);
        clearCache();

        if (strlen(newCategory.CategoryId) > 10 || strlen(newCategory.CategoryId) == 0) {
            printf("\tError: Category ID must be 1-10 characters!\n"); // ID nam trong khoang tu 1 - 10 ki tu
        } else if (isDuplicateID(categories, *count, newCategory.CategoryId)) {
            printf("\tError: Category ID already exists!\n"); // ID danh muc da ton tai
        } else {
            break; // Hop le
        }
    } while (1);

    // Nhap ten danh muc
    do {
        printf("\tEnter Category Name: ");
        scanf("%s", newCategory.CategoryName);
        clearCache();

        if (strlen(newCategory.CategoryName) > 10 || strlen(newCategory.CategoryName) == 0) {
            printf("\tError: Category Name must be 1-10 characters!\n"); // Ten danh muc nam trong khoang tu 1 - 10 ki tu
        } else if (isDuplicateName(categories, *count, newCategory.CategoryName)) {
            printf("\tError: Category Name already exists!\n"); // Ten danh muc da ton tai
        } else {
            break; // Hop le
        }
    } while (1);

    categories[*count] = newCategory;
    (*count)++; // TTang danh muc len 1

    // Luu danh muc moi vao File
    writeFile(categories, *count);
    printf("\n\tCategory Added Successfully !!!\n");
    goBack(categories, count);
}

// Ham sua danh muc
void editCategory(Category categories[], int count) {
    char id[10];
    printf("\n\tEnter Category ID to edit: ");
    scanf("%s", id);

    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(categories[i].CategoryId, id) == 0) {
            printf("\n\tOne Category Found for ID: %s\n", id);
            printf("\tCurrent Category Name: %s\n", categories[i].CategoryName);

            // Nhap ten danh muc moi
            char newCategoryName[11]; //
            do {
                printf("\n\tEnter new Category Name: ");
                getchar();
                fgets(newCategoryName, sizeof(newCategoryName), stdin);
                newCategoryName[strcspn(newCategoryName, "\n")] = 0;

                if (strlen(newCategoryName) < 1 || strlen(newCategoryName) > 10) {
                    printf("\tError: Category Name must be 1-10 characters!\n");
                } else if (isDuplicateName(categories, count, newCategoryName)) {
                    printf("\tError: Category Name already exists!\n");
                } else {
                    break;
                }
            } while (1);

            // Cap nhat ten danh muc
            strcpy(categories[i].CategoryName, newCategoryName);

            // Ghi vao file
            writeFile(categories, count);
            printf("\n\tCategory Updated successfully !!!\n");
            return;
        }
    }
    printf("\tError: Category not found.\n");
}


// Ham xoa danh muc
void deleteCategory(Category categories[], int *count) {
    // Khai bao mang chua ID danh muc can xoa
    char id[10];
    printf("\n\tEnter Category ID to delete: ");
    scanf("%s", id);
    clearCache();

    // So sanh ID vua nhap voi cac ID danh muc trong mang
    int i, j;
    for (i = 0; i < *count; i++) {
        if (strcmp(categories[i].CategoryId, id) == 0) {
            // Thong bao da tim thay
            printf("\n\tOne Category Found for ID: %s\n", id);
            printf("\tCategory informations\n");
            printf("\t--------------------------\n");
            // Hien thi thong tin danh muc can xoa
            printf("\tCategory ID: %s\n", categories[i].CategoryId);
            printf("\tCategory Name: %s\n", categories[i].CategoryName);
            // Thong bao xac nhan xoa
            printf("\n\tAre you sure you want to delete this category? (Y/N): ");
            char confirm;
            scanf(" %c", &confirm);
            if (confirm == 'Y') {
                for (j = i; j < *count - 1; j++) {
                    categories[j] = categories[j + 1];
                }
                (*count)--; // Giam danh muc di 1
                // Luu cac thay doi vao File
                writeFile(categories, *count);
                printf("\n\n\tCategory Deleted successfully !!!\n");
                goBack(categories, count);
            }
            else {
                printf("\n\n\tCategory deletion cancelled !!!\n");
            }
            return;
        }
    }
    // Neu khong tim thay se thong bao khong tim thay
    printf("\tError: Category not found.\n");
}

// Ham tim kiem danh muc theo ten
void searchCategory(const Category categories[], int count) {
    int found = 0;
    // Khai bao mang chua ten danh muc can tim kiem 
    char name[10];
    printf("\n\tEnter Category Name to search: ");
    scanf("%s", name);
    clearCache();

    int i;
    // Su dung ham strstr de tim kiem tuong doi
    for (i = 0; i < count; i++) {
        if (strstr(categories[i].CategoryName, name) != NULL) {
            if (found == 0)
            {
                printf("\n\t|============|==============|");
                printf("\n\t|%-10s |%-10s |\n", "Category ID", "Category Name");
                printf("\t|============|==============|\n");
                printf("\t| %-10s | %-10s   |\n", categories[i].CategoryId, categories[i].CategoryName);
                printf("\t|------------|--------------|\n");
            }
            else
            {
                printf("\t| %-10s | %-10s   |\n", categories[i].CategoryId, categories[i].CategoryName);
                printf("\t|------------|--------------|\n");
            }
            
            found++;
        }
    }
    // Neu khong tim thay se thong bao khong tim thay
    if (found == 0)
    {
        printf("\n\tCategory not found.\n");
        goBack(categories, count);
        return;
    }
    goBack(categories, count);
}

// Ham sap xep danh muc theo ten tang dan
void sortCategoriesUp(Category categories[], int count) {
    // Su dung thuat toan sap xep noi bot
    int i, j;
    for (i = 0; i < count; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (strcmp(categories[j].CategoryName, categories[j + 1].CategoryName) > 0) {
                Category temp = categories[j];
                categories[j] = categories[j + 1];
                categories[j + 1] = temp;
            }
        }
    }
    // Luu cac thay doi vao File
    writeFile(categories, count);
    printf("\n\tCategories Sorted Successfully!\n");
}

// Ham sap xep danh muc theo ten giam dan
void sortCategoriesDown(Category categories[], int count) {
    // Su dung thuat toan sap xep noi bot
    int i, j;
    for (i = 0; i < count; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (strcmp(categories[j].CategoryName, categories[j + 1].CategoryName) < 0) {
                Category temp = categories[j];
                categories[j] = categories[j + 1];
                categories[j + 1] = temp;
            }
        }
    }
    // Luu cac thay doi vao File
    writeFile(categories, count);
    printf("\n\tCategories Sorted Successfully!\n");
}

// Ham hien thi toan bo danh muc
void displayCategories(const Category categories[], int count) {
    // Kiem tra xem neu khong co danh muc nào thì se thong bao khong co
    if (count == 0) {
        printf("\n\tError: No categories available to display.\n");
        goBack(categories, count);
        return;
    }
    // Hien thi danh muc
    printf("\n\t|============|==============|");
    printf("\n\t|%-10s |%-10s |\n", "Category ID", "Category Name");
    printf("\t|============|==============|\n");
    int i;
    for (i = 0; i < count; i++) {
        printf("\t| %-10s | %-10s   |\n", categories[i].CategoryId, categories[i].CategoryName);
        printf("\t|------------|--------------|\n");
    }
    goBack(categories, count);
}

// Ham kiem tra trung lap ID
int isDuplicateID(Category categories[], int count, char id[]) {
    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(categories[i].CategoryId, id) == 0) {
            return 1; // Trung ID
        }
    }
    return 0;
}

// Ham kiem tra trung lap Name
int isDuplicateName(Category categories[], int count, char name[]) {
    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(categories[i].CategoryName, name) == 0) {
            return 1; // Trung Name
        }
    }
    return 0;
}

// Ham quay lai menu
void goBack(Category categories[], int *count) {
    char choice;
    do {
        printf("\n\tGo back (b)? or Exit (0)?: ");
        scanf(" %c", &choice);
        clearCache();

        if (choice == 'b') {
            return;
            break;
        } 
        else if (choice == '0') {
            printf("\n\t======== Thank You =========\n");
            printf("\t======= See You Soon ========\n");
            printf("\n\t-----------------------------\n");
            system("pause");
            exit(0);
        } 
        else {
            printf("\tInvalid option. Please try again.\n");
        }
    } while (1);
}


// Ham lua chon cac chuc nang danh muc
void mainMenu(Category categories[], int *count) {
    while (1) {
        nameSystem();
        int c = menuCategory();

        switch (c) {
            case 1: // Hien thi toan bo danh muc
                displayCategories(categories, *count);
                break;

            case 2: // Them danh muc
                nameAddCategory();
                addCategory(categories, count);
                break;

            case 3: // Sua danh muc
                nameEditCategory();
                editCategory(categories, *count);
                break;

            case 4: // Xoa danh muc
                nameDeleteCategory();
                deleteCategory(categories, count);
                break;

            case 5: // Tim kiem danh muc theo ten
                searchCategory(categories, *count);
                break;

            case 6: // Sap xep danh muc theo ten
                sortCategoriesMenu(categories, *count);
                break;

            case 0: // Thoat chuong trinh
                printf("\n\t========= Thank You =========\n");
                printf("\t======= See You Soon ========\n");
                printf("\n\t-----------------------------\n");
                system("pause");
                exit(0);

            default:
                printf("\tInvalid option. Try again.\n");
                break;
        }
    }
}

// Ham lua chon cach sap xep
void sortCategoriesMenu(Category categories[], int count) {
    printf("\tEnter The Sort Choice\n");
    printf("\t1 : Increase, 2 : Decrease\n");
    int c = choice();

    switch (c) {
        case 1: // Sap xep tang dan
            sortCategoriesUp(categories, count);
            displayCategories(categories, count);
            break;

        case 2: // Sap xep giam dan
            sortCategoriesDown(categories, count);
            displayCategories(categories, count);
            break;

        default:
            printf("\tInvalid option. Try again.\n");
            break;
    }
}

void LoginAdmin(Admin admin[], int countAdmin)
{
    char a[30];
    char p[30];

    do
    {
        printf("\n\t|======== LOGIN ADMIN ========|\n");

        printf("\n\tAccount: ");
        scanf("%s", a);
        clearCache();

        printf("\tPassword: ");
        scanf("%s", p);
        clearCache();

        int i;
        for (i = 0; i < countAdmin; i++)
        {
            if (strcmp(a, admin[i].Account) == 0 && strcmp(p, admin[i].Password) == 0)
            {
                printf("\n\tLog in successfully.\n");
                return;
            }
        }

        printf("\n\tInvalid username or password. Please try again.\n");

    } while (1);
}
