#include <stdio.h>
int main()
{
    int i,j,k,a[1420]={0},n,c=0,n1;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {scanf("%d",&n1);a[n1]++;}
    for(i=0;i<1420;i++)
    {
        while(a[i]--)
        {
            c++;if(a[i+30]){a[i+30]--;if(a[i+60]){a[i+60]--;if(a[i+90]){a[i+90]--;}}}
        }
    }
    printf("%d\n",c);
    return 0;
}