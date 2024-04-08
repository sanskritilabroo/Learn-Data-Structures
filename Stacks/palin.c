#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 10
typedef struct
{
    int top;
    char data[max];
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

void push(Stack *stack,char c)
{
    if(isFull(stack))
        printf("Stack overflow");
    else
    {
       stack->top++;
       stack->data[stack->top]=c;
    }
}

char pop(Stack *stack)
{
    if(isEmpty(stack))
        printf("Stack underflow");
    else
    {
        char item=stack->data[stack->top];
        stack->top--;
        return item;
    }
}

int isPalin(char str[])
{
    int flag=1;
    Stack stack;
    for(int i=0;i<strlen(str);i++)
    {
        push(&stack,str[i]);
    }
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]==pop(&stack)) continue;
        else flag=0;
    }
    return flag;
}

void main()
{
    char str[10];
    printf("Enter a word : ");
    scanf("%s",&str);
    if(isPalin(str)) printf("The word is a palindrome");
    else printf("The word is not a palindrome");
}
