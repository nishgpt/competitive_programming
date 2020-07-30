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
	int n, k, z;in(n);
	in2(k, z);
	
	vector<int> a(n), sum(n);
	for(int i=0;i<n;i++) {
		in(a[i]);
		sum[i] = a[i];
		if(i>0) sum[i] += sum[i-1];
	}

	int ans = 0;
	for(int i=0;i<n;i++) {
		int l = k-i;
		if(l < 0) break;
		
		int flip = 0;
		int s = sum[i];
		if(i+1<n) {
			int m = min(2*z, l);
			for(int j=1;j<=m;j++) {
				if(!flip) s+=a[i+1];
				else s+=a[i];
				flip = !flip;
			}
			l -= m;
			if(l > 0) {
				if(m&1) s += (sum[i+1+l]-sum[i+1]);
				else s += (sum[i+l]-sum[i]);
			}
		}
		ans = max(ans, s);
	}
	cout<<ans<<en;
}

int main() {
	int t = 1;
	
	cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
