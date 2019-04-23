#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct node
{
    int d;
    struct node *l;
}node;
node *s1,*s2,*s3;
void Insert(node *s,int data)
{
    if(s==NULL)
    {
        node *temp;
        temp=(node*)malloc(sizeof(node));
        temp->d=data;
        temp->l=NULL;
        s1=temp;
    }
    else
    {
        node *temp,*temp1;
    temp=s1;
    while(temp->l!=NULL)
    {
        temp=temp->l;
    }
    temp1=(node*)malloc(sizeof(node));
    temp1->d=data;
    temp1->l=NULL;
    temp->l=temp1;
    }

}
void Insert2(node *s,int data)
{
    if(s==NULL)
    {
        node *temp;
        temp=(node*)malloc(sizeof(node));
        temp->d=data;
        temp->l=NULL;
        s2=temp;
    }
    else
    {
        node *temp,*temp1;
    temp=s2;
    while(temp->l!=NULL)
    {
        temp=temp->l;
    }
    temp1=(node*)malloc(sizeof(node));
    temp1->d=data;
    temp1->l=NULL;
    temp->l=temp1;
    }

}
void Insert3(node *s,int data)
{
    if(s==NULL)
    {
        node *temp;
        temp=(node*)malloc(sizeof(node));
        temp->d=data;
        temp->l=NULL;
        s3=temp;
    }
    else
    {
        node *temp,*temp1;
    temp=s3;
    while(temp->l!=NULL)
    {
        temp=temp->l;
    }
    temp1=(node*)malloc(sizeof(node));
    temp1->d=data;
    temp1->l=NULL;
    temp->l=temp1;
    }

}
void main()
{

    Insert(s1,1);
    Insert(s1,2);
    Insert(s1,3);
    Insert2(s2,4);
    Insert2(s2,5);
    Insert2(s2,6);
    while(s1!=NULL && s2!=NULL)
    {
        int d=s1->d+s2->d;
        Insert3(s3,d);
        s1=s1->l;
        s2=s2->l;
    }
    while(s3!=NULL)
    {
        printf("%d",s3->d);
        s3=s3->l;
    }

}
