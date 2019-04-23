#include<stdio.h>
#include<conio.h>
void swap(int *i,int *j)
{
    int temp=*i;
    *i=*j;
    *j=temp;
}
void main()
{
    int arr[]={7,8,2,3,6,5,1,9};
    int i,j;
    for(i=0;i<7;i++)
    {
        for(j=0;j<7-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
    for(i=0;i<8;i++)
    {
        printf("%d\t",arr[i]);
    }
}
