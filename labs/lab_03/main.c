#include <stdio.h>
#include "student.h"
int main(void) {
    //beolvasas billrol
    /*Student_t student1;
    readStudentDetails(&student1);
    printStudent(student1);*/
    Student_t student2={"Kis Imre","KKGGLOL","Marosvasarhely",{2004,11,05},0,7.50};
    printStudent(student2);
    Student_t student3;
    //if(freopen("diak3.txt","r",stdin))
    return 0;
}
