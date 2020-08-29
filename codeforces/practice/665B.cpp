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
	int z1, o1, t1, z2, o2, t2;
	cin>>z1>>o1>>t1;
	cin>>z2>>o2>>t2;
	
	int sum = 0;
	if(t1 > 0) {
		int x = min(t1, o2);
		t1 -= x;
		o2 -= x;
		sum += 2*x;
		
		x = min(t1, t2);
		t1 -= x;
		t2 -= x;
		
		x = min(t1, z2);
		t1 -= x;
		z2 -= x;
	}
	
	if(o1 > 0) {
		int x = min(o1, z2);
		o1-=x;z2-=x;
		
		x = min(o1, o2);
		o1-=x;o2-=x;
		
		x = min(o1, t2);
		o1-=x;t2-=x;
		sum -= 2*x;
	}
	
	cout<<sum<<en;
}

int main() {
	int t = 1;
	
	cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
