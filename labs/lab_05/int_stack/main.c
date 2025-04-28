#include <stdio.h>

#include "int_stack_functions.h"

int main(void) {
    Stack_t stack;
        int sum=0;

        createStack(4, &stack);
        push(&stack, 1);
        push(&stack, 2);
        push(&stack, 3);
        push(&stack, 4);
        push(&stack, 5);

        printf("A kivett elem erteke: %i\n", pop(&stack));
        printf("A kivett elem erteke: %i\n", pop(&stack));
        push(&stack, 6);
        push(&stack, 7);
        push(&stack, 8);

        printf("A kivett elem erteke: %i\n", pop(&stack));

        printf("A legfelso elem erteke: %i\n", peek(stack));

        while(!isEmpty(stack)) {
            sum+=peek(stack);
            pop(&stack);
        }
        printf("A veremben talalhato elemek osszege: %i\n", sum);
    return 0;
}
