#include<stdio.h>
#include<conio.h>
int gra[5][5],visited[5],que[5],f=-1,r=-1;
void add_in_queue(int data)
{
    if(f==-1)
    {
         f=0;
         r=0;
    que[f]=data;
    }
    else{
        r++;
        que[r]=data;
    }

}
void bfs(int s)
{
    int d,i,v;
    add_in_queue(s);
    while(!que_empty())
    {
        d=que[f];
        printf("%d\t",d);
        visited[d]=1;
        f++;
        v=d;
        for(i=0;i<5;i++)
        {
            if(gra[v][i]==1&&visited[i]==0)
            {
                add_in_queue(i);
            }
        }
    }
}
int que_empty()
{
    if(f>r||f>4)
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
    bfs(s);
}
