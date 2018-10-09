/*	NISHANT GUPTA	CSE-MNNIT ALLAHABAD*/
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
typedef long long LL;typedef vector<int> VI;typedef pair<int, int> II;typedef vector<long long> VLL;typedef vector<bool> VB; 
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

int main()
{
	int i,j,k,x,y,row[1235],col[5679],rpos[1235],cpos[5679];
	char c;
	rep(i,1,5679)
	{
		if(i<1235){row[i]=rpos[i]=i;/*printf("%d ",row[i]);*/}
		col[i]=cpos[i]=i;
		//printf("%d\n",col[i]);
	}
	while(scanf("%c",&c)!=EOF)
	{
		if(c=='R')
		{
			inp(x);inp(y);
			j=row[x];row[x]=row[y];row[y]=j;
			rpos[row[x]]=x;rpos[row[y]]=y;
		}
		else if(c=='C')
		{
			inp(x);inp(y);
			j=col[x];col[x]=col[y];col[y]=j;
			cpos[col[x]]=x;cpos[col[y]]=y;
		}
		else if(c=='Q')
		{
			inp(x);
			inp(y);
			x=row[x];y=col[y];
			k=(x-1)*5678+y;
			printf("%d\n",k);
		}
		else if(c=='W')
		{
			inp(x);
			j=x/5678+1;
			k=x%5678;
			if(!k){k=5678;j--;}
			printf("%d %d\n",rpos[j],cpos[k]);
		}
	}
	return 0;
}