#include<stdio.h>
#include<stdbool.h>
#define max 5
int que_arr[max];
int front=-1;
int rear=-1;
void add(int que_arr[],int *rear,int *front,int val)
{
    if((*rear)==max-1)
    {
        printf("overflowed\n");
    }
    else
    {
        if((*rear)==-1)
        {
            (*front)++;
        }
        (*rear)++;
        que_arr[*rear]=val;

    }
}
int del(int que_arr[],int *rear,int *front)
{
    if((*rear)==-1 || (*rear)<(*front))
    {
        printf("underflowed\n");
    }
    else
    {
        int b;
        b=que_arr[*front];
        (*front)++;
        return b;
    }
}
void display(int que_arr[],int *rear,int *front)
{
    if((*rear)==-1 || (*rear)<(*front))
    {
        printf("underflowed\n");
    }
    else
    {
        printf("Elements inside the queues is\n");
        int i;
        for(i=*front;i<=*rear;i++)
        {
            printf("%d\n",que_arr[i]);
        }
    }
}
int main()
{
    int que_arr[max];
    int front=-1;
    int rear=-1;
    printf("select 1 to add()\n");
    printf("select 2 to delete()\n");
    printf("select 3 to display()\n");
    printf("select 4 to exit\n");
    int pref;
    int v;
    while(true)
    {
          printf("enter your preference:\n");
          scanf("%d",&pref);
          if(pref==1)
          {
              printf("Enter the value:\n");
              scanf("%d",&v);
              add(que_arr,&rear,&front,v);
          }
          else if(pref==2)
          {
              v=del(que_arr,&rear,&front);
              printf("Element deleted is %d\n",v);
          }
          else if(pref==3)
          {
              display(que_arr,&rear,&front);
          }
          else if(pref==4)
          {
              break;
          }
          else
          {
              printf("pref not found\n");
          }
    }

}
