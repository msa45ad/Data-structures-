#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
bool palindrome(struct node *);
struct node * create(struct node *,int);
int main()
{
    struct node * head;
    head=NULL;
    int pref,val;
    printf("Select 1 to create linked list\n");
    printf("Select 2 to check palindrome\n");
    printf("Select 3 to break\n");
    bool a;
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
            a=palindrome(head);
            if(a)
            {
                printf("true\n");
            }
            else
            {
                printf("false\n");
            }
        }
        else if(pref==3)
        {
            break;
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
bool palindrome(struct node *head)
{
    struct node *h;
    bool b=true;
    h=head;
    while(h->next!=NULL)
    {
        h=h->next;
    }
    while(head!=NULL &&  head!=h)
    {
        if(head->data!=h->data)
        {
            b=false;
            break;
        }
        head=head->next;
        h=h->prev;
    }
    return b;
}
