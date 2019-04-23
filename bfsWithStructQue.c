#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
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
void bfs(int N,int graph[N][N],int source,Que *que,int visited[N])
{
    Enque(que,source);
    while(!isEmpty(que))
    {
        int d=Deque(que);
        printf("%d\t",d);
        visited[d]=1;
        int i;
        for(i=0;i<N;i++)
        {
            if(graph[d][i]==1&&visited[i]==0)
            {
                Enque(que,i);
            }
        }
    }
}
void main()
{
    printf("Enter No of node");
    int v;
    scanf("%d",&v);
    Que *que=createQue(v);
    printf("Enter adjancy matrix");
    int i,j,visited[v],graph[v][v];
    for(i=0;i<v;i++)
    {
        visited[i]=0;
        for(j=0;j<v;j++)
            scanf("%d",&graph[i][j]);
    }
    printf("Enter source of graph");
    scanf("%d",&i);
    bfs(v,graph,i,que,visited);

}
