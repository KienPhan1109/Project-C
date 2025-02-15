#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "function.h"
#include "datatype.h"

// * ================================================ ADMIN ================================================

// Ham ghi File admin.bin
void writeFileAdmin(const Admin admin[], int countAdmin) {
    FILE *f = fopen("admin.bin", "wb");

    if (f == NULL) {
        printf("\tError: Writing file admin.bin !!!\n");
        return;
    }

    fwrite(&countAdmin, sizeof(int), 1, f);
    fwrite(admin, sizeof(Admin), countAdmin, f);

    fclose(f);
}

// Ham doc File admin.bin
void readFileAdmin(Admin admin[], int *countAdmin) {
    FILE *f = fopen("admin.bin", "rb");

    if (f == NULL) {
        printf("\tError: Reading file admin.bin !!!\n");
        Admin defaultAdmin = {"KienPhan", "11092006"};
        *countAdmin = 1;
        writeFileAdmin(&defaultAdmin, *countAdmin);
        return;
    }

    fread(countAdmin, sizeof(int), 1, f);
    fread(admin, sizeof(Admin), *countAdmin, f);

    fclose(f);
}

// Ham dang nhap Admin
void LoginAdmin(Admin admin[], int countAdmin) {
    char a[30];
    char p[30];

    do {
        printf("\n\t|======== LOGIN ADMIN ========|\n");

        printf("\n\tAccount: ");
        scanf("%s", a);
        clearCache();

        printf("\n\tPassword: ");

        // Nhap mat khau voi dau '*'
        int i = 0;
        char ch;
        while (1) {
            ch = getch(); // Lay 1 ki tu nhung khong hien thi ra man hinh
            if (ch == 13) { // ASCII 13 tuong duong voi ENTER de ket thuc nhap
                p[i] = '\0';
                break;
            } else if (ch == 8 && i > 0) { // Nhan BACKSPACE de xoa ki tu
                printf("\b \b"); // xoa 1 ki tu tren man hinh
                i--;
            } else if (ch != 8) { // Neu khong phai BACKSPACE
                printf("*"); // Hien thi '*'
                p[i] = ch;
                i++;
            }
        }

        // Kiem tra tai khoan va mat khau
        for (i = 0; i < countAdmin; i++) {
            if (strcmp(a, admin[i].Account) == 0 && strcmp(p, admin[i].Password) == 0) {
                printf("\n\tLog in successfully.\n");
                return;
            }
        }

        printf("\n\tInvalid username or password. Please try again.\n");

    } while (1);
    printf("\n");
}

// * ===================================================== HAM CHUNG =====================================================

// Ham nhap lua chon
int choice()
{
    int c;
    printf("\n\tEnter The Choice: ");
    scanf("%d", &c);
    return c;
}

// Ham xoa bo nho dem
void clearCache()
{
    int c;
    while ((c = getchar() ) != '\n' && c != EOF);
}

// Ham quay lai menu
void goBack() {
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
            printf("\n\tInvalid option. Please try again.\n");
        }
    } while (1);
}

// * ============================================== HAM KIEM TRA TRUNG LAP ==============================================

// Ham kiem tra trung lap ID Category
int isDuplicateIDCategory(Category categories[], int countCategory, char id[]) {
    int i;
    for (i = 0; i < countCategory; i++) {
        if (strcmp(categories[i].CategoryId, id) == 0) {
            return 1; // Trung ID
        }
    }
    return 0;
}

// Ham kiem tra trung lap Name Category
int isDuplicateNameCategory(Category categories[], int countCategory, char name[]) {
    int i;
    for (i = 0; i < countCategory; i++) {
        if (strcmp(categories[i].CategoryName, name) == 0) {
            return 1; // Trung Name
        }
    }
    return 0;
}

// Ham kiem tra trung lap ID san pham cung danh muc
int isDuplicateIDProductInCategory(Product products[], int countProduct, char *productID, char *categoryID) {
    int i;
    for (i = 0; i < countProduct; i++) {
        if (strcmp(products[i].CategoryId, categoryID) == 0 && strcmp(products[i].ProductId, productID) == 0) {
            return 1; // Trung ID
        }
    }
    return 0;
}

