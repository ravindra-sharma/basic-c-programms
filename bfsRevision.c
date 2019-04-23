#include<stdio.h>
#include<conio.h>
#include<malloc.h>
//for que implementation
#define A 5
#if A==5
struct Que{
    int f,r,capacity,siz;
    int *arr;
};
struct Que* createQue(int capa)
{
        struct Que *que=(struct Que*)malloc(sizeof(struct Que));
        que->capacity=capa;
        que->f=que->siz=0;
        que->r=capa-1;
        que->arr=(int *)malloc(capa*sizeof(int));
        return que;
}
void Enque(int item,struct Que *que)
{
    que->r=(que->r+1)%que->capacity;
    que->arr[que->r]=item;
    que->siz=que->siz+1;
}
int Deque(struct Que *que)
{
    int item=que->arr[que->f];
    que->f=(que->f+1)%que->capacity;
    que->siz=que->siz-1;
    return item;
}
int isFull(struct Que *que)
{
    return (que->siz==que->capacity);
}
int isEmpty(struct Que *que)
{
    return (que->siz==0);
}
#elif A==6
void bfs(int n,int source,int graph[n][n],int visited[n],struct Que *que)
{
    Enque(source,que);
    visited[source]=1;
    while(!isEmpty(que))
    {
        int d=Deque(que);
        printf("%d\t",d);
        int i;
        for(i=0;i<n;i++)
        {
            if(graph[d][i] && !visited[i])
            {
                Enque(i,que);
                visited[i]=1;
            }
        }
    }
}
#endif
struct Node
{
    int data;
    struct Node *link;
};
struct Node **listi;
struct Node* getNode(int d)
{
        struct Node *node=(struct Node*)malloc(sizeof(struct Node));
        node->data=d;
        node->link=NULL;
        return node;
}
void createEdge(int i,int j)
{
        if(listi[i]==NULL)
        {
            listi[i]=getNode(j);

        }
        else{
        struct Node *temp=listi[i];
        while(temp->link!=NULL)
        {
            temp=temp->link;
        }
        temp->link=getNode(j);
        }
}
void bfs(int n,int source,int visited[n],struct Que *que)
{
    Enque(source,que);
    visited[source]=1;
    while(!isEmpty(que))
    {
        int d=Deque(que);
        printf("%d\t",d);
        struct Node *temp=listi[d];
        while(temp!=NULL)
        {
            if(!visited[temp->data])
            {
                Enque(temp->data,que);
                visited[temp->data]=1;
            }
            temp=temp->link;
        }
    }
}
void main()
{
    int i=0,j=0,n;
    printf("Enter the no. of vertix in graph");
    scanf("%d",&n);
    int visited[n],source;
    struct Que *que=createQue(n);
    listi=(struct Node**)malloc(n*sizeof(struct Node*));
    for(i=0;i<n;i++)
    {
        listi[i]=NULL;
    }
    while(n)
    {
        scanf("%d%d",&i,&j);
        if(i!=-1 && j!=-1)
        createEdge(i,j);
        else
            break;
    }
    for(i=0;i<n;i++)
    {
        struct Node *temp=listi[i];
        printf("%d->",temp->data);
        while(temp!=NULL)
        {
            printf("%d->",temp->data);
            temp=temp->link;
        }
        printf("NULL\n");
    }
    printf("Enter the source of bfs");
    scanf("%d",&source);
   bfs(n,source,visited,que);


}
