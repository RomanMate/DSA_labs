//
// Created by Román Máté on 2025. 03. 03..
//

#include "student.h"


void readStudentDetails(Student_t *pStudent) {
    printf("Enter name: ");
    scanf("%[^\n]",pStudent->name);

    printf("Enter Neptun code: ");
    scanf("%s", pStudent->neptunCode);

    printf("Enter birth place: ");
    scanf("%s",pStudent->birthPlace);

    printf("Enter birth date: ");
    scanf("%d %d %d", &pStudent->dateOfBirth.yearOfBirth,&pStudent->dateOfBirth.monthOfBirth,&pStudent->dateOfBirth.dayOfBirth);

    printf("Enter gender (0 - MALE, 1 - FEMALE): ");
    //int genderstudent;
    scanf("%i",&pStudent->gender);
    //pStudent->gender=(Gender_t)genderstudent;


    printf("Enter exam result: \n");
    scanf("%lf", &pStudent->examResult);
}

void printStudent(Student_t student) {
    printf("Name: %s\nNeptun: %s\nBirthplace: %s\nYear: %d\nMonth: %d\nDay: %d\nGender: %s\nExam Result: %.2f\n",
           student.name, student.neptunCode, student.birthPlace,
           student.dateOfBirth.yearOfBirth,student.dateOfBirth.monthOfBirth,student.dateOfBirth.dayOfBirth,
           getGender(student.gender),
           student.examResult);
}
char* getGender(Gender_t gender) {
        switch (gender) {
            case 0: return "Male";
            case 1: return "Female";
            default: return "Error";
        }
}

void allocateMemoryForStudents(Student_t **dpStudents, int numberOfStudents) {
    *dpStudents = (Student_t *)malloc(numberOfStudents * sizeof(Student_t));
    if (*dpStudents == NULL) {
        perror("Memóriafoglalási hiba");
        exit(EXIT_FAILURE);
    }
}

void readAllStudentsDetails(Student_t **dpStudents, int *numberOfStudents, const char *input) {
    FILE *file = NULL;
    if (strcmp(input, "CON") == 0) {
        printf("Adja meg a diákok számát: ");
        scanf("%d", numberOfStudents);
        allocateMemoryForStudents(dpStudents, *numberOfStudents);
        for (int i = 0; i < *numberOfStudents; i++) {
            printf("%d. diák adatai:\n", i + 1);
            readStudentDetails(&(*dpStudents)[i]);
        }
    } else {
        file = fopen(input, "r");
        if (!file) {
            perror("Hiba az állomány megnyitásakor");
            exit(EXIT_FAILURE);
        }
        fscanf(file, "%d", numberOfStudents);
        allocateMemoryForStudents(dpStudents, *numberOfStudents);
        for (int i = 0; i < *numberOfStudents; i++) {
            fscanf(file, "%50s %8s %25s %d %d %f", (*dpStudents)[i].name, (*dpStudents)[i].neptunCode, (*dpStudents)[i].birthPlace, &(*dpStudents)[i].dateOfBirth.yearOfBirth, (int *)&(*dpStudents)[i].gender, &(*dpStudents)[i].examResult);
        }
        fclose(file);
    }
}

void printAllStudents(Student_t *pStudents, int numberOfStudents, const char *destination) {
    FILE *file = NULL;
    if (strcmp(destination, "CON") == 0) {
        for (int i = 0; i < numberOfStudents; i++) {
            printStudent(pStudents[i]);
        }
    } else {
        file = fopen(destination, "w");
        if (!file) {
            perror("Hiba az állomány megnyitásakor");
            exit(EXIT_FAILURE);
        }
        for (int i = 0; i < numberOfStudents; i++) {
            fprintf(file, "Név: %s\nNEPTUN kód: %s\nSzületési hely: %s\nSzületési év: %d\nNem: %s\nVizsgaátlag: %.2f\n\n",
                    pStudents[i].name, pStudents[i].neptunCode, pStudents[i].birthPlace,
                    pStudents[i].dateOfBirth.yearOfBirth, (pStudents[i].gender == MALE) ? "Férfi" : "Nő",
                    pStudents[i].examResult);
        }
        fclose(file);
    }
}