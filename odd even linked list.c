#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
    int data;
    struct node *link;
};
struct node * create(struct node *,int);
struct node * oddEven(struct node *,struct node *,struct node *);
void display(struct node *);
int main()
{
    int val;
    struct node *head;
    struct node *head1;
    struct node *head2;
    head=NULL;
    head1=NULL;
    head2=NULL;
    int pref;
    printf("Select 1 to create\n");
    printf("select 2 to terminate the creation\n");
    printf("select 3 to oddEven\n");
    printf("select 4 to display\n");
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
            break;
        }
        else if (pref==3)
        {
            head2=oddEven(head,head1,head2);
        }
        else if(pref==4)
        {
            display(head2);
        }
        else
        {
            printf("No preference found\n");
        }
    }


}
struct node * create(struct node *head,int val)
{
    struct node *ptr,*p;
    p=head;
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=val;
    ptr->link=NULL;
    if(head==NULL)
    {
        head=ptr;
    }
    else
    {
        while(p->link!=NULL)
        {
            p=p->link;
        }
        p->link=ptr;
    }
    return head;

}
struct node * oddEven(struct node *head,struct node *head1,struct node *head2)
{
    int count=0;
    while(head!=NULL)
    {
        count++;
        if(count%2==0)
        {
            head1=create(head1,head->data);
        }
        else
        {
            head2=create(head2,head->data);
        }
        head=head->link;
    }
    struct node *h;
    h=head2;
    while(h->link!=NULL)
    {
        h=h->link;
    }
    h->link=head1;
    return head2;
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
            head2=head2->link;
        }
    }
}
