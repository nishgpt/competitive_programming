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
#define MAX 500002
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

vector<int> divi[MAX];

void pre() {
	for(int i=1;i*i<=MAX;i++) {
		for(int j=i;j<MAX;j+=i) {
			if(i*i <= j) {
				divi[j].PB(i);
				if(i*i != j) divi[j].PB(j/i);
			}
		}
	}
	
	for(int i=1;i<MAX;i++) {
		sort(divi[i].begin(), divi[i].end());
	}
}
void solve() {
	int n, m; in2(n, m);
	
	LL ans = 0;
	for(int i=2;i<=n;i++) {
		int b = i;
		int x = m - (m%b);
		if(x >= MAX) raise(SIGABRT);
		if(x == 0) {
			ans = ans + b - 1;
		}
		else {
			ans = ans + (upper_bound(divi[x].begin(), divi[x].end(), b-1) - divi[x].begin());
		}
		//~chk2(b, ans);
	}
	cout<<ans<<en;
}

int main() {
	int t = 1;
	
	pre();
	cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
