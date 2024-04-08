#include <stdio.h>
#include <stdlib.h>

void forward(int *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(p + i)); // Added format specifier and space
    }
    printf("\n"); // Added newline at the end
}

void backward(int *p, int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        printf("%d ", *(p + i)); // Added format specifier and space
    }
    printf("\n"); // Added newline at the end
}

int main()
{
    int n, *pf, *pb;
    int *arrptr;
    printf("Enter value of n:\n");
    scanf("%d", &n);
    arrptr = (int *)calloc(n, sizeof(int));
    printf("Enter elements:");
    for (int i = 0; i < n; i++)
        scanf("%d", &arrptr[i]);
    
    printf("Forward: ");
    forward(arrptr, n);
    
    printf("Backward: ");
    backward(arrptr, n);
    
    free(arrptr);
    return 0;
}