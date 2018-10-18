#include <stdio.h>
int main()
{
    int n,m,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        if(!n&&!m)printf("0\n");
        else if(m==0||n==0)printf("0\n");
        else
        {
            int k=n-m;
            int j=(m-1)/2;//printf("%d %d",k,j);
            int g=k&j;//printf("%d\n",g);
            printf("%d\n",!g);
        }
    }
    return 0;
}
