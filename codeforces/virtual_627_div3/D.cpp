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
#define MSV(A,a) memset(A, a, sizeof(A))
#define rep_itr(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)
typedef pair<int, int> pi;
typedef pair<LL, LL> pl;

void solve() {
	int n;
	cin>>n;
	int a[n], b[n];
	int d[n], pos = 0;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	for(int i=0;i<n;i++) {d[i] = a[i] - b[i];if(d[i] > 0) pos++;}
	
	sort(d, d+n);
	
	LL ans = 0;
	for(int i=0;i<n;i++) {
		if(d[i] > 0) ans += (n-i-1);
		else if(d[i] == 0) ans += pos;
		else {
			int key = -1 * d[i] + 1;
			int idx = lower_bound(d+i+1, d+n, key) - d;
			ans += (n-idx);
		}
	}
	cout<<ans<<endl;	
}

int main() {
	int t = 1;
	
	//~cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
