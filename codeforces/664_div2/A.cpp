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
	int r, g, b, w;
	cin>>r>>g>>b>>w;
	
	int m1 = min(min(r, g), b);
	int m2 = max(0, m1 - 1);
	
	int o = 0;
	o += (r%2 == 1);
	o += (w%2 == 1);
	o += (g%2 == 1);
	o += (b%2 == 1);
	
	if(o <= 1) finish("Yes");
	
	o = 0;
	o += ((r-m1)%2 == 1);
	o += ((g-m1)%2 == 1);
	o += ((b-m1)%2 == 1);
	o += ((w+m1)%2 == 1);
	if(o <= 1) finish("Yes");
	
	o = 0;
	o += ((r-m2)%2 == 1);
	o += ((g-m2)%2 == 1);
	o += ((b-m2)%2 == 1);
	o += ((w+m2)%2 == 1);
	if(o <= 1) finish("Yes");
	
	finish("No");
}

int main() {
	int t = 1;
	
	cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
