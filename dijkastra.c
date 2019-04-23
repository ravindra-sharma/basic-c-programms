#include<stdio.h>
int d[10],p[10];
void dij(int g[],int n,int s)
{
    int I=9999,i,j=1,flag[n];
    for(i=0;i<n;i++)
    {
        flag[i]=0;
        d[i]=I;
    }
    d[s]=0;
    while(!queempty())
    {
        i=mininque();
        s=s+i;
        for(j=0;j<n;j++)
        {
            if(a[i][j]>0)
            {
                relax(i,s,a[i][j]);
            }
        }
    }


}

void relax(u,v,w)
{
    if(d[v]>d[u]+w)
    {
        d[v]=d[u]+w;
        p[u]=u;
        flag[v]=1;
    }
}
void main()
{
    int i,j,adj[10][10],n,s;
    printf("enter the number of nodes");
    scanf("%d",&n);
    printf("enter your graph matrix");
    for(i=0;i<n;i++)
        for(j=0;j<n);j++)
            scanf("%d",&adj[i][j]);
    printf("enter source node");
    scanf("%d",&s);
    dij(adj,n,s);
}
