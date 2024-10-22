// Here the infix expression is coverted into pstfix
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

char *stack=NULL;
int top=-1,size;

void push(char ele)
{
    stack[++top]=ele;
}

char pop()
{
    return stack[top--];
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
char* get_stack(int size)
{
    char *stack;
    stack=(char*)malloc(size*sizeof(char));
    return stack;
}

void main()
{
    printf("enter the size of the stack\n");
    scanf("%d",&size);
    stack=get_stack(size);
    char infix[10];
    printf("enter the valid infix expression\n");
    scanf("%s",infix);
    push('#');
    printf("postfix expression is\n");
    int i=0;
    while(infix[i]!='\0')
    {
        if(isalnum(infix[i]))//here this function check the charcter is alphabet or numeric value
            printf("%c",infix[i]);
        else if(infix[i]=='(')
            push('(');
        else if(infix[i]==')')
        {
            while(infix[i]!='(')
            {
                printf("%c",pop());stack_priority(stack[top]);

            }
        }
        else
        {
            while(input_priority(infix[i])<=stack_priority(stack[top]))
            {
                printf("%c",pop());
            }
            push(infix[i]);
            
        }
        i++;
    }
    while(top>0)
        printf("%c",pop());
              
}
