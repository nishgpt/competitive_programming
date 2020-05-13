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
#define MOD 998244353 
#define INF 0x3f3f3f3f
#define INFL (LL(1e18))
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
	int m, n, q;
	LL x;
	inp(m);inp(n);inp(q);
	
	LL a[m][n], b[m][n];
	
	for(int i=0;i<n;i++) {
		inp1(x);
		for(int j=0;j<m;j++) {
			a[j][i] = x;
		}
	}
	
	b[0][0] = a[0][0];
	for(int i=1;i<n;i++) {
		b[0][i] = (a[0][i] * b[0][i-1]) % MOD;
	}
	
	for(int i=1;i<m;i++) {
		b[i][0] = (a[i][0] * b[i-1][0]) % MOD;
	}
	
	for(int i=1;i<m;i++) {
		for(int j=1;j<n;j++) {
			b[i][j] = (a[i][j] * (b[i-1][j] + b[i][j-1]) % MOD) % MOD;
		}
	}

	int k;
	while(q--) {
		inp(k);
		cout<<b[k-1][n-1]<<endl;
	}
    return 0;
}

