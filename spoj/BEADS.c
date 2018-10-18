#include <stdio.h>
#include <string.h>
int fun(int i,int j,int l,char s[])
{
    int k;
    for(k=0;k<l;k++,i++,j++)
    {
    if(i==l)i=0;
    if(j==l)j=0;
    if(s[i]!=s[j])return s[i]-s[j];
    }
    return 0;
}
int main()
{
    char s[10050];int i,ans,l,n,k;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",s);
        l=strlen(s);ans=0;
        for(i=0;i<l;i++)
        {
          k=fun(ans,i,l,s);
          if(k>0)ans=i;
        }
        printf("%d\n",ans+1);
    }
    return 0;
}