
#include "array_functions.h"
int main(void) {
    int n, *array;
    readArray(&n,&array,"input.txt");
    printArray(n,array,"CON");
    return 0;
}

