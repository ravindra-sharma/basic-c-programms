#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct tree
{
    int data;
    struct tree *left,*right;
}node;
node* maketree(int d)
{
    node *temp=(node*)malloc(sizeof(node));
    temp->data=d;
    temp->left=NULL;
    temp->right=NULL;
}
node* insertN(node *t,int d)
{
    if(t==NULL)
      {
         t=maketree(d);
         return t;
      }
    else
    {
        if(t->data<d)
            t->right=insertN(t->right,d);
        else
            t->left=insertN(t->left,d);
    }
}
void inorder(node *root)
{
    if(root!=NULL)
    {

        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}
int srch(node *root,int d)
{
    if(root!=NULL)
    {
        if(d==root->data)
            return 1;
        else
        {
            if(d<root->data)
                srch(root->left,d);
            else
                srch(root->right,d);
        }
    }
}
node* dlt(node *root,int d)
{
    if(root!=NULL)
    {
         if(d==root->data)
        {
            dltNode(root);
            }
        else
        {
            if(d<root->data)
                root->left=dlt
            else
                srch(root->right,d);
        }

    }
}
void main()
{
    node *root=maketree(5);
    insertN(root,6);
    insertN(root,7);
    insertN(root,4);
    insertN(root,8);
    insertN(root,3);
    insertN(root,2);
    insertN(root,9);
    inorder(root);
    int i=srch(root,10);
    i==1?printf("Element found!!! %d",i) : printf("Element not found %d",i);
    dlt(root,5);
}
