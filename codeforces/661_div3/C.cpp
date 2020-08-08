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
#define MAX 55
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
	int n;
	in(n);
	int a[n];
	int maxi = -1;
	for(int i=0;i<n;i++) {
		in(a[i]);
		maxi = max(maxi, a[i]);
	}
	
	int ms = -1;
	for(int i=1;i<=2*MAX;i++) {
		int f[MAX] = {0};
		for(int j=0;j<n;j++) f[a[j]]++;
		
		int tt = 0;
		for(int j=1;j<=maxi;j++) {
			if(i-j <= 0 || i-j >= MAX) continue;
			if(i-j == j) {
				tt += f[j]/2; 
				f[j]=0;
			}
			else {
				int x = min(f[j], f[i-j]);
				if(x > 0) {
					tt += x;
					f[j] = 0;
					f[i-j] = 0;
				}
			}
		}
		ms = max(ms, tt);
	}
	cout<<ms<<en;
}

int main() {
	int t = 1;
	
	cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
