#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
}Node;

Node *head = NULL;
Node *curr = NULL;

void insert(int item)
{
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = item;
    newnode->llink = newnode->rlink = NULL;
    if (head = NULL)
    {
        head = curr = newnode;
    }
    else
    {
        curr->rlink = newnode;
        newnode->llink = curr;
        curr = newnode;
    }
}

void create(Node *head,Node *curr,int item)
{
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = item;
    newnode->llink = newnode->rlink = NULL;
    if (head = NULL)
    {
        head = curr = newnode;
    }
    else
    {
        curr->rlink = newnode;
        newnode->llink = curr;
        curr = newnode;
    }
}

void delete(int n)
{
    Node *temp = head;
    int count=0;
    while(temp)
    {
        count++;
        temp = temp->rlink;
    }
    n=count-n;
    temp = head;
    for(int i=0; temp->rlink->rlink!=NULL; i++)
    {
        if (i == n-1) break;
        else{
            temp = temp->rlink;
        }
    }
    temp->rlink = temp->rlink->rlink;
    temp->rlink->rlink->llink = temp;
    free(temp->rlink);
    
}

Node* concatenate(Node *list1, Node *list2)
{
    Node *list3h = NULL;
    Node *list3c = NULL;
    while(list1)
    {
        create(list3h,list3c,list1->data);
        list1=list1->rlink;
    }
    while(list2)
    {
        create(list3h,list3c,list2->data);
        list2=list2->rlink;
    }
    return list3h;
}

int main()
{
    int ch;
    int item;
    do
    {
        printf("Enter 1 to insert and 0 to display:");
        scanf("%d",&ch);
        if (ch==1)
        {
            printf("Enter data:");
            scanf("%d", &item);
            insert(item);
        }
        if (ch==0)
        {
            display();
        }
    }
    while(ch!=0);
}
while(list3)
{
    root=createTree(root,list3->data);
    list3=list3->link;
}