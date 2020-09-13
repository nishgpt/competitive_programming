/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int
#define getcx getchar_unlocked
#define X first
#define Y second
#define PB push_back
#define MP make_pair
#define MAX 100005
#define LOG_MAX 20
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL (LL(1e18))
#define chk(a) cerr << endl << #a << " : " << a << endl
#define chk2(a,b) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << endl
#define chk3(a,b,c) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << endl
#define chk4(a,b,c,d) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << "\t" << #d << " : " << d << endl
#define rep(i, a, n) for(i=a;i<n;i++)
#define rev(i, a, n) for(i=a;i>=n;i--)
#define in(x) scanf("%d", &x)
#define inl(x) scanf("%lld", &x)
#define in2(x, y) scanf("%d %d", &x, &y)
#define inl2(x, y) scanf("%lld %lld", &x, &y)
#define MSV(A,a) memset(A, a, sizeof(A))
#define rep_itr(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)
#define finish(x) {cout<<x<<'\n'; return;}
typedef pair<int, int> pi;
typedef pair<LL, LL> pl;
const char en = '\n';

LL dist(pl p1, pl p2) {
	return abs(p1.X-p2.X) + abs(p1.Y-p2.Y);
}

void solve() {
	int n;
	in(n);
	LL x, y;
	vector<pl> v;
	if(n == 1) finish(0);
	
	LL m1 = INT_MIN, m2 = INT_MIN, m4 = INT_MIN, m3 = INT_MIN;
	pl p1, p2, p3, p4;
	for(int i=0;i<n;i++) {
		inl2(x, y);
		v.PB(MP(x, y));
	}
	for(int i=0;i<n;i++) {
		if(m1 < v[i].X+v[i].Y) {
			m1 = v[i].X + v[i].Y;
			p1 = v[i];
		}
		if(m2 < -1*v[i].X + v[i].Y) {
			p2 = v[i];
			m2 = -1*v[i].X + v[i].Y;
		}
		if(m3 < v[i].X - v[i].Y) {
			p3 = v[i];
			m3 = v[i].X - v[i].Y;
		}
		if(m4 < -1*v[i].X - v[i].Y) {
			p4 = v[i];
			m4 = -1*v[i].X - v[i].Y;
		}
	}
	
	LL ans = INT_MIN;
	for(int i=0;i<n;i++) {
		ans = max(ans, dist(p1, v[i]));
		ans = max(ans, dist(p2, v[i]));
		ans = max(ans, dist(p3, v[i]));
		ans = max(ans, dist(p4, v[i]));
	}
	cout<<ans<<en;
}

int main() {
	int t = 1;
	
	//~cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
