#include<stdio.h>
void main()
{
    int a[50]={10,20,30,40};
    int size=4;
    printf("array elementes are::\n");
    for(int i=0;i<size;i++)
    {
        printf("%d ",a[i]);
    }
    //  delet at Beging
    printf("\ndeletion at beging::\n");
    if(size==0)
        printf("array is empty::");
    else
        for(int i=0;i<size;i++)
        {
            a[i]=a[i+1];
        }
    size--;
    
    for(int i=0;i<size;i++)
    {
        printf("%d ",a[i]);
    }
    //  delet at end
    printf("\n deletion at end::\n");
    
    size--;
    for(int i=0;i<size;i++)
    {
        printf("%d ",a[i]);
    }

    // delet at any position
    printf("deletion at any position:;\n");
    int pos;
    printf("\nenter position to delet::\n");
    scanf("%d",&pos);
    for(int i=pos-1;i<size;i++)
    {
       a[i]=a[i+1]; 
    }
    size--;
    for(int i=0;i<size;i++)
    {
        printf("%d ",a[i]);
    }

}

void insert_At_Beging(int size,int *array,int ele)
{
    if(size==0)
    {
        array[size]=ele;
        size++;
    } 
    else
    {
        for(int i=size;i>=0;i--)
        {
            //array[i]=array[i-1];
            *(array+i)=*(array+i-1);
            
        }
        *(array)=ele;
        size++;
    }
}
void insert_At_End(int size,int *array,int ele)
{
    array[size]=ele;
    size++;
}