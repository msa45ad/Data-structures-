#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{

    int data;
    struct node *link;
};
struct node * add(struct node *,int);
void search(struct node *,int);
int main()
{
    struct node *head,*ptr;
    head=(struct node *)malloc(sizeof(struct node));
    int num;
    printf("enter the no of nodes req:\n");
    scanf("%d",&num);
    int i;
    int val;
    printf("enter the value:\n");;
    scanf("%d",&val);
    head->data=val;
    head->link=NULL;
    ptr=head;
    for(i=0;i<num-1;i++)
    {
        printf("enter the name:\n");
        scanf("%d",&val);
        ptr=add(ptr,val);
    }
    printf("Enter the element to be searched:\n");
    scanf("%d",&val);
    search(head,val);
}
void search(struct node *head,int val)
{
    int i=0;
    while(head!=NULL)
    {
        if(head->data==val)
        {
            printf("element is found at index is:%d",i);
            break;
        }
        i++;
        head=head->link;
    }
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
