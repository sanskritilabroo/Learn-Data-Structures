#include <stdio.h>
#include <stdlib.h>
#define max 10
typedef struct
{
    int top;
    int *data;
}Stack;

void initialize(Stack *stack)
{
    stack->top=-1;
}

int isFull(Stack *stack)
{
    if(stack->top==max-1) return 1;
    else return 0;
}
int isEmpty(Stack *stack)
{
    if(stack->top==-1) return 1;
    else return 0;
}

void push(Stack *stack,int c)
{
    if(isFull(stack))
        printf("Stack overflow");
    else
    {
       stack->top++;
       stack->data[stack->top]=c;
    }
}

int pop(Stack *stack)
{
    if(isEmpty(stack))
        printf("Stack underflow");
    else
    {
        int item=stack->data[stack->top];
        stack->top--;
        return item;
    }
}

void display(Stack *stack)
{
    for(int i=0;i<=stack->top;i++)
    {
        printf("%d\t",stack->data[i]);
    }
    printf("\n");
}

void sort(Stack *stack)
{
    for(int i=0;i<=stack->top;i++)
    {
        for(int j=0;j<=stack->top-i-1;j++)
        {
            if(stack->data[j]>stack->data[j+1])
            {
                int temp=stack->data[j];
                stack->data[j]=stack->data[j+1];
                stack->data[j+1]=temp;
            }
        }
    }
}

int average(Stack *stack)
{
    int total=0;
    for(int i=0;i<=stack->top;i++)
    {
        total+=stack->data[i];
    }
    return total/(stack->top+1);
}
void main()
{
    int n;int n1,item;
    Stack *stack;
    stack=(Stack*)malloc(sizeof(Stack));
    stack->data=(int *)malloc(max*sizeof(int));
    initialize(stack);
    do
    {
        printf("Select 1)push 2)pop 3)display 4)sort 5)average 6)exit \n");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            printf("Enter element:\n ");
            scanf("%d",&n1);
            push(stack,n1);
            break;
        case 2:
            item=pop(stack);
            printf("poped=%d\n",item);
            break;
        case 3:
            display(stack);
            break;

        case 4:
            sort(stack);
            printf("Sorted\n");
            break;
        case 5:
            printf("Average=%d\n",average(stack));

        }
    }while(n!=6);
}