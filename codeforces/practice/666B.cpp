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
#define INF 1000000000000000000
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

LL get_ans(vector<LL> &v, LL p, LL n) {
	LL ans = 0;
	for(int i=0;i<n;i++) {
		LL pp = pow(p, i);
		if(pp < 0) return INF;
		LL diff = abs(v[i] - pp);
		ans += diff;
	}
	return ans;
}

void solve() {
	int n;
	in(n);
	vector<LL> v(n);
	for(int i=0;i<n;i++) inl(v[i]);
	sort(v.begin(), v.end());
	
	LL n1 = pow(v[n-1], 1.0/(n-1));
	LL n2 = n1+1;
	//~chk2(n1, n2);
	LL g1 = get_ans(v, n1, n);
	LL g2 = get_ans(v, n2, n);
	//~chk2(g1, g2);
	cout<<min(g1, g2)<<en;
}

int main() {
	int t = 1;
	
	//~cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
