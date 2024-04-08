#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct node
{
    char data;
    struct node *lchild, *rchild;
}Node;

typedef struct
{
    Node *arr[10];
    int top;
}Stack;

void push(Stack *s,Node *t)
{
    s->arr[++s->top]=t;
}
Node *pop(Stack *s)
{
    return s->arr[s->top--];
}
Node* getNode(char val)
{
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = val;
    newnode->lchild = newnode->rchild = NULL;
    return newnode;
}

Node * createBT(char *p)
{
    Stack *s=(Stack*)malloc(sizeof(Stack));
    s->top=-1;
    Node *root;
    for(int i=strlen(p)-1;p[i] >= 0;i++)
    {
        char ch = p[i];
        root = getNode(ch);
        if (isalnum(ch))
        {
            push(s,root);
        }
        else
        {
            root->lchild = pop(s);
            root->rchild = pop(s);
            push(s,root);
        }
    }
    return pop(s);
}

int eval(Node *root)
{
    if(root->lchild == NULL && root->rchild == NULL)
    {
        return (root->data - '0');
    }
    else
    {
        if (root->data == '*')
            return eval(root->lchild) * eval(root->rchild);
        if (root->data == '/')
            return eval(root->lchild) / eval(root->rchild);
        if (root->data == '+')
            return eval(root->lchild) + eval(root->rchild);
        if (root->data == '-')
            return eval(root->lchild) - eval(root->rchild);
    }
}