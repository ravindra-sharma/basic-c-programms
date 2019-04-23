#include<stdio.h>
int* getResult(int tar,int arr[],int n)
{
    int i,j,res[2];
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
    if(arr[i]+arr[j]==tar){res[0]=arr[i];
    res[1]=arr[j];}
    return res;
}
void main()
{
    int n;
    printf("Enter the number of element in an array\n");
    scanf("%d",&n);
    int arr[n];
    printf("Eneter the element in array\n");
    int i;
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Enter the target\n");
    int tar;
    scanf("%d",&tar);
    int *res=getResult(tar,arr,n);
    printf("solutionn is %d\t%d",*res,*(res+1));
}
