#include <stdio.h>
#include <string.h>
int main()
{
    int i,j,k,l,n,m,p,q,sum;
    char s[100000];char a[][4]={"063","010","093","079","106","103","119","011","127","107"};
    char ans[1000][4];
    scanf("%s",s);char n1[5]={'\0'};char n2[5]={'\0'};
    while(strcmp(s,"BYE"))
    {
        l=strlen(s);j=0;n=0;m=0;sum=0;
        for(i=0;i<l;i+=3)
        {p=0;q=0;
            if(s[i]=='+'){j=1;i-=2;continue;}
            else if(s[i]=='='){break;}
            if(j==0)
            {n1[p++]=s[i];n1[p++]=s[i+1];n1[p++]=s[i+2];
            for(k=0;k<10;k++){if(!(strcmp(n1,&a[k]))){break;}}
            n=n*10+k;
            }
            else if(j==1)
            {
                n2[q++]=s[i];n2[q++]=s[i+1];n2[q++]=s[i+2];
            for(k=0;k<10;k++){if(!(strcmp(n2,&a[k]))){break;}}
            m=m*10+k;
            }
            n1[0]='\0';n2[0]='\0';
        }
        sum=n+m;p=0;
        for(i=sum;i!=0;i/=10)
        {
            strcpy(&ans[p],&a[i%10]);p++;
        }
        printf("%s",s);
        for(i=p-1;i>=0;i--){printf("%s",ans[i]);}
        printf("\n");
        n1[0]='\0';n2[0]='\0';
        scanf("%s",s);
    }
    return 0;
}