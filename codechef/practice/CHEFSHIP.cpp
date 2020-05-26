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

void preprocess(string p, int* pie, int m) { 
    int len = 0, i = 1;   
    pie[0] = 0; 
    while (i < m) { 
        if (p[i] == p[len]) {
			pie[i] = ++len; i++; 
        } 
        else {  
            if (len) len = pie[len - 1];   
            else { 
				pie[i] = 0; i++; 
            } 
        } 
    } 
}

int get_period(int pie, int n) {
	if(pie >= (n+1)/2 && (n % (n-pie) == 0)) return n/(n-pie);
	return INF;
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		string s, rev;
		cin>>s;
		rev = s;
		int n = s.length();
		int f[n], r[n];
		reverse(rev.begin(), rev.end());
		
		preprocess(s, f, n);
		preprocess(rev, r, n);
		
		int ans = 0;
		for(int i=1;i<n;i+=2) {
			int len = i+1;
			int p1 = get_period(f[i], len);
			int p2 = get_period(r[n-len-1], n-len); 
			if(p1 && (p1 % 2) == 0 && p2 && (p2%2) == 0) {
				ans++;
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}

