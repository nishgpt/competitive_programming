#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define max(x,y) x>y?x:y
#define min(x,y) x<y?x:y
#define abso(x) (x)<0?(-x):(x)
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
	int i,j,t,tot,k,a[26],b[26];
	scanf("%d\n",&t);
	char s1[1000],s2[1000];
	while(t--)
	{
		gets(s1);gets(s2);tot=0;
		int odd=0,even=0;
		memset(a,0,sizeof a);memset(b,0,sizeof b);
		for(i=0;s1[i]!='\0';i++)
		{
			if(s1[i]>=65&&s1[i]<=90){s1[i]=s1[i]+32;}
			if(s1[i]>=97&&s1[i]<=122)
			  a[(int)s1[i]-97]++;
		}
		for(i=0;s2[i]!='\0';i++)
		{
			if(s2[i]>=65&&s2[i]<=90)s2[i]+=32;
			if(s2[i]>=97&&s2[i]<=122)
			  b[(int)s2[i]-97]++;
		}
		char ch;
		rep(i,26)
		{
			b[i]=abso((a[i]-b[i]));
			if(b[i]!=0)
			{
				if(b[i]&1)        //odd
				{odd++;ch=(char)(i+97);b[i]--;tot++;}
				else{even++;tot++;}   //even
			}
		}
		char ans[1000];int q=0;
		if(!tot)printf("YES\n");
		
		else            //making palindrome to be added
		{
			//printf("%d %d %d\n",tot,even,odd);
			if(odd>1){printf("NO LUCK\n");}
			else
			{
				for(i=0;i<26;i++)
				{
					b[i]=b[i]/2;
					while(b[i]--)
					ans[q++]=(char)(i+97);
				}
				ans[q]='\0';
				if(q>0)
				printf("%s",ans);
				if(odd==1)printf("%c",ch);
				for(i=q-1;i>=0;i--)printf("%c",ans[i]);printf("\n");
				ans[0]='\0';
			}
		}
	}
	return 0;
}