//
// Created by Román Máté on 2025. 05. 12..
//

#include "library.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
#define MAX_YEAR_LENGTH 5

Node *createNewNode(Book newBook) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->book = newBook;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insertLeft(Node *root, Book newBook) {
    if (root == NULL) {
        return createNewNode(newBook);
    }
    root->left = createNewNode(newBook);
    return root->left;
}

Node *insertRight(Node *root, Book newBook) {
    if (root == NULL) {
        return createNewNode(newBook);
    }
    root->right = createNewNode(newBook);
    return root->right;
}
Node *find(Node *root, const char *title) {
    if (root == NULL || strcmp(root->book.title, title) == 0)
        return root;

    if (strcmp(title, root->book.title) < 0)
        return find(root->left, title);

    return find(root->right, title);
}

Node *deleteNode(Node *root, const char *title) {
    if (root == NULL) {
        return root;
    }
    if (strcmp(title, root->book.title) < 0) {
        root->left = deleteNode(root->left, title);
    } else if (strcmp(title, root->book.title) > 0) {
        root->right = deleteNode(root->right, title);
    } else {
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        Node *temp = root->right;
        while (temp && temp->left != NULL) {
            temp = temp->left;
        }

        root->book = temp->book;
        root->right = deleteNode(root->right, temp->book.title);
    }
    return root;
}

Node *deleteOldBooks(Node *root, Node **oldBooks) {
    if (root == NULL) {
        return root;
    }

    if (2025 - root->book.year > 50) {
        *oldBooks = insertRight(*oldBooks, root->book);
        root = deleteNode(root, root->book.title);
    }

    root->left = deleteOldBooks(root->left, oldBooks);
    root->right = deleteOldBooks(root->right, oldBooks);
    return root;
}

void printOldBooks(Node *oldBooks) {
    if (oldBooks != NULL) {
        printOldBooks(oldBooks->left);
        printf("Régi könyv: Cím: %s | Szerző: %s | Év: %d\n",
               oldBooks->book.title, oldBooks->book.author, oldBooks->book.year);
        printOldBooks(oldBooks->right);
    }
}

void destroyBinaryTree(Node **root) {
    if (*root == NULL) return;
    destroyBinaryTree(&(*root)->left);
    destroyBinaryTree(&(*root)->right);
    free(*root);
    *root = NULL;
}
void readLine(char *buffer, int maxLength) {
    int i = 0;
    char c;
    while ((c = fgetc(stdin)) != '\n' && c != EOF && i < maxLength - 1) {
        buffer[i++] = c;
    }
    buffer[i] = '\0';
}
void inorderTraversal(Node *root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%s by %s, %d - %s\n", root->book.title, root->book.author, root->book.year, root->book.isRented ? "Rented" : "Available");
    inorderTraversal(root->right);
}

Book readBookFromFile(char *file) {
    Book newBook;

    readLine(newBook.title, MAX_TITLE_LENGTH);

    readLine(newBook.author, MAX_AUTHOR_LENGTH);

    char yearStr[MAX_YEAR_LENGTH];
    readLine(yearStr, MAX_YEAR_LENGTH);
    char rentedStr[MAX_YEAR_LENGTH];
    readLine(rentedStr, MAX_YEAR_LENGTH);
    newBook.isRented = atoi(rentedStr);

    return newBook;
}