#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
    int data;
    struct node *link;
};
struct node * deletefront(struct node *);
void deleterear(struct node *);
void deletepos(struct node *,int );
void display(struct node *);
struct node * add(struct node *,int);
int main()
{
    struct node *head,*ptr;
    head=(struct node *)malloc(sizeof(struct node));
    int val;
    int pref;
    head=NULL;
    printf("Select 1 to Create()\n");
    printf("Select 2 to delete front()\n");
    printf("Select 3 to delete rear()\n");
    printf("Select 4 to delete at certain position()\n");
    printf("Select 5 to exit()\n");
    printf("Select 6 to display()\n");
    while(true)
    {
        printf("enter the preference:\n");
        scanf("%d",&pref);
        if(pref==1)
        {
            printf("enter the value:\n");
            scanf("%d",&val);
            head=add(head,val);
        }
        else if(pref==2)
        {
            head=deletefront(head);
        }
        else if(pref==3)
        {
            deleterear(head);
        }
        else if(pref==4)
        {
            int pos;
            printf("enter the position to be deleted:\n");
            scanf("%d",&pos);
            deletepos(head,pos);
        }
        else if(pref==5)
        {
            break;
        }
        else if(pref==6)
        {
            display(head);
        }
         else
        {
            printf("no preference found\n");
        }
    }
}
struct node * deletefront(struct node *head)
{
    if(head==NULL)
    {
        printf("empty linked list");
        return head;
    }
    else
    {
         struct node *ptr;
         ptr=head;
         head=head->link;
         free(ptr);
         ptr=NULL;
         return head;
    }
}
void deleterear(struct node *head)
{
    struct node *ptr;
    ptr=head;
    while(ptr->link!=NULL)
    {
        head=ptr;
        ptr=ptr->link;
    }
    head->link=NULL;
    free(ptr);
    ptr=NULL;
}
void deletepos(struct node *head,int pos)
{
    struct node *ptr,*p;
    ptr=head;
    int i=0;
    while(i!=pos-1)
    {
        i++;
        p=ptr;
        ptr=ptr->link;
    }
    p->link=ptr->link;
    free(ptr);
    ptr=NULL;
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
    struct node *ptr,*temp;
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=val;
    ptr->link=NULL;
    temp=head;
    if(head==NULL)
    {
        head=ptr;
    }
    else
    {
        while(temp->link!=NULL)
        {
            temp=temp->link;
        }
        temp->link=ptr;
    }
    return head;
}
