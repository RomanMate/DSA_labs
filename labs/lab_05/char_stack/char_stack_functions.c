//
// Created by balin on 2025. 03. 17..
//

#include "char_stack_functions.h"

void createStack(int capacity, Stack_t *stack) {
    stack->capacity=capacity;
    stack->top=-1;
    stack->elements=(char*)malloc(capacity*sizeof(char));
}

bool isFull(Stack_t stack) {
    return stack.top==stack.capacity-1;
}

bool isEmpty(Stack_t stack) {
    return stack.top==-1;
}

void push(Stack_t *stack, char item) {
    if (isFull(*stack)) {
        printf("The stack is full!\n");
    }
    else{stack->elements[++stack->top]=item;}
}

int pop(Stack_t *stack) {
    if(isEmpty(*stack)) {
        printf("The stack is empty!\n");
        return INT_MIN;
    }
    int save=stack->elements[stack->top];
    stack->elements[stack->top--]='_';
    return save;
}