#include<stdio.h>
#include<conio.h>
void swapit(int *i,int *j)
{
    int temp=*i;
    *i=*j;
    *j=temp;
}
int partit(int arr[],int l,int h)
{
    int pi=arr[h];
    int i=l-1,j;
    for(j=l;j<h;j++)
    {
        if(pi>arr[j])
        {
            i++;
            swapit(&arr[i],&arr[j]);
        }
    }
    swapit(&arr[i+1],&arr[h]);
    return i+1;
}
void quick(int arr[],int l,int h)
{
    if(l<h)
    {
        int pi=partit(arr,l,h);
        quick(arr,l,pi-1);
        quick(arr,pi+1,h);
    }
}
void main()
{
    int arr[]={9,2,3,6,5,7,4};
    quick(arr,0,6);
    int i;
    for(i=0;i<7;i++)
    {
        printf("%d\t",arr[i]);
    }
}
