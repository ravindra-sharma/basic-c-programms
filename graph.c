#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
int que[5],visit[5],f=-1,r=-1;
typedef struct Graph
{
    int data;
    struct Graph *link;
}node;
node* listi[5];
node* getNode(int d)
{
    node *temp;
    temp=(node*)malloc(sizeof(node));
    temp->data=d;
    temp->link=NULL;
    return temp;
}
void addEdge(int s,int d)
{
    if(listi[s]==NULL)
    {
        listi[s]=getNode(d);
    }
    else
    {
        node *temp;
        temp=listi[s];
        while(temp->link!=NULL)
        {
            temp=temp->link;
        }
        temp->link=getNode(d);
    }
}
void printGraph()
{
    int i;
    for(i=0;i<5;i++)
    {
        node *temp=listi[i];
        printf("%d->",i);
        while(temp!=NULL)
        {
            printf("%d->",temp->data);
            temp=temp->link;
        }
        printf("NULL\n");
    }
}
void addQue(int d)
{
    if(f==-1 && r==-1)
    {
        f=0;
    }
    r++;
    que[r]=d;
}
int fetch()
{
    return que[f++];
}
int queEmpty()
{
    if(f>r)
    {
        return 1;
    }
    return 0;
}
void bfs(int s)
{
    addQue(s);
    while(!queEmpty())
    {
        int d=fetch();
        visit[d]=1;
        printf("%d\t",d);
        node *temp=listi[d];
        while(temp!=NULL)
        {

            if(visit[temp->data]==0)
            {
                addQue(temp->data);
            }
            temp=temp->link;
        }
    }
}
void main()
{
    int i;
    for(i=0;i<5;i++)
    {
        visit[i]=0;
        listi[i]=NULL;
    }
    addEdge(0,1);
    addEdge(0,2);
    addEdge(0,3);
    addEdge(1,0);
    addEdge(1,3);
    addEdge(2,0);
    addEdge(2,3);
    addEdge(3,0);
    addEdge(3,1);
    addEdge(3,2);
    addEdge(1,4);
    addEdge(4,1);
    printGraph();
    bfs(0);
}
