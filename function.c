#include <stdio.h>
#include <string.h>
#include "function.h"
#include "datatype.h"

// Ham ghi File
void writeFile(const Category categories[], int count) {
    FILE *f = fopen("categories.dat", "wb");

    if (f == NULL) {
        printf("Loi ghi file categories.dat.\n");
        return;
    }

    fwrite(&count, sizeof(int), 1, f);
    fwrite(categories, sizeof(Category), count, f);

    fclose(f);
}

// Ham doc File
void readFile(Category categories[], int *count) {
    FILE *f = fopen("categories.dat", "rb");
    
    if (f == NULL) {
        printf("Loi doc File categories.dat.\n");
        return;
    }

    fread(count, sizeof(int), 1, f);
    fread(categories, sizeof(Category), *count, f);

    fclose(f);
}

// Thoat he thong
void exitSystem()
{
    printf("\n========== Thank You ==========\n");
    printf("======== See You Soon =========\n");
}
// Ten he thong
void nameSystem()
{
    printf("\n*** Store Management System Using C ***\n");
}

// Ham nhap lua chon
int choice()
{
    int c;
    printf("Nhap lua chon cua ban: ");
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
    printf("\n|       CATEGORY MENU       \n");
    printf("|==========================|\n");
    printf("| [1] Show All categories. |\n");
    printf("| [2] Add A New category.  |\n");
    printf("| [3] Edit A category.     |\n");
    printf("| [4] Delete A category.   |\n");
    printf("| [5] Search A category.   |\n");
    printf("| [6] Sort categories.     |\n");
    printf("| [0] Exit the Program.    |\n");
    printf("|==========================|\n");
    c = choice();
    return c;
}

// Ham them danh muc
void addCategory(Category categories[], int *count) {
    if (*count >= 100) {
        printf("Danh muc da day.\n");
        return;
    }
    // Nhap vao ID danh muc
    printf("Nhap vao ID danh muc: ");
    scanf("%s", categories[*count].CategoryId);
    // Nhap vao Ten danh muc
    printf("Nhap vao ten danh muc: ");
    scanf("%s", categories[*count].CategoryName);
    (*count)++; // Tang danh muc len 1
    // Luu danh muc moi them vao File
    writeFile(categories, *count);
    printf("Them danh muc thanh cong!\n");
}

// Ham sua danh muc
void editCategory(Category categories[], int count) {
    // Khai bao mang chua ID danh muc can sua
    char id[10];
    printf("Nhap vao ID danh muc can sua: ");
    scanf("%s", id);
    // So sanh ID da nhap voi cac ID danh muc trong mang
    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(categories[i].CategoryId, id) == 0) {
            // Hien thi thong tin danh muc can sua
            printf("ID danh muc: %s\n", categories[i].CategoryId);
            printf("Ten danh muc: %s\n", categories[i].CategoryName);
            // Nhap ten danh muc moi
            printf("Nhap ten danh muc moi: ");
            scanf("%s", categories[i].CategoryName);
            // Luu danh muc moi vao File
            writeFile(categories, count);
            printf("Cap nhat danh muc thanh cong!\n");
            return;
        }
    }
    // Neu khong tim thay se thong bao khong tim thay
    printf("Danh muc khong tim thay.\n");
}

// Ham xoa danh muc
void deleteCategory(Category categories[], int *count) {
    // Khai bao mang chua ID danh muc can xoa
    char id[10];
    printf("Nhap vao danh muc can xoa: ");
    scanf("%s", id);
    // So sanh ID vua nhap voi cac ID danh muc trong mang
    int i, j;
    for (i = 0; i < *count; i++) {
        if (strcmp(categories[i].CategoryId, id) == 0) {
            // Thong bao xac nhan xoa
            printf("Ban co chac muon xoa danh muc nay? (y/n): ");
            char confirm;
            scanf(" %c", &confirm);
            if (confirm == 'y') {
                for (j = i; j < *count - 1; j++) {
                    categories[j] = categories[j + 1];
                }
                (*count)--; // Giam danh muc di 1
                // Luu cac thay doi vao File
                writeFile(categories, *count);
                printf("Xoa danh muc thanh cong!\n");
            }
            else {
                printf("Da huy xoa danh muc.\n");
            }
            return;
        }
    }
    // Neu khong tim thay se thong bao khong tim thay
    printf("Danh muc khong tim thay.\n");
}

// Ham tim kiem danh muc theo ten
void searchCategory(const Category categories[], int count) {
    // Khai bao mang chua ten danh muc can tim kiem 
    char name[10];
    printf("Nhap vao ten danh muc can tim: ");
    scanf("%s", name);
    int i;
    // Su dung ham strstr de tim kiem tuong doi
    for (i = 0; i < count; i++) {
        if (strstr(categories[i].CategoryName, name) != NULL) {
            printf("Found: ID=%s, Name=%s\n", categories[i].CategoryId, categories[i].CategoryName);
        }
    }
    // Neu khong tim thay se thong bao khong tim thay
    printf("Danh muc khong tim thay.\n");
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
    printf("Danh sach danh muc da sap xep thanh cong!");
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
    printf("Danh sach danh muc da sap xep thanh cong!\n");
}

// Ham hien thi toan bo danh muc
void displayCategories(const Category categories[], int count) {
    // Kiem tra xem neu khong co danh muc nào thì se thong bao khong co
    if (count == 0) {
        printf("Khong co danh muc trong menu.\n");
        return;
    }
    // Hien thi danh muc
    printf("\n=== Category List ===\n");
    printf("%-10s | %-10s\n", "Category ID", "Category Name");
    printf("-----------------------\n");
    int i;
    for (i = 0; i < count; i++) {
        printf("%-10s | %-10s\n", categories[i].CategoryId, categories[i].CategoryName);
    }
}
