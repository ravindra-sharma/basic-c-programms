#include<stdio.h>
#include<conio.h>
int gra[5][5],visited[5],stak[5],t=-1;
void add_in_stak(int data)
{
    if(t==-1)
    {
         t=0;

    stak[t]=data;
    }
    else{
        t++;
        stak[t]=data;
    }

}
void dfs(int s)
{
    int d,i,v;
    add_in_stak(s);
    while(!stak_empty())
    {
        d=stak[t];
        printf("%d\t",d);
        visited[d]=1;
        t--;
        v=d;
        for(i=0;i<5;i++)
        {
            if(gra[v][i]==1&&visited[i]==0)
            {
                add_in_stak(i);
            }
        }
    }
}
int stak_empty()
{
    if(t<0||t>=4)
        return 1;
    else
        return 0;
}

void main()
{
    printf("Enter the value of graph");
    int i,j,s;
    for(i=0;i<5;i++)
     {
         visited[i]=0;
         for(j=0;j<5;j++)
            scanf("%d",&gra[i][j]);
     }
    printf("Enter the source node");
    scanf("%d",&s);
    dfs(s);
}
