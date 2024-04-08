//eg +23*76
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef struct
{
    int data[MAX];
    int top;
}Stack;

void init(Stack *s)
{
    s->top = -1;
}
int isEmpty(Stack *s)
{
    return (s->top == -1);
}

int isFull(Stack *s)
{
    return (s->top == MAX-1);
}
void push(Stack *s, int item)
{
    if (isFull(s))
    {
        printf("Overflow\n");
    }
    else
    {
        s->data[++s->top] = item;
    }
}

int pop(Stack *s)
{    
    if (isEmpty(s))
    {
        printf("Underflow\n");
    }
    else
    {
        int item = s->data[s->top--];
        return item;
    }
}

int evaluate(int op1, int op2,char op)
{
    if (op == '+')
    return (op1+op2);
    if (op == '-')
    return (op1-op2);
    if (op == '/')
    return (op1/op2);
    if (op == '*')
    return (op1*op2);
}

int main()
{
    Stack *s; 
    char expr[100];
    init(s);
    printf("Enter a prefix expression: ");
    scanf("%s",expr);
    int i;
    //traverse expression right to left
    for (i = strlen(expr)-1; i>=0; i--)
    {
        char ch = expr[i];
        printf("%c",ch);
        if (ch == '+' ||ch == '-' || ch == '*' || ch == '/')
        {
            int op2 = pop(s);
            int op1 = pop(s);
            int item = evaluate(op1,op2,ch);
            //printf("%d",item);
            push(s, item);
        }
        else if (ch >= '0' && ch <= '9') // Use character literals ('0' and '9') instead of ASCII values
        {
            int x = ch - '0';//convert char to int
            push(s, x);
        }
    }
    printf("Result: %d", s->data[0]);
    return 0;
}