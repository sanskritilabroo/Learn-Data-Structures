#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}Node;

Node *top = NULL;

void push()
{
    if(top==NULL)
    {
        top = malloc(sizeof(Node));
        printf("Enter item : ");
        scanf("%d",&top->data);
        top->link = NULL;
    }
    else
    {
        Node *newnode = malloc(sizeof(Node));
        printf("Enter data : ");
        scanf("%d",&newnode->data);
        newnode->link = top;
        top = newnode;//insert from front for a stack so that when popping the first element gets deleted from rear rather than the first one
    }
}

void pop()
{
    if(top!=NULL)
    {
        printf("Popped=%d",top->data);
        top=top->link;
    }
    else
    {
        printf("Stack is empty");
    }
}


void display()
{
    Node *curr;
    curr=top;
    while(curr!=NULL)
    {
        printf("%d\t",curr->data);
        curr=curr->link;
    }
}

int main()
{
    int n,no=1;
    while(no)
    {
        printf("1-push,2-pop,3-display\n");
        scanf("%d",&n);

        switch(n)
        {
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
        }
        printf("Do you want to continue 0 or 1\n");
        scanf("%d",&no);
    }
    return 0;
}