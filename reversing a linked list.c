#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
    int data;
    struct node *link;
};
struct node * add(struct node *,int);
struct node * rev(struct node *);
int main()
{
    struct node *head,*ptr;
    head=(struct node *)malloc(sizeof(struct node));
    int num;
    printf("Enter the number of nodes:\n");
    scanf("%d",&num);
    int val;
    printf("enter the value:\n");
    scanf("%d",&val);
    int i;
    head->data=val;
    head->link=NULL;
    ptr=head;
    for(i=0;i<num-1;i++)
    {
        printf("enter the value:\n");
        scanf("%d",&val);
        ptr=add(ptr,val);
    }
    printf("Elements in the linked list before reversing:\n");
    display(head);
    head=rev(head);
    printf("Elements in the linked list after reversing are:\n");
    display(head);
}
void display(struct node *head)
{
    while(head!=NULL)
    {
        printf("%d\n",head->data);
        head=head->link;
    }
}
struct node * rev(struct node *head)
{
    struct node *prev,*next;
    next=head;
    prev=NULL;
    while(next->link!=NULL)
    {
        head=next;
        next=next->link;
        head->link=prev;
        prev=head;
    }
    next->link=prev;
    head=next;
    return head;
}
struct node * add(struct node *h,int val)
{
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    if(h==NULL)
    {
        h=ptr;
        return h;
    }
    else
    {
        ptr->data=val;
        ptr->link=NULL;
        h->link=ptr;
        return ptr;
    }


}
