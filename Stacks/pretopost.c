#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define max 20

typedef struct
{
    int top;
    char data[max][max];
} Stack;

void initialize(Stack *stack)
{
    stack->top = -1;
}

int isFull(Stack *stack)
{
    return stack->top == max - 1;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

void push(Stack *stack, char d[])
{
    if (isFull(stack))
        printf("Stack overflow...");
    else
    {
        stack->top++;
        strcpy(stack->data[stack->top], d);
    }
}

char* pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow...");
        return "";                     // whem error
    }
    else
    {
        char* item = stack->data[stack->top];
        stack->top--;
        return item;
    }
}

int isoperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void evaluate(char pos[])
{
    char temp[2];
    char strin[max];
    char* op1;
    char* op2;
    char ch;
    Stack stack;
    initialize(&stack);

    for (int i = 0; pos[i] != '\0'; i++)
    {
        ch = pos[i];
        temp[0] = ch;
        temp[1] = '\0';
        if (isalpha(ch))
            push(&stack, temp);
        else if (isoperator(ch))
        {
            op1 = pop(&stack);
            op2 = pop(&stack);
            strcpy(strin, temp);
            strcat(strin, op2);
            strcat(strin, op1);          //last three lines- operator+op2+op1
            push(&stack, strin);
        }
    }
    printf("\nPrefix Expression: %s\n", stack.data[0]);
}

int main()
{
    char c[max];
    printf("Enter postfix:\n");
    gets(c);
    evaluate(c);
    return 0;
}