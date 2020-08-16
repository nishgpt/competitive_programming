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
#define MAX 1000005
#define LOG_MAX 20
#define MOD 1000000007
#define INF 0x3f3f3f3f
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
const LL INFL = 1e18;

multiset<LL> ms;
LL cost[MAX];
LL ans[MAX];
void solve() {
	LL n, m;
	inl2(n, m);
	ms.clear();
	for(int i=0;i<n;i++) {
		inl(cost[i]);
	}
	
	ms.insert(0);
	ans[n-1] = 0;
	for(int i=n-2;i>=0;i--) {
		LL mini = *(ms.begin());
		if(i > 0) {
			if(cost[i] == 0 || mini == INFL) ans[i] = INFL;
			else ans[i] = mini + cost[i];
		}
		else ans[i] = mini;
		if(i + m < n) ms.erase(ms.find(ans[i+m]));
		ms.insert(ans[i]);
	}
	cout<<((ans[0] == INFL) ? -1 : ans[0])<<en;
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
