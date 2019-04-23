#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct que
{
    int siz,f,r,capacity;
    int *arr;
};
struct que* createQue(int c)
{
        struct que *Que=(struct que*)malloc(sizeof(struct que));
        Que->capacity=c;
        Que->f=Que->siz=0;
        Que->r=c-1;
        Que->arr=(int*)malloc(sizeof(Que->capacity*sizeof(int)));
        return Que;

}
int isFull(struct que *Que)
{
    return (Que->siz==Que->capacity);
}
int isEmpty(struct que *Que)
{
    return (Que->siz==0);
}
void Enque(struct que *Que ,int data)
{
    if(isFull(Que))
        return;
    Que->r=(Que->r+1)%Que->capacity;
    Que->siz=Que->siz+1;
    Que->arr[Que->r]=data;
}
int Deque(struct que *Que)
{
    if(isEmpty(Que))
        return 0;
    int data=Que->arr[Que->f];
    Que->f=(Que->f+1)%Que->capacity;
    Que->siz=Que->siz-1;
    return data;
}
void main()
{
    struct que *Que=createQue(100);
    Enque(Que,10);
    Enque(Que,11);
    Enque(Que,12);
    Enque(Que,13);
    printf("%d\n",Que->siz);
    int i,j=Que->siz;
    for(i=1;i<=j;i++)
        printf("%d\t",Deque(Que));

}
