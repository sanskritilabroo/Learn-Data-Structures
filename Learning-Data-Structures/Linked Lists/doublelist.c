#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *rlink, *llink;
} Node;

Node *head = NULL;
Node *curr = NULL;

void insert(int data) {
    Node *newnode = malloc(sizeof(Node));
    newnode->data = data;
    newnode->rlink = newnode->llink = NULL;
    if (head == NULL) 
    {
        head = curr = newnode;
    } 
    else 
    {
        curr->rlink = newnode; //add newnode to the right of the current node
        newnode->llink = curr; //now left of newnode is current node technically
        curr = newnode; //now update current
    }
}

void display() {
    Node *newnode = head; //head is start pointer so points to first element in list
    printf("Going front:\n");
    while (newnode) 
    {
        printf("%d\t", newnode->data);
        newnode = newnode->rlink;
    }

    newnode = curr;//curr is the tail pointer so points to last eleemnt in list
    printf("\nGoing back:\n");
    while (newnode) 
    {
        printf("%d\t", newnode->data);
        newnode = newnode->llink;
    }
    printf("\n");
}

int main() {
    int n, value;
    do {
        printf("Enter 1 to insert and 2 to display and 0 to exit: ");
        scanf("%d", &n);
        switch (n) 
        {
        case 1:
            printf("Enter element: ");
            scanf("%d", &value);
            insert(value);
            break;
        case 2:
            display();
            break;
        }
    } while (n != 0);

    while (head) 
    {
        Node *temp = head;
        head = head->rlink;
        free(temp);
    }

    return 0;
}

