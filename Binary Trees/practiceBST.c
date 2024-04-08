#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *lchild, *rchild;
}Node;

Node* getNode(int val)
{
    Node *nn = (Node*)malloc(sizeof(Node));
    nn->data = val;
    nn->lchild = nn->rchild = NULL;
    return nn;
}

Node* createBT(Node *root, int val)
{
    if (root == NULL)
    {
        root = getNode(val);
    }
    else
    {
        if(root->data > val)
        root->lchild = createBT(root->lchild,val);
        else if(root->data < val)
        root->rchild = createBT(root->rchild,val);
        else
        printf("No duplicates allowed");
    }
    return root;
}



void display(Node* root)
{
    if (root)
    {
        display(root->lchild);
        printf("%d",root->data);
        display(root->rchild);
    }
}



void main()
{
    int ch,val;
    Node *root;
    do
    {    
        printf("Enter 1 to insert element and 0 to display \n");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("Enter data");
            scanf("%d",&val);
            root = createBT(root,val);
        }
        if(ch==0)
        {
            display(root);
        }
    } while (ch == 0);

    //printf("Enter an element ");
    int element = 3;
    root = createBT(root,3);
}