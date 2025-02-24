#include <stdio.h>
#include "array_functions..h"
int main(void) {
    int a;
    scanf("%i",&a);
    printf("%i",sum(a%10,a/10));
    return 0;
}
