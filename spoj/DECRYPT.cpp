#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define max(x,y) x>y?x:y
#define min(x,y) x<y?x:y
#define abso(x) x<0?(-x):x
#define rep(i,n) for(i=0;i<n;i++)
#define rev(i,n) for(i=n;i>=0;i--)
#define getcx getchar_unlocked
using namespace std;
inline void inp( int &n ) 
{
    n=0;
    int ch=getcx();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
    n=n*sign;
}   

int main()
{
	char s[100100];
	int i,t,j,k,q,p;
	inp(t);
	while(t--)
	{
		inp(p);
		scanf("%s",s);
		for(i=0;s[i]!='\0';i++)
		{
			if(s[i]=='.')printf(" ");
			else 
			{
				j=(int)s[i];
			    q=p/26;k=p%26;
			    if(j>=65&&j<=90)
			    {
			    	j=j+k;if(j>90){j=j-90;j+=64;}
			    	if(q)j+=32;
			    }
			    else if(j>=97&&j<=122)
			    {
			    	j=j+k;if(j>122){j=j-122;j+=96;}
			    	if(q)j-=32;
			    }
			    printf("%c",j);
			}
		}
		printf("\n");
	}
	return 0;
}