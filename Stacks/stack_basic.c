#include<stdio.h>
#include<stdlib.h>
#define max 10
int stack[max];
int top=-1;

void push(void)
{
    int ele;
    printf("enter the element to push\n");
    scanf("%d",&ele);
    if(top==max-1)
    {
        printf("OVERFLOW CONDITION!!\n");
        return; 
    }
    top++;
    stack[top]=ele;
}
void pop(void)
{
    if(top==-1)
    {
        printf("UNDERFLOW CONDITION!!\n");
       return;
    }
    int ele=stack[top];
    top--;
    printf("deleted element is %d\n",ele);
}

void peek()
{
    if(top==-1)
    {
        printf("stack is empty\n");
        return;
    }
    int ele=stack[top];
    printf("the top element is %d\n",ele);
}

void display()
{
    printf("stack element are\n");
    for(int i=top;i>-1;i--)//i>=0
    {
        printf("%d\n",stack[i]);
    }
}

void reverse()
{
    printf("reversed stack is\n");
    for(int i=0;i<=top;i++)
    {
        printf("%d\n",stack[i]);
    }
}


void main()
{
    int choice;
    do
    {
        printf("1.push::2.pop::3.peek::4.display::5.reverse::6.exit>>>>>\n");
        printf("enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                reverse();
                break;
            case 6:
                exit(0);
            default:
                printf("invalid choice\n");
                
        }
    } while(choice);   
}