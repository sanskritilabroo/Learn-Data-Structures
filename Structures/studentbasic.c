#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
	char name[30];
	int roll;
	int cgpa;
}student;

student readone(struct student stud)
{
	printf("Enter name, roll number and cgpa of student: \n");
	scanf("%s %d %d",stud.name, &stud.roll, &stud.cgpa);
	return (stud);
}
void displayone(struct student stud)
{
	printf("Name: %s \n", stud.name);
	printf("Roll Number: %d \n", stud.roll);
	printf("CGPA: %.d \n", stud.cgpa);

}
student* readmany(struct student *students, int n)
{
	for(int i=0; i<n; i++)
	{
		scanf("%s", (students+i) -> name); //or *(students+i).name (students+i) -> name)
		scanf("%d", &(students+i) -> roll);
		scanf("%d", &(students+i) -> cgpa);
	}
	return (students);
}
student sorted(struct student *students, int n)
{
	struct student temp;
	for (int i=0; i<n-1; i++){
		for (int j=0; j<n-1+i; j++){
			if (students[j].roll > students[j+1].roll)
			{
				temp = students[j].roll;
				students[j].roll = students[j+1].roll;
				students[j+1].roll = temp;
			}
		}
	}
}

int main()
{
	int n;
	struct student stud;
	printf("Enter number of students: \n");
	scanf("%d",&n);
	displayone(readone(stud));

	student *students = (student*)calloc(n,sizeof(student)); //pointer for array of structures
	printf("Enter name, roll number and cgpa of students: \n");
	sorted(reamdany(students, n),n);
}
