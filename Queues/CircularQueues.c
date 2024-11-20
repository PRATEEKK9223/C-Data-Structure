#include<stdio.h>
#include<stdlib.h>
#define size 3

int CQ[size],ele;
int rare=-1;
int front=-1;

void enQueue(int ele)
{
    if((rare+1)%size == front)
        printf("Queue is FUll\n");
    else if(rare==-1 && front==-1)
    {
        rare=front=0;
        CQ[rare]=ele;
    }
    else{
        rare=(rare+1)%size;
        CQ[rare]=ele;
    }
}
int deQueue()
{
    if(rare==-1 && front==-1)
        printf("Queue is empty\n");
    else if(rare==front)
    {
        ele=CQ[front];
        rare=front=-1;
        return ele;
    }
    else{
        ele=CQ[front];
        front=(front+1)%size;
        return ele;
    }
}

int peek()
{
    if(rare==-1&&front==-1)
        printf("Queue is \aempty\n");
    else{
        return CQ[front];
    }
}

void display()
{
    if(rare==-1 && front==-1)
        printf("Queue is empty\n");
    else{
        int i=front;
        while(i!=rare)
        {
            printf("%d ",CQ[i]);
            i=(i+1)%size;
        }
        printf("%d ",CQ[i]);
        printf("\n");
    }
}

int  main()
{
    int choice,ele;
    for(;;)
    {
        printf("enter your choice\n");
        printf("1-insertion: 2-deletion: 3-peek: 4-display: 5-exit>>>>>>>\n\n");
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
                ele=peek();
                printf("the peek element is %d\n",ele);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("invalid choice\n");

        }
    }
    return 0;
}


