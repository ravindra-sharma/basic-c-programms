#include<stdio.h>
int adj[3][3],que[3],visit[3],c=0,f=-1,r=-1;
void setstart(int i)
{
    f++;
    r++;
    que[f]=i;
    while(!(r==-1||f>r))
    {
        bfs(que[f]);
    }
}
void bfs(int i)
{
    int j=0;
    visit[i]=1;
    printf("%d",que[f]);
    f++;
    for(j=0;j<3;j++)
    {
            if(adj[i][j]==1&&visit[i]!=1)
            {
                r++;
                que[r]=j;
            }
    }

}
void main()
{
    int i,j;
    for(i=0;i<3;i++)
    {
        visit[i]=0;
        for(j=0;j<3;j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }
    printf("Enter starting node");
    scanf("%d",&i);
    setstart(i);
}
