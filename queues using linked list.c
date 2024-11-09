#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
    int data;
    struct node *link;
};
struct node * push(struct node *,int);
int main()
{
    struct node *head,*ptr;
    head=NULL;
    int pref,val;
    printf("enter 1 to push()\n");
    printf("Enter  2 to pop()\n");
    printf("Enter 3 to display()\n");
    printf("Enter 4 to exit\n");
    while(true)
    {
        printf("Enter the preference:\n");
        scanf("%d",&pref);
        if(pref==1)
        {
            printf("enter the value:\n");
            scanf("%d",&val);
            if(head==NULL)
            {
                head=push(head,val);
                ptr=head;
            }
            else
            {
                ptr=push(ptr,val);
            }
        }
        else if(pref==2)
        {
            head=pop(head);
        }
        else if(pref==3)
        {
            display(head);
        }
    }
}
struct node * push(struct node *head,int val)
{
    struct node *h;
    h=(struct node *)malloc(sizeof(struct node));
    h->data=val;
    h->link=NULL;
    if(head==NULL)
    {
        head=h;
        return head;
    }
    else
    {
        head->link=h;
        return h;
    }
}
int pop(struct node *head)
{
    if(head==NULL)
    {
        printf("stack is empty\n");
        return;
    }
    struct node *next;
    next=head;
    head=head->link;
    free(next);
    next=NULL;
    return head;

}
void display(struct node *head)
{
    printf("elements in the stack are:\n");
    while(head!=NULL)
    {
        printf("%d\n",head->data);
        head=head->link;
    }
}

