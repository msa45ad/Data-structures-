#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node * create(struct node *,int );
void deleteRear(struct node *);
struct node * deleteFront(struct node *);
void display(struct node *);
struct node * deletePos(struct node *,int);
int main()
{
    struct node *head;
    head=NULL;
    printf("select 1 to create linked list\n");
    printf("select 2 to deleteFront\n");
    printf("select 3 to delete Rear\n");
    printf("Select 4 to deletePos\n");
    printf("Select 5 to display\n");
    printf("Select 6 to exit\n");
    int pref,val,pos;
    while(true)
    {
        printf("enter the preference:\n");
        scanf("%d",&pref);
        if(pref==1)
        {
            printf("enter the value:\n");
            scanf("%d",&val);
            if(head==NULL)
            {
                head=create(head,val);
            }
            else
            {
                create(head,val);
            }
        }
        else if(pref==2)
        {
            head=deleteFront(head);
        }
        else if(pref==3)
        {
            deleteRear(head);
        }
        else if(pref==4)
        {
            printf("enter the position to be deleted\n");
            scanf("%d",&pos);
            head=deletePos(head,pos);
        }
        else if(pref==5)
        {
            display(head);
        }
        else if(pref==6)
        {
            break;
        }
        else
        {
            printf("preference not found\n");
        }
    }

}
struct node * create(struct node *h,int val)
{
    struct node *ptr,*p;
    p=h;
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=val;
    ptr->next=NULL;
    ptr->prev=NULL;
    if(h==NULL)
    {
        return ptr;
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
}
struct node * deleteFront(struct node *h)
{
    if(h==NULL)
    {
        printf("linked list is empty\n");
    }
    else if(h->next==NULL)
    {
        free(h);
        h=NULL;
        return h;
    }
    else
    {
          struct node *ptr;
          ptr=h;
          h=h->next;
          free(ptr);
          return h;
    }
}
void deleteRear(struct node *h)
{
    if(h==NULL)
    {
        printf("linked list is empty\n");
    }
    else if(h->next==NULL)
    {
        deleteFront(h);
    }
    else
    {
        struct node *head,*ptr;
        head=h;
        while(head->next!=NULL)
        {
            ptr=head;
            head=head->next;
        }
        free(head);
        ptr->next=NULL;
    }
}
struct node * deletePos(struct node *h,int pos)
{
    struct node *p;
    p=h;
    if(h==NULL)
    {
        printf("linked list is empty\n");
    }
    int c=0;
    while(p!=NULL)
    {
        p=p->next;
        c++;
    }
    if(pos==c)
    {
        deleteRear(h);
        return h;
    }
    else if(pos==1)
    {
        h=deleteFront(h);
        return h;
    }
    else if(pos>c)
    {
        printf("position out of the range:\n");
    }
    else
    {
          struct node *head,*ptr;
          int count=0;
          head=h;
          while(count!=pos-1)
          {
              ptr=head;
              head=head->next;
              count++;
          }
          ptr->next=head->next;
          head->next->prev=ptr;
          free(head);
          head==NULL;
          return h;

    }
}
void display(struct node *head)
{
    if(head==NULL)
    {
        printf("linked list  is empty\n");
    }
    else
    {
        printf("Elements in the doubly linked list are\n");
        while(head!=NULL)
        {
            printf("%d\n",head->data);
            head=head->next;
        }
    }
}


