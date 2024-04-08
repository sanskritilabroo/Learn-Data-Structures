#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void palindrome(char *p, int n)
{
    char *first = p;
    char *last = p + n - 1;
    bool flag = true;

    while (first < last)
    {
        if (*first != *last) // Compare characters, not pointers
        {
            flag = false;
            break;
        }
        first++;
        last--;
    }

    if (flag)
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");
}

int main()
{
    int n;
    printf("Enter string length: ");
    scanf("%d", &n);
    char *arrptr = (char *)calloc(n + 1, sizeof(char)); // +1 for the null terminator


    printf("Enter string: ");
    scanf("%s", arrptr); // Use %s to read a string and no & for string inputs

    n = strlen(arrptr);
    palindrome(arrptr, n);

    free(arrptr);
    return 0;
}