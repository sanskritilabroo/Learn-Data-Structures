#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct
{
    int data[MAX];
    int rear;
}Queue;

void initialize(Queue *q)
{
    q->rear=-1;
}

void push(Queue *q,int item)
{
    if(q->rear==MAX-1)
        printf("Queue is full");
    else
    {
        int i=q->rear;
        while(i>=0 && q->data[i]>item)
        {
            q->data[i+1]=q->data[i];
            i--;
        }
        q->data[i+1]=item;
        q->rear++;
    }
}

int pop(Queue *q)
{
    if(q->rear==-1)
    {
        printf("Queue is empty");
        return -1;
    }
    else
    {
        int max=q->data[0];
        for(int i=0;i<q->rear;i++)
        {
            q->data[i]=q->data[i+1];
        }
        q->rear--;
        return max;
    }
}

void display(Queue *q)
{
    for(int i=0;i<q->rear;i++)
        printf("%d\t",q->data[i]);
}

void main()
{
    Queue q;
    initialize(&q);
    int n,item;
    do
    {
        printf("\nrear=%d",q.rear);
        printf("\nChoose 1)push 2)pop 3)display and 4)exit\n");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            printf("Enter item: ");
            scanf("%d",&item);
            push(&q,item);
            break;
        case 2:
            printf("popped=%d",pop(&q));
            break;
        case 3:
            display(&q);
        }
    }while(n!=4);
}