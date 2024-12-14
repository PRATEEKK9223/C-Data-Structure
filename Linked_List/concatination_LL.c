#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *head1=0,*head2=0;
struct node *newnode;

struct node* getNode()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the data\n");
    scanf("%d",&newnode ->data);
    newnode->link=0;
    return newnode;
}

void list1()
{
    newnode=getNode();
    if(head1==0)
        head1=newnode;
    else{
        newnode->link=head1;
        head1=newnode;
    }
}

void list2()
{
    newnode=getNode();
    if(head2==0)
        head2=newnode;
    else{
        newnode->link=head2;
        head2=newnode;
    }
}

struct node* reverse(struct node* head)
{
    struct node *previous,*current,*nextnode;
    previous=0;
    current=nextnode=head;
    while(nextnode!=0)
    {
        nextnode=current->link;
        current->link=previous;
        previous=current;
        current=nextnode;
    }
    head=previous;
    return head;
}

struct node* concatination(struct node *list1,struct node *list2)
{
    struct node *temp=list1;
    while (temp->link!=0)
    {
        temp=temp->link;
    }
    temp->link=list2;
    return list1;

}
void display(struct node* head)
{
    struct node *temp=head;
    if(head==0)
        printf("emoty\n");
    else{
        while(temp!=0)
        {
            printf("%d->",temp->data);
            temp=temp->link;
        }

    }

}

int length(struct node *head)
{
    int count=0;
    struct node *temp=head;
    if(head==0)
        return 0;
    else{
        while(temp!=0)
        {
            count++;
            temp=temp->link;
        }
    }
    return count;
}

void sort_assending(struct node *head)
{
    struct node *current,*next;
    
    for(current=head;current!=0;current=current->link)
    {
        for(next=current->link;next!=0;next=next->link)
        {
            if(current->data > next->data)
            {
                int temp=current->data;
                current->data=next->data;
                next->data=temp;
            }
        }
    }
    
}

void main()
{
    struct node *reversed,*concat;
    int n1,n2,len;
    printf("enter number of nodes for list1\n");
    scanf("%d",&n1);
    printf("enter the nodes list1\n");
    for(int i=0;i<n1;i++)
    {
        list1();
    }

    printf("enter number of nodes for list2\n");
    scanf("%d",&n2);

    printf("enter the nodes of list2\n");
    for(int i=0;i<n2;i++)
    {
        list2();
    }

    printf("list1\n");
    display(head1);

    sort_assending(head1);
    printf("\nafter sorting\n");
    display(head1);
    
    printf("list2\n");
    display(head2);

    printf("\n cancatinated\n");
    concat=concatination(head1,head2);
    display(concat);

    len=length(head1);
    printf("\nthe number of node is %d",len);

    
    printf("\nreveresed\n");
    reversed=reverse(head1);
    display(reversed);

    
    
}