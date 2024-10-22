#include<stdio.h>
#include<stdbool.h>
#define max 5
int main()
{
    int front=-1;
    int rear=-1;
    int que_arr[max];
    int val;
    int pref;
    printf("Select 1 to insert()\n");
    printf("Select 2 to delete()\n");
    printf("Select 3 to display()\n");
    printf("Select 4 to terminate\n");
    while(true)
    {
        printf("Enter the preference:\n");
        scanf("%d",&pref);
        if(pref==1)
        {
            printf("enter the value to be inserted:\n");
            scanf("%d",&val);
            insert(que_arr,&front,&rear,val);
        }
        else if(pref==2)
        {
            val=del(que_arr,&front,&rear);
            printf("Element deleted from the circular queue is :%d\n",val);
        }
        else if(pref==3)
        {
            display(que_arr,&front,&rear);
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
void insert(int que_arr[],int *front,int *rear,int val)
{
    if((*rear+1)%max==*front)
    {
        printf("overflow\n");
        return -1;
    }
    else if(*front==-1)
    {
        *front=0;
    }
    *rear=(*rear+1)%max;
    que_arr[*rear]=val;
}
int del(int que_arr[],int *front,int *rear)
{
    if(*front==-1)
    {
        printf("underflow\n");
        return;
    }
    int v;
    v=que_arr[*front];
    if(*rear==*front)
    {
        *rear=-1;
        *front=-1;
    }
    else
    {
        *front=(*front+1)%max;
    }
    return v;

}
void display(int que_arr[],int *front,int *rear)
{
    printf("Elements in the queue are:\n");
    int i=*front;
    while(true)
    {
        printf("%d\n",que_arr[i]);
        if(i==*rear)
        {
            break;
        }
        i=(i+1)%max;
    }
}
