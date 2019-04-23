#include<stdio.h>
void main()
{
    char* str="agabnbn";
    int h=1;
    int i=0;
    int c=0;
    while(str[i]!='\0')
    {
        int j=0;
        for(j=0;j<i;j++)
        {
            if(str[i]==str[j])
            {
              c=0;
              break;
            }
            c++;
        }
        i++;
        if(c+1>h)
            h=c;

    }
    printf("%d",h);
}
