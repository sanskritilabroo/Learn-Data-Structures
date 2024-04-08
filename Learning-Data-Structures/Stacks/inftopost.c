#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 20

typedef struct {
    int top;
    char data[MAX_SIZE];
} Stack;

void init(Stack *s) {
    s->top = -1;
}

void push(Stack *s, char item) {
    if (s->top == MAX_SIZE - 1)
        return;
    else {
        s->data[++s->top] = item;
    }
}

char pop(Stack *s) {
    if (s->top == -1)
        return ' ';
    else {
        return s->data[s->top--];
    }
}

int precedence(char op) {
    if (op == '(')
        return 2;
    if ((op == '*') || (op == '/'))
        return 1;
    if ((op == '+') || (op == '-'))
        return 0;
}

char *eval(char *p) {
    Stack *s;
    s = (Stack *)(malloc(sizeof(Stack)));
    init(s);
    char *result = (char *)(malloc(strlen(p) + 1)); // Fix memory allocation
    int x = 0;
    for (int i = 0; p[i] != '\0'; i++) {
        char ch = p[i];
        if (ch == '(') {
            push(s, ch);
        } else if (ch == ')') {
            while (s->data[s->top] != '(') {
                result[x++] = pop(s);
            }
            pop(s);
        } else if (isalnum(ch)) {
            result[x++] = ch;
        } else {
            if (s->top == -1) {
                push(s, ch);
            } else {
                while (precedence(ch) <= precedence(s->data[s->top])) {
                    result[x++] = pop(s);
                }
                push(s, ch);
            }
        }
    }
    while (s->top != -1) {
        result[x++] = pop(s);
    }
    result[x] = '\0';
    free(s); // Free dynamically allocated memory for Stack
    return result;
}

int main() {
    char *exp = (char *)(malloc(20));
    char *postfix = (char *)(malloc(20));
    printf("Enter an infix expression:");
    scanf("%s", exp);
    postfix = eval(exp);
    printf("Postfix expression: %s\n", postfix);
    free(exp);     // Free dynamically allocated memory for exp
    free(postfix); // Free dynamically allocated memory for postfix
    return 0;
}