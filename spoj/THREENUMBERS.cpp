#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define MAX 300005
#define LIMIT 10
#define getcx getchar_unlocked
#define mini(a, b) (a < b ? a : b)
#define maxi(a, b) (a > b ? a: b)
#include <signal.h>
 
 
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
 
LL get_divisors(LL a, LL b, LL x, LL hcf) {
	return (x/a) + (x/b) - (x / ((a*b)/hcf));
}
 
LL solve(LL a, LL b, LL n) {
	LL low = mini(a, b), high = (maxi(a, b)) * n + 1, mid;
	LL ans;
	LL cnt = 0;
	while(low<=high) {
		cnt++;
		if(cnt > 100000) raise(SIGABRT);
		mid = (low + high) >> 1;
		LL divi = get_divisors(a, b, mid, __gcd(a, b));
		if(divi < n) {
			low = mid + 1;
		}
		else {
			ans = mid;
			high = mid - 1;
		}
	}
	return ans;
}
 
int main() {
	LL t, a, b;
	LL n;
	scanf("%lld", &t);
	
	while(t--) {
		scanf("%lld %lld %lld", &a, &b, &n);
		printf("%lld\n", solve(a, b, n));
	}
	return 0;
}