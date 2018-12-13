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

int main() {
	int t, i, j, k, l, r;
	LL mod;
	LL a[100005];
	inp(t);
	while(t--) {
		inp(l);inp(r);inp1(mod);
		if(mod == 1) {
			printf("%d\n", r-l+1);
			continue;
		}
		a[1] = a[2] = 1;
		int flag = 0;
		for(i=3;i<=r;i++) {
			a[i] = a[i-1] + a[i-2];
			if(a[i] >= mod) {
				a[i] %= mod;
			}
			if(a[i] == 0) {
				flag = 1;
				break;
			}
		}
		if(flag == 0) {
			printf("0\n");
			continue;
		}
		int first, last;
		if(i>=l)first = i;
		else {
			first = (l+i-1)/i*i;
		}
		last = r/i*i;
		int ans = 0;
		if(last >= first) {
			ans = last/i - first/i + 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}