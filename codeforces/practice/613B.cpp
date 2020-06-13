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
	LL a[n], maxi = -1 * (1e18);
	LL sum = 0, l[n], r[n];
	for(int i=0;i<n;i++) {
		cin>>a[i];
		sum+=a[i];
		l[i] = sum;
	}
	for(int i=n-1;i>=0;--i) {
		r[i] = (i==n-1) ? a[i] : (r[i+1] + a[i]);
	}
	
	for(int i=0;i<n;i++) {
		if(i == 0) maxi = max(maxi, r[i+1]);
		else if(i == n-1) maxi = max(maxi, l[i-1]);
		else maxi = max(maxi, max(r[i+1], l[i-1]));
	}
	
	cout<<((sum > maxi) ? "YES" : "NO")<<endl;
}

int main() {
	int t = 1;
	
	cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
