#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node * create(struct node *,int);
void display(struct node *);
struct node * create(struct node *,int);
void swap(struct node *,int);
struct node * create(struct node *head,int val)
{
    struct node *ptr,*p;
    p=head;
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->prev=NULL;
    ptr->data=val;
    ptr->next=NULL;
    if(head==NULL)
    {
        head=ptr;
    }
    else
    {
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=ptr;
        ptr->prev=p;
    }
    return head;

}
int main()
{
    struct node * head;
    head=NULL;
    int pref,k,val;
    printf("Select 1 to create linked list\n");
    printf("Select 2 to swap\n");
    printf("Select 3 to display\n");
    printf("Select 4 to terminate\n");
    while(true)
    {
        printf("Enter the preference:\n");
        scanf("%d",&pref);
        if(pref==1)
        {
            printf("Enter the value:\n");
            scanf("%d",&val);
            head=create(head,val);
        }
        else if(pref==2)
        {
            printf("enter the position to be swapped:\n");
            scanf("%d",&val);
            swap(head,val);
        }
        else if(pref==3)
        {
            display(head);
        }
        else if(pref==4)
        {
            break;
        }
        else
        {
            printf("No preference found\n");
        }
    }

}
void swap(struct node *head,int pos)
{
    int count=0;
    int a;
    struct node *h;
    h=head;
    struct node *h1=head;
    while(count!=pos-1)
    {
        h=h->next;
        count++;
    }
    a=h->data;
    count=0;
    while(h1->next!=NULL)
    {
        h1=h1->next;
    }
    while(count!=pos-1)
    {
        h1=h1->prev;
        count++;
    }
    h->data=h1->data;
    h1->data=a;
}
void display(struct node *head2)
{
    if(head2==NULL)
    {
        printf("linked list is empty\n");
    }
    else
    {
        while(head2!=NULL)
        {
            printf("%d\n",head2->data);
            head2=head2->next;
        }
    }
}
