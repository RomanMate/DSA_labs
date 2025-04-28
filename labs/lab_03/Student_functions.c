//
// Created by balin on 2025. 03. 03..
//

#include "Student_functions.h"
#include <stdio.h>
#include <stdlib.h>

void readStudentDetails(Student_t* pStudent)
{
    scanf("%[^\n]\n", pStudent->name);
    scanf("%s\n", pStudent->neptunCode);
    scanf("%[^\n]\n", pStudent->birthPlace);
    scanf("%i%i%i\n", &pStudent->dateOfBirth.year, &pStudent->dateOfBirth.month, &pStudent->dateOfBirth.day);
    scanf("%i\n", &pStudent->gender);
    scanf("%f\n", &pStudent->examResult);
}

void printStudent(Student_t student)
{
    printf("%s\n", student.name);
    printf("%s\n", student.neptunCode);
    printf("%s\n", student.birthPlace);
    printf("%i %i %i\n", student.dateOfBirth.year, student.dateOfBirth.month, student.dateOfBirth.day);
    printf("%s\n", getGender(student.gender));
    printf("%.2f\n", student.examResult);
}

char *getGender(enum Gender gender) {
    switch (gender) {
        case 0: return "Male";
        case 1: return "Female";
        default: return "Error!";
    }
}

void allocateMemoryForStudents(Student_t **dpStudents, int numberOfStudents) {
    *dpStudents=(Student_t*)malloc(numberOfStudents*sizeof(Student_t));
    if (!(*dpStudents)) {
        printf("Memory allovation error");
        exit(-1);
    }
}

void readAllStudentsDetails(Student_t **dpStudents, int *numberOfStudents, const char *input) {
    if (!freopen(input, "r", stdin)) {
        printf("Hiba a beolvasasnal");
        exit (-1);
    }
    scanf("%i\n", numberOfStudents);
    allocateMemoryForStudents(dpStudents, *numberOfStudents);
    for (int i=0; i<*numberOfStudents; i++) {
        readStudentDetails(&(*dpStudents)[i]);
    }
    freopen("CON", "r", stdin);
}

void printAllStudents(Student_t *pStudents, int numberOfStudents, const char *destination) {
    freopen(destination, "w", stdout);
    for (int i=0; i<numberOfStudents; i++) {
        printStudent(pStudents[i]);
    }
    freopen("CON", "w", stdout);
}
