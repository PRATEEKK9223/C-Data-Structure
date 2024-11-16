#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define size 20

char stack[size];
int top=-1;

void push(char ele)
{
    if(top==(size-1))
        printf("overflow\n");
    else
        stack[++top]=ele;
}
char pop()
{
    char sym;
    if(top==-1)
        return -1;
    else{
        sym=stack[top--];
    }
    return sym;
}

int stack_priority(char sym)
{
    if(sym=='#')
        return -1;
    if(sym=='(')
        return 0;
    if(sym=='+'||sym=='-')
        return 2;
    if(sym=='*'||sym=='/'||sym=='%')
        return 4;
    if(sym=='$'||sym=='^')
        return 5;
}

int input_priority(char sym)
{
    if(sym=='(')
        return 9;
    if(sym=='+'||sym=='-')
        return 1;
    if(sym=='*'||sym=='/'||sym=='%')
        return 3;
    if(sym=='$'||sym=='^')
        return 6;
}

void reverse(char *str)
{
    int i=0,length=0;
    while(str[i]!='\0')
    {
        length++;
        i++;
    }
    i=0;
    while(i<length)
    {
        char temp=str[i];
        str[i]=str[length-1];
        str[length-1]=temp;
        i++;
        length--;
    }
}

void swap(char *str)
{
    int i=0;
    while(str[i]!='\0')
    {
        if(str[i]=='(')
            str[i]=')';
        else if(str[i]==')')
            str[i]='(';
        i++;
    }
}

int main()
{
    int top2=0;
    char infix[100];
    char postfix[100];
    printf("enter the valid infix expression\n");
    scanf("%s",infix);
    reverse(infix);
    swap(infix);
    push('#');
    int i=0;
    while(infix[i]!='\0')
    {
        if(isalnum(infix[i]))
            postfix[top2++]=infix[i];
        else if(infix[i]=='(')
            push(infix[i]);
        else if(infix[i]==')')
        {
            char sym;
            while((sym=pop())!='(')
                postfix[top2++]=sym;
        }
        else{
            while(input_priority(infix[i]) <= stack_priority(stack[top]))
            {
                postfix[top2++]=pop();
            }
            push(infix[i]);
        }
        i++;
    }
    while(top!=0)
        postfix[top2++]=pop();

    postfix[top2]='\0';

    reverse(postfix);

    printf("prefix=%s",postfix); 

    return 0;
}
