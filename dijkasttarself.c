#include<stdio.h>
#include<conio.h>
#define n 5
#define infi 9999
int minindex(int d[n],int ss[n])
{
    int mini=infi,minin,i;
    for(i=0;i<n;i++)
    {
        if(d[i]<=mini && ss[i]!=1)
        {
            mini=d[i];
            minin=i;
        }
    }
    return minin;
}
void dijkastra(int graph[n][n],int s)
{
    int sptset[n],dis[n],i;
    for(i=0;i<n;i++)
    {
        sptset[i]=0;
        dis[i]=infi;
    }
    dis[s]=0;
    int u,v;
    for(i=0;i<n-1;i++)
    {
        u=minindex(dis,sptset);
        sptset[u]=1;
        for(v=0;v<n;v++)
        {
            if(graph[u][v] && dis[u]+graph[u][v]<dis[v])
            {
                dis[v]=dis[u]+graph[u][v];
            }
        }
    }
    for(i=0;i<n;i++)
        printf("\n%d from source is:=%d",i,dis[i]);
}
void main()
{
    int graph[n][n]={ {0,1,2,4,0},{1,0,0,0,1},{2,0,0,1,1},{4,0,1,0,0},{4,1,0,0,0}};
    dijkastra(graph,0);
}