// Ham kiem tra trung lap ten san pham cung danh muc
int isDuplicateNameProductInCategory(Product products[], int countProduct, char *productName, char *categoryID) {
    int i;
    for (i = 0; i < countProduct; i++) {
        if (strcmp(products[i].CategoryId, categoryID) == 0 && strcmp(products[i].ProductName, productName) == 0) {
            return 1; // Trung ten
        }
    }
    return 0;
}

// * =================================================== HAM GHI FILE ====================================================

// Ham ghi File categories.bin
void writeFileCategory(const Category categories[], int countCategory) {
    FILE *f = fopen("categories.bin", "wb");

    if (f == NULL) {
        printf("\n\tError: Writing file categories.bin !!!\n");
        return;
    }

    fwrite(&countCategory, sizeof(int), 1, f);
    fwrite(categories, sizeof(Category), countCategory, f);

    fclose(f);
}

// Ham ghi File products.bin
void writeFileProduct(const Product products[], int countProduct) {
    
    FILE *f = fopen("products.bin", "wb");

    if (f == NULL) {
        printf("\n\tError: Writing file products.bin !!!\n");
        return;
    }

    fwrite(&countProduct, sizeof(int), 1, f);
    fwrite(products, sizeof(Product), countProduct, f);

    fclose(f);
}

// * =================================================== HAM DOC FILE ====================================================

// Ham doc File categories.bin
void readFileCategory(Category categories[], int *countCategory) {
    FILE *f = fopen("categories.bin", "rb");
    
    if (f == NULL) {
        printf("\n\tError: Reading file categories.bin !!!\n");
        return;
    }

    fread(countCategory, sizeof(int), 1, f);
    fread(categories, sizeof(Category), *countCategory, f);

    fclose(f);
}

// Ham doc File products.bin
void readFileProduct(Product products[], int *countProduct) {
    FILE *f = fopen("products.bin", "rb");

    if (f == NULL) {
        printf("\n\tError: Reading file products.bin !!!\n");
        return;
    }

    fread(countProduct, sizeof(int), 1, f);
    fread(products, sizeof(Product), *countProduct, f);

    fclose(f);
}

// * =================================================== HAM HIEN THI ====================================================

// Ham hien thi danh sach danh muc
void displayCategories(const Category categories[], int countCategory) {
    
    printf("\n\t*** All Category ***\n");
    
    // Kiem tra xem neu khong co danh muc nao thi se thong bao khong co
    if (countCategory == 0) {
        printf("\n\tError: No categories available to display.\n");
        return;
    }
    // Hien thi danh muc
    printf("\n\t|============|==============|");
    printf("\n\t|%-10s |%-10s |\n", "Category ID", "Category Name");
    printf("\t|============|==============|\n");
    int i;
    for (i = 0; i < countCategory; i++) {
        printf("\t| %-10s | %-10s   |\n", categories[i].CategoryId, categories[i].CategoryName);
        printf("\t|------------|--------------|\n");
    }
}

// Ham hien thi danh sach san pham
void displayProducts(const Product products[], int countProduct) {

    printf("\n\t*** All Product ***\n");

    // Kiem tra xem neu khong co san pham nao thi se thong bao khong co
    if (countProduct == 0) {
        printf("\n\tError: No products available to display.\n");
        goBack();
        return;
    }
    // Hien thi san pham
    printf("\n\t|=============|===============|=============|=============|=============|");
    printf("\n\t| %-11s | %-11s   | %-11s | %-11s | %-11s |\n", "Category ID", "Product ID", "Name", "Quantity", "Price");
    printf("\t|=============|===============|=============|=============|=============|\n");
    int i;
    for (i = 0; i < countProduct; i++) {
        printf("\t| %-11s | %-11s   | %-11s | %-11d | %-11d |\n", products[i].CategoryId, products[i].ProductId, products[i].ProductName, products[i].Quantity, products[i].Price);
        printf("\t|-------------|---------------|-------------|-------------|-------------|\n");
    }
    goBack();
}

// * ====================================================== HAM THEM =====================================================

