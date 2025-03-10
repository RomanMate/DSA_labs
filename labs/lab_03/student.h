//
// Created by Román Máté on 2025. 03. 03..
//

#ifndef STUDENT_H
#define STUDENT_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef enum {
    Male,Female
}Gender_t;

typedef struct {
    int yearOfBirth;
    int monthOfBirth;
    int dayOfBirth;
} Date_t;

typedef struct {
    char name[51];
    char neptunCode[9];
    char birthPlace[26];
    Date_t dateOfBirth;
    Gender_t gender;
    float examResult;
} Student_t;

/**
* Reads all details of a student, student must be passed by reference
* @param pStudent - pointer to a student
*/
void readStudentDetails(Student_t *pStudent);
/**
2
* Prints all details of a student
* @param student
*/
void printStudent(Student_t student);

char* getGender(Gender_t gender);

inline void allocateMemoryForStudents(Student_t** dpStudents,int numberOfStudents);
void readAllStudentsDetails(Student_t **dpStudents, int *numberOfStudents, const char *input);
void printAllStudents(Student_t *pStudents, int numberOfStudents, const char *destination);
void printAllStudents(Student_t *pStudents, int numberOfStudents, const char *destination);
void calculatePercentageBoysGirls (Student_t **dpStudents, int numberOfStudents);
void deallocate(Student_t **pStudent);

#endif
