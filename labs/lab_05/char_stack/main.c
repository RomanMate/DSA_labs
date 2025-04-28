#include <stdio.h>
#include <string.h>
#include "char_stack_functions.h"

#define MAX_ELEMENTS 15

int main(void){
    Stack_t stack;
        createStack(MAX_ELEMENTS, &stack);
        char s[MAX_ELEMENTS]="bab";
        for(int i=0; i<strlen(s); i++){
            push(&stack, s[i]);
        }

        while(!isEmpty(stack)){
            
        }

    return 0;
}
