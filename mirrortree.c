#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct tree
{
    int data;
    struct tree *left,*right;
}node;
node* insertN(int d)
{
    node *temp=(node*)malloc(sizeof(node));
    temp->left=NULL;
    temp->right=NULL;
    temp->data=d;
    return temp;
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
void mirror(node *root)
{
    if(root==NULL)
        return;
    else
    {
        mirror(root->left);
        mirror(root->right);
        node *temp=root->left;
        root->left=root->right;
        root->right=temp;
    }
}
void main()
{
    node* root=insertN(5);
    root->left=insertN(6);
    root->right=insertN(9);
    root->left->right=insertN(3);
    inorder(root);
    mirror(root);
    inorder(root);
}
