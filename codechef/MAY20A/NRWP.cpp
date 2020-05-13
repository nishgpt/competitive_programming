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
#define INFL (1e18)
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
	int t, h, w, n, x, y;
	inp(t);
	
	while(t--) {
		inp(h);inp(w);inp(n);
		LL a[h+1][w+1];
		LL p[n+1];
		vector<pair<int, int> > v(n+1);
		for(int i=1;i<=h;i++) {
			for(int j=1;j<=w;j++) {
				inp1(a[i][j]);
			}
		}
		
		for(int i=1;i<=n;i++) {
			inp(x);inp(y);inp1(p[i]);
			v[i].X = x;
			v[i].Y = y;
		}
		
		vector<pair<int, int> > pairs;
		for(int i=1;i<=n;i++) {
			for(int j=i+1; j<=n;j++) {
				if(abs(v[i].X-v[j].X) + abs(v[i].Y-v[j].Y) == 1) {
					pairs.PB(MP(i, j));
				}
			}
		}
		
		LL ans = -1 * INFL;
		vector<int> ans_signs(n);
		for(int i=0;i<(1<<n);i++) {
			vector<int> signs(n, -1);
			for(int j=0;j<n;j++) {
				if(i & (1<<j)) {
					signs[j] = 1;
				}
			}
			
			//compute the value
			//Summation p*a[][]
			LL temp = 0;
			for(int j=0;j<n;j++) {
				temp += (p[j+1] * signs[j] * a[v[j+1].X][v[j+1].Y]);
			}
			
			for(int j=0;j<pairs.size();j++) {
				int p1 = pairs[j].X, p2 = pairs[j].Y;
				temp += p[p1] * signs[p1-1] * p[p2] * signs[p2-1]; 
			}
			
			//summation of pi*pj
			if(ans < temp) {
				ans = temp;
				ans_signs = signs;
			}
		}
		
		cout<<ans<<endl;
		for(int i=0;i<n;i++) cout<<ans_signs[i]<<" ";
		cout<<endl;
	}

    return 0;
}