// Ham them danh muc
void addCategory(Category categories[], int *countCategory) {
    
    printf("\n\t*** Add A New Category ***\n");

    if (*countCategory >= 100) {
        printf("\n\tError: Category list is Full !!!\n");
        return;
    }

    Category newCategory;

    // Nhap ID danh muc
    do {
        printf("\n\tEnter Category ID: ");
        scanf("%s", newCategory.CategoryId);
        clearCache();

        if (strlen(newCategory.CategoryId) > 10 || strlen(newCategory.CategoryId) == 0) {
            printf("\n\tError: Category ID must be 1-10 characters!\n"); // ID nam trong khoang tu 1 - 10 ki tu
        } else if (isDuplicateIDCategory(categories, *countCategory, newCategory.CategoryId)) {
            printf("\n\tError: Category ID already exists!\n"); // ID danh muc da ton tai
        } else {
            break; // Hop le
        }
    } while (1);

    // Nhap ten danh muc
    do {
        printf("\n\tEnter Category Name: ");
        fgets(newCategory.CategoryName, sizeof(newCategory.CategoryName), stdin);
        newCategory.CategoryName[strcspn(newCategory.CategoryName, "\n")] = '\0';


        if (strlen(newCategory.CategoryName) > 10 || strlen(newCategory.CategoryName) == 0) {
            printf("\n\tError: Category Name must be 1-10 characters!\n"); // Ten danh muc nam trong khoang tu 1 - 10 ki tu
        } else if (isDuplicateNameCategory(categories, *countCategory, newCategory.CategoryName)) {
            printf("\n\tError: Category Name already exists!\n"); // Ten danh muc da ton tai
        } else {
            break; // Hop le
        }
    } while (1);

    categories[*countCategory] = newCategory;
    (*countCategory)++; // Tang danh muc len 1

    // Luu danh muc moi vao File
    writeFileCategory(categories, *countCategory);
    printf("\n\tCategory Added Successfully !!!\n");
    goBack();
}

// Ham them san pham
void addProduct(Product products[], int *countProduct, Category categories[], int *countCategory)
{
    printf("\n\t*** Add A New Product ***\n");

    if (*countProduct >= 100) {
        printf("\n\tError: Category list is Full !!!\n");
        return;
    }
    
    Product newProduct;

    char IDCategory[10];
    int CategoryFound = 0;

    // Hien thi toan bo danh muc de them san pham
    displayCategories(categories , *countCategory);

    do
    {
        printf("\n\tEnter Category ID: ");
        scanf("%s", IDCategory);
        clearCache();

        int i;
        for (i = 0; i < *countCategory; i++)
        {
            if (strcmp(categories[i].CategoryId, IDCategory) == 0)
            {
                CategoryFound++;
                break;
            }
        }
        if (!CategoryFound) {
            printf("\n\tError: Category ID does not exist!\n");
        }
    } while (!CategoryFound);

    // Gan ID danh muc vao san pham
    strcpy(newProduct.CategoryId, IDCategory);

    // Nhap ID san pham
    do {
        printf("\n\tEnter Product ID: ");
        scanf("%s", newProduct.ProductId);
        clearCache();

        if (strlen(newProduct.ProductId) > 10 || strlen(newProduct.ProductId) == 0) {
            printf("\n\tError: Product ID must be 1-10 characters!\n"); // ID nam trong khoang tu 1 - 10 ki tu
        } else if (isDuplicateIDProductInCategory(products, *countProduct, newProduct.ProductId, IDCategory)) {
            printf("\n\tError: Product ID already exists!\n"); // ID san pham da ton tai
        } else {
            break; // Hop le
        }
    } while (1);
    
    // Nhap ten san pham
    do {
        printf("\n\tEnter Product Name: ");
        fgets(newProduct.ProductName, sizeof(newProduct.ProductName), stdin);
        newProduct.ProductName[strcspn(newProduct.ProductName, "\n")] = '\0';

        if (strlen(newProduct.ProductName) > 10 || strlen(newProduct.ProductName) == 0) {
            printf("\n\tError: Product Name must be 1-10 characters!\n"); // Ten san pham nam trong khoang tu 1 - 10 ki tu
        } else if (isDuplicateNameProductInCategory(products, *countProduct, newProduct.ProductName, IDCategory)) {
            printf("\n\tError: Product Name already exists!\n"); // Ten san pham da ton tai
        } else {
            break; // Hop le
        }
    } while (1);

    // Nhap so luong san pham
    printf("\n\tEnter Product Quantity: ");
    scanf("%d", &newProduct.Quantity);

    // Nhap gia san pham
    printf("\n\tEnter Product Price: ");
    scanf("%d", &newProduct.Price);
    
    products[*countProduct] = newProduct;
    (*countProduct)++; // Tang san pham len 1

    // Luu san pham moi vao File
    writeFileProduct(products, *countProduct);
    printf("\n\tProduct Added Successfully !!!\n");
    goBack();
}

