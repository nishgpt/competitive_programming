#include <stdio.h>
#include <string.h>
int main()
{
    int a[123]={0},b[123]={0},i,j,c,k;char s1[1005],s2[1005];
    while(scanf("%s\n%s",s1,s2)!=EOF)
    {
        for(i=97;i<123;i++){a[i]=0;b[i]=0;}
        for(i=0;i<strlen(s1);i++)
        {
            k=(int)s1[i];a[k]++;
        }
        for(i=0;i<strlen(s2);i++)
        {k=(int)s2[i];b[k]++;}
        for(i=97;i<123;i++)
        {
            if(a[i]>0&&b[i]>0)
            {
                j=a[i]<b[i]?a[i]:b[i];
                while(j--)
                printf("%c",(char)i);
            }
        }
        printf("\n");
    }
    return 0;
}