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
#define MAX 1000001
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
const int m = 4*MAX+1;

int etf[m], ans[m];
void pre() {
	for(int i=0;i<m;i++) {
		etf[i] = i;
	}
	
	for(int i=2;i<m;i++) {
		if(i == etf[i]) { //prime number
			etf[i]--;
			for(int j=i*2;j<m;j+=i) {
				etf[j] = (etf[j]/i)*(i-1);
			}
		}
	}
	
	for(int i=1;i<m;i++) {
		ans[i] += i-1; //self
		for(int j=i*2;j<m;j+=i) {
			ans[j] += ((1+etf[j/i])/2) * i; //all divisors
		}
	}
}

void solve() {
	int k;in(k);
	
	printf("%d\n", ans[4*k+1]);
}

int main() {
	int t = 1;
	pre();
	cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
