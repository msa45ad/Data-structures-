#include<stdio.h>
#include<stdbool.h>
#define max 5
int main()
{
    int top=-1;
    int stack_arr[max];
    int s_arr[max];
    int v;
    int t=-1;
    int pref;
    printf("select 1 to insert()\n");
    printf("select 2 to delete()\n");
    printf("select 3 to display()\n");
    printf("select 4 to exit()\n");
    while(true)
    {
        printf("enter your preference:\n");
        scanf("%d",&pref);
        if(pref==1)
        {
            printf("enter the value to be inserted:\n");
            scanf("%d",&v);
            insert(stack_arr,&top,v);
        }
        else if(pref==2)
        {
            int x;
            x=del(stack_arr,&top,s_arr,&t);
            printf("elements deleted in queue is: %d\n",x);
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
void insert(int stack_arr[],int *top,int val)
{
    if(*top==max-1)
    {
        printf("overflow\n");
    }
    else
    {
        (*top)++;
    stack_arr[*top]=val;

    }
}
int del(int stack_arr[],int *top,int s_arr[],int *t)
{
    if(*top==-1)
    {
        printf("underflow\n");
    }
    else
    {
        while(*top!=-1)
    {
        *t=*t+1;
        s_arr[*t]=stack_arr[*top];
        (*top)--;
    }
    int a;
    int v;
    v=s_arr[*t];
    *t=*t-1;
    while(*t!=-1)
    {
        (*top)++;
        stack_arr[*top]=s_arr[*t];
        (*t)--;
    }
    return v;

    }
}
void display(int stack_arr[],int *top)
{
    printf("elements in the stack are:\n");
    int i;
    for(i=0;i<=*top;i++)
    {
        printf("%d\n",stack_arr[i]);
    }
}

