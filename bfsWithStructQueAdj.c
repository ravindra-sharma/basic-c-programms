#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//fo graph
typedef struct Graph
{
    int data;
    struct Graph *link;
}node;
node *listi[5];
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
//Code for que
typedef struct QueStruct
{
    int f,r,siz,capa;
    int *arr;
}Que;
//for createQue
Que* createQue(int c)
{
    Que *que=(Que*)malloc(sizeof(Que));
    que->capa=c;
    que->f=que->siz=0;
    que->r=c-1;
    que->arr=(int*)malloc(c*sizeof(int));
    return que;
}
//for check if que is full
int isFull(Que *que)
{
    return (que->siz==que->capa);
}
//fo check if que is empty
int isEmpty(Que *que)
{
    return (que->siz==0);
}
//to insert in queue
void Enque(Que *que,int data)
{
    if(isFull(que))
        return;
    que->r=(que->r+1)%que->capa;
    que->arr[que->r]=data;
    que->siz=que->siz+1;
}
//to deque an element
int Deque(Que *que)
{
    if(isEmpty(que))
        return;
    int data=que->arr[que->f];
    que->f=(que->f+1)%que->capa;
    que->siz=que->siz-1;
    return data;
}
void bfs(int N,int source,Que *que,int visited[N])
{
    Enque(que,source);
    visited[source]=1;
    while(!isEmpty(que))
    {
        int d=Deque(que);
        printf("%d\t",d);
        node *temp=listi[d];
        while(temp!=NULL){
            if(visited[temp->data]==0)
            {
                Enque(que,temp->data);
                visited[temp->data]=1;
            }
            temp=temp->link;
            }
    }
}
void main()
{
    printf("Enter No of node as 5");
    int v;
    scanf("%d",&v);
    Que *que=createQue(v);
    int visited[v];
    int i=0,j=0;
    for(i=0;i<5;i++)
    {
        visited[i]=0;
        listi[i]=NULL;
    }
    while(i!=-1 && j!=-1)
    {
        printf("Enter source and destination if Wanna exit press -1 and -1\n");
        scanf("%d%d",&i,&j);
        addEdge(i,j);
    }
    printf("Enter source of graph");
    scanf("%d",&i);
    bfs(v,i,que,visited);
    printf("This is your graph\n");
    printGraph();

}
