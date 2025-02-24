//
// Created by Román Máté on 2025. 02. 17..
//

#ifndef FUNCTION_H
#define FUNCTION_H

/**
 * Kiszamolja ket szam osszeget
 * @param number1 elso szam
 * @param number2 masodik szam
 * @return  a ket szam osszege
 */
int sum(int number1,int number2);



/**
 * Minimumot keres
 * @param number1 elso szam
 * @param number2 masodik szam
 * @param number3 harmadik szam
 * @return a legkisebb szam (min)
 */
float minimum(float number1, float number2, float number3);



/**
 * n elemu tomb helyfoglalasa dinamikusan
 *
 * @param n az elemek szama
 * @return lefoglalt memoriacimet
 */
int* allocateMemoryForArray1(int n);

/**
 *
 * @param n
 * @param dpArray
 */
void allocateMemoryForArray2(int n, int **dpArray);

/**
 *
 * @param pn
 * @param dpArray
 * @param input
 */
void readArray(int* pn, int** dpArray, const char* input);

/**
 *
 * @param n
 * @param pArray
 * @param output
 */
void printArray(int n, int* pArray, const char* output);

/**
 *
 * @param dpArray
 */
void deallocateMemoryForArray(int** dpArray);

#endif