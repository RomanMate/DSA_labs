#include <stdio.h>
#include "headers/binary_tree.h"

int main() {
    /*Node *root = createNewNode(1);
    insertLeft(root, 2);
    insertRight(root, 3);
    Node *temp = insertLeft(root->left, 4);
    insertRight(root->left, 5);
    insertLeft(temp, 8);
    insertRight(temp, 9);
    insertLeft(root->right, 6);
    insertRight(root->right, 7);*/

    /*Node *root = createNewNode(10);
    insertLeft(root, 12);
    insertRight(root->left, 25);
    Node *temp = insertLeft(root->left->right, 7);
    insertLeft(temp, 8);
    insertRight(temp,4);*/

    Node *root = createNewNode(100);
    insertLeft(root,500);
    insertRight(root,600);
    insertLeft(root->right,700);
    Node *temp = insertRight(root->right,800);
    insertRight(temp,900);
    insertRight(temp->right,1000);


    ///traversals
    printf("\nPreorder: ");
    preorderTraversal(root);
    printf("\nInorder: ");
    inorderTraversal(root);
    printf("\nPostorder: ");
    postorderTraversal(root);

    ///deallocate
    destroyBinaryTree(&root);


    return 0;
}