// * ======================================================= HAM SUA ====================================================

// Ham sua danh muc
void editCategory(Category categories[], int countCategory) {
    
    printf("\n\t*** Edit A Category ***\n");
    
    char id[10];
    printf("\n\tEnter Category ID to edit: ");
    scanf("%s", id);
    clearCache();

    int i;
    for (i = 0; i < countCategory; i++) {
        if (strcmp(categories[i].CategoryId, id) == 0) {
            // Thong bao da tim thay
            printf("\n\tOne Category Found for ID: %s\n", id);
            printf("\tCategory informations\n");
            printf("\t--------------------------\n");
            // Hien thi thong tin danh muc can xoa
            printf("\tCategory ID: %s\n", categories[i].CategoryId);
            printf("\tCategory Name: %s\n", categories[i].CategoryName);

            // Nhap ten danh muc moi
            char newCategoryName[11];
            do {
                printf("\n\tEnter new Category Name: ");
                fgets(newCategoryName, sizeof(newCategoryName), stdin);
                newCategoryName[strcspn(newCategoryName, "\n")] = '\0';

                if (strlen(newCategoryName) < 1 || strlen(newCategoryName) > 10) {
                    printf("\n\tError: Category Name must be 1-10 characters!\n"); // Ten danh muc nam trong khoang tu 1 - 10 ki tu
                } else if (isDuplicateNameCategory(categories, countCategory, newCategoryName)) {
                    printf("\n\tError: Category Name already exists!\n"); //Ten danh muc da ton tai
                } else {
                    break; // Hop le
                }
            } while (1);

            // Cap nhat ten danh muc
            strcpy(categories[i].CategoryName, newCategoryName);

            // Ghi vao file
            writeFileCategory(categories, countCategory);
            printf("\n\tCategory Updated successfully !!!\n");
            goBack();
            return;
        }
    }
    printf("\n\tError: Category not found.\n");
    goBack();
}

// Ham sua san pham
void editProduct(Product products[], int *countProduct, Category categories[], int *countCategory) {
    
    printf("\n\t*** Edit A Product ***\n");
    // * SUAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
    char IDCategory[15];
    int CategoryFound = 0;
    do
    {
        printf("\n\tEnter Category ID: ");
        scanf("%s", IDCategory);
        clearCache();

        int i;
        for (i = 0; i < *countCategory; i++)
        {
            if (strcmp(categories[i].CategoryId, IDCategory) == 0)
            {
                CategoryFound++;
                break;
            }
        }
        if (!CategoryFound) {
            printf("\n\tError: Category ID does not exist!\n");
        }
    } while (!CategoryFound);

    char idProduct[15];
    printf("\n\tEnter Product ID to edit: ");
    scanf("%s", idProduct);
    clearCache();
    
    int i;
    for (i = 0; i < *countProduct; i++) {
        if (strcmp(products[i].ProductId, idProduct) == 0) {
            // Thong bao da tim thay
            printf("\n\tOne Product Found for ID: %s\n", idProduct);
            printf("\tProduct informations\n");
            printf("\t--------------------------\n");
            // Hien thi thong tin danh muc can xoa
            printf("\tProduct ID: %s\n", products[i].ProductId);
            printf("\tProduct Name: %s\n", products[i].ProductName);
            printf("\tProduct Quantity: %d\n", products[i].Quantity);
            printf("\tProduct Price: %d\n", products[i].Price);
            
            // Nhap ten san pham moi
            char newProductName[11];
            do {
                printf("\n\tEnter new Product Name: ");
                fgets(newProductName, sizeof(newProductName), stdin);
                newProductName[strcspn(newProductName, "\n")] = '\0';

                if (strlen(newProductName) > 10 || strlen(newProductName) < 1) {
                    printf("\n\tError: Product Name must be 1-10 characters!\n"); // Ten san pham nam trong khoang tu 1 - 10 ki tu
                } else if (isDuplicateNameProductInCategory(products, *countProduct, newProductName, products[i].CategoryId)) {
                    printf("\n\tError: Product Name already exists!\n"); // Ten san pham da ton tai
                } else {
                    break; // Hop le
                }
            } while (1);

            // Cap nhat ten danh muc
            strcpy(products[i].ProductName, newProductName);
            
            // Nhap so luong moi
            printf("\n\tEnter new Product Quantity: ");
            scanf("%d", &products[i].Quantity);
            
            // Nhap gia moi
            printf("\n\tEnter new Product Price: ");
            scanf("%d", &products[i].Price);
            
            writeFileProduct(products, *countProduct);
            printf("\n\tProduct Updated successfully !!!\n");
            goBack();
            return;
        }
    }
    printf("\n\tError: Product not found.\n");

    goBack();
}

