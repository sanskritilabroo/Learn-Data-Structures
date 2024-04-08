#include <stdio.h>
#include <stdlib.h>


struct DOB {
    int day;
    int *month;
    int year;
};


struct STU_INFO {
    int reg_no;
    char *name;
    char *address;
};


struct COLLEGE {
    char *college_name;
    char *university_name;
};


struct STUDENT {
    struct DOB dob;
    struct STU_INFO stu_info;
    struct COLLEGE college;
};

int main() {
 
    struct STUDENT *student = (struct STUDENT *)malloc(sizeof(struct STUDENT));

   
    student->dob.month = (int *)malloc(sizeof(int));
    student->stu_info.name = (char *)malloc(50 * sizeof(char));
    student->stu_info.address = (char *)malloc(100 * sizeof(char));
    student->college.college_name = (char *)malloc(50 * sizeof(char));
    student->college.university_name = (char *)malloc(50 * sizeof(char));

    
    printf("Enter Date of Birth (day month year): ");
    scanf("%d %d %d", &student->dob.day, student->dob.month, &student->dob.year);
    printf("Enter Registration Number: ");
    scanf("%d", &student->stu_info.reg_no);
    printf("Enter Name: ");
    scanf("%s", student->stu_info.name);
    printf("Enter Address: ");
    scanf("%s", student->stu_info.address);
    printf("Enter College Name: ");
    scanf("%s", student->college.college_name);
    printf("Enter University Name: ");
    scanf("%s", student->college.university_name);

   
    printf("\nStudent Information:\n");
    printf("Date of Birth: %d/%d/%d\n", student->dob.day, *student->dob.month, student->dob.year);
    printf("Registration Number: %d\n", student->stu_info.reg_no);
    printf("Name: %s\n", student->stu_info.name);
    printf("Address: %s\n", student->stu_info.address);
    printf("College Name: %s\n", student->college.college_name);
    printf("University Name: %s\n", student->college.university_name);

    
    free(student->dob.month);
    free(student->stu_info.name);
    free(student->stu_info.address);
    free(student->college.college_name);
    free(student->college.university_name);
    free(student);

    return 0;
}
