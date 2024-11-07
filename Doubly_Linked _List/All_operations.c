#include<stdio.h>
#include<stdlib.h>
struct node* getNode();
void insert_At_Beging();
void insert_At_End();
void insert_At_pos();



struct node{
    int ele;
    struct node *rlink;
    struct node *llink;
};

typedef struct node DLL;
DLL *head=NULL;
DLL *tail=NULL;
DLL *newnode;

struct node* getNode()
{
    newnode=(DLL*)malloc(sizeof(DLL));
    if(newnode==NULL)
        printf("memory not allocted\n");
    else{
        printf("enter the element\n");
        scanf("%d",&newnode->ele);
        newnode->rlink=0;
        newnode->llink=0;
    }
    return newnode;
}

void insert_At_Beging()
{
    newnode=getNode();
    if(head==0)
        head=tail=newnode;
    else{
        newnode->rlink=head;
        head->llink=newnode;
        head=newnode;
        //here no need to set the tail because taile is already in last node itself
    }
    printf("\ninsertion at beging is sucessfully\n");
}

void insert_At_End()
{
    DLL *temp=head;
    newnode=getNode();
    if(head==NULL)
        tail=head=newnode;
    else{
        tail->rlink=newnode;
        newnode->llink=tail;
        tail=newnode;//it is for set the tail to end
    }
}

void insert_At_pos()
{
    DLL *temp=head;
    int pos,length;
    newnode=getNode();
    printf("enter the position to add\n");
    scanf("%d",&pos);
    if(pos<0||pos>length)
        printf("invalid position\n");
    else if(pos==1)
        insert_At_Beging();
    else{
        for(int i=1;i<pos-1;i++)
            temp=temp->rlink;
        newnode->llink=temp;
        newnode->rlink=temp->rlink;
        temp->rlink->llink=newnode;
        temp->rlink=newnode;
    }
}

void display()
{
    DLL *temp=head;
    if(head==NULL)
        printf("empty LL\n");
    else{
        while(temp!=0)
        {
            printf("%d",temp->ele);
            temp=temp->rlink;
            if(temp!=0)
                printf("<->");
           
        }
    }

}

void main()
{
    int choice;
    for(;;)
    {
        printf("\nenter the choice\n");
        printf("\n1:insert front\n 2:insert end \n 3:insert at pos\n 4:display \n 5:exit>>\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                insert_At_Beging();
                break;
            case 2:
                insert_At_End();
                break;
            case 3:
                insert_At_pos();
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

