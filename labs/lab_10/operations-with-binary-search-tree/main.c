#include <stdio.h>
#include "headers/binary_search_tree.h"
#include <time.h>
#include <stdlib.h>

int main() {
    /*int items[] = {7, 5, 12, 3, 6, 9, 15, 1, 4, 8, 10, 13, 17};
    int n = 13;
    Node *root = createNewNode(items[0]);
    for (int i = 1; i < n; ++i) {
        insert(root, items[i]);
    }
    srand(time(NULL));
    Node* root = NULL;
    for (int i = 1; i <= 10; ++i) {
        int num = rand() % 401 + 500;
        printf("%d ", num);
        root = insert(root, num);
    }
    printf("\nInorder: ");
    inorderTraversal(root);

    /*deleteNode(root, 17);
    printf("\nInorder: ");
    inorderTraversal(root);

    deleteNode(root, 15);
    printf("\nInorder: ");
    inorderTraversal(root);

    deleteNode(root, 7);
    printf("\nInorder: ");
    inorderTraversal(root);

    destroyBinaryTree(&root);*/

    return 0;
}
