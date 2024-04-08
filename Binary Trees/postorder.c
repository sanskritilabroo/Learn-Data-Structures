#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *rlink, *llink;
} Node;

typedef struct
{
    Node *node;
    int flag;
} Stack;

Node *createTree(int item)
{
    if (item != -1)
    {
        Node *temp = malloc(sizeof(Node));
        temp->data = item;
        temp->llink = NULL;
        temp->rlink = NULL;

        int x;
        printf("Enter left child of %d : ", item);
        scanf("%d", &x);
        temp->llink = createTree(x);
        printf("Enter right child of %d : ", item);
        scanf("%d", &x);
        temp->rlink = createTree(x);

        return temp;
    }
    return NULL;
}

void postorder(Node *root)
{  
    Stack s[20];
    int top = -1;
    Node *cur = root;
    if (root == NULL)
    {
        return;
    }
    while (1)
    {
        while (cur)
        {
            s[++top].node = cur;
            s[top].flag = 1;
            cur = cur->llink;
        }
        while (s[top].flag < 0)
        {
            cur = s[top--].node;
            printf("%d\t", cur->data);
            if (top == -1)
                return;
        }

        cur = s[top].node;
        cur=cur->rlink;
        s[top].flag = -1;
    }
}

int main()
{
    printf("Enter root item : ");
    int i;
    scanf("%d", &i);
    Node *root = createTree(i);

    printf("Postorder:\n");
    postorder(root);

    return 0;
}