#include<stdio.h>
#include<stdbool.h>
int top=-1;
#define max 5
int stack_arr[max];
void push(int);
int pop();
void display();
int main()
{
    printf("enter 1 to push\n");
    printf("Enter 2 to pop\n");
    printf("enter 3 to display\n");
    printf("enter 4 to exit\n");
    int pref;
    int v;
    while(true)
    {
        printf("Enter the preference:\n");
        scanf("%d",&pref);
        if(pref==1)
        {
            printf("Enter the value to be inserted:\n");
            scanf("%d",&v);
            push(v);
        }
        else if(pref==2)
        {
            v=pop();
        }
        else if(pref==3)
        {
            display();
        }
        else if(pref==4)
        {
            break;
        }
        else
        {
            printf("preference not found\n");
        }
    }
}
void push(int v)
{
    if(top==max-1)
    {
        printf("stack is overloaded\n");
    }
    else
    {
       top++;
       stack_arr[top]=v;
    }
}
int pop()
{
    int v;
   if(top==-1)
    {
        printf("stack is underflowed\n");
    }
    else
    {
        v=stack_arr[top];
        top--;
        return v;
    }
}
void display()
{
    int i;
    printf("Elements in the stack are:\n");
    for(i=0;i<=top;i++)
    {
        printf("%d\n",stack_arr[i]);
    }
}
