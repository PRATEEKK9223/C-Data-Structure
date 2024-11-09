#include<stdio.h>
#include<stdlib.h>
void insert_At_Beging();
void insert_At_end();
void insert_At_pos();
void delet_At_Beging();
void delet_At_end();
void delet_At_pos();
int get_length();
void Reverse();
void display();

struct node{
    char name[10];
    struct node *next;
};
 typedef struct node CLL;
 CLL *tail=NULL,*newnode;

 // here we using only tail pointer (not use head pointer)

 CLL* get_Node()
 {
    newnode=(CLL*)malloc(sizeof(CLL));
    printf("enter te name\n");
    scanf("%s",&newnode->name);
    newnode->next=NULL;
     return newnode;
 }

 void insert_At_Beging()
 {
    newnode=get_Node();
    if(tail==NULL)
    {
        tail=newnode;
        tail->next=newnode;
    }
    else{
        newnode->next=tail->next;
        tail->next=newnode;
    }
 }

 void insert_At_end()
 {
    newnode=get_Node();
    if(tail==NULL)
    {
        tail=newnode;
        tail->next=newnode;
    }
    else{
        newnode->next=tail->next;
        tail->next=newnode;
        tail=newnode;
    }   
 }

 void insert_At_pos()
 {
    CLL *temp=tail->next;
    newnode=get_Node();
    int pos,i=1;
    printf("enter te position\n");
    scanf("%d",&pos);
    if(pos<0 || pos>get_length())
        printf("invldlid postion\n");
    else if(pos==1)
        insert_At_Beging();
    else{
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
 }

 void delet_At_Beging()
 {
    CLL *temp=tail->next;
    if(tail==NULL)
        printf("empty CLL\n");
    else{
        tail->next=temp->next;
        temp->next=NULL;
        free(temp);
    }

 }
 void delet_At_end()
 {
    CLL *temp=tail->next,*previous,*temp2;
    if(tail==NULL)
        printf("empty CLL\n");
    else if(tail==tail->next)
        tail=NULL;
    else{
        do{
            previous=temp;
            temp=temp->next;
        }while(temp->next!=tail->next);
        previous->next=tail->next;//temp
        temp2=tail;
        tail=previous;
        free(temp2);
    }

 }

 void delet_At_pos()
 {
    CLL *temp=tail->next,*previous;
    int pos,i=1;
    if(tail==NULL)
        printf("empty LL\n");
    else{
        printf("enter the position you want to delet\n");
        scanf("%d",&pos);
        if(pos<0 || pos>get_length())
            printf("invild position\n");
        else if(pos==1)
            delet_At_Beging();
        else if(pos==get_length())
            delet_At_end();
        else{
            do{
                previous=temp;
                temp=temp->next;
                i++;
            }while(i<pos);

            previous=temp->next;
            temp->next=0;
            free(temp);
        }
    }
 }

 int get_length()
 {
    int count=0;
    CLL *temp=tail->next;
    if(tail==NULL)
        return 0;
    else{
        do{
            count++;
            temp=temp->next;
        }while(temp!=tail->next);
  
    }
    return count;
 }
void Reverse()
{
    CLL *previous,*current=tail->next,*nextnode=current->next;

    if(tail==0)
        printf("empty CLL\n");
    else if(tail==tail->next)
        printf("you have only one element\n");
    else{
        while(current!=tail)
        {
            previous=current;
            current=nextnode;
            nextnode=current->next;//current->next;
            current->next=previous;
        }
        nextnode->next=tail;
        tail=nextnode;    

    }
}

 void display()
 {
    if(tail==NULL)
        printf("empty CLL\n");
    else{
        CLL *temp=tail->next;
        do{
            printf("%s",temp->name);
            temp=temp->next;
            if(temp!=tail->next)
                printf("->");
        }while(temp!=tail->next);
        printf("\n");
    }
 }

 void main()
 {
    int ch;
    for(;;)
    {
        printf("enter the choice\n");
        printf("1-insert at beging\n 2-insert at end\n 3-insert at position\n 4-get length\n 5-delet at beging\n 6-delet at end\n 7-delet at position\n 8-Reverse\n 9-display\n 10-exit....\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                insert_At_Beging();
                break;
            case 2:
                insert_At_end();
                break;
            case 3:
                insert_At_pos();
                break;
            case 4:
                {
                    int length;
                    length=get_length();
                    printf("NODES=%d\n",length);
                    break;
                }
            case 5:
                delet_At_Beging();
                break;
            case 6:
                delet_At_end();
                break;
            case 7:
                delet_At_pos();
                break;
            case 8:
                Reverse();
                break;
            case 9:
                display();
                break;
            case 10:
                exit(0);
            default:
                printf("invalid choice\n");

        }
    }
 }