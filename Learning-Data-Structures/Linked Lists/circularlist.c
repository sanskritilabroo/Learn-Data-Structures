#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} Node;

Node *front = NULL;
Node *rear = NULL;

void insertFront(int item)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = item;
    newnode->link = NULL;
    if (front == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        newnode->link = front;
        front = newnode;
        rear->link = front;
    }
}

void insertRear(int item)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = item;
    newnode->link = NULL;
    if (rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->link = newnode;
        rear = newnode;
        rear->link = front;
    }
}

Node* deleteFront()
{
    Node *temp = front;
    front = front->link;
    rear->link = front;
    return temp;
}

Node* deleteRear()
{ 
    Node *temp = rear;
    Node *curr = front;
    while (curr->link != rear)
    {
        curr = curr->link;
    }
    rear = curr;
    rear->link = front;
    return temp;
}

int length(Node* last)
{ 
    Node* temp;
    int count = 0;
    if (last) 
    {
        temp = last;
        do 
        { 
            count++;
            temp = temp->link;
        } while (temp!=last);
    }
    return count;
}

void display()
{
    if (front == NULL)
    {
        printf("Circular Linked List is empty.\n");
        return;
    }

    Node *temp = front;
    do
    {
        printf("%d ", temp->data);
        temp = temp->link;
    } while (temp != front);
    printf("\n");
}

int main()
{
    int choice, item;

    do
    {
        printf("\nCircular Linked List Menu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the item to insert at the front: ");
            scanf("%d", &item);
            insertFront(item);
            break;

        case 2:
            printf("Enter the item to insert at the rear: ");
            scanf("%d", &item);
            insertRear(item);
            break;

        case 3:
            deleteFront();
            printf("Deleted from front.\n");
            break;

        case 4:
            deleteRear();
            printf("Deleted from rear.\n");
            break;

        case 5:
            display();
            break;

        case 0:
            printf("Exiting the program.\n");
            break;

        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}
