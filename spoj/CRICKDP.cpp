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
#define INF 0x3f3f3f3f
#define INFL (LL(1e18))
#define EPS 1e-12
#define chkbit(s, b) (s & (1<<b))
#define setbit(s, b) (s |= (1<<b))
#define clrbit(s, b) (s &= ~(1<<b))
#define rep(i, a, n) for(i = a; i < n; i++)
#define rev(i, a, n) for(i = a; i > n; i--)
#define FORALL(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)
#define ALL(A) A.begin(), A.end()
#define LLA(A) A.rbegin(), A.rend()
#define N 10005

inline void inp( int &n )
{ 
	n=0;    int ch=getcx();int sign=1;   
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();} 
	while(  ch >= '0' && ch <= '9' )    
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}   	
inline void inp1( LL &n )
{ 
	n=0;    LL ch=getcx();LL sign=1;   
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();} 
	while(  ch >= '0' && ch <= '9' )    
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}   

LL mat[N][505];
LL maxi(LL a, LL b) {
	if(a>b) return a;
	return b;
}

int main() {
    int t, i, j, k, n, m;
	inp(t);
	int a[N];
	int cost[N];
	while(t--) {
		inp(n);inp(k);inp(m);
		
		LL sum = 0;
		for(i=1;i<n+1;i++) {
			inp(a[i]);
			cost[i] = INF;
			sum += a[i];
		}

		int l, r, c;
		vector<int> v;
		for(i=0;i<m;i++) {
			inp(l);inp(r);inp(c);
			for(j=l;j<=r;j++) {
				cost[j] = MIN(cost[j], c);
			}
		}

        for(i=1;i<=n;i++) {
            if(cost[i] != INF && a[i] < 0)
                v.push_back(i);
        }

		int len = v.size();
		for(i=1;i<len+1;i++) {
			for(j=1;j<=k;j++) {
				if(cost[v[i-1]] > j) {
					mat[i][j] = mat[i-1][j];
				}
				else {
					mat[i][j] = maxi(mat[i-1][j], (-1)*a[v[i-1]] + mat[i-1][j-cost[v[i-1]]]);
				}
			}
		}
		printf("%lld\n", sum + mat[len][k]);
	}
	return 0;
}
