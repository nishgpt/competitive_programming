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
	int n, m, x, k;
	int i, j;
	cin>>n>>m>>x;
	
	int a[n][m];
	int c[n];
	for(i=0;i<n;i++) {
		for(j=0;j<=m;j++) {
			if(j == 0) cin>>c[i];
			else cin>>a[i][j-1];
		}
	}
	
	int mini_cost = INT_MAX;
	for(i=0;i<(1<<n);i++) {
		vector<int> b;
		for(j=0;j<n;j++) {
			if(i&(1<<j)) b.PB(j);
		}
		
		//compute all algo value
		int algo[m];
		MSV(algo, 0);
		int cost = 0;
		for(j=0;j<b.size();j++) {
			int book = b[j];
			cost += c[book];
			for(k=0;k<m;k++) {
				algo[k] += a[book][k];
			} 
		}
		
		bool possible = true;
		for(j=0;j<m;j++) {
			if(algo[j] < x) {possible = false;break;}
		}
		if(possible) mini_cost = min(mini_cost, cost);
	}
	
	if(mini_cost == INT_MAX) mini_cost = -1;
	cout<<mini_cost<<endl;
    return 0;
}

