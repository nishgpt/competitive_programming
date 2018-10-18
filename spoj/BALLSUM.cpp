#include <bits/stdc++.h>
using namespace std;
#define LL long long int

LL gcd(LL a,LL b)
{
	if(!b)
	return a;
	return gcd(b,a%b);
}
int main() {
	LL n, k;
	while(1) {
		cin>>n>>k;
		if(n == -1)break;
		if(k <= 1 || n <= 1){cout<<0<<"\n";continue;}
		LL x = k - 2;
		LL tot = n*(n-1)/2, g;
		if(!(x&1)) {
			x = x>>1;
			g = gcd(tot, x*(x+1));
			if(x*(x+1) == tot) printf("1\n");
			else if(x*(x+1) == 0) printf("0\n");
			else printf("%lld/%lld\n", x*(x+1)/g, tot/g);
		}
		else {
			x = (x+1)>>1;
			g = gcd(tot, x*(x+1) - x);
			if((x*(x+1) - x) == tot) printf("1\n");
			else if(x*x == 0) printf("0\n");
			else printf("%lld/%lld\n",(x*x)/g, tot/g);
		}
	}
	return 0;
}