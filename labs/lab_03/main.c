#include <stdio.h>
#include "library.h"
#include "Student_functions.h"

int main(void) {
    /*Student_t student1;
    readStudentDetails(&student1);
    printStudent(student1);*/
    //ertekadas hardcorral
    /*Student_t student2 = {"Varga Mate", "ZRT78", "Kolovar", {2004, 5, 6}, 0, 7.65};
    printStudent(student2);*/

    //adatok beolvasasa allomanybol
    /*Student_t student3;
    if (!freopen("egydiak.txt", "r", stdin)) {
        printf("Hiba az allomanynal!");
        return -1;
    }

    readStudentDetails(&student3);
    printStudent(student3);*/

    Student_t *array;
        int n;
        readAllStudentsDetails(&array, &n, "students.txt");
        printAllStudents(array, n, "CON");

    return 0;
}