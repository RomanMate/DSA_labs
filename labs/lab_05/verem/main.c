#include <stdio.h>
#include "verem.h"

int main(void) {

    Stack_t stack;
    createStack(4,&stack);
    push(&stack,1);
    push(&stack,2);
    push(&stack,3);
    push(&stack,4);
    push(&stack,5);
    printf("\nA kivett elem erteke:%i\n",pop(&stack));
    printf("\nA kivett elem erteke:%i\n",pop(&stack));
    push(&stack,6);
    push(&stack,7);
    push(&stack,8);
    printf("\nA kivett elem erteke:%i\n",pop(&stack));

    return 0;
}
