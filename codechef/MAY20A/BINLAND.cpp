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
#define MAX 30005
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL (LL(1e18))
#define rep(i, a, n) for(i=a;i<n;i++)
#define rev(i, a, n) for(i=a;i>=n;i--)
#define MSV(A,a) memset(A, a, sizeof(A))
#define rep_itr(itr, c) for(itr = (c).begin(); itr != (c)._end(); itr++)

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
LL a[MAX][10][10];
int n, q, c, d, i, j, st=0, _end = -1;
vector<int> v[MAX];
void compute() {
	for(j=0;j<n;j++) {
		for(int k=0;k<n;k++) {
			if(k==j) a[st][k][j] = 1;
			else a[st][k][j] = 0;
		}
	}
	
	for(i=st+1;i<=_end;i++) {
		for(j=0;j<n;j++) {
			for(int k=0;k<n;k++) {
				a[i][k][j] = 0;
				if(v[st][k] != v[i][j]) continue;
				if(v[i][j] == v[i-1][j]) a[i][k][j] = (a[i][k][j] + a[i-1][k][j]) % MOD;
				if(j-1 >= 0 && v[i-1][j-1] == v[i][j]) a[i][k][j] = (a[i][k][j] + a[i-1][k][j-1]) % MOD;
				if(j+1 < n && v[i-1][j+1] == v[i][j]) a[i][k][j] = (a[i][k][j] + a[i-1][k][j+1]) % MOD;
			}
		}
	}
}
int main() {
	inp(n);inp(q);

	string op;
	string row;
	
	MSV(a, 0);
	
	bool computed = false;
	while(q--) {
		cin>>op;
		
		if(op[0] == 'a') { //add
			cin>>row;
			++_end;
			for(i=0;i<n;i++) v[_end].PB(row[i]-'0');
			computed = false;
		}
		
		else if(op[0] == 'r') { //remove
			++st;
			computed = false;
		}
		
		else { //path
			cin>>c>>d;
			--c;--d;
			if(st > _end) {
				printf("0\n");
				continue;
			}		
			
			if(!computed) {
				compute();
				computed = true;
			}
			
			printf("%lld\n", a[_end][c][d]);
		}
	}
    return 0;
}

