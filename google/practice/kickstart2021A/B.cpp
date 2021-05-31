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
#define MAX 1002
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
	int n, m;
	in2(n, m);
	
	int a[n][m];
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			in(a[i][j]);
		}
	}
	
	int l[n][m], r[n][m], u[n][m], d[n][m];
	MSV(l, 0);
	MSV(r, 0);
	MSV(u, 0);
	MSV(d, 0);
	
	//precomputation
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(a[i][j]) {
				l[i][j] = 1;
				u[i][j] = 1;
				
				if(j-1>=0 && a[i][j-1]) l[i][j] += l[i][j-1];
				if(i-1>=0 && a[i-1][j]) u[i][j] += u[i-1][j];
			}
		}
	}
	
	for(int i=n-1;i>=0;i--) {
		for(int j=m-1;j>=0;j--) {
			if(a[i][j]) {
				r[i][j] = 1; d[i][j] = 1;
				
				if(j+1 < m && a[i][j+1]) r[i][j] += r[i][j+1];
				if(i+1 < n && a[i+1][j]) d[i][j] += d[i+1][j];
			}
		}
	}
	
	int cnt = 0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(a[i][j]) {
				int up = u[i][j], lt = l[i][j], rt = r[i][j], dn = d[i][j];
				cnt += max(0, min(up/2, rt) - 1);
				cnt += max(0, min(up, rt/2) - 1);
				
				cnt += max(0, min(rt/2, dn) - 1);
				cnt += max(0, min(rt, dn/2) - 1);
				
				cnt += max(0, min(dn/2, lt) - 1);
				cnt += max(0, min(dn, lt/2) - 1);
				
				cnt += max(0, min(lt/2, up) - 1);
				cnt += max(0, min(lt, up/2) - 1);
			}
		}
	}
	
	cout<<cnt<<en;
}

int main() {
	int t = 1;
	
	cin>>t;
	for(int i=1;i<=t;i++) {
		cout<<"Case #"<<i<<": ";
		solve();
	}
    return 0;
}
