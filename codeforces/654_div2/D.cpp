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

void solve() {
	
	int n, k;
	
	in2(n, k);
	
	int a[n][n];
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) a[i][j] = 0;
	
	int off = 1;
	int x=0, y=0;
	while(k>0) {
		a[x][y] = 1;k--;
		x++;y++;
		x %= n;
		if(x == 0) y = off++;
		y %= n;
	}
	
	int minr = INT_MAX, minc = INT_MAX;
	int maxr = -1, maxc = -1; 
	for(int i=0;i<n;i++) {
		int r = 0;
		for(int j=0;j<n;j++) {
			if(a[i][j]) r++;
		}
		maxr = max(maxr, r);
		minr = min(minr, r);
	}
	
	for(int i=0;i<n;i++) {
		int c = 0;
		for(int j=0;j<n;j++) {
			if(a[j][i]) c++;
		}
		maxc = max(maxc, c);
		minc = min(minc, c);
	}
	
	cout<<(maxr-minr) * (maxr-minr) + (maxc-minc) * (maxc-minc)<<en;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cout<<a[i][j];
		}
		cout<<en;
	}
}

int main() {
	int t = 1;
	
	cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
