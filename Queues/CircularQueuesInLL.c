//This is implementation of Circular Queues using Circular LL
//the rules
//1. It follows FIFO
//2. Time complexity should be O(1)
//3. so insertion at end (using two pointrs) deletion at beging
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node CQLL;

CQLL *front=0,*rare=0;
CQLL *newnode;

CQLL* getNode(int ele)
{
    newnode=(CQLL*)malloc(sizeof(CQLL));
    if(newnode==NULL)
        exit(0);
    else{
        newnode->data=ele;
        newnode->next=0;
    }
    return newnode;
}

void enQueue(int ele)
{
    //here there is no full condition because it dynamic memory allocation usung LL
    newnode=getNode(ele);
    if(front==0 && rare==0)
    {
        front=rare=newnode;
        front->next=front;
    }
    else{
        rare->next=newnode;
        rare=newnode;
        rare->next=front;
    }

}

int deQueue()
{
    int ele;
    if(rare==0 && front==0)
        printf("Queue is empty\n");
    else if(front==front->next)
    {
        ele=front->data;
        front=rare=0;
        return ele;
    }
    else{
        ele=front->data;
        front=front->next;
        rare->next=front;
        return ele;
    }
}

void display()
{
    CQLL *temp=front;
    if(rare==0 && front==0)
        printf("Queue is empty\n");
    else{
        do{
            printf("%d",temp->data);
            temp=temp->next;
            if(temp!=rare->next)
                printf("->");
        }while(temp!=rare->next);
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
                printf("enter the element \n");
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



