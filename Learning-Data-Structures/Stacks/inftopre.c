#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX_SIZE 20

char stack[MAX_SIZE];
int top = -1;

void push(char ch)
{
    top++;
    stack[top] = ch;
}

char pop()
{
    char x;
    x = stack[top];
    top--;
    return x;
}

char peek()
{
    char t;
    t = stack[top];
    return t;
}

int precedence(char p)
{
    switch (p)
    {
    case '(':
        return 2;
    case '+':
    case '-':
        return 3;
    case '*':
    case '/':
        return 4;
    case '^':
        return 5;
    }
    return 1;
}

void reverse(char *c)
{
    int n = strlen(c);
    for (int i = 0; i < n / 2; i++)
    {
        char temp = c[i];
        c[i] = c[n - i - 1];
        c[n - i - 1] = temp;
    }
    for (int i = 0; i < strlen(c); i++)
    {
        if (c[i] == '(')
            c[i] = ')';
        else if (c[i] == ')')
            c[i] = '(';
    }
}

void evaluate(char c[])
{
    char str[50];
    int x = 0;
    for (int i = 0; c[i] != '\0'; i++)
    {
        if (isalpha(c[i]))
        {
            str[x++] = c[i];
        }
        else
        {
            if (c[i] == '(')
            {
                push(c[i]);
            }
            else if (c[i] == ')')
            {
                while (peek() != '(')
                {
                    str[x++] = pop();
                }
                pop();
            }
            else if (top == -1)
            {
                push(c[i]);
            }
            else
            {
                while (precedence(peek()) >= precedence(c[i]))
                {
                    str[x++] = pop();
                }
                push(c[i]);
            }
        }
    }
    while (top != -1)
    {
        str[x++] = pop();
    }
    str[x] = '\0';
    reverse(str);
    printf("Prefix=%s", str);
}

int main()
{
    char exp[50];
    printf("Enter expression\n");
    scanf("%s", exp);
    reverse(exp);
    evaluate(exp);
    return 0;
}