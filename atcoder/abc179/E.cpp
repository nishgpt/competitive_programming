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

vector<LL> v;
void solve() {
	LL n, x, m;
	inl2(n, x);inl(m);
	
	v.PB(0);
	v.PB(x);
	vector<LL> pos(m, -1);
	pos[x] = 1;
	
	LL idx = 2;
	LL loop = -1;
	for(idx=2;;idx++) {
		LL mod = (v[idx-1]*v[idx-1]) % m;
		if(pos[mod] != -1) {
			loop = pos[mod];
			break;
		}
		v.PB(mod);
		pos[mod] = idx; 
	}
	
	if(loop <= 0) raise(SIGABRT);
	
	idx--;
	for(LL i=1;i<=idx;i++) {
		v[i] += v[i-1];
	}
	
	if(n <= idx) {
		finish(v[n]);
	}
	
	LL ans = v[idx];
	n -= idx;
	LL sz = idx - loop + 1;
	LL sum_loop = v[idx] - v[loop-1];
	ans = ans + (sum_loop) * (n/sz);
	
	
	LL rem = n % sz;
	if(rem != 0) ans = ans + v[loop+rem-1] - v[loop-1];
	
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
