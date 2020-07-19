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
#define MAX 5000
#define LIM 20000005
#define LOG_MAX 20
#define MOD 100000007
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


inline void inp( int &n ) { 
	n=0;    int ch=getcx();int sign=1;   
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();} 
	while(  ch >= '0' && ch <= '9' )    
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}

inline void inp1( LL &n ) { 
	n=0;    LL ch=getcx();LL sign=1;   
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();} 
	while(  ch >= '0' && ch <= '9' )    
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}

int np[MAX];
vector<int> a, b;
void pre() {
	np[0] = np[1] = 1;
	for(int i=2;i*i<MAX;i++) {
		if(np[i]) continue;
		for(int j=i*i;j<MAX;j+=i) np[j]=1;
	}
	
	for(int i=1;i<MAX;i++) {
		if(!np[i]) a.PB(i*i);
		else b.PB(i*i);
	}
}

void solve() {
	LL n, l, r;
	vector<LL> p(4);
	inp1(n);inp1(l);inp1(r);
	inp1(p[0]);inp1(p[1]);inp1(p[2]);inp1(p[3]);
	
	int i1 = lower_bound(a.begin(), a.end(), l) - a.begin();
	int i2 = upper_bound(a.begin(), a.end(), r) - a.begin();
	int x = i2-i1;
	LL p1 = (x * p[0]) % MOD;
	
	i1 = lower_bound(b.begin(), b.end(), l) - b.begin();
	i2 = upper_bound(b.begin(), b.end(), r) - b.begin();
	int y = i2-i1;
	LL p2 = (y * p[1]) % MOD;
	
	LL ans = (p1 + p2) % MOD;
	ans = (ans + (p[2] * (r-l+1-x-y)) % MOD) % MOD;

	printf("%lld\n", ans);
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
