#include <stdio.h>
#include "array_functions.h"
int main(void) {
    printf("szumma: %i",sum(4,7));
    printf("\nmini:%.2f",minimum(3,8,2));
    int k, *array;
    readArray(&k,&array,"input.txt");
    printArray(k,array,"output.txt");
    return 0;
}

