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
//#define MIN(a,b) (((a) >= (b)) ? (b) : (a))
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
#define rep(i, a, n) for( i = a; i < n; i++)
#define rev(i, a, n) for(int i = a; i > n; i--)
#define FORALL(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)
#define ALL(A) A.begin(), A.end()
#define LLA(A) A.rbegin(), A.rend()

inline void inp( int &n ) 
{
    n=0;
    int ch=getcx();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
    n=n*sign;
}   

int MIN(int x,int y)
{
	if(x<y)return x;
	return y;
}
int main()
{
	int i,j,k,a[100005][3],n,x=1;
	inp(n);
	while(n)
	{
		rep(i,0,n)
		{
			inp(a[i][0]);inp(a[i][1]);inp(a[i][2]);
		}
		int f=0;
		if(a[0][2]+a[0][1]<a[0][1]){f=1;a[0][2]+=a[0][1];}
		a[1][0]+=a[0][1];
		if(f==0)a[1][1]+=MIN(a[0][1],a[1][0]);
		else a[1][1]+=MIN(a[0][1],MIN(a[1][0],a[0][2]));
		
		if(f==0)a[1][2]+=MIN(a[0][1],a[1][1]);
		else a[1][2]+=MIN(a[0][1],MIN(a[1][1],a[0][2]));
		for(i=2;i<n;i++)
		{
			for(j=0;j<3;j++)
			{
				if(j==0)
					a[i][j]+=MIN(a[i-1][j],a[i-1][j+1]);
				else if(j==1)
					a[i][j]+=(MIN(MIN(a[i][j-1],a[i-1][j-1]),MIN(a[i-1][j],a[i-1][j+1])));
				else if(j==2)
					a[i][j]+=MIN(a[i-1][j],MIN(a[i][j-1],a[i-1][j-1]));
			}
		}
		printf("%d. %d\n",x++,a[n-1][1]);
		inp(n);
	}
	return 0;
}