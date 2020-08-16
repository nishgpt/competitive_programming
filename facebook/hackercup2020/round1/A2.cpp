//~Partially Correct : Need to rectify
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

void print_set(set<pl> &s, string name) {
	cout<<name<<en;
	set<pl> :: iterator it = s.begin();
	while(it != s.end()) {
		pl p = *it;
		cout<<p.X<<" "<<p.Y<<en;
		++it;
	}
}

void solve() {
	int n, k;
	inp(n);inp(k);	
	vector<LL> l(n), h(n), w(n);
	
	//input and compute l[]
	for(int i=0;i<k;i++) inp1(l[i]);
	LL al, bl, cl, dl;
	inp1(al);inp1(bl);inp1(cl);inp1(dl);
	for(int i=k;i<n;i++) {
		l[i] = ((l[i-2]*al) % dl + (l[i-1]*bl) % dl + cl) % dl + 1;
	}
	
	//input and compute w[]
	for(int i=0;i<k;i++) inp1(w[i]);
	LL aw, bw, cw, dw;
	inp1(aw);inp1(bw);inp1(cw);inp1(dw);
	for(int i=k;i<n;i++) {
		w[i] = ((w[i-2]*aw) % dw + (w[i-1]*bw) % dw + cw) % dw + 1;
	}
	//input and compute h[]
	for(int i=0;i<k;i++) inp1(h[i]);
	LL ah, bh, ch, dh;
	inp1(ah);inp1(bh);inp1(ch);inp1(dh);
	for(int i=k;i<n;i++) {
		h[i] = ((h[i-2]*ah) % dh + (h[i-1]*bh) % dh + ch) % dh + 1;
	}
	
	set<pl> ls, rs;
	LL minus1 = -1;
	LL currp = 0, prod = 1;
	set<pl> :: iterator lptr, rptr;
	set<pl> :: iterator lit, rit;	
	for(int i=0;i<n;i++) {
		//new range
		if(i == 0 || ls.empty()) {
			currp = (currp + 2 * (h[i] + w[i])) % MOD;
			prod = (prod * currp) % MOD;
			ls.insert(MP(l[i], l[i]+w[i]));
			rs.insert(MP(l[i]+w[i], l[i]));
			continue;
		}
		
		//this l[i] starts even after the last range, no overlap
		if(l[i] > (*rs.rbegin()).X) {
			currp = (currp + 2 * (h[i] + w[i])) % MOD;
			prod = (prod * currp) % MOD;
			ls.insert(MP(l[i], l[i]+w[i]));
			rs.insert(MP(l[i]+w[i], l[i]));
			continue;
		}
		
		//this l[i]+w[i] ends before the first range, no overlap
		if(l[i]+w[i] < (*ls.begin()).X) {
			currp = (currp + (2 * (h[i] + w[i])) % MOD) % MOD;
			prod = (prod * currp) % MOD;
			ls.insert(MP(l[i], l[i]+w[i]));
			rs.insert(MP(l[i]+w[i], l[i]));
			continue;
		}
		
		//check for l[i], first range whose end is >= l[i]
		lptr = lower_bound(rs.begin(), rs.end(), MP(l[i], minus1));
		//check for l[i]+w[i], first range whose start > l[i]+w[i]
		rptr = upper_bound(ls.begin(), ls.end(), MP(l[i]+w[i], minus1));
		
		rptr--; //converge to the range it overlaps with
		pl lpair = *lptr, rpair = *rptr;
		//this range lies entirely between two other ranges without overlap
		if(lpair.Y > rpair.X) {
			currp = (currp + (2 * (h[i] + w[i])) % MOD) % MOD;
			prod = (prod * currp) % MOD;
			ls.insert(MP(l[i], l[i]+w[i]));
			rs.insert(MP(l[i]+w[i], l[i]));
			continue;
		}
		
		//Now there are overlaps
		if(l[i] <= lpair.Y) {
			currp = (currp + 2 * (lpair.Y - l[i])) % MOD;
		}
		if(l[i]+w[i] >= rpair.Y) {
			currp = (currp + 2 * (l[i]+w[i] - rpair.Y)) % MOD;
		}
		
		pl prev_pair = MP(lpair.Y, lpair.X);
		lit = ls.find(prev_pair), rit = lptr;
		ls.erase(lit++);
		rs.erase(rit++);
		while(lit != ls.end()) {
			pl cpair = *lit;
			if(cpair.X > rpair.X) break;
			
			currp = (currp + 2 * (cpair.X - prev_pair.Y)) % MOD;
			currp = (currp - 2 * h[i] + MOD) % MOD;
			prev_pair = cpair;
			ls.erase(lit++);
			rs.erase(rit++);
		}
		prod = (prod * currp) % MOD;
		
		pl curr_range = MP(min(l[i], lpair.Y), max(l[i]+w[i], rpair.Y));
		ls.insert(curr_range);
		rs.insert(MP(curr_range.Y, curr_range.X));		
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
