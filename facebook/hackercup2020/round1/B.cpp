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
	int n, m, k, s;
	inp(n);inp(m);inp(k);inp(s);
	
	vector<LL> p(n), q(m);
	
	//input and compute p[]
	for(int i=0;i<k;i++) inp1(p[i]);
	LL ap, bp, cp, dp;
	inp1(ap);inp1(bp);inp1(cp);inp1(dp);
	for(int i=k;i<n;i++) {
		p[i] = ((p[i-2]*ap) % dp + (p[i-1]*bp) % dp + cp) % dp + 1;
	}
	
	//input and compute q[]
	for(int i=0;i<k;i++) inp1(q[i]);
	LL aq, bq, cq, dq;
	inp1(aq);inp1(bq);inp1(cq);inp1(dq);
	for(int i=k;i<m;i++) {
		q[i] = ((q[i-2]*aq) % dq + (q[i-1]*bq) % dq + cq) % dq + 1;
	}
	
	sort(p.begin(), p.end());
	sort(q.begin(), q.end());
	
	LL low = 1, high = 2*max(dp, dq);
	LL ans = 0;
	while(low <= high) {
		LL mid = (low + high) >> 1;
		
		LL st = min(q[0],p[0]);
		int pidx = 0, qidx = 0;
		bool ok = true;
		while(pidx < n && qidx < m) {
			while(qidx < m) { //loop for q[]
				if(q[qidx] > p[pidx]) break;
				qidx++;
			}
			
			//if the left logs are not even possible in mid time units
			if(p[pidx] - st > mid) {
				ok = false;
				break;
			}
			
			while(qidx < m) {
				LL m1 = p[pidx]-st;
				LL m2 = q[qidx] - p[pidx];
				if(2 * min(m1, m2) + max(m1, m2) > mid) {
					st = q[qidx];
					pidx++;
					if(pidx < n) st = min(st, p[pidx]);
					break;
				}
				qidx++;
			}
		}
		
		if(qidx < m) ok = false;
		if(ok) {
			ans = mid;
			high = mid - 1;
		}
		else low = mid + 1;
	}
	
	printf("%lld\n", ans);
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
