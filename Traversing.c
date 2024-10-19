    int array[50],size;
    void read()
    {
        printf("eneter the size of the array\n");
        scanf("%d",&size);
        for(int i=0;i<size;i++)
        {
            scanf("%d",&array[i]);
        }
    }
    
    void display()
    {
        for(int i=0;i<size;i++)
        {
            printf("%d ",array[i]);
        }
    }

void main()
{
    read();
    display();
}