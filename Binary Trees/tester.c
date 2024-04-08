#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *r,*l;
}Node;

Node *getNode()
{
    Node *newnode = malloc(sizeof(Node));
    return newnode;
}

Node *createTree(Node *root, int val)
{
    if (root == NULL)
    {
        root = getNode();
        root->data = val;
        root->r = root->l = NULL;
    }
    else
    {
        if (root->data > val)
        root->l = createTree(root->l,val);
        else if (root->data < val)
        root->r = createTree(root->r,val);
        else
        printf("Duplicates not allowed");
    }
    return root;
}

void display(Node *root)
{
    if(root)
    {
        display(root->l);
        printf("%d \t",root->data);
        display(root->r);
}
}

void main()
{
    Node *root=NULL;
    int n,item;
    do
    {
        printf("Enter 0 to display and 1 to enter :\n");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            printf("Enter value : ");
            scanf("%d",&item);
            root=createTree(root,item);
            break;
        case 0:
            display(root);
            exit(0);
        }
    }while(1);
}
