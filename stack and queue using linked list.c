#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
    int data;
    struct node *link;
};
int main()
{
    int pref,p,val;
    struct node *head,*h,*ptr,p1;
    head=NULL;
    h=NULL;
    struct node * push(struct node *,int);
    struct node * deque(struct node *);
    printf("Select 1 to stack()\n");
    printf("Select 2 to queue\n");
    printf("select 3 to display to stack()\n");
    printf("Select 4 to display queue()\n");
    while(true)
    {
        printf("enter the preference:\n");
        scanf("%d",&pref);
        if(pref==1)
        {
            printf("Select 1 to push()\n");
            printf("Select 2 to pop()\n");
            printf("enter the preference:\n");
            scanf("%d",&p);
            if(p==1)
            {
                printf("enter the value:\n");
                scanf("%d",&val);
                if(head==NULL)
                {
                    head=push(head,val);
                    ptr=head;
                }
                else
                {
                    push(head,val);
                }
            }
            else if(p==2)
            {
                pop(head);
            }
        }
        else if(pref==2)
        {
            printf("Select 1 to Enqueue()\n");
            printf("Select 2 to Dequeue()\n");
            printf("enter the pref:\n");
            scanf("%d",&p);
            if(p==1)
            {
                printf("enter the value:\n");
                scanf("%d",&val);
                if(h==NULL)
                {
                    h=push(h,val);
                }
                else
                {
                    push(h,val);
                }
            }
            else if(p==2)
            {
                h=deque(h);
            }
        }
        else if(pref==3)
        {
            printf("Elements in the stack are\n");
            display(head);
        }
        else if(pref==4)
        {
            printf("Elements in the queue are:\n");
            display(h);
        }
    }
}
struct node * push(struct node *head,int val )
{
    struct node *ptr,*p;
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=val;
    ptr->link=NULL;
    if(head==NULL)
    {
        head=ptr;
        return ptr;
    }
    else
    {
        p=head;
        while(p->link!=NULL)
        {
            p=p->link;
        }
        p->link=ptr;

    }

}
void pop(struct node *head)
{
    struct node *p,*ptr;
    p=head;
    while(p->link!=NULL)
    {
        ptr=p;
        p=p->link;
    }
    ptr->link=NULL;
    free(p);
}
struct node * deque(struct node *head)
{
    struct node *p;
    p=head;
    head=head->link;
    free(p);
    return head;
}
void display(struct node *h)
{
    while(h!=NULL)
    {
        printf("%d\n",h->data);
        h=h->link;
    }
}

