#include<stdio.h>
#include<conio.h>
typedef struct tree
{
    int data;
    struct tree *left,*right;
}node;
node **que[10];
int f=-1,r=-1;
void add(node **t)
{
    if(f==-1)
        f==0;
    que[++r]=t;
}
node** fetch()
{
    node *t=que[f];
    f++;
    return t;
}
void bfs(node *temproot)
{
    while(temproot!=NULL)
    {
        printf("%d\t",temproot->data);
        add(temproot->left);
        add(temproot->right);
        temproot=fetch();
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
    int i;
    for(i=0;i<10;i++)
        que[i]=NULL;
    bfs(root);
}
