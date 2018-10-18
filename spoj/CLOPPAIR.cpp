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

struct Cmp {
	bool operator ()(const pair<pair<LL, LL>, LL> &a, const pair<pair<LL, LL>, LL> &b) {
		return a.X.Y < b.X.Y;
	}	
};

long double dist(pair<LL, LL> a, pair<LL, LL> b) {
	long double val = (a.X-b.X)*(a.X-b.X)*1.0 + (a.Y-b.Y)*(a.Y-b.Y)*1.0;
	return sqrt(val);
}

int main() {
	LL i, j, k, n, m, x, y;
	inp1(n);
	multiset<pair<pair<LL, LL>, LL>, Cmp> s;
	multiset<pair<pair<LL, LL>, LL>, Cmp> :: iterator it;
	vector<pair<pair<LL, LL>, LL> > p;
	rep(i,0,n) {
		inp1(x);inp1(y);
		p.PB(MP(MP(x, y), i));
	}
	sort(p.begin(), p.end());
	
	s.insert(p[0]);
	long double mini = 100000000000000000.0;
	// printf("%lf", mini);
	pair<LL, LL> ans;
	rep(i, 1, n) {
		it = s.begin();
		while(it != s.end()) {
			pair<LL, LL> temp = MP(it->first.first, it->first.second);
			if(p[i].X.X - temp.X > mini) {
				s.erase(it);
			}
			else {
				long double d = dist(p[i].X, temp);
				if(d < mini) {
					mini = d;
					ans = MP(it->second, p[i].second);
				//	cout<<mini<<" "<<ans.X<<" "<<ans.Y<<endl;
				}
			}
			it++;
		}
		s.insert(p[i]);
	}
	
	printf("%lld %lld %.6Lf\n", MIN(ans.X, ans.Y), MAX(ans.X, ans.Y), mini);
	return 0;
}