//
// Created by Román Máté on 2025. 04. 28..
//

#include "binarisfa.h"
#include <stdio.h>
#include <stdlib.h>

Node *newNode(Barat new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if(!new_node) {
        exit(-1);
    }
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}
bool isEmpty(Node *head) {
    return head == NULL;
}
void insertAtBeginning(Node** head_ref, Barat new_data) {
    Node* new_node = newNode(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void insertAfter(Node* prev_node, Barat new_data) {
    if (prev_node == NULL) {
        return;
    }
    Node* new_node = newNode(new_data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}
void insertAtEnd(Node** head_ref, Barat new_data) {
    Node* new_node = newNode(new_data);
    Node* last = *head_ref;
    if (isEmpty(*head_ref)) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL) last = last->next;
    last->next = new_node;
}
void printList(Node* node) {
    while (node != NULL) {
        printf("%s\t|\t%d\t|\t%d\t|\t%d\t|\t%c\t|\t%d\t", node->data);
        node = node->next;
    }
}