// * ========================================================= HAM XOA ===================================================

// Ham xoa danh muc
void deleteCategory(Category categories[], int *countCategory, Product products[], int *countProduct) {
    
    printf("\n\t*** Delete A Category ***\n");

    char id[15];
    printf("\n\tEnter Category ID to delete: ");
    scanf("%s", id);
    clearCache();

    // So sanh ID vua nhap voi cac ID danh muc trong mang
    int i, j;
    for (i = 0; i < *countCategory; i++) {
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
            clearCache();
            if (confirm == 'Y' || confirm == 'y') {
                for (j = i; j < *countCategory - 1; j++) {
                    categories[j] = categories[j + 1];
                }
                (*countCategory)--; // Giam danh muc di 1
                
                if(*countProduct > 0) { 
                    // Xoa tat ca san pham thuoc danh muc
                    int newCount = 0;
                    int k;
                    for (k = 0; k < *countProduct; k++) {
                        if (strcmp(products[k].CategoryId, id) != 0) {
                            products[newCount++] = products[k];  // Giu lai san pham khong bi xoa
                        }
                    }
                    *countProduct = newCount;
                } 
                
                // Luu cac thay doi vao File
                writeFileCategory(categories, *countCategory);
                writeFileProduct(products, *countProduct);
                printf("\n\tCategory Deleted successfully !!!\n");
                goBack();
            }
            else {
                printf("\n\tCategory deletion cancelled !!!\n");
                goBack();
            }
            return;
        }
    }
    printf("\n\tError: Category not found.\n");

    goBack();
}

// Ham xoa san pham
void deleteProduct(Product products[], int *countProduct) {

    printf("\n\t*** Delete A Product ***\n");

    char id[15];
    printf("\n\tEnter Product ID to delete: ");
    scanf("%s", id);
    clearCache();
    
    // So sanh ID vua nhap voi cac ID danh muc trong mang
    int i, j;
    for (i = 0; i < *countProduct; i++) {
        if (strcmp(products[i].ProductId, id) == 0) {
            // Thong bao da tim thay
            printf("\n\tOne Product Found for ID: %s\n", id);
            printf("\tProduct informations\n");
            printf("\t--------------------------\n");
            // Hien thi thong tin danh muc can xoa
            printf("\tProduct ID: %s\n", products[i].ProductId);
            printf("\tProduct Name: %s\n", products[i].ProductName);
            printf("\tProduct Quantity: %d\n", products[i].Quantity);
            printf("\tProduct Price: %d\n", products[i].Price);
            // Thong bao xac nhan xoa
            printf("\n\tAre you sure you want to delete this product? (Y/N): ");
            char confirm;
            scanf(" %c", &confirm);
            if (confirm == 'Y'|| confirm == 'y') {
                for (j = i; j < (*countProduct) - 1; j++) {
                    products[j] = products[j + 1];
                }
                (*countProduct)--; // Giam san pham di 1
                // Luu cac thay doi vao File
                writeFileProduct(products, *countProduct);
                printf("\n\n\tProduct Deleted successfully !!!\n");
                goBack();
            }
            else {
                printf("\n\n\tProduct deletion cancelled !!!\n");
                goBack();
            }
            return;
        }
    }
    printf("\n\tError: Product not found.\n");
    goBack();
}

// * ==================================================== HAM TIM KIEM ===================================================

