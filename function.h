#ifndef FUNCTION_H
#define FUNCTION_H

#include "datatype.h"

// Ham xoa bo nho dem
void clearCache();

// Ham nhap lua chon
int choice();

// Ten he thong
void nameSystem();

// Ham doc FIle categories.bin
void readFile(Category categories[], int *count);

// Ham ghi File categories.bin
void writeFile(const Category categories[], int count);

// Ham doc File admin.bin
void readFileAdmin(Admin admin[], int *countAdmin);

// Ham ghi File admin.bin
void writeFileAdmin(const Admin admin[], int countAmin);

// Ham hien thi toan bo danh muc
void displayCategories(const Category categories[], int count);

// Ham them danh muc
void addCategory(Category categories[], int *count);

// Ham sua danh muc
void editCategory(Category categories[], int count);

// Ham xoa danh muc
void deleteCategory(Category categories[], int *count);

// Ham tim kiem danh muc theo ten
void searchCategory(const Category categories[], int count);

// Ham sap xep danh muc theo ten tang dan
void sortCategoriesUp(Category categories[], int count);

// Ham sap xep danh muc theo ten giam dan
void sortCategoriesDown(Category categories[], int count);

// Ten ham them danh muc
void nameAddCategory();

// Ham ten sua danh muc
void nameEditCategory();

// Ham ten xoa danh muc
void nameDeleteCategory();

// Ham ten hien thi danh muc
void nameShowCategory();

// Ham kiem tra trung lap ID
int isDuplicateID(Category categories[], int count, char id[]);

// Ham kiem tra trung lap Name
int isDuplicateName(Category categories[], int count, char name[]);

// Ham quay lai menu
void goBack(Category categories[], int *count);

// Ham lua chon cach sap xep
void sortCategoriesMenu(Category categories[], int count);

// Ham lua chon cac chuc nang danh muc
void mainMenu(Category categories[], int *count);

// Ham dang nhap
void LoginAdmin(Admin admin[], int countAmin);

#endif
