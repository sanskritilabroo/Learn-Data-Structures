//linear Queue
#include <stdio.h>
#include <stdlib.h>
#define MAX 20 
typedef struct 
{
    int x[MAX]; 
    int front;
    int rear;
} Queue;

void init(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}
int isEmpty(Queue *q)
{
    return (q->front==-1 || q->front > q->rear);
}
int isFull(Queue *q)
{
    return (q->rear == MAX-1);
}
void addq(Queue *q, int item)
{
    if (isFull(q))
    {
        printf("OVERFLOW");
    }
    else
    {
        if(q->front==-1) 
        {
            q->front=0;
        }
        q->x[++q->rear]=item;
    }
}
int deleteq(Queue *q)
{
    if (isEmpty(q))
    {
        printf("UNDERFLOW");
    }
    else
    {
        int item = q->x[q->front++];
        return item;
    }
}
void display(Queue *q)
{
    for(int i=q->front;i<=q->rear;i++)
    {
        printf("%d\t",q->x[i]);
    }
    printf("\n");
}

void main()
{
    int n,item;
    Queue *q;

    q=(Queue*)malloc(sizeof(Queue));
    init(q);
    do
    {
        printf("\nChoose option 1)push 2)pop 3)display 4)exit : ");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            printf("Enter new element: ");
            scanf("%d",&item);
            addq(q,item);
            printf("front=%d and rear=%d",q->front,q->rear);
            break;
        case 2:
            item=deleteq(q);
            printf("Popped=%d\n",item);
            printf("front=%d and rear=%d",q->front,q->rear);
            break;
        case 3:
            display(q);
        }
    }while(n!=4);
}