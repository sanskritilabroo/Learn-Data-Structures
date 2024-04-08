#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *link;
}Node;

Node *head = NULL;
Node *curr = NULL;

void insertend(int data)
{
    Node *newnode = malloc(sizeof(Node));
    newnode->data = data;
    newnode->link = NULL;

    while(curr != NULL)
    {
        curr = curr->link;
    }
    curr->link = newnode;
    curr = newnode;

}



void insertmid(int data, int key)
{
    Node *newnode = malloc(sizeof(Node));
    newnode->data = data;
    newnode->link = NULL;

    while(newnode->data != key)
    {
        curr = curr->link;
    }
    curr->link = newnode;
    curr = newnode;
}



void insertstart(int data)
{
    Node *newnode = malloc(sizeof(Node));
    newnode->data = data;
    newnode->link = NULL;

    newnode->link = head;
    head = newnode;
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
    int ch;
    int item;
    do
    {
        printf("1. Insert at end, 2. Insert in middle, 3.Insert at start, 4.Display");
        scanf("%d",&ch);

        if(ch == 1)
        {
            printf("Enter element: ");
            scanf("%d",&item);
            insertend(item);
        }

        if(ch == 2)
        {
            printf("Enter element: ");
            scanf("%d",&item);
            insertmid(item, 4);
        }

        if(ch == 3)
        {
            printf("Enter element: ");
            scanf("%d",&item);
            insertstart(item);
        }

        if(ch == 4)
        {
            display();
            exit(0);
        }
    } while (ch!=4);
}