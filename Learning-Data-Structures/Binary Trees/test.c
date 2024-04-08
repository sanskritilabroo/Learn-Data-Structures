#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* l;
    struct node* r;
}Node;

Node* getNode(int val)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = val;
    newnode->l = newnode->r = NULL;
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

void display(Node *root)
{
    if (root)
    {
        display(root->l);
        display(root->r);
        printf("%d \t", root->data);
    }
}

void main()
{
    int val;
    Node *root;
    printf("Enter data: \n");
    scanf("%d",&val);
    root = createTree(val);
    printf("Original: \n");
    display(root);
}