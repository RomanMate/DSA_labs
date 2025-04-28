#include <stdio.h>
#include "array_functions.h"

int main(void)
{
    //1
    int szam, osszeg=0;
    scanf("%i", &szam);
    while (szam) {
        int szam_jegy=szam%10;
        osszeg=sum(szam_jegy, osszeg);
        szam=szam/10;
    }
    printf("A szamjegyek osszege: %i", osszeg);

    //2


    return 0;
}