#include <stdio.h>
#define max(x,y) x>y?x:y
int main()
{
    int a[1000000],n,k,i,j,m=0,ma;
    scanf("%d",&n);
    char c=getchar();
    for(i=0;i<n;i++)
    {scanf("%d",&a[i]);}
    scanf("%d",&k);
    for(i=0;i<k;i++){if(m<a[i]){m=a[i];}}
    if(k==n){printf("%d",m);}
    else printf("%d ",m);
    for(i=1;i<=n-k;i++)
    {
        if(a[i-1]==m)
        {
           m=0;for(j=i;j<i+k;j++){if(m<a[j]){m=a[j];}} 
        }
        else m=max(a[i+k-1],m);
        if(i==n-k){printf("%d",m);}
        else printf("%d ",m);
    }
    return 0;
}