//
// Created by balin on 2025. 03. 03..
//

enum Gender{
  Male, Female
};

typedef struct {
    int year;
    int month;
    int day;
}Date_t;

typedef struct {
    char name[51];
    char neptunCode[9];
    char birthPlace[26];
    Date_t dateOfBirth;
    enum Gender gender;
    float examResult;
}Student_t;

#ifndef STUDENT_FUNCTIONS_H
#define STUDENT_FUNCTIONS_H

void printStudent(Student_t student);
void readStudentDetails(Student_t *pStudent);
char *getGender(enum Gender gender);
void allocateMemoryForStudents(Student_t **dpStudents, int numberOfStudents);
void readAllStudentsDetails(Student_t **dpStudents, int *numberOfStudents, const char *input);
void printAllStudents(Student_t *pStudents, int numberOfStudents, const char *destination);


#endif //STUDENT_FUNCTIONS_H
