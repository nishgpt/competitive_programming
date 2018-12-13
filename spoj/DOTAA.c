#include <stdio.h>
int main()
{
  int t,n,m,d,h,n1,i;
  scanf("%d",&t);
  while(t--)
  {
      scanf("%d %d %d",&n,&m,&d);h=0;
      for(i=0;i<n;i++)
      {
          scanf("%d",&n1);
          while(n1>d)
          {
              n1-=d;h++;
          }
      }
      if(h>=m){printf("YES\n");}
      else printf("NO\n");
  }
  return 0;
}
