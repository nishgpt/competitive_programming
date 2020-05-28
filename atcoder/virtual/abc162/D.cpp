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
#define MAX 4005
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

int main() {
	
	LL lr[MAX]= {0}, lg[MAX] = {0}, lb[MAX] = {0};
	LL tr = 0, tg = 0, tb = 0;
	
	string s;
	int n;
	cin>>n;
	cin>>s;
	
	
	for(int i=0;i<s.length();i++) {
		if(s[i] == 'R') {
			lr[i] = 1;
			tr++;
		} else if(s[i] == 'G') {
			lg[i] = 1;
			tg++;
		} else {
			lb[i] = 1;
			tb++;
		}
	}

	for(int i=1;i<MAX;i++) {
		lr[i] += lr[i-1];
		lg[i] += lg[i-1];
		lb[i] += lb[i-1];
	}
	
	LL ans = 0;
	for(int i=1;i<n-1;i++) {
		for(int d=0;d<i;d++) {
			int diff = i-d;
			
			if(s[i] == s[d]) continue;
			
			if(s[i] == 'R') {
				if(s[d] == 'G') {
					ans += (tb - lb[i]);
					if(i+diff < n && s[i+diff] == 'B') ans--;
				}
				else if(s[d] == 'B') {
					ans += (tg - lg[i]);
					if(i+diff < n && s[i+diff] == 'G') ans--;
				}
			}
			
			if(s[i] == 'G') {
				if(s[d] == 'B') {
					ans += (tr - lr[i]);
					if(i+diff < n && s[i+diff] == 'R') ans--;
				}
				else if(s[d] == 'R') {
					ans += (tb - lb[i]);
					if(i+diff < n && s[i+diff] == 'B') ans--;
				}
			}
			
			if(s[i] == 'B') {
				if(s[d] == 'G') {
					ans += (tr - lr[i]);
					if(i+diff < n && s[i+diff] == 'R') ans--;
				}
				else if(s[d] == 'R') {
					ans += (tg - lg[i]);
					if(i+diff < n && s[i+diff] == 'G') ans--;
				}
			}
		}
	}
	
	cout<<ans<<endl;
    return 0;
}

