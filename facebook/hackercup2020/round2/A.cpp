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

struct info {
	LL s;
	LL x;
	LL y;
};

//sort by most requirement first
bool cmp1(info &a, info &b) {
	return (a.s-a.x) > (b.s-b.x);
}

void solve() {
	int n, k;
	inp(n);inp(k);
	
	//Input starts here********************
	vector<info> v(n);
	LL s, as, bs, cs, ds;
	for(int i=0;i<k;i++) {
		inp1(s);
		v[i].s = s;
	}
	inp1(as);inp1(bs);inp1(cs);inp1(ds);
	for(int i=k;i<n;i++) {
		LL p = ((v[i-2].s * as) % ds + (v[i-1].s * bs) % ds + cs) % ds;
		v[i].s = p;
	}
	
	LL x, ax, bx, cx, dx;
	for(int i=0;i<k;i++) {
		inp1(x);
		v[i].x = x;
	}
	inp1(ax);inp1(bx);inp1(cx);inp1(dx);
	for(int i=k;i<n;i++) {
		LL p = ((v[i-2].x * ax) % dx + (v[i-1].x * bx) % dx + cx) % dx;
		v[i].x = p;
	}
	
	LL y, ay, by, cy, dy;
	for(int i=0;i<k;i++) {
		inp1(y);
		v[i].y = y;
	}
	inp1(ay);inp1(by);inp1(cy);inp1(dy);
	for(int i=k;i<n;i++) {
		LL p = ((v[i-2].y * ay) % dy + (v[i-1].y * by) % dy + cy) % dy;
		v[i].y = p;
	}
	//Input ends here***********************
	
	sort(v.begin(), v.end(), cmp1);
	//take out extra into whoever requires
	LL ans = 0, more = 0;
	for(int i=0;i<n;i++) {
		if(v[i].s > v[i].x + v[i].y) {
			more += (v[i].s - (v[i].x + v[i].y));
			v[i].s = v[i].x + v[i].y;
		}
	}
	ans += more;
	
	for(int i=n-1;i>=0;i--) {
		if(more <= 0) break;
		if(v[i].s >= v[i].x) break;
		LL req = min(more, v[i].x - v[i].s);
		more -= req;
		v[i].s += req;
	}
	
	//sort again
	sort(v.begin(), v.end(), cmp1);
	
	if(more > 0) {
		for(int i=n-1;i>=0;i--) {
			int fill = min(v[i].y + v[i].x - v[i].s, more);
			more -= fill;
			v[i].s += fill;
		}
		if(more > 0) finish(-1);
		finish(ans);
	}
	
	LL left = 0;
	for(int i=0;i<n;i++) {
		if(v[i].s > v[i].x) left += (v[i].s-v[i].x);
	}
	
	for(int i=n-1;i>=0;i--) {
		if(left <= 0) break;
		if(v[i].s >= v[i].x) break;
		int req = min(v[i].x-v[i].s, left);
		left -= req;
		v[i].s += req;
		ans += req;
	}
	
	bool ok = true;
	for(int i=0;i<n;i++) {
		if(v[i].s > v[i].x + v[i].y || v[i].s < v[i].x) {
			ok = false;
			break;
		}
	}
	
	if(ok) finish(ans);
	finish(-1);
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
