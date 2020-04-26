/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 100005
#define LOG_MAX 20
#define MOD 998244353
#define getcx getchar_unlocked

using namespace std;

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

LL power(LL base, LL exp, LL ans) {
	if(!exp) return ans % MOD;
	if(exp&1) ans = (ans * base) % MOD;
	return power((base * base) % MOD, exp>>1, ans);
}


int main() {
	int t, n, i;
	inp(t);
	
	while(t--) {
		inp(n);
		int a[n];
		map<int, int> freq;
		 for(i=0;i<n;i++) {
			 inp(a[i]);
			 freq[a[i]]++;
		 }
		 
		 int maxi = -1;
		 for(i=1;i<=MAX;i++) {
			if(freq[i] == 0) {
				maxi = i;
				break;
			}
		 }
		 
		 int total = n;
		 LL ans = 0;
		 LL prev = 0;
		 
		 for(i=1;i<=maxi;i++) {
			total -= freq[i];
			LL subsets = power(2, total, 1);
			if(prev != 0) {
				subsets = (subsets * prev) % MOD;
				prev = (prev * (power(2, freq[i], 1) - 1 + MOD) % MOD) % MOD;
			} else {
				prev = (power(2, freq[i], 1) - 1 + MOD) % MOD;
			}
			ans = (ans + (i * subsets) % MOD) % MOD;
		 }
		 
		 cout<<ans<<endl;
		 
	}
    return 0;
}

