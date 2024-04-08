#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
typedef struct
{
    int* data;
    int front;
    int rear;
}Queue;

void init(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

void enqueue(Queue *q, int item)
{
    if ((q->rear + 1) % MAX_SIZE == q->front)
    return;
    else
    {
        if(q->front == -1)
        {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % MAX_SIZE;
        q->data[q->rear] = item;
    }
}

int dequeue(Queue *q)
{
    if (q->rear == q->front)
    return;
    else
    {
        q->front = (q->front + 1) % MAX_SIZE;
        return q->data[q->front];
    }
}
void display(Queue *q)
{
    if(q->rear > q->front)
    {
        for(int x = q->front; x<q->rear; x++)
        {
            printf("%d", q->data[x]);
        }
    }
    else
    {
        for(int i=q->front;i<MAX_SIZE;i++)
        {
            printf("%d",q->data[i]);
        }
        for(int j=0;j<q->rear;j++)
        {
            printf("%d",q->data[j]);
        }
    }
}