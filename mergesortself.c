#include<stdio.h>
#include<conio.h>
void mergeit(int arr[],int l,int u,int mid)
{
    int n1,n2;
    n1=mid-l+1;
    n2=u-mid;
    int i,j,L[n1],R[n2];
    for(i=0;i<n1;i++)
        L[i]=arr[l+i];
    for(j=0;j<n2;j++)
        R[j]=arr[mid+1+j];
    i=0;
    j=0;
    int k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=R[j];
        j++;
        k++;
    }
}
void mergesort(int arr[],int l,int u)
{
    if(l<u)
    {
        int mid=l+(u-l)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,u);
        mergeit(arr,l,u,mid);
    }
}

void printarray(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
}
void main()
{
    int arr[]={9,5,4,6,3,1};
    mergesort(arr,0,5);
    printarray(arr,6);
}
