#include<stdio.h>
#include<conio.h>
void swapit(int *i,int *j)
{
    int temp;
    temp=*i;
    *i=*j;
    *j=temp;
}
void main()
{
    int mini,i,j,arr[]={9,6,1,2,4,3,5};
    for(i=0;i<6;i++)
    {
        mini=i;
        for(j=i+1;j<7;j++){
            if(arr[j]<arr[mini]){
                mini=j;

            }
        }
        swapit(&arr[i],&arr[mini]);
    }
    for(i=0;i<7;i++)
        printf("%d\t",arr[i]);
}
