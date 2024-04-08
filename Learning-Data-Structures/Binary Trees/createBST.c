#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *r,*l;
}Node;

Node *getnode(int item)
{
    Node *newnode = malloc(sizeof(Node));    
    newnode->data = item;
    newnode->r = newnode->l = NULL;
    return newnode;
}

Node *create(Node *newnode,int item)
{
    if(newnode == NULL)
    {
        newnode = getnode(item);
    }
    else
    {
        if(newnode->data > item)
            newnode->l = create(newnode->l,item);
        else if(newnode->data < item)
            newnode->r = create(newnode->r,item);
    }
    return newnode;
}


void display(Node *root)
{
    if(root!=NULL)
    {
        display(root->l);
        printf("%d\t",root->data);
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
            root=create(root,item);
            break;
        case 0:
            display(root);
            exit(0);
        }
    }while(1);
}
