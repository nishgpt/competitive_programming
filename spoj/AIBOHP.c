/*
  NISHANT GUPTA
  MNNIT ALLAHABAD
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define max(x,y) x>y?x:y
#define min(x,y) x<y?x:y
#define abso(x) x<0?(-x):x
#define rep(i,n) for(i=0;i<n;i++)
#define rev(i,n) for(i=n;i>=0;i--)

int main()
{
	int t,i,j,k,a[2][6110];
	char s[6101];
//inp(t);
	scanf("%d",&t);
	while(t--)
	{
		memset(a,0,sizeof a);
		scanf("%s",s);
		k=strlen(s);int f=0;
		for(i=1;i<=k;i++)
		{
			if(f==1){
			for(j=1;j<=k;j++)
			{
					if(s[i-1]==s[k-j])a[f][j]=a[f-1][j-1]+1;
					else a[f][j]=max(a[f-1][j],a[f][j-1]);
			}f=0;}
			else
			{
				for(j=1;j<=k;j++)
				{
					if(s[i-1]==s[k-j])a[f][j]=a[f+1][j-1]+1;
					else a[f][j]=max(a[f+1][j],a[f][j-1]);
				}f=1;
			}
		}
		f=(f==1?0:1);
		printf("%d\n",k-a[f][k]);
	}
	return 0;
}
