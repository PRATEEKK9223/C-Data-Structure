#include<stdio.h>
#include<ctype.h>

int  stack[10];
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

int compute(int op1,int op2,char operator)
{
    switch (operator)
    {
    case '+':
       return op2+op1;
        break;
    case '-':
       return op2-op1;
        break;
    case '*':
       return op2*op1;
        break;
    case '/':
       return op2/op1;
        break;
    case '%':
        return op2%op1;
        break;
    default:
        break;
    }
}

void main()
{
    int op1,op2;
    char postfix[20];
    printf("enter te postfix expression\n");
    scanf("%s",postfix);
    for(int i=0;postfix[i]!='\0';i++)
    {
        if(isdigit(postfix[i]))
        {
            int num=postfix[i]-'0';
            push(num);
        }
        else{
            op1=pop();
            op2=pop();
            int result=compute(op1,op2,postfix[i]);
            //result=(char)result;
            push(result);
        }
    }
    if(top!=0)
        printf("invalid postfix expression\n");
    else
        printf("result=%d",stack[top]);
}