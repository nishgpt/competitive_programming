/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>
 
#define LL long long int
#define getcx getchar_unlocked
#define X first
#define Y second
#define PB push_back
#define MP make_pair
#define MAX 100005
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL (LL(1e18))
#define chk(a) cerr << endl << #a << " : " << a << endl
#define chk2(a,b) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << endl
#define chk3(a,b,c) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << endl
#define chk4(a,b,c,d) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << "\t" << #d << " : " << d << endl
#define rep(i, a, n) for(i=a;i<n;i++)
#define rev(i, a, n) for(i=a;i>=n;i--)
#define MSV(A,a) memset(A, a, sizeof(A))
#define rep_itr(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)
 
using namespace std;
 
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

struct sfaction {
	int quotient;
	int arrival;
	int idx;
};

bool operator<(sfaction a, sfaction b) {
	if(a.quotient != b.quotient) {
		return a.quotient > b.quotient;
	}
	return a.arrival < b.arrival;
}
 
int main() {
	int n, k, i;
	inp(n);inp(k);
	
	int a[n], b[n], c[n];
	vector<pair<int, pair<int, int> > > ab;
	for(i=0;i<n;i++) inp(a[i]); 
	for(i=0;i<n;i++) inp(b[i]);
	for(i=0;i<n;i++) inp(c[i]);

	for(i=0;i<n;i++) {
		ab.PB(MP(a[i], MP(b[i], i)));
	}
	sort(ab.begin(), ab.end());
	
	priority_queue<int, vector<int>, greater<int> > pq;
	for(i=0;i<k;i++) pq.push(0);
	
	int factor = 3;
	int times[n], idx = 0, sq = n/factor;
	vector<pair<int, int> > blocks;
	for(int q=0;q<factor;q++) {
		blocks.PB(MP(idx, min(idx + sq, n)));
		idx = min(idx+sq, n);
	}
	if(idx < n) blocks.PB(MP(idx, n));
	
	for(int bi=0;bi<blocks.size();bi++) {
		int st = blocks[bi].X, e = blocks[bi].Y;
		chk2(st, e);
		vector<sfaction> ca;
		for(i=st;i<e;i++) {
			idx = ab[i].Y.Y;
			int arrival = ab[i].X;
			ca.PB((sfaction) {c[idx], arrival, idx});
		}
		sort(ca.begin(), ca.end());

		for(i=0;i<ca.size();i++) {
			int arrival = ca[i].arrival;
			idx = ca[i].idx;
			int prep_time = b[idx];
			
			int chef = pq.top();
			pq.pop();
			if(chef <= arrival) {
				times[idx] = arrival;
				pq.push(arrival + prep_time);
			} else {
				times[idx] = chef;
				pq.push(chef + prep_time);
			}
		}
	}
	
	for(i=0;i<n;i++) {
		cout<<times[i]<<" ";
		if(times[i] > 1000000000) raise(SIGABRT);
	}
	cout<<"\n";
    return 0;
}
