#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node
{
    char p;
    struct node *l, *r;
} Node;

typedef struct stack
{
    Node *nodes[20];
    int top;
} Stack;

void push(Stack *s, Node *temp)
{
    s->nodes[++s->top] = temp;
}

Node *pop(Stack *s)
{
    return s->nodes[s->top--];
}

Node *getNode(char p1)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->p = p1;
    newnode->l = newnode->r = NULL;
    return newnode;
}

Node *prefix(char *p)
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = -1;

    for (int i = strlen(p) - 1; i >= 0; i--)
    {
        char c = p[i];
        Node *temp = getNode(c);

        if (isalnum(c))
            push(s, temp);
        else
        {
            temp->l = pop(s);
            temp->r = pop(s);
            push(s, temp);
        }
    }
    return pop(s);
}

void display(Node *root)
{
    if (root)
    {
        printf("(");
        display(root->l);
        printf("%c", root->p);
        display(root->r);
        printf(")");
    }
}

int eval(Node *root)
{
    if (root->l == NULL && root->r == NULL)
    {
        return root->p - '0';
    }
    else if (root == NULL)
    {
        return 0;
    }
    else
    {
        switch (root->p)
        {
        case '+':
            return eval(root->r) + eval(root->l);
            break;
        case '-':
            return eval(root->r) - eval(root->l);
            break;
        case '*':
            return eval(root->r) * eval(root->l);
            break;
        case '/':
            return eval(root->r) / eval(root->l);
            break;
        }
    }
}

int main()
{
    printf("Enter expression : ");
    char *p = (char *)malloc(20);
    scanf("%s", p);

    Node *root = prefix(p);
    display(root);
    printf("\nEvaluated expression : %d", eval(root));

    return 0;
}
