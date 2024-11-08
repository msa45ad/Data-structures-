#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node * add(struct node *,int);
void display(struct node *);
void del_alter_node(struct node *);
int main()
{
    struct node *head,*ptr;
    head=(struct node *)malloc(sizeof(struct node));
    int val;
    int pref;
    int n;
    printf("enter the no of nodes req:\n");
    scanf("%d",&n);
    printf("enter the value:\n");
    scanf("%d",&val);
     head->data=val;
    head->link=NULL;
    ptr=head;
    int i;
    for(i=0;i<n-1;i++)
    {
        printf("enter the value:\n");
        scanf("%d",&val);
        ptr=add(ptr,val);
    }
    display(head);
    del_alter_node(head);
    display(head);
}
void del_alter_node(struct node *head)
{
    struct node *prev,*next,*p;
    int count=0;
    prev=NULL;
    next=head;
    while(next!=NULL)
    {
        if(count%2!=0)
        {
            prev->link=next->link;
            p=next;
            next=next->link;
            free(p);
            p=NULL;
            count++;
        }
        else{
            prev=next;
            next=next->link;
            count++;
        }
    }
    prev->link=NULL;

}
void display(struct node *head)
{
    printf("Elements in the linked list is:\n");
    struct node *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->link;
    }

}
struct node * add(struct node *head,int val)
{
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=val;
    ptr->link=NULL;
    head->link=ptr;
    return ptr;
}
