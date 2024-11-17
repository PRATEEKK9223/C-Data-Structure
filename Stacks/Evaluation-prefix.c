#include<stdio.h>
#include<ctype.h>
#include<string.h>

int stack[100];
int top=-1;

void push(int ele)
{
    if(top==9)
        printf("overflow\n");
        else{
            stack[++top]=ele;
        }
}

int pop()
{
    if(top==-1)
        return -1;
    else{
        return stack[top--];
    }
}
void reverse(char *str)
{
    int length=strlen(str);
    for(int i=0;i<length/2;i++)
    {
        char temp=str[i];
        str[i]=str[length-1];
        str[length-1]=temp;
        length--;
    }
}
int compute(int op1,int op2,char operator)
{
    switch (operator)
    {
    case '+':
       return op1+op2;
        break;
    case '-':
       return op1-op2;
        break;
    case '*':
       return op1*op2;
        break;
    case '/':
       return op1/op2;
        break;
    case '%':
        return op1%op2;
        break;
    default:
        break;
    }
}

void main()
{
    char prefix[100];
    printf("enter the prefix expression \n");
    scanf("%s",prefix);
    reverse(prefix);
    printf("%s",prefix);
    for(int i=0;prefix[i]!='\0';i++)
    {
        int op1,op2;
        if(isdigit(prefix[i]))
        {
            int num=prefix[i]-'0';
            push(num);
        }
        else{
            op1=pop();
            if(top==-1)
                printf("invalid prefix\n");
            op2=pop();
            int result=compute(op1,op2,prefix[i]);
            push(result);
        }
    }
    if(top!=0)
            printf("invlid expression\n");
    else{
        printf("\nresult=%d",stack[top]);
    }
}