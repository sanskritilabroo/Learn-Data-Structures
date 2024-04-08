#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *l, *r;
}Node;

typedef struct stack
{
    Node* nodes[20];
    int top;
}Stack;

void push(Stack *s, Node *temp)
{
    s->nodes[++s->top] = temp;
}

Node* pop(Stack *s)
{
    return s->nodes[s->top--];
}

Node* getNode(int val)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = val;
    newnode->l = newnode->r = NULL;
    return newnode;
}

Node* createTree(int val)
{
    int lc,rc;
    if (val!=-1)
    {
        Node *newnode = getNode(val);
        printf("Enter left child of %d : ", val);
        scanf("%d",&lc);
        newnode->l = createTree(lc);
        printf("Enter right child of %d : ", val);
        scanf("%d",&rc);
        newnode->r = createTree(rc);
        return newnode;
    }
    else
    return NULL;
}

void inorder(Node* root)
{
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->top = -1;
    Node *curr = root;
    while(curr!=NULL || s->top!=-1)
    {
        while(curr)
        {
            push(s, curr);
            curr = curr->l;
        }
        if (s->top!=-1)
        {
            curr = pop(s);
            printf("%d \t",curr->data);

            curr = curr->r;
        }

    }
}

void preorder(Node* root)
{
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->top = -1;
    Node *curr = root;
    push(s,curr);
    while(s->top!=-1)
    {
        curr = pop(s);
        printf("%d \t", curr->data);
        if(curr->r!=NULL) push(s,curr->r);
        if(curr->l!=NULL) push(s, curr->l);
    }
}

int main()
{
    int val;
    printf("Enter data: ");
    scanf("%d", &val);
    Node *root = createTree(val);
    inorder(root);
    printf("\n");
    preorder(root);
    return 0;
}