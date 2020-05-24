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

int main() {
	int n, i;
	inp(n);
	
	int a[n];
	int x[MAX] = {0}, y[MAX] = {0};
	
	rep(i, 0, n) {
		inp(a[i]);
		if(i&1) y[a[i]]++;
		else x[a[i]]++;
	}
	
	pair<int, int> mx1, mx2, my1, my2;
	mx1.X = mx1.Y = mx2.X = mx2.Y = my1.X = my1.Y = my2.X = my2.Y = 0;
	for(i=1;i<MAX;i++) {
		if(x[i] >= mx1.Y) {
			mx2 = mx1;
			mx1.X = i;
			mx1.Y = x[i];
		} else if(x[i] > mx2.Y) {
			mx2.X = i;
			mx2.Y = x[i];
		}
		
		if(y[i] >= my1.Y) {
			my2 = my1;
			my1.X = i;
			my1.Y = y[i];
		} else if(y[i] > my2.Y) {
			my2.X = i;
			my2.Y = y[i];
		}
	}
	
	int ans = n;
	if(mx1.X != my1.X) {
		ans = min(ans, n - mx1.Y - my1.Y);
	} else {
		ans = min(ans, n - mx1.Y - my2.Y);
		ans = min(ans, n - mx2.Y - my1.Y);
	}
	
	cout<<ans<<endl;
    return 0;
}

