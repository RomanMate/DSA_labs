//
// Created by balin on 2025. 02. 24..
//

#ifndef ARRAY_FUNCTIONS_H
#define ARRAY_FUNCTIONS_H

/**
 * Kiszamolja ket szam osszeget.
 * @param number1 elso szam
 * @param number2 masodik szam
 * @return ket szam osszeget
 */
int sum(int number1, int number2);

/**
 * kimutatja harom szam kozul a legkisebbet
 * @param number1 elso szam
 * @param number2 masodik szam
 * @param number3 harmadik szam
 * @return legkisebb szam (minimum)
 */
float minimum(float number1, float number2, float number3);

/**
 * n elemu tomb helyfoglalasa dinamikusan
 * @param n az elemek szama
 * @return a lefoglalt memoriacimet
 */
int* allocateMemoryForArray1(int n);

/**
 * n elemu tomb helyfoglalasa dinamikusan
 * @param n az elemek szama
 * @param dpArray dupla pointer
 */
void allocateMemoryForArray2(int n, int** dpArray);

void readArray(int *pn, int **dpArray, const char *input);

void printArray(int n, int *pArray, const char *output);

void deallocateMemoryForArray(int **dpArray);


#endif //ARRAY_FUNCTIONS_H
