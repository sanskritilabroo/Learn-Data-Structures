#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n,m;
    int **arr;
    printf("Enter no.of rows: ");
    scanf("%d",&n);
    arr=(int **)malloc(n*sizeof(int *));
    for(int i=0;i<n;i++)
    {
        printf("Enter no.of elements in row %d=",i+1);
        scanf("%d",&m);
        arr[i]=(int *)malloc((m+1)*sizeof(int));
        arr[i][0]=m; //first column of each row sotres the number of columns in thst row
        printf("Enter elements of row %d:\n ",i+1);

        for(int j=1;j<=m;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    printf("Ragged array:\n");

    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=arr[i][0];j++)
        {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }

}