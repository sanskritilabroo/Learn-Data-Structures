#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
}Node;
Node *front = NULL; //delete from front
Node *rear = NULL; //add from rear

void enqueue()
{
    if(rear == NULL) //adding just one new node
    {
      rear=(Node*)malloc(sizeof(Node));
      printf("Enter data for first node\n");
      scanf("%d",&rear->data); //adding first node to rear list
      rear->link = NULL; //only one node so rear points to NULL
      front = rear; //point front to same place as rear
    }
    else
    {
      Node *newnode = (Node*)malloc(sizeof(Node));
      printf("Enter data\n");
      scanf("%d",&newnode->data);
      newnode->link = NULL;
      rear->link = newnode; //adding newnode to rear list
      rear = newnode; //rear should now point to the newnode
    }
}


void dequeue()
{
    Node *temp;
    if(front!=NULL)
    {
        printf("The element deleted is %d\n",front->data); 
        temp = front; 
        front = front->link; 
        temp->link=NULL; 
    }  
    else
    {
        printf("No element to be deleted\n");
        exit(0);
    }  
}
void display()
{
    printf("The queue is :  ");
    while(front!=NULL)
    {
        printf("%d\t",front->data);
        front=front->link;
    }
    exit(0);
}

int main()
{
    int n,no=1;
    while(no)
    {
        printf("1-enqeue,2-dequeue,3-display\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            enqueue();
            break;
            case 2:
            dequeue();
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