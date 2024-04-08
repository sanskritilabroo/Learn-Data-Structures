#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} Node;

Node *head = NULL;
Node *curr = NULL;

void insert(int item)
{
    Node *newnode = malloc(sizeof(Node));
    newnode->data = item;
    newnode->link = NULL;

    if (head == NULL)
    {
        head = curr = newnode;
    }
    else
    {
        curr->link = newnode;
        curr = newnode;
    }
}

Node *concatenate(Node *list1, Node *list2)
{
    if (list1 == NULL)
        return list2;
    else
    {
        Node *temp = list1;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = list2;
        return list1;
    }
}

void display(Node *list)
{
    while (list != NULL)
    {
        printf("%d\t", list->data);
        list = list->link;
    }
    printf("\n");
}

int main()
{
    int choice, item;

    do
    {
        printf("\nMenu:\n");
        printf("1. Insert an element\n");
        printf("2. Display the list\n");
        printf("3. Concatenate with another list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d", &item);
            insert(item);
            break;

        case 2:
            printf("Displaying the list:\n");
            display(head);
            break;

        case 3:
            printf("Enter elements for the second list (enter -1 to stop):\n");
            do
            {
                scanf("%d", &item);
                if (item != -1)
                {
                    insert(item);
                }
                else
                {
                    break;
                }
            } while (1);

            printf("Concatenating the lists:\n");
            head = concatenate(head, curr);
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
