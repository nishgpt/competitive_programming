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

int n, m;
string s[MAX];
pi ans[MAX][MAX][2];

bool valid(int i, int j) {
	return i>=0 && j>=0 && i<n && j<m;
}

pi sum(pi x, pi y) {
	return MP(x.X+y.X, x.Y+y.Y);
}

pi get_best(int p, pi rt, pi dn) {
	if(dn.X == 0 && dn.Y == 0) return rt;
	if(rt.X == 0 && rt.Y == 0) return dn;
	
	int drt = rt.X-rt.Y;
	int ddn = dn.X-dn.Y;
	
	if(p) {
		drt = drt * (-1);
		ddn = ddn * (-1);
	}
	
	if(drt >= ddn) {
		return rt;
	}
	return dn;
}

//p is player; 0 for Takahashi, 1 for Aoki
pi dfs(int p, int i, int j) {
	//~chk2(i, j);
	if(ans[i][j][p].X != INT_MIN) return ans[i][j][p];
		
	//right
	pi rt = MP(0, 0);
	if(valid(i, j+1)) {
		int pts = (s[i][j+1] == '+') ? 1 : -1;
		
		pi curr;
		if(!p) curr = MP(pts, 0);
		else curr = MP(0, pts);
		
		rt = dfs(!p, i, j+1);
		rt = sum(rt, curr);
	}
	
	//down
	pi dn = MP(0, 0);
	if(valid(i+1, j)) {
		int pts = (s[i+1][j] == '+') ? 1 : -1;
		
		pi curr;
		if(!p) curr = MP(pts, 0);
		else curr = MP(0, pts);
		
		dn = dfs(!p, i+1, j);
		dn = sum(dn, curr);
	}
	
	pi best = get_best(p, rt, dn);
	return ans[i][j][p] = best;
}

void solve() {
	for(int i=0;i<MAX;i++) for(int j=0;j<MAX;j++) {
		ans[i][j][0] = MP(INT_MIN, INT_MIN);
		ans[i][j][1] = MP(INT_MIN, INT_MIN);
	}
	
	in2(n, m);
	for(int i=0;i<n;i++) cin>>s[i];
	
	pi value = dfs(0, 0, 0);
	
	if(value.X > value.Y) finish("Takahashi");
	if(value.X < value.Y) finish("Aoki");
	finish("Draw");
}

int main() {
	int t = 1;
	
	//~cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
