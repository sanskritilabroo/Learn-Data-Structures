#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[100];
    int *p;

}Student;

void main()
{
    int n;
    printf("Enter number of students: ");
    scanf("%d",&n);
    Student *student[n];
    for(int i=0;i<n;i++)
    {
        student[i]=(Student*)malloc(sizeof(Student));

        printf("Enter name for student %d : ",i+1);
        scanf("%s",student[i]->name);

        printf("Enter number of marks for student %d : ",i+1);
        int m;
        scanf("%d",&m);
        student[i]->p=(Student*)malloc((m+1)*sizeof(int));
        student[i]->p[0]=m;
        printf("Enter marks:\n");
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&student[i]->p[j]);
        }
    }

    for(int i=0;i<n;i++)
    {
        printf("\nName=%s\n",student[i]->name);
        int max=0;
        printf("All marks:\n");
        for(int j=1;j<=student[i]->p[0];j++)
        {
            if(student[i]->p[j]>max)
                max=student[i]->p[j];

            printf("%d\t",student[i]->p[j]);
        }
        printf("\nMax=%d",max);
    }
}