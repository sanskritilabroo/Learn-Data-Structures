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

void display(const struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack contents: ");
    for (int i = 0; i <= stack->top; ++i) {
        printf("%c ", stack->data[i]);
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    initialize(&stack);

    int choice;
    char item;

    do {
        printf("1.Push\t");
        printf("2.Pop\t");
        printf("3.Display\t");
        printf("4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a character to push: ");
                scanf(" %c", &item);
                push(&stack, item);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                display(&stack);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}













