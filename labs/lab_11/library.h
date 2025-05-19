//
// Created by Román Máté on 2025. 05. 12..
//

#ifndef LIBRARY_H
#define LIBRARY_H

#include <stdbool.h>

// Könyv adatstruktúra
typedef struct {
    char title[100];
    char author[100];
    int year;
    bool isRented;
} Book;

// Bináris fa csomópont
typedef struct Node {
    Book book;
    struct Node* left;
    struct Node* right;
} Node;

// Függvények
Node *createNewNode(Book newBook);
Node *insertLeft(Node *root, Book newBook);
Node *insertRight(Node *root, Book newBook);
void destroyBinaryTree(Node **root);
Node *find(Node *root, const char *title);
Node *deleteNode(Node *root, const char *title);
Node *deleteOldBooks(Node *root, Node **oldBooks);
void printOldBooks(Node *oldBooks);
Book readBookFromFile(char *file);
void readLine(char *buffer, int maxLength);
void inorderTraversal(Node *root);


#endif //LIBRARY_H
