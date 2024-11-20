#include<stdio.h>
#include<stdlib.h>
#define size 5

int Queue[size];
int front=-1;
int rare=-1;

int isfull()
{
    if(rare==size-1)
        return 1;
    else    
        return 0;
}
int isempty()
{
    if(rare==-1 && front==-1)
        return 1;
    else    
        return 0;
}

void enQueue(int ele)
{
    if(isfull())
        printf("Overflow condition\n");
    else if(front==-1 && rare==-1)
    {
        front=rare=0;
        Queue[rare]=ele;
    }
    else{
        //rare++;
        Queue[++rare]=ele;
    }
    
}
int deQueue()
{
    int ele;
    if(isempty())
    {
        printf("underflow(empty)\n");
        return -1;
    }
    else if(rare==front)
        rare=front=-1;
    else{
        ele=Queue[front++];
    }
    return ele;
}
int peek()
{
    int peek;
    if(isempty())
        printf("Overflow(full)\n");
    else{
        peek=Queue[front];  
    }
    return peek;
}

void display()
{
    if(isempty())
        printf("underflow condition(empty)\n");
    else{
        for(int i=front;i<=rare;i++)
        {
            printf("%d ",Queue[i]);
        }
        printf("\n");
    }
}

void main()
{
    int choice,ele;
    for(;;)
    {
        printf("enter your choice\n");
        printf("1-insertion: 2-deletion: 3-peek: 4-display: 5-exit>>>>>>>\n");
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
}
=======
#include<stdio.h>
#include<stdlib.h>
#define size 5

int Queue[size];
int front=-1;
int rare=-1;

int isfull()
{
    if(rare==size-1)
        return 1;
    else    
        return 0;
}
int isempty()
{
    if(rare==-1 && front==-1)
        return 1;
    else    
        return 0;
}

void enQueue(int ele)
{
    if(isfull())
        printf("Overflow condition\n");
    else if(front==-1 && rare==-1)
    {
        front=rare=0;
        Queue[rare]=ele;
    }
    else{
        //rare++;
        Queue[++rare]=ele;
    }
    
}
int deQueue()
{
    int ele;
    if(isempty())
    {
        printf("underflow(empty)\n");
        return -1;
    }
    else if(rare==front)
        rare=front=-1;
    else{
        ele=Queue[front++];
    }
    return ele;
}
int peek()
{
    int peek;
    if(isempty())
        printf("Overflow(full)\n");
    else{
        peek=Queue[front];  
    }
    return peek;
}

void display()
{
    if(isempty())
        printf("underflow condition(empty)\n");
    else{
        for(int i=front;i<=rare;i++)
        {
            printf("%d ",Queue[i]);
        }
        printf("\n");
    }
}

void main()
{
    int choice,ele;
    for(;;)
    {
        printf("enter your choice\n");
        printf("1-insertion: 2-deletion: 3-peek: 4-display: 5-exit>>>>>>>\n");
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
}

