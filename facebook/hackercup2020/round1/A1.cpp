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

void solve() {
	int n, k, w;
	inp(n);inp(k);inp(w);
	vector<LL> l(n), h(n);
	
	//input and compute l[]
	for(int i=0;i<k;i++) inp1(l[i]);
	LL al, bl, cl, dl;
	inp1(al);inp1(bl);inp1(cl);inp1(dl);
	for(int i=k;i<n;i++) {
		l[i] = ((l[i-2]*al) % dl + (l[i-1]*bl) % dl + cl) % dl + 1;
	}
	
	//input and compute h[]
	for(int i=0;i<k;i++) inp1(h[i]);
	LL ah, bh, ch, dh;
	inp1(ah);inp1(bh);inp1(ch);inp1(dh);
	for(int i=k;i<n;i++) {
		h[i] = ((h[i-2]*ah) % dh + (h[i-1]*bh) % dh + ch) % dh + 1;
	}
	
	LL prod = 1, currp = 0;
	int idx = 0;
	multiset<LL> ms;
	
	for(int i=0;i<n;i++) {
		//erase heights out of 'w' window 
		while(idx < i) {
			if(l[idx] + w >= l[i]) break;
			ms.erase(ms.find(h[idx]));
			++idx;
		}
		if(i == 0 || l[i] > l[i-1] + w) {
			currp = (currp + (2*(h[i]+w)) % MOD) % MOD;
			ms.clear();
			idx = i;
		}
		else {
			LL maxh = *(ms.rbegin());
			if(h[i] < maxh) {
				currp = (currp + (2*(l[i]-l[i-1])) % MOD) % MOD;
			}
			else {
				currp = (currp + (2*(h[i]-maxh+l[i]-l[i-1])) % MOD) % MOD;
			}
		}
		prod = (prod * currp) % MOD;
		ms.insert(h[i]);
	}
	
	printf("%lld\n", prod);
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
