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
#define MOD 998244353
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

void solve() {
	int n, m;
	in2(n, m);
	int mini = INT_MAX;
	vector<int> a(n), b(m);
	for(int i=0;i<n;i++) {in(a[n-i-1]);mini = min(a[n-i-1], mini);}
	for(int i=0;i<m;i++) in(b[i]);
	
	sort(b.rbegin(), b.rend());
	
	if(mini < b[m-1]) finish(0);
	//for b[0]
	int idx = -1;
	bool ok = true;
	bool f = false;
	for(int i=0;i<n;i++) {
		if(a[i] < b[0]) {
			ok = false;
			break;
		}
		if(b[0] == a[i]) {
			idx = i;
			f = true;
			break;
		}
	}
	
	if(!ok || !f) finish(0);
	
	int curr = 1;
	LL ans = 1;
	while(curr < m) {
		int prev = idx;
		f = false;
		for(int i=prev+1;i<n;i++) {
			if(a[i] < b[curr]) {
				ok = false;
				break;
			}
			if(b[curr] == a[i]) {
				f = true;
				idx = i;
				break;
			}
		}
		
		if(!ok || !f) finish(0);
		
		int bp = -1;
		for(int i=prev+1;i<=idx;i++) {
			if(b[curr-1] > a[i]) {bp = i;break;}
		}
		
		ans = (ans * (bp-prev)) % MOD;
		curr++;
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
