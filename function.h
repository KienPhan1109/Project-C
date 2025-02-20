#ifndef FUNCTION_H
#define FUNCTION_H

#include "datatype.h"


void writeFileAdmin(const Admin admin[], int countAdmin);

void readFileAdmin(Admin admin[], int *countAdmin);

void LoginAdmin(Admin admin[], int countAdmin);

void mainMenu();

int choice();

void clearCache();

void goBack();

int isDuplicateIDCategory(Category categories[], int countCategory, char id[]);

int isDuplicateNameCategory(Category categories[], int countCategory, char name[]);

int isDuplicateIDProductInCategory(Product products[], int countProduct, char *productID, char *categoryID);

int isDuplicateNameProductInCategory(Product products[], int countProduct, char *productName, char *categoryID);

void writeFileCategory(const Category categories[], int countCategory);

void writeFileProduct(const Product products[], int countProduct);

void readFileCategory(Category categories[], int *countCategory);

void readFileProduct(Product products[], int *countProduct);

void displayCategories(const Category categories[], int countCategory);

void displayProducts(const Product products[], int countProduct);

void addCategory(Category categories[], int *countCategory);

void addProduct(Product products[], int *countProduct, Category categories[], int *countCategory);

void editCategory(Category categories[], int countCategory);

void editProduct(Product products[], int *countProduct, Category categories[], int *countCategory);

void deleteCategory(Category categories[], int *countCategory, Product products[], int *countProduct);

void deleteProduct(Product products[], int *countProduct, Category categories[], int *countCategory);

void searchCategory(const Category categories[], int countCategory);

void searchProduct(const Product products[], int countProduct);

void sortCategoriesUp(Category categories[], int countCategory);

void sortCategoriesDown(Category categories[], int countCategory);

void sortProductsUp(Product products[], int countProduct);

void sortProductsDown(Product products[], int countProduct);

void menuCategory(Category categories[], int *count, Product products[], int *countProduct, int *checkAdmin);

void menuProduct(Product products[], int *countProduct, Category categories[] , int *countCategory, int *checkAdmin);

void sortCategoriesMenu(Category categories[], int count);

void sortProductsMenu(Product products[], int countProduct);

void filterProductMenu(Product products[], int countProduct, Category categories[], int countCategory);

void filterProductsByCategory(Product products[], int countProduct, Category categories[], int countCategory);

void filterProductsByPrice(Product products[], int countProduct);

#endif
