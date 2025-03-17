//
// Created by Román Máté on 2025. 03. 17..
//

#include "verem.h"
#include <stdlib.h>
#include <stdio.h>
void createStack(int capacity, Stack_t * stack) {
    stack->capacity=capacity;
    stack->top=-1;
    stack->elements=(int*)malloc(stack->capacity*sizeof(int));
}

void destroyStack(Stack_t* stack) {
    stack->capacity=0;
    stack->top=-1;
    free(stack->elements);
    stack=NULL;
}
bool isFull(Stack_t stack) {
    return stack.top==stack.capacity-1;
}
bool isEmpty(Stack_t stack) {
    return stack.top==-1;
}
void push(Stack_t* stack, int item) {
    if(isFull(*stack)) {
        printf("thestack is full");
        exit(-3);
    }
    stack->elements[++stack->top]=item;
}
int pop(Stack_t* stack) {
    if(isEmpty(*stack)) {
        printf("the stack is empty");
        return INT_MIN;
    }
    int save=stack->elements[stack->top];
    stack->elements[stack->top--]=0;
    return save;
}
int peek(Stack_t stack) {
    if(isEmpty(stack)) {
        printf("the stack is empty");
        return INT_MIN;
    }
    return stack.elements[stack.top];
};
int size(Stack_t stack) {
    return stack.top+1;
}