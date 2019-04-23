#include<stdio.h>
#include<conio.h>
int bs(int a[],int n,int l,int h)
{
    int mid=(l+(h-l))/2;
    if(l<=h){
    if(n==a[mid])
    {
        return 1;
    }
    else
    {
        if(n>a[mid])
        {
           return bs(a,n,mid+1,h);
        }
        else
        {
           return bs(a,n,l,mid-1);
        }
    }}
    return -1;
}
void main()
{
    int a[]={1,2,3,4,5,6};
    int r=bs(a,2,0,5);
    (r==-1)?printf("Element not found"): printf("Element found");
}
