#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *link;
}Node;

Node *head=NULL;
Node *curr=NULL; //tail node, points to the recent most added node in the list



void insert(int data) //basically a create function (insert at end)
{
    Node *newnode = malloc(sizeof(Node));
    newnode->data = data;
    newnode->link = NULL;
    
    if(head == NULL) 
    head = curr = newnode;
    else
    {
        curr->link = newnode; //adding new node right after current one
        curr = newnode; //updating current
    }
}


void display()
{
    while(head!=NULL)
    {
        printf("%d\t",head->data);
        head = head->link;
    }
}


void main()
{
    int ch,item;
    do
    {
        printf("Enter 1 to enter element and 0 to stop and display:\n");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("Enter element: ");
            scanf("%d",&item);
            insert(item);
        }
        if(ch==0)
        {
            display();
            exit(0);
        }
    }
    while(1);
}
