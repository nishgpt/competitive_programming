#include <stdio.h>
#include <math.h>
int main()
{
    char a[5];long long int i,n,p,j,k,g;double l;
    scanf("%s",a);
    while(!(a[0]=='0'&&a[1]=='0'))
    {
        i=(int)a[0];
        i=i-48;j=(int)a[1];j=j-48;k=(int)a[3];k=k-48;
    n=((10*i)+j)*pow(10,k);
    l=log2(n);g=(int)l;p=2*(n-pow(2,g))+1;
    printf("%lld\n",p);scanf("%s",a);
    }
    return 0;
}