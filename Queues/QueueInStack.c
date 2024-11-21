//When implementing the Queue using stack we required 2 stacks 
//two methods are there 
//1:method enQueue O(1) and deQueue O(n)
//2:method deQueueO(1) and enQueue O(n)
//in this program we use method:1

#include<stdio.h>
#include<stdlib.h>

int stack1[10],stack2[10];
int top1=-1,top2=-1;
int count=0;

void push1(int ele)
{
    stack1[++top1]=ele;
}
int pop1()
{
    return stack1[top1--];
}
void push2(int ele)
{
    stack2[++top2]=ele;
}
int pop2()
{
    return stack2[top2--];
}

void enQueue(int ele)
{
    push1(ele);
    count++;
}
int deQueue()
{
    int ele,poped;
    for(int i=0;i<count;i++)
    {
        ele=pop1();
        push2(ele);
    }
    poped=pop2();
    count--;
    for(int i=0;i<count;i++)
    {
        ele=pop2();
        push1(ele);
    }
    return poped;
}

void display()
{
    for(int i=0;i<count;i++)
    {
        printf("%d",stack1[i]);
    }
}


void main()
{
    int choice,ele;
    for(;;)
    {
        printf("enter your choice\n");
        printf("1-insertion: 2-deletion: 3-display: 4-exit>>>>>>>\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("enter element to insert\n");
                scanf("%d",&ele);
                enQueue(ele);
                break;
            case 2:
                ele=deQueue();
                printf("deleted element is %d\n",ele);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("invalid choice\n");

        }
    }
}


   