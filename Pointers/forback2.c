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
    int *start = p + n - 1;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(start - i)); // Added format specifier and space
    }
    printf("\n"); // Added newline at the end
}

int main()
{
    int n;
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