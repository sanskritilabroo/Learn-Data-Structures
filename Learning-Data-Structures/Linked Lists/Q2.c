#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct node
{
    char* name;
    int seat;
    struct node *link;
}Node;

Node *head = NULL;
Node *tail = NULL;

void create(char* name, int seat)
{
    Node *newnode=(Node*)malloc(sizeof(Node));
    newnode->name = (char*)malloc(strlen(name)+1);
    strcpy(newnode->name,name);
    newnode->seat = seat;
    newnode->link = NULL;

    if(head == NULL)
    {
        head = tail = newnode;
    }
    else
    {
        tail->link = newnode;
        tail = newnode;
    }

}

void sort()
{
    char* sorter = (char*)malloc(20);
    Node *temp = head;
    while(temp != NULL)
    {
        Node *runner = temp;
        
        while(runner->link)
        {
            if(strcmp(runner->name, runner->link->name) > 0)
            {
                sorter = runner->name;
                runner->name = runner->link->name;
                runner->link->name = sorter;

                int x = runner->seat;
                runner->seat = runner->link->seat;
                runner->link->seat = x;
            }

            runner=runner->link;
        }
        temp=temp->link;
    }
}

Node* reverse(Node *lead)
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
    Node *temp = head;
    while(temp!=NULL)
    {
        printf("Name = %s \t", temp->name);
        printf("Seat Number = %d \n", temp->seat);
        temp = temp->link;
    }
}

void displayrev()
{
    Node *temp = reverse(head);
    while(temp!=NULL)
    {
        printf("Name = %s \t", temp->name);
        printf("Seat Number = %d \n", temp->seat);
        temp = temp->link;
    }
}

void main()
{
    int ch,s;
    char *name = (char*)malloc(10);
    do
    {
        printf("Enter 1 to insert and 0 to display: \n");
        scanf("%d", &ch);
        if(ch==1)
        {         
            printf("Enter your name: \n");
            scanf("%s", name);
            printf("Enter seat number: \n");
            scanf("%d", &s);
            create(name,s);
        }
        else if(ch==0)
        {
            printf("ORIGINAL: \n");
            display();
            break;
        }
    } while (ch!=0);
    sort();
    printf("SORTED: \n");
    display();
    printf("REVERSED: \n");
    displayrev();
}