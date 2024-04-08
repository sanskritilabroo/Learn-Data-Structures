#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct
{
    int data[MAX];
    int rear;
    int front;
}Queue;

void initialize(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

void enqueue(Queue *q, int item)
{
    if ((q->rear+1)%MAX == q->front)
        return;
    else
    {
        int i = q->rear;
        //for(i=q->rear;q->data[i]>item;i--){
        while(q->data[i]>item)
        {
            q->data[i+1] = q->data[i];
            i--;
            if(i==0)
            {
                i==MAX-1;
            }
        }
        q->data[i+1]=item;
        q->rear=(q->rear+1)%MAX;
    }
}

int dequeue(Queue *q)
{
    if (q->rear == q->front)
    return;
    else
    {
        q->front = (q->front + 1) % MAX;
        return q->data[q->front];
    }
}