#include <stdio.h>
#include <stdlib.h>
#define max 10
typedef struct
{
    int top;
    int data[max];
}Stack;

void initialize(Stack *stack)
{
    stack->top=-1;
}

int isFull(Stack *stack)
{
    if(stack->top==max-1) return 1;
    else return 0;
}
int isEmpty(Stack *stack)
{
    if(stack->top==-1) return 1;
    else return 0;
}

void push(Stack *stack,int c)
{
    if(isFull(stack))
        printf("Stack overflow");
    else
    {
       stack->top++;
       stack->data[stack->top]=c;
    }
}

int pop(Stack *stack)
{
    if(isEmpty(stack))
        printf("Stack underflow");
    else
    {
        int item=stack->data[stack->top];
        stack->top--;
        return item;
    }
}

void dectobin(int n)
{
    Stack stack;
    initialize(&stack);
    while(n>=1)
    {
        int d=n%2;
        push(&stack,d);
        n=n/2;
    }
    push(&stack,n);
    while(stack.data[stack.top]!=-1)
        printf("%d",pop(&stack));
}

void main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    dectobin(n);
}
