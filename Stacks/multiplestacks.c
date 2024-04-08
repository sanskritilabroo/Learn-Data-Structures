#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *arr;
    int *top;
    int *b;
} Stack;

void init(Stack *s, int m, int n)
{
    s->arr = malloc(m * sizeof(int));
    s->top = malloc(n * sizeof(int));
    s->b = malloc((n + 1) * sizeof(int));
    s->top[0] = s->b[0] = -1;
    for (int i = 1; i < n; i++)
    {
        s->top[i] = s->b[i] = (m * i) / n;
    }
    s->b[n] = m - 1;
}

void push(Stack *s, int i, int item)
{
    if (s->top[i] + 1 == s->b[i + 1])
    {
        printf("Stack %d overflow\n", i + 1);
        return;
    }

    s->arr[++s->top[i]] = item;
}

int pop(Stack *s, int i)
{
    if (s->top[i] == s->b[i])
    {
        printf("Stack %d underflow\n", i + 1);
        return -1;
    }

    return s->arr[s->top[i]--];
}

void display(Stack *s, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Stack %d:\n", i + 1);
        for (int j = s->b[i] + 1; j <= s->top[i]; j++)
        {
            printf("%d\t", s->arr[j]);
        }
        printf("\n");
    }
}

void destroy(Stack *s)
{
    free(s->arr);
    free(s->top);
    free(s->b);
}

int main()
{
    int m, n;
    printf("Enter the total size of the array: ");
    scanf("%d", &m);
    printf("Enter the number of stacks: ");
    scanf("%d", &n);

    Stack s;
    init(&s, m, n);

    int choice, stackNum, item;

    do
    {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter stack number (1 to %d): ", n);
            scanf("%d", &stackNum);
            if (stackNum >= 1 && stackNum <= n)
            {
                printf("Enter item to push: ");
                scanf("%d", &item);
                push(&s, stackNum - 1, item);
            }
            else
            {
                printf("Invalid stack number\n");
            }
            break;

        case 2:
            printf("Enter stack number (1 to %d): ", n);
            scanf("%d", &stackNum);
            if (stackNum >= 1 && stackNum <= n)
            {
                int poppedItem = pop(&s, stackNum - 1);
                if (poppedItem != -1)
                {
                    printf("Popped item: %d\n", poppedItem);
                }
            }
            else
            {
                printf("Invalid stack number\n");
            }
            break;

        case 3:
            display(&s, n);
            break;

        case 4:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice\n");
        }
    } while (choice != 4);

    destroy(&s);

    return 0;
}