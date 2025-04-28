//
// Created by balin on 2025. 03. 03..
//

#include "utils.h"
#include <stdlib.h>

bool isPrime(int number) {
    int dbsz=0;
    for (int i=1; i<=number; i++) {
        if(number%i==0) {
            dbsz++;
        }
    }
    if (dbsz==2) {
        return 1;
    }
    else {
        return 0;
    }
}

bool isPalindrome(int number) {
    int ved_number, szamj_szama=0;
    ved_number=number;
    while (ved_number) {
        ved_number/=10;
        szamj_szama++;
    }
    int *t;
    t=(int *)malloc(szamj_szama*sizeof(int));
}