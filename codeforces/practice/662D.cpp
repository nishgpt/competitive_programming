/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

#define LL long long int
#define getcx getchar_unlocked
#define X first
#define Y second
#define PB push_back
#define MP make_pair
#define MAX 2002
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

void solve() {
	int n, m;in2(n, m);
	int hz[n][m], up[n][m];
	string s[n];
	for(int i=0;i<n;i++) cin>>s[i];
	
	//horizontal compute
	for(int i=0;i<n;i++) {
		int x, y;
		for(y=0,x=0;y<m;y++) {
			if(y > 0 && s[i][y] != s[i][y-1]) {
				for(int j=x;j<y&&j<m;j++) {
					hz[i][j] = min(j-x+1, y-j); 
				}
				x = y;
			}
		}
		for(int j=x;j<y && j<m;j++) {
			hz[i][j] = min(j-x+1, y-j); 
		}
	}
	
	//up compute
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			int up_val = (i == 0 || s[i][j] != s[i-1][j]) ? 0 : up[i-1][j];
			up[i][j] = min(up_val + 1, hz[i][j]);
		}
	}
	
	LL ans = 0;
	//down compute + answer compute
	for(int i=n-1;i>=0;i--) {
		for(int j=0;j<m;j++) {
			int down_val = (i == n-1 || s[i][j] != s[i+1][j]) ? 0 : up[i+1][j];
			down_val = min(down_val + 1, hz[i][j]);
			ans += min(up[i][j], down_val);
			up[i][j] = down_val;
		}
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
