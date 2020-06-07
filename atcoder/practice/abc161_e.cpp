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

void print(int *x, int n) {
	for(int i=0;i<n;i++) cout<<x[i]<<" ";
	cout<<endl;
}

void solve() {
	int n, k, c;
	cin>>n>>k>>c;
	string s;
	cin>>s;
	
	int left[n], right[n], lo[n];
	MSV(left, 0);
	MSV(right, 0);
	MSV(lo, -1);
	
	for(int i=n-1;i>=0;i--) {
		if(i == n-1) right[i] = (s[i] == 'o'); 
		else {
			if(s[i] == 'x') right[i] = right[i+1];
			else {
				right[i] = 1;
				if(i+c+1 < n) right[i] += right[i+c+1];
			}
		}
	}
	
	
	for(int i=0;i<n;i++) {
		if(s[i] == 'o') lo[i] = 1;
		if(i == 0) left[i] = (s[i] == 'o'); 
		else {
			lo[i] += lo[i-1];
			if(s[i] == 'x') left[i] = left[i-1];
			else {
				left[i] = 1;
				if(i-c-1 >= 0) left[i] += left[i-c-1];
			}
		}
	}
	
	int a[n+1];
	MSV(a, 0);
	
	for(int i=1;i<=c;i++) {
		if(right[i] < k) {
			a[0] += 1;
			a[i] -= 1;
		}
	}
	
	for(int i=c+1;i<n;i++) {
		if(right[i] + left[i-c-1] < k) {
			a[i]-=1;
			a[i-c-1]+=1;
		}
	}
	
	for(int i=n-c-1;i<n-1;i++) {
		if(left[i] < k) {
			a[i+1]+=1;
			a[n-1]-=1;
		}
	}
	for(int i=1;i<n;i++) {
		a[i] += a[i-1];
	}
	for(int i=0;i<n;i++) {
		if(a[i] && s[i] == 'o') cout<<i+1<<endl;
	}
}

int main() {
	int t = 1;
	
	//~cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
