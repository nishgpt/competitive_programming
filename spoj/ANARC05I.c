#include <stdio.h>
int a[2002][2002];
int main()
{
    char s[1001];int i,j=1,n,m,ans;
    scanf("%s",s);
    while(s[0]!='Q')
    {
        n=1000;m=1000;ans=0;a[n][m]=j;
        for(i=0;s[i]!='Q';i++)
        {
            if(s[i]=='U'){n--;}
            else if(s[i]=='D'){n++;}
            else if(s[i]=='L'){m--;}
            else m++;
            if(a[n][m]==j)ans++;
            else a[n][m]=j;
        }
        printf("%d\n",ans);j++;
     scanf("%s",s);   
    }
    return 0;
}