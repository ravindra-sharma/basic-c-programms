#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct tree
{
    int data;
    struct tree *left,*right;
}node;
void bfs(node *temproot)
{
    int h=get_height(temproot);
    printf("height is = %d\n",h);
    int i;
    for(i=1;i<=h;i++)
        printGivenLevel(temproot,i);
}
void printGivenLevel(node *temp,int level)
{
    if(temp==NULL)
        return;
    if(level==1)
        printf("%d\t",temp->data);
    else if(level>1)
    {
        printGivenLevel(temp->left,level-1);
        printGivenLevel(temp->right,level-1);
    }
}
int get_height(node *temp)
{
    if(temp==NULL)
        return 0;
    else
    {
        int lh=get_height(temp->left);
        int rh=get_height(temp->right);
        if(lh>rh)
            return lh+1;
        else
            return rh+1;
    }
}
node* newNode(int d)
{
    node *temp;
    temp=(node*)malloc(sizeof(node));
    temp->left=NULL;
    temp->right=NULL;
    temp->data=d;
}
void main()
{
    node *root=newNode(4);
    root->left=newNode(6);
    root->right=newNode(9);
    root->left->right=newNode(1);
    bfs(root);
}
