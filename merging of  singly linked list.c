#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
    int data;
    struct node *link;
};
struct node * add(struct node *,int );
void display(struct node *);
void merge(struct node *,struct node *);
void prnt(struct node *);
void print(struct node *);
int main()
{
    struct node *head,*ptr;
    int num,i;
    head=(struct node *)malloc(sizeof(struct node));
    printf("enter the no of nodes required for the 1st linked list:\n");
    scanf("%d",&num);
    int val;
    printf("enter the value:\n");
    scanf("%d",&val);
    head->data=val;
    head->link=NULL;
    ptr=head;
    for(i=0;i<num-1;i++)
    {
        printf("enter the value::\n");
        scanf("%d",&val);
        ptr=add(ptr,val);
    }
    prnt(head);
    struct node *h1,*p;
    h1=(struct node *)malloc(sizeof(struct node));
    int n;
    printf("enter the no of nodes required for the 2nd linked list:\n");
    scanf("%d",&n);
    printf("enter the value:\n");
    scanf("%d",&val);
    h1->data=val;
    h1->link=NULL;
    p=h1;
    for(i=0;i<n-1;i++)
    {
        printf("enter the value:\n");
        scanf("%d",&val);
        p=add(p,val);
    }
    print(h1);
    merge(ptr,h1);
    display(head);
}
void merge(struct node *last1,struct node *first2)
{
    last1->link=first2;
}
void display(struct node *head)
{
    printf("merged linked list is:");
    struct node *h;
    h=head;
    while(h!=NULL)
    {
        printf("%d\n",h->data);
        h=h->link;
    }
}
void prnt(struct node *h)
{
    printf("elements in the linked list-1 are\n");
    struct node *a;
    a=h;
    while(a!=NULL)
    {
        printf("%d\n",a->data);
        a=a->link;
    }

}
void print(struct node *h)
{
    printf("elements in the linked list-2 are\n");
    struct node *a;
    a=h;
    while(a!=NULL)
    {
        printf("%d\n",a->data);
        a=a->link;
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
