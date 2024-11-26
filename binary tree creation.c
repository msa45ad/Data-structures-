#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *left;
    int data;
    struct node *right;
};
struct node *newNode(int val)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->left=NULL;
    temp->right=NULL;
    temp->data=val;
    return temp;
}
struct node *insertion(struct node *h,int val)
{
    if(h==NULL)
    {
        return newNode(val);
    }
    if(val<h->data)
    {
        h->left=insertion(h->left,val);
    }
    else if(h->data<val)
    {
        h->right=insertion(h->right,val);
    }
    return h;
}
void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
int main()
{
    struct node *root;
    root=NULL;
    root=insertion(root,50);
    insertion(root,30);
    insertion(root,20);
    insertion(root,40);
    insertion(root,70);
    insertion(root,60);
    insertion(root,80);
    printf("Postorder :\n");
    postorder(root);
    printf("\n");
    printf("Preorder :\n");
    preorder(root);
    printf("\n");
    printf("Inorder :\n");
    inorder(root);
    printf("\n");
}

