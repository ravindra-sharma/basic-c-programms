#include<stdio.h>
#include<conio.h>
#define n 5
#define infi 9999
int minkey(int k[n],int ms[n])
{
    int i,mini=infi,minin;
    for(i=0;i<n;i++)
    {
        if(ms[i]==0 && k[i]<mini)
        {
            mini=k[i];
            minin=i;
        }
    }
    return minin;
}
void prims(int graph[n][n],int s)
{
    int parent[n],key[n],mstset[n],i,u,v;
    for(i=0;i<n;i++)
    {
        key[i]=infi;
        mstset[i]=0;
    }
    key[s]=0;
    parent[s]=-1;
    for(i=0;i<n-1;i++)
    {
        u=minkey(key,mstset);
        mstset[u]=1;
        for(v=0;v<n;v++)
        {
            if(mstset[v]==0 && graph[u][v] && graph[u][v]<key[v])
            {
                parent[v]=u;
                key[v]=graph[u][v];
            }
        }
    }
    printf("Edge   Weight\n");
   for (i = 1; i < n; i++)
      printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);

}
void main()
{
    int graph[n][n]={ {0,1,2,4,0},{1,0,0,0,1},{2,0,0,1,1},{4,0,1,0,0},{4,1,0,0,0}};
    prims(graph,0);
}
