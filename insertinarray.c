#include<stdio.h>
void main()
{
    int i,n,s,a[100],p;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&p);
    for(i=n;i>p;i--)
        a[i]=a[i-1];

    scanf("%d",&s);
    a[p]=s;
    for(i=0;i<=n;i++)
        printf("%d\t",a[i]);
}
