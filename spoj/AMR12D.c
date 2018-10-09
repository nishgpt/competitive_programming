#include <stdio.h>
#include <string.h>

int main()
{
    int t,i,j,k,p;
    char s[11],c[11];
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {p=0;
        scanf("%s",s);
        j=strlen(s);
        for(k=j-1;k>=0;k--)
        c[p++]=s[k];
    c[p]='\0';
    if(!(strcmp(c,s)))
    printf("YES\n");
    else printf("NO\n");
    }
return 0;
}