#include<stdio.h>
#include<stdlib.h>
void insert_At_Beging();
void insert_At_End();
void insert_At_pos();
int get_length();
void display();
void delet_At_Beging();
int pos;

struct node
{
    char ch;
    struct node *next,*prev;
};

typedef struct node CDLL;
CDLL *head=NULL,*tail,*newnode;

CDLL* get_Node()
{
    newnode=(CDLL*)malloc(sizeof(CDLL));
    printf("enter the data\n");
    getchar();
    scanf("%c",&newnode->ch);
    newnode->next=0;
    newnode->prev=0;
    return newnode;
}

void insert_At_Beging()
{
    newnode=get_Node();
    if(head==NULL)
    {
        head=tail=newnode;
        head->next=head;
        head->prev=head;
    }
    else{
        newnode->next=head;
        head->prev=newnode;
        newnode->prev=tail;
        tail->next=newnode;
        head=newnode;
    }
}

void insert_At_End()
{
    newnode=get_Node();
    if(head==0){
        head=tail=newnode;
        newnode->next=head;
        newnode->prev=head;
    }
    else{
        newnode->prev=tail;
        newnode->next=head;//tail->next
        tail->next=newnode;
        head->prev=newnode;
        tail=newnode;
    }
}

void insert_At_pos()
{
    CDLL *temp=head;
    int i=1;
    printf("enter the positon you want to add\n");
    scanf("%d",&pos);
    newnode=get_Node();
    if(pos==1)
        insert_At_Beging();
    else if(pos==get_length())
        insert_At_End();
    else{
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next->prev=newnode;
        temp->next=newnode;
    }
}

int get_length()
{
    int count=1;
    CDLL *temp=head;
    if(head==0)
        return 0;
    else{
        while(temp!=tail)
        {
            temp=temp->next;
            count++;
        }
    }
    return count;
}

void display()
{
    struct node *temp=head;
    if(head==0)
        printf("empty DCLL\n");
    else{
        do{
            printf("%c",temp->ch);
            temp=temp->next;
            if(temp!=tail->next)//temp!=head
                printf("<->");
        }while(temp!=head);
        printf("\n");
    }
}

//deletion operations........

void delet_At_Beging()
{
   CDLL *temp=head;
    if(head==0)
        printf("empty CDLL\n");
    else if(head==head->next || head==head->prev)
    {
        head=0;
        free(temp);
    }
    else{
        head=temp->next;
        head->prev=tail;
        tail->next=head;
        temp->next=0;
        free(temp);
    } 
    printf("deletion at beging is sucssefully\n");   

}
void delet_AT_end()
{
    CDLL *temp;
    if(head==0)
        printf("empty CDLL\n");
    else if(head==head->next || head==head->prev)
    {
        head=0;
    }
    else{
        temp=tail;
        tail=temp->prev;
        tail->next=head;
        temp->prev=0;
    }
    free(temp);
}
void delet_At_pos()
{
    CDLL *temp=head;
    int i=1;
    printf("enter the position you want to delet\n");
    scanf("%d",&pos);
    if(head==0)
        printf("empty DCLL\n");
    else if(pos==1)
        delet_At_Beging();
    else if(pos==get_length())
        delet_AT_end();
    else{
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
    }
}


void main()
{
    int choice;
    for(;;)
    {
        printf("enter the choice\n");
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
                delet_At_Beging();
                break;
            case 6:
                delet_AT_end();
                break;
            case 7:
                delet_At_pos();
                break;
        }
    }
}
