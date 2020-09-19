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
#define MAX 200005
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

LL dp[MAX];
//~LL call(int pos, vector<int> &steps, int n) {
	//~if(pos == n) return 1;
	//~if(dp[pos] != -1) return dp[pos];
	
	//~LL ans = 0;
	//~for(int i=0;i<steps.size();i++) {
		//~if(pos + steps[i] > n) break;
		//~ans = ans + call(pos+steps[i], steps, n);
		//~if(ans >= MOD) ans %= MOD;
	//~}
	
	//~return dp[pos] = ans;
//~}

void solve() {
	int n, k;
	in2(n, k);
	vector<pi> v;
	for(int i=0;i<k;i++) {
		int l, r;
		in2(l, r);
		v.PB(MP(l, r));
	}
	
	sort(v.begin(), v.end());
	
	dp[1] = 1;
	vector<LL> sum(MAX, 0);
	sum[1] = 1;
	for(int i=2;i<=n;i++) {
		LL cnt = 0;
		for(int j=0;j<k;j++) {
			if(i-v[j].X <= 0) break;
			LL temp = sum[i-v[j].X];
			
			int st = max(0, i-v[j].Y-1);
			temp = (temp - sum[st] + MOD) % MOD;
			cnt = (cnt + temp) % MOD;
		}
		dp[i] = cnt;
		sum[i] = (dp[i] + sum[i-1]) % MOD;
	}
	
	cout<<dp[n]<<en;
}

int main() {
	int t = 1;
	
	//~cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
