#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>  // Include this for isdigit() function
#define max 20

typedef struct
{
    int top;
    int data[max];
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

void push(Stack *stack, int data)
{
    if (isFull(stack))
        printf("Stack overflow...");
    else
    {
        stack->top++;
        stack->data[stack->top] = data;
    }
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow...");
        return -1;  // Return a sentinel value to indicate an error
    }
    else
    {
        int item = stack->data[stack->top];
        stack->top--;
        return item;
    }
}

int isoperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int evaluate(char c[])
{
    Stack stack;
    initialize(&stack);
    int v1,v2,res=0;
    for(int i=strlen(c)-1;i>=0;i--)
    {
        char ch=c[i];
        if(isdigit(ch))
        {
            int d=ch-'0';
            push(&stack,d);
        }
        else if(isoperator(ch))
        {
            v1=pop(&stack);
            v2=pop(&stack);
            switch(ch)
            {
            case '+':
                res=v1+v2;
                push(&stack,res);
                break;
            case '-':
                res=v1-v2;
                push(&stack,res);
                break;
            case '*':
                res=v1*v2;
                push(&stack,res);
                break;
            case '/':
                res=v1/v2;
                push(&stack,res);
                break;
            }

        }
    }
    return pop(&stack);
}

void main()
{
    char c[20];
    printf("Enter prefix expression: ");
    scanf("%s",c);
    printf("Result=%d",evaluate(c));
}
