#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void read(int*, int);
void display(int*,int);
void insert(int*,int*,int ,int);
int delet(int*,int*,int);


void read(int *array ,int size)
{
    printf("enter the array  elements\n");
    for(int i=0;i<size;i++)
        scanf("%d",array+i);
}

void display(int *array,int size)
{
    printf("array elements are \n");
    printf("\n{");
    for(int i=0;i<size;i++)
    {
        printf("%d ",*(array+i));
    }
    printf("}\n");
}

void insert(int *array,int *size,int pos,int ele)
{
    if(pos<=(*size))   
    { 
        for(int i=(*size);i>pos-1;i--)
        {
            //array[i]=array[i-1];
            *(array+i)= *(array+i-1);
        }
        array[pos-1]=ele;
        (*size)++;
        printf("inserted successfully!\n");
    }
    else
        printf("\ninvalid position\n");
}

int delet(int *array,int *size,int pos)
{
    int item=*(array+(pos-1));
    for(int i=pos-1;i<(*size);i++)
    {
        //array[i]=array[i+1];
        *(array+i)=*(array+i+1);
    }
    (*size)--;
    printf("deleted successfully!\n");
    return item;
}

int search(int *array,int size,int ele)
{
    bool iselement =false;
    for(int i=0;i<size;i++)
    {
        if((*array+i)==ele)
        {
            return i;
        }   
    }
    return -1;
}

void delet_using_value(int *array,int *size,int ele)
{
    int pos;
    pos=search(array,(*size),ele);
    if(pos>=0)
    {
       // array[pos]=array[*size-1];//when array is not in sorted form
       //(*size)--;
        delet(array,size,pos+1);
        printf("DELET SUCCESSFULLY\n");
    }
    else
        printf("enter element is not found!!\n");
}

void main()
{
    int a[50],choice,size,pos,key;
    int *size_ptr=&size;
    
    while(1)
    {
        printf("1.read :: 2.dislay :: 3.insert :: 4.delet :: 5.search :: 6.delet_value ::other key to exit>>>> \n");
        printf("enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:{
            printf("enetr the size \n");
            scanf("%d",&size);
            read(a,size);
            break;
            }


            case 2:{
            display(a,size);
            break;
            }


            case 3:{
            printf("\nenter the position to insert\n");
            scanf("%d",&pos);
            printf("\nenter the element to insert\n");
            scanf("%d",&key);
            insert(a,size_ptr,pos,key);
            break;
            }


            case 4:{
            printf("enter the position to delet\n");
            scanf("%d",&pos);
            int res=delet(a,size_ptr,pos);
            printf("\ndeleted element is %d\n",res);
            break;
            }
            case 5: {
                printf("\n enter the element to search\n");
                scanf("%d",&key);
                pos=search(a,size,key);
                if(pos>=0)
                    printf("\nelement is found at position %d\n",pos+1);
                else
                    printf("\nelement is not found\n");
                break;
            }
            case 6:{
                printf("enter the element you want to delet\n");
                scanf("%d",&key);
                delet_using_value(a,size_ptr,key);
                break;
            }


            default :
            exit(0);

        }

    }


}
