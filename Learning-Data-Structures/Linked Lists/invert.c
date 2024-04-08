#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}Node;

Node *head = NULL;
Node *curr = NULL;

void insert(int item)
{
    Node *newnode = malloc(sizeof(Node));
    while(curr!=NULL)
    {
        curr = curr->link;
    }
    curr->link = newnode;
    newnode->link = NULL;
    curr = newnode;
    free(newnode);

}

Node* invert(Node *lead)
{
    Node *middle = NULL;
    Node *trail;
    while (lead) {
    trail = middle;
    middle = lead;
    lead = lead->link;
    middle->link = trail;
    }
    return middle;
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
