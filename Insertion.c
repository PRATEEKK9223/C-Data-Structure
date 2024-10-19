#include<stdio.h>

void main()
{
    int a[50],size;
    printf("eneter the size of the array\n");
    scanf("%d",&size);
    for(int i=0;i<size;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nbefore insertion::\n");
    for(int i=0;i<size;i++)
    {
        printf("%d ",a[i]);
    }
    //insertion at beging
    for(int i=size;i>=0;i--)
    {
        a[i]=a[i-1];
    }
    a[0]=100;
    size++;
    printf("\nafter insertion::\n");
    for(int i=0;i<size;i++)
    {
        printf("%d ",a[i]);
    }
    a[size]=100;
    size++;
    printf("\ninertion at end ::\n");
    for(int i=0;i<size;i++)
    {
        printf("%d ",a[i]);
    }
    int pos;
    printf("\nenter position \n");
    scanf("%d",&pos);
    for(int i=size;i>pos-1;i--)
    {
        a[i]=a[i-1];
    }
    a[pos-1]=120;
    size++;
    printf(" after insertion at any position::\n ");
    for(int i=0;i<size;i++)
    {
        printf("%d ",a[i]);
    }
}

