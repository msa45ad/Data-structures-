#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void sort(struct node *,int );
struct node * add(struct node *,int);
void display(struct node *head);
int main()
{
    struct node *head,*ptr;
    head=(struct node *)malloc(sizeof(struct node));
    int val,num;
    printf("enter the no of nodes req:\n");
    scanf("%d",&num);
    printf("enter the data:\n");
    scanf("%d",&val);
    int i;
    head->data=val;
    ptr=head;
    for(i=0;i<num-1;i++)
    {
        printf("enter the data:\n");
        scanf("%d",&val);
        ptr=add(ptr,val);
    }
    display(head);
    sort(head,num);
    display(head);
}
struct node * add(struct node *h,int val)
{
    struct node *he;
    he=(struct node *)malloc(sizeof(struct node));
    he->data=val;
    he->link=NULL;
    h->link=he;
    return he;
}
void display(struct node *head)
{
    printf("elements in the linked list are\n");
    while(head!=NULL)
    {
        printf("%d\n",head->data);
        head=head->link;
    }
}
void sort(struct node *head,int num)
{
    struct node *ptr,*p;
    ptr=head->link;
    p=head;
    int i,j,k;
    for(i=0;i<num-1;i++)
    {
        for(j=i;j<num-1;j++)
        {
            if((p->data)>(ptr->data))
            {
                k=p->data;
                p->data=ptr->data;
                ptr->data=k;
            }
            ptr=ptr->link;
        }
        p=p->link;
        ptr=p->link;
    }
}

