#include<stdio.h>
#include<stdbool.h>
#define max 5
void push(int[],int *,int);
int pop(int[],int *);
void display(int[],int *);
int main()
{
    int top=-1;
    int stack_arr[max];
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
            push(stack_arr,&top,v);
        }
        else if(pref==2)
        {
            v=pop(stack_arr,&top);
        }
        else if(pref==3)
        {
            display(stack_arr,&top);
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
void push(int stack_arr[],int *top,int v)
{
    if(*top==max-1)
    {
        printf("stack is overloaded\n");
        return -1;
        
    }
    else
    {
       (*top)++;
       stack_arr[*top]=v;
    }
}
int pop(int stack_arr[],int *top)
{
    int v;
   if(*top==-1)
    {
        printf("stack is underflowed\n");
        return;
    }
    else
    {
        v=stack_arr[*top];
        (*top)--;
        return v;
    }
}
void display(int stack_arr[],int *top)
{
    int i;
    printf("Elements in the stack are:\n");
    for(i=0;i<=*top;i++)
    {
        printf("%d\n",stack_arr[i]);
    }
}
