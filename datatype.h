#ifndef DATATYPE_H
#define DATATYPE_H

// Dinh nghia struct Category
typedef struct {
    char CategoryId[10];
    char CategoryName[10];
} Category;

// Dinh nghia struct Login
typedef struct 
{
    char Account[30];
    char Password[30];
} Admin;

// Dinh nghia struct Product
typedef struct {
    char ProductId[10];
    char CategoryId[10];
    char ProductName[10];
    int Quantity;
    int Price;
} Product;

#endif
