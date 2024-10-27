#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node * addFront(struct node *,int );
void addEnd(struct node *,int);
struct node * add(struct node *,int);
struct node * addPos(struct node *,int,int);
int main()
{
    struct node *head,*ptr,*p;
    head=(struct node *)malloc(sizeof(struct node));
    int val;
     int co;
    printf("Enter the no of nodes req:\n");
    scanf("%d",&co);
    printf("enter the value:\n");
    scanf("%d",&val);
    head->data=val;
    head->link=NULL;
    ptr=head;
    int i;
    int pref;
    for(i=0;i<co-1;i++)
    {
        printf("Enter the value:\n");
        scanf("%d",&val);
        ptr=add(ptr,val);
    }
    printf("Select 1 to addFront()\n");
    printf("Select 2 to addEnd()\n");
    printf("Select 3 to addPos()\n");
    printf("select 4 to display()\n");
    printf("Select 5 to exit\n");
    while(true)
    {
        int pref;
        printf("enter the preference:\n");
        scanf("%d",&pref);
        int position;
        if(pref==1)
        {
            printf("enter the value to  be inserted at front:\n");
            scanf("%d",&val);
            head=addFront(head,val);
        }
        else if(pref==2)
        {
            printf("enter the value at the rear:\n");
            scanf("%d",&val);
            addEnd(head,val);
        }
        else if(pref==4)
        {
            display(head);
        }
        else if(pref==3)
        {
            printf("Enter the position to be inserted:\n");
            scanf("%d",&position);
            printf("Enter the value to be inserted:\n");
            scanf("%d",&val);
            head=addPos(head,position,val);
        }

    }
}
struct node * addFront(struct node *head,int val)
{
    struct node *h;
    h=(struct node *)malloc(sizeof(struct node));
    h->data=val;
    h->link=head;
    head=h;
    return head;
}
void display(struct node *h)
{
    printf("elements in the linked list are:\n");
    while(h!=NULL)
    {
        printf("%d\n",h->data);
        h=h->link;
    }
}
void addEnd(struct node *head,int val)
{
    struct node *h;
    h=(struct node *)malloc(sizeof(struct node));
    h->data=val;
    h->link=NULL;
    while(head->link!=NULL)
    {

        head=head->link;
    }
    head->link=h;
}
struct node * add(struct node *h,int val)
{
    struct node *head;
    head=(struct node *)malloc(sizeof(struct node));
    head->data=val;
    head->link=NULL;
    h->link=head;
    return head;
}
struct node * addPos(struct node *head,int pos,int val)
{
    struct node *p,*a,*b;
    b=head;
    p=(struct node *)malloc(sizeof(struct node));
    p->data=val;
    p->link=NULL;
    if(pos==1)
    {
        head=addFront(head,val);
        return head;
    }
    else
    {
        int i;
        for(i=0;i<pos-1;i++)
        {
            a=head;
            head=head->link;
        }
        p->link=head;
        a->link=p;
    }
    return b;
}
