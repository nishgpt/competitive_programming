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
	int n;in(n);
	LL a[n], l[n], r[n];
	for(int i=0;i<n;i++) inl(a[i]);
	
	MSV(l, 0);
	MSV(r, 0);
	for(int i=0;i<n;i++) {
		l[i] = a[i];
		if(i-2>=0) l[i] += l[i-2];
	}
	
	for(int i=n-1;i>=0;i--) {
		r[i] = a[i];
		if(i+2 < n) r[i] += r[i+2];
	}
	
	LL maxi = -1;
	for(int i=0;i<n;i++) {
		LL t1 = a[i], t2 = a[i];
		if(i+1<n) t1 = t1 + r[i+1];
		if(i-2>=0) t1 = t1 + l[i-2];
		
		if(i+2 < n) t2 += r[i+2];
		if(i-1>=0) t2 += l[i-1];
		
		maxi = max(maxi, max(t1, t2));
	}
	cout<<maxi<<en;
}

int main() {
	int t = 1;
	
	//~cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
