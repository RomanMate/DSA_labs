#include <stdio.h>
#include <stdlib.h>
#include "library.h"

int main() {
    Node *root = NULL;
    Node *oldBooks = NULL;

    FILE *file = fopen("books.txt", "r");
    if (file == NULL) {
        printf("A fájlt nem sikerült megnyitni.\n");
        return 1;
    }

    while (!feof(file)) {
        Book newBook = readBookFromFile(file);
        if (newBook.year == 0) continue;

        root = insertRight(root, newBook);
    }

    fclose(file);

    printf("Könyvek listázása:\n");
    inorderTraversal(root);

    printf("\nRégi könyvek eltávolítása (50 évnél régebbi):\n");
    root = deleteOldBooks(root, &oldBooks);

    printf("\nRégi könyvek:\n");
    printOldBooks(oldBooks);

    destroyBinaryTree(&root);
    destroyBinaryTree(&oldBooks);

    return 0;
}
