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
	int n, x;
	in2(n, x);
	LL a;
	vector<LL> vl, vg;
	
	for(int i=0;i<n;i++) {
		inl(a);
		if(a >= x) vg.PB(a);
		else vl.PB(a);
	}
	
	sort(vl.rbegin(), vl.rend());
	sort(vg.rbegin(), vg.rend());
	
	for(int i=1;i<vg.size();i++) vg[i] += vg[i-1];
	for(int i=1;i<vl.size();i++) vl[i] += vl[i-1];
	
	int i=0, j=0, done = 0;
	while(i<vg.size() && j<vl.size()) {
		int cnt = i+j+2;
		if((vg[i] + vl[j]) / cnt >= x) {
			j++;
			done = j;
		} else i++;
	}
	cout<<vg.size()+done<<en;
}

int main() {
	int t = 1;
	
	cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
