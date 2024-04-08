#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char* data; 
    struct node  *link;
}Node;

Node *head1 = NULL;
Node *tail1 = NULL;
Node *head2 = NULL;
Node *tail2 = NULL;
int ct = 0;

void create2(char* val)
{
    printf("%s added to waiting list \n",val);
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = (char*)malloc(strlen(val)+1);
    strcpy(newnode->data,val);
    newnode->link = NULL;
    if(head2 == NULL)
    {
        head2 = tail2 = newnode;
    }
    else
    {
        tail2->link = newnode;
        tail2 = newnode;
    }

}

void create1(char* val,int n)
{
    if(ct==n)
    {
        create2(val);
        return;
    }
    printf("%s added to hospital \n",val);
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = (char*)malloc(strlen(val)+1);
    strcpy(newnode->data,val);
    newnode->link = NULL;
    ct++;
    if(head1 == NULL)
    {
        head1 = tail1 = newnode;
    }
    else
    {
        tail1->link = newnode;
        tail1 = newnode;
    }
}

void delete()
{
    ct--;
    printf("Patient %s is releasd and %s is added to hospital\n",head1->data,head2->data);
    Node *curr = head2;
    head2=head2->link;
    head1=head1->link;
    tail1->link=curr;
}


void display()
{
    printf("HOSPITAL LIST: \n");
    Node* temp1 = head1; // Use temporary pointers
    while (temp1) {
        printf("%s\n", temp1->data);
        temp1 = temp1->link;
    }
    printf("WAITING LIST: \n");
    Node* temp2 = head2; // Use temporary pointers
    while (temp2) {
        printf("%s\n", temp2->data);
        temp2 = temp2->link;
    }
}

void main()
{
    int ch,n;
    char* val = (char*)malloc(20);
    printf("Enter hospital capacity: \n");
    scanf("%d",&n);
    do
    {
        printf("Enter 1 to add patients 2 to remove 3 to display 4 to exit ");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("Enter data");
            scanf("%s",val);
            create1(val,n);
        }
        if(ch==2)
        {
            delete();
        }
        if(ch==3)
        {
            display();
        }
    } while (ch!=4);
}