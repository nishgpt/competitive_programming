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
inline void inp( LL &n )
{ 
	n=0;    LL ch=getcx();LL sign=1;   
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();} 
	while(  ch >= '0' && ch <= '9' )    
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}   	

inline void inp1( int &n )
{ 
	n=0;    int ch=getcx();int sign=1;   
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();} 
	while(  ch >= '0' && ch <= '9' )    
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
} 
int a[2005][2005];LL mat[1005][1005]={0};

int main()
{
	int n,m,q,k,i,j,p,x1,x2,y1,y2;
	inp1(n);inp1(m);inp1(q);inp1(k);
	LL wt[1005],b[1005];
	rep(i,0,n)
	{
		rep(j,0,m)
		{
			inp1(a[i][j]);
			if(j)a[i][j]+=a[i][j-1];
		}
	}
	LL sum=0;
	rep(i,0,q)
	{
		inp1(x1);inp1(y1);inp1(x2);inp1(y2);
		x1--;x2--;y1--;y2--;
		sum=0;
		rep(j,x1,x2+1)
		{
			if(y1)sum+=(a[j][y2]-a[j][y1-1]);
			else sum+=a[j][y2];
		}
		b[i]=(x2-x1+1)*(y2-y1+1);
		wt[i]=sum;
	}
	//rep(i,0,q)printf("%lld %lld\n",wt[i],b[i]);
	//knapsack with sack weight 'k' wt[] , b[]
	rep(i,1,q+1)
	{
		rep(j,1,k+1)
		{
			if(wt[i-1]>j)mat[i][j]=mat[i-1][j];
			else if(wt[i-1]<=j)mat[i][j]=MAX(mat[i-1][j],(b[i-1]+mat[i-1][j-wt[i-1]]));
		}
	}
	printf("%lld\n",mat[q][k]);
	return 0;
}