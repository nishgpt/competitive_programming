#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define MAX 300005
#define LIMIT 10000000000000000
#define getcx getchar_unlocked
 
 
inline void inp( int &n )
{ 
	n=0;    int ch=getcx();int sign=1;   
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();} 
	while(  ch >= '0' && ch <= '9' )    
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}   	
inline void inp1( LL &n )
{ 
	n=0;    LL ch=getcx();LL sign=1;   
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();} 
	while(  ch >= '0' && ch <= '9' )    
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}   
 
 
int n;
int a[MAX];
int maxi = -1;
 
int main() {
	int i, j;
	inp(n);
	LL left[MAX];
	LL right[MAX];
 
	for(i=0;i<n;i++) {
		inp(a[i]);
	}
	
	sort(a, a+n);
 
 
	for(i=n-1,j=0;i>=0;i--, j++) {
		if(j==0)left[j] = a[j];
		else left[j] = a[j] + left[j-1];
		
		if(i==n-1)right[i] = a[i];
		else right[i] = right[i+1] + a[i];
	}
	
	LL ans = LIMIT;
	for(i=0;i<n;i++) {
		LL cost;
		if(i == 0) {
			cost = (right[i+1] - ((LL)(n-i-1) * a[i]));				
		} else if(i == n-1) {
			cost = left[i-1];
		} else {
			cost = (right[i+1] - ((LL)(n-i-1) * a[i])) + left[i-1];
		}
		ans = min(ans, cost);
	}
	printf("%lld\n", ans);
	return 0;
} 