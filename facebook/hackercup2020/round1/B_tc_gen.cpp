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
	int n = 500000, m = 500000;
	LL hlimit = 123456;
	int k = n;
	cout<<n<<" "<<m<<" "<<k<<" 0"<<en;
	
	for(int i=0;i<n;i++) {
		printf("%lld ", rand() % hlimit + 1);
	}
	cout<<en;
	cout<<"0 0 0 "<<hlimit<<en;
	
	for(int i=0;i<m;i++) {
		printf("%lld ", rand() % (hlimit) + 1);
	}
	cout<<en;
	cout<<"0 0 0 "<<hlimit<<en;
}

int main() {
	int t = 10;
	
	//~cin>>t;
	cout<<t<<en;
	srand(time(0));
	while(t--) {
		solve();
	}
    return 0;
}
