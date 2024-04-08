#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

struct Stack {
    char data[MAX_SIZE];
    int top;
};

void initialize(struct Stack *stack) {
    stack->top = -1;
}

bool isEmpty(const struct Stack *stack) {
    return stack->top == -1;
}

bool isFull(const struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack *stack, char item) {
    if (isFull(stack)) {
        printf("Error: Stack overflow\n");
        return;
    }
    stack->data[++stack->top] = item;
    printf("Pushed %c onto the stack\n", item);
}

char pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack underflow\n");
        return '\0';
    }
    char item = stack->data[stack->top--];
    printf("Popped %c from the stack\n", item);
    return item;
}

void main()
{
    char expn[25], c, d;
    int i = 0;
    struct Stack s;
    s.top = -1;

    printf("\n Enter the expression: ");
    gets(expn);

    while ((c = expn[i++]) != '\0')
    {
        if (c == '(')
            push(&s, c);
        else if (c == ')')
        {
            d = pop(&s);
            if (d != '(')
            {
                printf("\n Invalid Expression");
                break;
            }
        }
    }

    if (empty(&s))
        printf("\n Balanced Expression");
    else
        printf("\n Not a Balanced Expression");
}
