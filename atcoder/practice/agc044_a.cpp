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
#define INFL 1e18
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

typedef pair<LL, LL> pi; 

struct value {
	LL v = -1;
};

map<LL, value> dp;

LL a, b, c, d, n;
value call(LL num) {
	if(dp[num].v != -1) {
		return dp[num];
	}
	
	if(num == 0) {
		value val;
		val.v = 0;
		dp[num] = val;
		return dp[num];
	}
	
	LL all_d = d * num;
	if(all_d < 0) all_d = INFL;
	
	LL ans = INFL;
	ans = min(ans, all_d);
	if(num % 2 == 0) {
		ans = min(ans, call(num/2).v + a);
	} else {
		LL rem = num % 2;
		ans = min(ans, call(num/2).v + d*rem + a);
		if(num != 1) {
			rem = 2-rem;
			ans = min(ans, call((num+rem)/2).v + d*rem + a); 
		}
	}
	
	if(num % 3 == 0) {
		ans = min(ans, call(num/3).v + b);
	} else {
		LL rem = num % 3;
		ans = min(ans, call(num/3).v + d*rem + b);
		if(num != 1) {
			rem = 3-rem;
			ans = min(ans, call((num+rem)/3).v + d*rem + b); 
		}
	}
	
	if(num % 5 == 0) {
		ans = min(ans, call(num/5).v + c);
	} else {
		LL rem = num % 5;
		ans = min(ans, call(num/5).v + d*rem+c);
		if(num != 1) {
			rem = 5-rem;
			ans = min(ans, call((num+rem)/5).v + d*rem+c); 
		}
	}
	
	value ansv;
	ansv.v = ans;
	dp[num] = ansv;
	return dp[num];
}
int main() {
	int t;
	inp(t);
	
	while(t--) {
		inp1(n);inp1(a);inp1(b);inp1(c);inp1(d);
		value ans = call(n);
		dp.clear();
		cout<<ans.v<<endl;
	}

    return 0;
}

