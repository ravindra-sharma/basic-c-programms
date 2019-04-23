#include<stdio.h>
#include<conio.h>
int graph[5][5]={{0,1,1,0,1},{1,0,0,1,0},{1,0,0,1,0},{0,1,1,0,1},{1,0,0,1,0}};
int curPath[5],inCurPath[5],n=-1;
void printPath()
{
    int i=0;
    for(i=0;i<=n;i++)
        printf("%d->",curPath[i]);
}
int inPath(int d)
{
    int i;
    for(i=0;i<=n;i++)
        if(inCurPath[i]==i)
            return 1;
    return 0;
}
void findpath(int s,int d)
{
    if(s==d)
    {
        printPath();
        int i;
        printf("\n");
        return;
    }
    else
    {
        int i;

        for(i=0;i<5;i++)
        {
            if(graph[s][i] && !inPath(i))
            {

                n++;
                inCurPath[n]=s;
                curPath[n]=i;
                findpath(i,d);
            }
        }
        n--;
    }

}
void main()
{
    int i;
    for(i=0;i<5;i++)
    {
        inCurPath[i]=0;
        curPath[i]=0;
    }
    findpath(0,4);
}
