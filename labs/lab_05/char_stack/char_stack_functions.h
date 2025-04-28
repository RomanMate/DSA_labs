//
// Created by balin on 2025. 03. 17..
//

#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int capacity;
    int top;
    char *elements;
}Stack_t;

#ifndef CHAR_STACK_FUNCTIONS_H
#define CHAR_STACK_FUNCTIONS_H

/**
* Initializing the capacity and size of stack,
* allocating memory for the @elements array
* @param capacity
* @param stack
*/
void createStack(int capacity, Stack_t *stack);

/**
* Checks whether the stack is full
* @param stack
* @return
*/
bool isFull(Stack_t stack);

/**
* Checks whether the stack is empty
* @param stack
* @return
*/
bool isEmpty(Stack_t stack);

/**
* Pushes a new item to the stack,
* if it is not full
* @param stack
* @param item
*/
void push(Stack_t* stack, char item);

/**
* Removes the top element from the stack,
* if it is not empty
* @param stack
* @return
*/
int pop(Stack_t* stack);

#endif //CHAR_STACK_FUNCTIONS_H
