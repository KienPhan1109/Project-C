#ifndef FUNCTION_H
#define FUNCTION_H

#include "datatype.h"

// Ham xoa bo nho dem
void clearInput();

// Ham nhap lua chon
int choice();

// Ten he thong
void nameSystem();

// Ham doc FIle
void readFile(Category categories[], int *count);

// Ham ghi File
void writeFile(const Category categories[], int count);

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

// Ham thoat chuong trinh
void exitSystem();

#endif
