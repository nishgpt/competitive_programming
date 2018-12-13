/*
	NISHANT GUPTA
	CSE-MNNIT ALLAHABAD
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <cctype>
#include <utility>
#include <map>
#include <string>
#include <climits>
#include <set>
#include <string>
#include <sstream>
#include <utility>
#include <ctime>
#include <cassert>
#include <fstream>
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> II;
typedef vector<long long> VLL;
typedef vector<bool> VB; 
#define SZ(A) ((int)A.size())
#define LEN(A) ((int)A.length())
#define MS(A) memset(A, 0, sizeof(A))
#define MSV(A,a) memset(A, a, sizeof(A))
#define MAX(a,b) ((a >= b) ? (a) : (b))
#define MIN(a,b) ((a >= b) ? (b) : (a))
#define ABS(a) (((a) > 0) ? (a) : (-a))
#define MP make_pair
#define X first
#define Y second
#define PB push_back
#define FOUND(A, x) (A.find(x) != A.end())
#define getcx getchar_unlocked
#define INF (int(1e9))
#define INFL (LL(1e18))
#define EPS 1e-12 
#define chkbit(s, b) (s & (1<<b))
#define setbit(s, b) (s |= (1<<b))
#define clrbit(s, b) (s &= ~(1<<b))
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rev(i, a, n) for(int i = a; i > n; i--)
#define FORALL(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)
#define ALL(A) A.begin(), A.end()
#define LLA(A) A.rbegin(), A.rend()
inline void inp( int &n )
{ 
	n=0;    int ch=getcx();int sign=1;   
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();} 
	while(  ch >= '0' && ch <= '9' )    
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}   	

int d[1000001],ans[1000001],a[1000001];
int main()
{
	int i,j,k=1,n;
	d[1]=1;
	rep(i,2,1000001)d[i]=2;
	for(i=2;i*i<=1000000;i++)
	{
		for(j=2*i;j<=1000000;j+=i)
		{
				if(i*i==j)d[j]++;
				else if(i*i<j)d[j]+=2;
		}
	}
	//rep(i,0,20)printf("%d\n",d[i]);
	int p,q,x=0;a[0]=a[1]=a[2]=a[3]=1;
	for(i=2;i*i<=1000000;i++)
	{
		for(j=2*i;j<=1000000;j+=i)
		{
			//if(j==999977)printf("%d %d\n",j,i);
			if(d[j]>3)
			{	
				p=i;q=j/i;
				if((d[j]%d[p])||(d[j]%d[q]))
				a[j]=1;
			}
			else a[j]=1;
		}
	}
//	printf("%d\n",d[999977]);
	rep(j,1,1000001)
	{
		if(!a[j]&&d[j]>3)ans[k++]=j;	
	}
	//printf("%d\n",ans[k-1]);
	for(i=108;i<k;i+=108)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
}