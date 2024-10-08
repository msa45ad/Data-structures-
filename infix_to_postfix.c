#include<stdio.h>
#include<string.h>
#define max 50
char stack_arr[max];
char post[max];
int top=-1;
void push(char val)
{
    if(top==max-1)
    {
        printf("stack is overflowed\n");
    }
    else
    {
        top++;
        stack_arr[top]=val;
    }
}
char pop()
{
    if(top==-1)
    {
        printf("underflow");
    }
    else
    {
        char v;
        v=stack_arr[top];
        top--;
        return v;

    }
}
int int_to_post(char ar[],int size)
{
    char op;
    int j=0;
    int i;
    int next;
    for(i=0;i<size;i++)
    {
        op=ar[i];
        if (op=='+')
        {
            while(top!=-1 && precedence(stack_arr[top])>=precedence(op))
            {
                next=pop();
                post[j]=next;
                j++;
            }
            push(op);
        }
        else if (op=='-')
        {
            while(top!=-1 && precedence(stack_arr[top])>=precedence(op))
            {
                next=pop();
                post[j]=next;
                j++;
            }
            push(op);
        }
           else if (op=='*')
        {
            while(top!=-1 && precedence(stack_arr[top])>=precedence(op))
            {
                next=pop();
                post[j]=next;
                j++;
            }
            push(op);
        }
           else if (op=='/')
        {
            while(top!=-1 && precedence(stack_arr[top])>=precedence(op))
            {
                next=pop();
                post[j]=next;
                j++;
            }
            push(op);
        }
        else if (op=='(')
        {
            push(op);
        }
        else if(op==')')
        {
            while((next=pop())!='(')
            {
                post[j]=next;
                j++;
            }
        }
        else
        {
            post[j]=op;
            j++;
        }

    }
    while(top!=-1)
    {
        post[j]=pop();
        j++;
    }
    post[j]='\0';
}
void precedence(char op)
{
    if (op=='+' || op=='-')
    {
        return 1;
    }
    else if(op=='*'|| op=='/')
    {
        return 2;
    }
}
char prnt(int size)
{
    int i;
    printf("Desired output is:\n");
    for(i=0;i<size;i++)
    {
        printf("%c",post[i]);
    }
}
int main()
{
    char ex[50];
    printf("enter the expression:");
    gets(ex);
    int l;
    l=strlen(ex);
    int_to_post(ex,l);
    prnt(l);
}

