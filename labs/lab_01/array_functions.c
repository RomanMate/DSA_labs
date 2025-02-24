//
// Created by Román Máté on 2025. 02. 17..
//

#include "array_functions.h"

#include <stdio.h>
#include <stdlib.h>

int sum(int number1,int number2){
    return number1+number2;
}
float minimum(float number1, float number2, float number3) {
    float min = number1;
    if (number2 < min) { min = number2; }
    if (number3 < min) { min = number3; }
    return min;
}

int* allocateMemoryForArray1(int n) {
    int *array;
    array=(int*)malloc(n*sizeof(int));
    if(array==NULL) {
        printf("memory allocation failed");
        return NULL;
    }
    return array;
}

void allocateMemoryForArray2(int n, int** dpArray)
{
    *dpArray = (int*)malloc(n * sizeof(int));
    if (!(*dpArray))
    {
        printf("Memory allocation error");
        exit(-1);
    }
}

void readArray(int* pn, int** dpArray, const char* input)
{
    if (!freopen(input, "r",stdin))
    {
        exit(-2);
    }
    scanf("%i", pn);

    allocateMemoryForArray2(*pn, dpArray);
    for (int i = 0; i < *pn; i++)
    {
        scanf("%i", &((*dpArray)[i]));
        //scanf("%i",*dpArray+i);
    }
    freopen("CON", "r",stdin);
}

void printArray(int n, int* pArray, const char* output)
{
    freopen(output, "w",stdout);
    for (int i = 0; i < n; i++)
    {
        printf("%i ", pArray[i]);
        //printf("%i ",*(pArray+i));
    }
    printf("\n");
    freopen("CON", "w",stdout);
}

void deallocateMemoryForArray(int** dpArray)
{
    free(*dpArray);
    *dpArray = NULL;
}
