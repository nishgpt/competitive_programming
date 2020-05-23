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
#define MAX 1001
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

//~X = 107^2 × 1361^2 × 10000019

int n, m;
LL a[MAX][MAX];
LL dp[MAX][MAX][3][3][3];
vector<int> get_powers(LL num) {
	int p1 = 0;
	while(num % 107 == 0) {
		p1++; num/=107;
		if(p1 == 2) break;
	}
	
	int p2 = 0;
	while(num % 1361 == 0) {
		p2++; num/=1361;
		if(p2 == 2) break;
	}
	
	int p3 = 0;
	while(num % 10000019 == 0) {
		p3++; num/=10000019;
		if(p3 == 2) break;
	}
	
	vector<int> v;
	v.PB(p1);v.PB(p2);v.PB(p3);
	return v;
}

void init() {
	vector<int> v = get_powers(a[0][0]);
	dp[0][0][v[0]][v[1]][v[2]] = 1;
	
	for(int j=1;j<m;j++) {
		vector<int> p = get_powers(a[0][j]);
		for(int p1=0;p1<3;p1++) {
			int pow1 = min(2, p1 + p[0]);
			for(int p2=0;p2<3;p2++) {
				int pow2 = min(2, p2 + p[1]);
				for(int p3=0;p3<3;p3++) {
					int pow3 = min(2, p3 + p[2]);
					dp[0][j][pow1][pow2][pow3] = (dp[0][j][pow1][pow2][pow3] + dp[0][j-1][p1][p2][p3]) % MOD; 
				}
			}
		}
	}
	
	for(int i=1;i<n;i++) {
		vector<int> p = get_powers(a[i][0]);
		for(int p1=0;p1<3;p1++) {
			int pow1 = min(2, p1 + p[0]);
			for(int p2=0;p2<3;p2++) {
				int pow2 = min(2, p2 + p[1]);
				for(int p3=0;p3<3;p3++) {
					int pow3 = min(2, p3 + p[2]);
					dp[i][0][pow1][pow2][pow3] = (dp[i][0][pow1][pow2][pow3] + dp[i-1][0][p1][p2][p3]) % MOD; 
				}
			}
		}
	}
}

int main() {
	inp(n);inp(m);
	int i, j, p1, p2, p3, pow1, pow2, pow3;
	
	for(i=0;i<n;i++) for(j=0;j<m;j++) inp1(a[i][j]);
	init();
	//~for(i=0;i<m;i++) {
		//~rep(p1, 0, 3) {
			//~rep(p2, 0, 3) {
				//~rep(p3, 0, 3) {
					//~chk4(i, p1, p2, p3);
					//~chk(dp[0][i][p1][p2][p3]);
				//~}
			//~}
		//~}
	//~}
	
	for(i=1;i<n;i++) {
		for(j=1;j<m;j++) {
			vector<int> p = get_powers(a[i][j]);
			rep(p1, 0, 3) {
				pow1 = min(2, p1 + p[0]);
				rep(p2, 0, 3) {
					pow2 = min(2, p2 + p[1]);
					rep(p3, 0, 3) {
						pow3 = min(2, p3 + p[2]);
						dp[i][j][pow1][pow2][pow3] = (dp[i][j][pow1][pow2][pow3] + dp[i-1][j][p1][p2][p3]) % MOD;
						dp[i][j][pow1][pow2][pow3] = (dp[i][j][pow1][pow2][pow3] + dp[i][j-1][p1][p2][p3]) % MOD;
					}
				}
			}
		}
	}
	
	LL total = 0;
	rep(p1, 0, 3) {
		rep(p2, 0, 3) {
			rep(p3, 0, 3) {
				if(p1 == 2 && p2 == 2 && p3 >= 1) continue;
				total = (total + dp[n-1][m-1][p1][p2][p3]) % MOD;
			}
		}
	}
	
	printf("%lld\n", total);
	
    return 0;
}

