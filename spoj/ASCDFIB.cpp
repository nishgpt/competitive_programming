/*
  NISHANT GUPTA
  MNNIT ALLAHABAD
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#define maxi(x,y) x>y?x:y
#define mini(x,y) x<y?x:y
#define abso(x) x<0?(-x):x
#define rep(i,n) for(i=0;i<n;i++)
#define rev(i,n) for(i=n;i>=0;i--)
#define llu long long unsigned int
#define getcx getchar_unlocked
using namespace std;
inline void inp( llu &n ) 
{
    n=0;
    llu ch=getcx();llu sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
    n=n*sign;
}   

llu a[2][2],ans[2][2];
llu fib(llu n)
{
		if(n==1)return 0;
	llu r,i,j,k,m,b[2][2];
    a[0][0]=1;a[0][1]=1;a[1][0]=1;a[1][1]=0;ans[0][0]=1;ans[0][1]=0;ans[1][0]=0;ans[1][1]=1;
    
       
       m=100000;n-=2;
        while(n!=0)
        {
            r=n%2;n/=2;
            if(r)
            {for(i=0;i<2;i++){for(j=0;j<2;j++){b[i][j]=0;}}
                for(i=0;i<2;i++)
                {
                    for(j=0;j<2;j++)
                    {
                        for(k=0;k<2;k++)
                        {
                            b[i][j]+=((ans[i][k]*a[k][j])%m);
                        }
                    }
                }
                for(i=0;i<2;i++){for(j=0;j<2;j++)ans[i][j]=b[i][j];}
            }
            for(i=0;i<2;i++){for(j=0;j<2;j++){b[i][j]=0;}}
            for(i=0;i<2;i++)
                {
                    for(j=0;j<2;j++)
                    {
                        for(k=0;k<2;k++)
                        {
                            b[i][j]+=((a[i][k]*a[k][j])%m);
                        }
                    }
                }
                for(i=0;i<2;i++){for(j=0;j<2;j++)a[i][j]=b[i][j];}
        }
        return ans[0][0]%m;
}      
int main()
{
    llu t,a,b,i,j,f1,f2,min,max,k,p,x=1,m=100000,freq[100000];
    scanf("%llu",&t);
    while(x<=t)
    {
		scanf("%llu %llu",&a,&b);memset(freq,0,sizeof freq);
		//printf("%llu\n",fib(n));
		f1=fib(a);
		f2=fib(a+1);
		k=b-1;
		min=mini(f1,f2);
		max=maxi(f1,f2);
		freq[f1]++;freq[f2]++;
		for(i=0;i<k;i++)
		{
			j=(f1+f2)%m;
			freq[j]++;
			f1=f2;f2=j;
			min=mini(j,min);
			max=maxi(j,max);
		}
		printf("Case %llu:",x++);
		//printf("%llu %llu\n",min,max);
		p=0;
		for(i=min;i<=max;i++)
		{	
			if(p==100)break;
			while(freq[i]--)
			{
				if(p==100)break;
				p++;
				printf(" %llu",i);
			}
		}
		printf("\n");
    }
    return 0;
}

