#include<stdio.h>
#include<conio.h>
int c=1;
void bsearch(int n,int *arr,int start,int last)
{
    c++;
    int mid=(start+last)/2;
    if(*(arr+mid)==n)
    {
        printf("Element Found");
    }
    if(c<6)
    {
        if(mid<n)
        {
            bsearch(n,arr,mid,last);
        }
        else
        {
            bsearch(n,arr,start,mid);
        }
    }
    if(c>=6)
    {
        printf("Element not found");
    }

}
void main()
{
    int a[]={1,2,3,4,5};
    int i=6;
    bsearch(i,a,0,4);
}
