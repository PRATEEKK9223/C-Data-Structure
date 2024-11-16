#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *top=0;
struct node *newnode;

void push(int ele)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=ele;
    newnode->next=top;
    top=newnode;
}
void pop()
{
    if(top==0)
        printf("Underflow condition\n");
    else{
        struct node* temp=top;
        printf("poped element is %d\n",top->data);
        top=temp->next;
        temp->next=0;
        free(temp); 
    }
}
void peek()
{
    if(top==0)
        printf("Underflow condition\n");
    else{
        printf("top element is %d\n",top->data);
    }
}
void display()
{
    struct node *temp=top;
   if(top==0)
        printf("Underflow condition\n");
    else{
        printf("stack elements are\n");
        while(temp!=0)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

void main(void)
{
    push(1);
    push(2);
    push(3);
    push(4);
    display();
    pop();
    peek();
    pop();
    peek();
}