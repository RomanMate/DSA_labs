#include <stdio.h>

int main(void) {
    int a;
    scanf("%i",&a);
    sum(a%10,a/10);
    return 0;
}
