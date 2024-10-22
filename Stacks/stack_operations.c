#include<stdio.h>
#include<stdlib.h>
int *stack,size,top=-1;

int isfull()
{
    if(top==size-1)
        return 1;
    return 0;
}
int isempty()
{
    if(top==-1)
        return 1;
    return 0;
}
void push(int ele)
{
    stack[++top]=ele;
}
int pop()
{
    int ele=stack[top--];
    //top--;
    return ele;
}
void display()
{
    if(isempty())
        printf("stack is empty\n");
    else
    {
        printf("stack elements are\n");
        for(int i=top;i>=0;i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}
void palidrome()
{
    int ele,flag=1;
    char str[10];
    printf("enter the string to check palidrome\n");
    scanf("%s",str);
    for(int i=0;str[i]!='\0';i++)
    {
        push(str[i]);
    }
    for(int i=0;str[i]!='\0';i++)
    {
        ele=pop();
        if(ele!=str[i])
            flag=0;
    }
    if(flag==1)
        printf("ENTERD string %s IS PALINDROME\n",str);
    else
    printf("enterd string %s is not a palidrome\n",str);
}

void main()
{
    int choice,item;
    printf("enter the size of the stack\n");
    scanf("%d",&size);
    stack=(int*)malloc(size*sizeof(int));
    for(;;)
    {
        printf("1->push:2->pop:3->display:4->palidrome:5->exit:>>>>\n");
        printf("enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:{
                printf("enter te element to push\n");
                scanf("%d",&item);
                if(isfull())
                    printf("stack is overflow\n");
                else
                    push(item);    
            }break;
            case 2:{
                if(isempty())
                    printf("stack is underflow\n");
                else{
                    item=pop();
                    printf("deleted item is %d\n",item);
                }
            }break;
            case 3:
                display();
                break;
            case 4:
                palidrome();
                break;
            case 5:
                exit(0);
            default:
                printf("invalid option\n");

        }
    }
}