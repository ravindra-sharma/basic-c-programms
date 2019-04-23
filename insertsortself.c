#include<stdio.h>
#include<conio.h>
void insort(int arr[],int n)
{
    int i,j,ele;
    for(i=1;i<n;i++)
    {
        ele=arr[i];
        j=i-1;
        while(j>=0 && ele<arr[j])
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=ele;
    }
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}

void main()
{
    int i,j,arr[]={9,5,2,6,3,4,1};
    insort(arr,7);
}
