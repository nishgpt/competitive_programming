#include <stdio.h>
int main()
{
    int i,j,n,m,t,n1,max1,max2;char ch;
    scanf("%d",&t);
    while(t--)
    {
        ch=getchar();max1=-1;max2=-1;
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++){scanf("%d",&n1);if(max1<n1){max1=n1;}}
        for(i=0;i<m;i++){scanf("%d",&j);if(max2<j){max2=j;}}
        if(max1>=max2)printf("Godzilla\n");
        else printf("MechaGodzilla\n");
    }
    return 0;
}