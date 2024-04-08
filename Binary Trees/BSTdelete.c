#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
} Node;

typedef struct
{
    Node *arr[10];
    int front;
    int rear;
} Queue;

void insert(Queue *q, Node *item)
{
    q->arr[++q->rear] = item;
}

Node *dele(Queue *q)
{
    return q->arr[++q->front];
}

Node *getNode(int data)
{
    Node *temp = malloc(sizeof(Node));
    temp->data = data;
    temp->llink = temp->rlink = NULL;
    return temp;
}

Node *create(Node *root, int data)
{
    if (root == NULL)
    {
        Node *temp = getNode(data);
        return temp;
    }
    else
    {
        if (data < root->data)
            root->llink = create(root->llink, data);
        else
            root->rlink = create(root->rlink, data);
        return root;
    }
}

void inorder(Node *root)
{
    if (root)
    {
        inorder(root->llink);
        printf("%d ", root->data);
        inorder(root->rlink);
    }
}
//tree deletion
Node *deletei(Node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }

    if (data < root->data)
    {
        root->llink = deletei(root->llink, data);
    }
    else if (data > root->data)
    {
        root->rlink = deletei(root->rlink, data);
    }
    else
    {
        if (root->llink == NULL)
        {
            Node *temp = root->rlink;
            free(root);
            return temp;
        }
        else if (root->rlink == NULL)
        {
            Node *temp = root->llink;
            free(root);
            return temp;
        }

        Node *temp = root->rlink;
        while (temp->llink != NULL)
        {
            temp = temp->llink;
        }
        root->data = temp->data;
        root->rlink = deletei(root->rlink, temp->data);
    }
    return root;
}

int main()
{
    Node *root1 = NULL;
    int n, d;

    printf("Tree 1 : \n");
    do
    {
        printf("1 to enter and 0 to exit : ");
        scanf("%d", &n);
        if (n == 1)
        {
            printf("Enter element : ");
            scanf("%d", &d);
            root1 = create(root1, d);
        }
    } while (n != 0);
    printf("Original: ");
    inorder(root1);

    printf("\nEnter element to delete : ");
    int s;
    scanf("%d", &s);
    root1 = deletei(root1, s);

    printf("New: ");
    inorder(root1);

    return 0;
}