#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *link;
}Node;

Node *head = NULL;
Node *curr;

void deleteend()
{
    curr = head;
    while(curr->link->link != NULL)
    {
        curr = curr->link;
    }
    free(curr->link);
    curr->link = NULL;
}



void deletemid(int key)
{
    curr = head;
    while(curr->data != key)
    {
        curr = curr->link;
    }
    free(curr);
    curr->link = NULL;
}



void deletestart()
{
    curr = head;
    head = head->link;
    free(curr);
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
    int key;
    do
    {
        printf("1. Delete at end, 2. Delete in middle, 3.Delete at start, 4.Display");
        scanf("%d",&ch);

        if(ch == 1)
        {
            deleteend();
        }

        if(ch == 2)
        {
            printf("Enter key: ");
            scanf("%d",&key);
            deletemid(4);
        }

        if(ch == 3)
        {
            deletestart();
        }

        if(ch == 4)
        {
            display();
            exit(0);
        }
    } while (ch!=4);
}