#include<stdio.h>
#include<conio.h>
int gra[3][3],visited[3],stak[3],t=-1,flag=0,tra[3];
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
    tra[s]=1;
    while(!stak_empty())
    {
        d=stak[t];
        printf("%d\t",d);
        visited[d]=1;
        t--;
        v=d;
        for(i=0;i<3;i++)
        {
            if(gra[v][i]==1&&visited[i]==0)
            {
                if(tra[i]==1&&v!=i)
                {
                    flag=1;
                    return;
                }
                else{
                add_in_stak(i);
                tra[i]=1;
                }

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
    for(i=0;i<3;i++)
     {
         visited[i]=0;
         tra[i]=0;
         for(j=0;j<3;j++)
            scanf("%d",&gra[i][j]);
     }
    printf("Enter the source node");
    scanf("%d",&s);
    dfs(s);
    if(flag==1)
    {
        printf("There is a cycle");
    }
    else{
        printf("there is no cycle");
    }
}
