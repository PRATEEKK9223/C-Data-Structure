//Implementation of DeQueue using circular Array

#include<stdio.h>
#include<stdlib.h>
#define N 5

int DeQueue[N];
int front=-1,rare=-1;

void enQueuerare(int ele)
{
    if(front==rare+1 || front==0 && rare==N-1)
        printf("Full\n");
    else if(front==-1 && rare==-1)
    {
        rare=front=0;
        DeQueue[rare]=ele;
    }
    else if(rare==N-1)
    {
        rare=0;
        DeQueue[rare]=ele;
    }
    else{
        rare++;
        DeQueue[rare]=ele;
    }
}

void enQueuefront(int ele)
{
    if(front==rare+1 || front==0&&rare==N-1)
        printf("Full\n");
    else if(front==-1&& rare==-1)
    {
        front=rare=0;
        DeQueue[front]=ele;
    }
    else if(front==0)
    {
        front=N-1;
        DeQueue[front]=ele;
    }
    else{
        front--;
        DeQueue[front]=ele;
    }       
}

int deQueuefront()
{
    int ele;
    if(rare==-1 && front==-1)
        return -1;
    else if(front==N-1)
    {
        ele=DeQueue[front];
        front=0;
    }
    else if(front==rare)
    {
        ele=DeQueue[front];
        front=rare=-1;
    }
    else{
        ele=DeQueue[front];
        front++;
    }
    return ele;
}
int deQueueRare()
{
    int ele;
    if(rare==-1&&front==-1)
      return -1;
    else if(rare==0)
    {
        ele=DeQueue[rare];
        rare=N-1;
    }
    else if(rare==front)
    {
        ele=DeQueue[rare];
        rare=front=-1;
    }
    else{
        ele=DeQueue[rare];
        rare--;
    }
    return ele;
}

int getFront()
{
    return DeQueue[front];
}
int getRare()
{
    return DeQueue[rare];
}

void display()
{
    if(rare==-1 && front==-1)
        printf("empty\n");
    else{
        int i=front;
        while(i!=rare)
        {
            printf("%d ",DeQueue[i]);
            i=(i+1)%N;
        }
        printf("%d",DeQueue[rare]);
        printf("\n");
    }
}

int  main()
{
    int choice,ele;
    for(;;)
    {
        printf("enter your choice\n");
        printf("1-insertion_rare: 2-insertion_front: 3-deletion_front: 4-deletion_rare: 5-display:6-get_front : 7-get rare :8-exit>>>>>>>\n\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("enter element to insert\n");
                scanf("%d",&ele);
                enQueuerare(ele);
                break;
            case 2:
                printf("enter element to insert\n");
                scanf("%d",&ele);
                enQueuefront(ele);
                break;

            case 3:
                ele=deQueuefront();
                printf("deleted element is %d\n",ele);
                break;
            case 4:
                ele=deQueueRare();
                printf("deleted element is %d\n",ele);
                break;
            case 5:
                display();
                break;
            case 6:
                printf("front element %d",getFront());
                break;
            case 7:
                printf("rare element %d",getRare());
                break;

            case 8:
                exit(0);
            default:
                printf("invalid choice\n");

        }
    }
    return 0;
}