// Ham tim kiem danh muc theo ten
void searchCategory(const Category categories[], int countCategory) {
    int found = 0;
    // Khai bao mang chua ten danh muc can tim kiem 
    char name[10];
    getchar();
    printf("\n\tEnter Category Name to search: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    int i;
    // Su dung ham strstr de tim kiem tuong doi
    for (i = 0; i < countCategory; i++) {
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
        goBack();
        return;
    }
    goBack();
}

// Ham tim kiem san pham theo ten
void searchProduct(const Product products[], int countProduct) {
    int found = 0;
    // Khai bao mang chua ten san pham can tim kiem 
    char name[10];
    getchar();
    printf("\n\tEnter Product Name to search: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    
    int i;
    // Su dung ham strstr de tim kiem tuong doi
    for (i = 0; i < countProduct; i++) {
        if (strstr(products[i].ProductName, name) != NULL) {
            if (found == 0)
            {
                printf("\n\t|=============|===============|=============|=============|=============|");
                printf("\n\t| %-11s | %-11s   | %-11s | %-11s | %-11s |\n", "Category ID", "Product ID", "Name", "Quantity", "Price");
                printf("\t|=============|===============|=============|=============|=============|\n");
                printf("\t| %-11s | %-11s   | %-11s | %-11d | %-11d |\n", products[i].CategoryId, products[i].ProductId, products[i].ProductName, products[i].Quantity, products[i].Price);
                printf("\t|-------------|---------------|-------------|-------------|-------------|\n");
            }
            else
            {
                printf("\t| %-11s | %-11s   | %-11s | %-11d | %-11d |\n", products[i].CategoryId, products[i].ProductId, products[i].ProductName, products[i].Quantity, products[i].Price);
                printf("\t|-------------|---------------|-------------|-------------|-------------|\n");
            }
            
            found++;
        }
    }
    // Neu khong tim thay se thong bao khong tim thay
    if (found == 0)
    {
        printf("\n\tProduct not found.\n");
        goBack();
        return;
    }
    goBack();
}

// * ================================================ HAM SAP XEP=========================================================

// Ham sap xep danh muc theo ten tang dan
void sortCategoriesUp(Category categories[], int countCategory) {
    // Su dung thuat toan sap xep noi bot
    int i, j;
    for (i = 0; i < countCategory; i++) {
        for (j = 0; j < countCategory - i - 1; j++) {
            if (strcmp(categories[j].CategoryName, categories[j + 1].CategoryName) > 0) {
                Category temp = categories[j];
                categories[j] = categories[j + 1];
                categories[j + 1] = temp;
            }
        }
    }
    // Luu cac thay doi vao File
    writeFileCategory(categories, countCategory);
    printf("\n\tCategories Sorted Successfully!\n");
}

// Ham sap xep danh muc theo ten giam dan
void sortCategoriesDown(Category categories[], int countCategory) {
    // Su dung thuat toan sap xep noi bot
    int i, j;
    for (i = 0; i < countCategory; i++) {
        for (j = 0; j < countCategory - i - 1; j++) {
            if (strcmp(categories[j].CategoryName, categories[j + 1].CategoryName) < 0) {
                Category temp = categories[j];
                categories[j] = categories[j + 1];
                categories[j + 1] = temp;
            }
        }
    }
    // Luu cac thay doi vao File
    writeFileCategory(categories, countCategory);
    printf("\n\tCategories Sorted Successfully!\n");
}

// Ham sap xep san pham theo gia tang dan
void sortProductsUp(Product products[], int countProduct) {
    // Su dung thuat toan sap xep noi bot
    int i, j;
    for (i = 0; i < countProduct; i++) {
        for (j = 0; j < countProduct - i - 1; j++) {
            if (products[j].Price > products[j + 1].Price) {
                Product temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            }
        }
    }
    // Luu cac thay doi vao File
    writeFileProduct(products, countProduct);
    printf("\n\tProducts Sorted Successfully!\n");
}

// Ham sap xep san pham theo gia giam dan
void sortProductsDown(Product products[], int countProduct) {
    // Su dung thuat toan sap xep noi bot
    int i, j;
    for (i = 0; i < countProduct; i++) {
        for (j = 0; j < countProduct - i - 1; j++) {
            if (products[j].Price < products[j + 1].Price) {
                Product temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            }
        }
    }
    // Luu cac thay doi vao File
    writeFileProduct(products, countProduct);
    printf("\n\tProducts Sorted Successfully!\n");
}

// * ============================================ HAM HIEN THI MENU LUA CHON =============================================

// Hien thi Menu chinh
void mainMenu()
{
    printf("\n\t*** Store Management System Using C ***\n");
    printf("\n\t|-------------*** MENU SYSTEM ***-------------|");
    printf("\n\t| [1] Menu Category Management.               |\n");
    printf("\t| [2] Menu Product Management.                |\n");
    printf("\t| [3] Exit Program.                           |\n");
    printf("\t|---------------------------------------------|\n");
}
    
// Ham hien thi menu quan ly danh muc
void menuCategory(Category categories[], int *count, Product products[], int *countProduct) {
    while (1) {
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

        int c = choice();

        switch (c) {
            case 1: // Hien thi toan bo danh muc
                displayCategories(categories, *count);
                goBack();
                break;

            case 2: // Them danh muc
                addCategory(categories, count);
                break;

            case 3: // Sua danh muc
                editCategory(categories, *count);
                break;

            case 4: // Xoa danh muc
                deleteCategory(categories, count, products, countProduct);
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
                goBack();
                break;
        }
    }
}

// Ham hien thi menu quan ly san pham
void menuProduct(Product products[], int *countProduct, Category categories[], int *countCategory) {
    while (1) {
        printf("\n\t       PRODUCT MENU       \n");
        printf("\t============================\n");
        printf("\t| [1] Show All products.   |\n");
        printf("\t| [2] Add A New product.   |\n");
        printf("\t| [3] Edit A product.      |\n");
        printf("\t| [4] Delete A product.    |\n");
        printf("\t| [5] Search A product.    |\n");
        printf("\t| [6] Sort product.        |\n");
        printf("\t| [0] Exit the Program.    |\n");
        printf("\t============================\n");

        int c = choice();

        switch (c) {
            case 1: // Hien thi toan bo danh muc
                displayProducts(products, *countProduct);
                break;

            case 2: // Them danh muc
                addProduct(products, countProduct, categories, countCategory);
                break;

            case 3: // Sua danh muc
                editProduct(products, countProduct);
                break;

            case 4: // Xoa danh muc
                deleteProduct(products, countProduct);
                break;

            case 5: // Tim kiem danh muc theo ten
                searchProduct(products, *countProduct);
                break;

            case 6: // Sap xep danh muc theo ten
                sortProductsMenu(products, *countProduct);
                break;

            case 0: // Thoat chuong trinh
                printf("\n\t========= Thank You =========\n");
                printf("\t======= See You Soon ========\n");
                printf("\n\t-----------------------------\n");
                system("pause");
                exit(0);

            default:
                printf("\n\tInvalid option. Try again.\n");
                goBack();
                break;
        }
    }
}

// Ham lua chon cach sap xep danh muc
void sortCategoriesMenu(Category categories[], int count) {
    printf("\n\tEnter The Sort Choice\n");
    printf("\t1 : Increase, 2 : Decrease\n");
    int c = choice();

    switch (c) {
        case 1: // Sap xep tang dan
            sortCategoriesUp(categories, count);
            displayCategories(categories, count);
            goBack();
            break;

        case 2: // Sap xep giam dan
            sortCategoriesDown(categories, count);
            displayCategories(categories, count);
            goBack();
            break;

        default:
            printf("\n\tInvalid option. Try again.\n");
            goBack();
            break;
    }
}

// Ham lua chon cach sap xep san pham
void sortProductsMenu(Product products[], int countProduct) {
    printf("\n\tEnter The Sort Choice\n");
    printf("\t1 : Increase, 2 : Decrease\n");
    int c = choice();

    switch (c) {
        case 1: // Sap xep tang dan
            sortProductsUp(products, countProduct);
            displayProducts(products, countProduct);
            break;

        case 2: // Sap xep giam dan
            sortProductsDown(products, countProduct);
            displayProducts(products, countProduct);
            break;

        default:
            printf("\n\tInvalid option. Try again.\n");
            goBack();
            break;
    }
}
