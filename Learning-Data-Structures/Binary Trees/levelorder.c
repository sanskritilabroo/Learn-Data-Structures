#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char *p;
    struct node *l, *r;
}Node;

typedef struct queue
{
    Node *nodes[20];
    int front,rear;
}Queue;

void enqueue(Queue *q, Node* temp)
{
    q->nodes[++q->rear] = temp;
}

Node* dequeue(Queue *q)
{
    return q->nodes[++q->front];
}

Node* getNode(char *p1)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->p=(char*)malloc(sizeof(strlen(p1)+1));
    strcpy(newnode->p,p1);
    newnode->l = newnode->r = NULL;
    return newnode;
}

Node* createTree(char *p1)
{
    char *lc=(char*)malloc(20);
    char *rc=(char*)malloc(20);;
    if(strcmp(p1,"-1") != 0)
    {
        Node *newnode = getNode(p1);
        printf("Enter left child of %s : \n", p1);
        scanf("%s", lc);
        newnode->l = createTree(lc);
        printf("Enter right child of %s: \n", p1);
        scanf("%s", rc);
        newnode->r = createTree(rc);
        return newnode;
    }
    else 
    return NULL;
}

void levelorder(Node* root)
{
    Node *curr = root;
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = -1;
    enqueue(q, curr);
    while(q->front < q->rear)
    {
        curr = dequeue(q);
        printf("%s", curr->p);
        if (curr->l != NULL) enqueue(q, curr->l);
        if (curr->r != NULL) enqueue(q, curr->r);
    }
}

int main()
{
    char* val = (char*)malloc(100);
    printf("Enter data: ");
    scanf("%s", val);
    Node *root = createTree(val);
    levelorder(root);
    return 0;
}