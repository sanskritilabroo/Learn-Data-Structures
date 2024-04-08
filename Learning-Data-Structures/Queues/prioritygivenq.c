#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5
typedef struct 
{
    int no[MAX_SIZE];
    int priority[MAX_SIZE];
    int front;
    int rear;
}queue;
int isFull(queue *q1)
{
    if(q1->rear==MAX_SIZE-1)
       return 1; 
    else 
      return 0;  
}
int isEmpty(queue *q1)
{
    if(q1->front>=q1->rear)
       return 1; 
    else 
      return 0;  
}
void display(queue *q1)
{
    printf("The queue is :  ");
        for(int i=q1->front;i<=q1->rear;i++)
    {
        printf("%d",q1->no[i]);
        printf("\t");
    }
    exit(0);
}
void enqueue(queue *q1)
{
    int x,y;
    if(isFull(q1))
    {
        printf("Overflow\n");
        display(q1);
    }
    else
    {
        if(q1->front==-1 && q1->rear==-1)
    {
          q1->front=q1->front+1;
    }
        q1->rear=q1->rear+1;
        printf("Enter no\n");
        scanf("%d",&x);
        q1->no[q1->rear]=x;
        printf("Enter priority\n");
        scanf("%d",&y);
        q1->priority[q1->rear]=y;
    }
}
void dequeue(queue *q1)// check
{
    int min,m;
    if(isEmpty(q1))
    {
        printf("Underflow\n");
        exit(0);
    }
    else
    {
            min=q1->priority[q1->front];
            m=q1->front;
            for(int j=q1->front+1;j<=q1->rear;j++)
            {
                if(min>q1->priority[j])
                {
                    min=q1->priority[j];
                    m=j;
                }
            }
             printf("The element dequeued is %d\n",q1->no[m]);
                for(int i=m;i<=q1->rear;i++)
            {
                if(i==q1->rear)
             {
                break;// if the last one has the least value 
             }
                 q1->no[i]=q1->no[i+1];
                 q1->priority[i]=q1->priority[i+1];
            }
            q1->rear--;//actually front should get incremented 
    }
}
int main()
{
    int n,no=1;
    queue q;
    q.front=-1;
    q.rear=-1;
    while(no)
    {
      printf("1-enqueue,2-dequeue,3-display\n");
      scanf("%d",&n);
    switch(n)
    {
        case 1:
        enqueue(&q);
        break;
        case 2:
        dequeue(&q);
        break;
        case 3:
        display(&q);
        break;
    }
    printf("Do you want to continue press 0 or 1\n");
    scanf("%d",&no);
    }
    return 0;
}