#include<bits/stdc++.h>
using namespace std;
#define LL long long int
#define MOD 1000000007
#define MP make_pair
#define PB push_back
#define MS(a) memset(a, 0, sizeof a)
#define M 1000000
#define getcx getchar_unlocked
 
inline void inp( int &n )
{ 
	n=0;    int ch=getcx();int sign=1;   
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();} 
	while(  ch >= '0' && ch <= '9' )    
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}
 
vector<int> v[1000001];
LL ans[1000001];
LL p[1000001];
LL cum[1000001];
bool prime[1000001];
LL inv[1000001];
 
LL power(LL b, LL e, LL ans, LL mod) {
	if(!e) return ans%mod;
	if(e&1) ans = (ans*b)%mod;
	return power((b*b)%mod, e>>1, ans, mod);
}
 
 
void pre() {
 
	int i, j, k;
 
	//inverse
	inv[1] = 1;
	for(i=2;i<=M;i++) {
		inv[i] = power(i, MOD-2, 1, MOD);
	}
	prime[0] = prime[1] = true;
	for(i=4;i<=M;i+=2) {
		prime[i] = true;
	}
	for(i=3;i*i<=M;i+=2) {
		if(!prime[i]) {
			for(j=i*i;j<=M;j+=2*i) {
				prime[j] = true;
			}
		}
	}
 
	for(i=2;i*i<=M;i++) {
		if(prime[i] == false) {
			v[i].PB(i);
		}
		for(j=2*i;j<=M;j+=i) {
			if(i*i <= j && prime[i] == false) {
				v[j].PB(i);
			}
			if(i*i < j && prime[j/i] == false) {
				v[j].PB(j/i);
			}
		}
	}
	for(j=i+1;j<=M;j++) {
		if(prime[j] == false) {
			v[j].PB(j);
		}
	}
 
	ans[1] = 1;
	ans[2] = 2;
	p[2] = 2;
	cum[0] = 0;
	cum[1] = 1;
	cum[2] = 3;
	LL tmp, tmp2;
	for(i=3;i<=M;i++) {
		ans[i] = ans[i-1];
		for(j=0;j<v[i].size();j++) {
			tmp = ans[i];
 
			if(p[v[i][j]]) {
				tmp = (tmp*inv[p[v[i][j]]])%MOD;
			}
			else p[v[i][j]] = 1;
			tmp2 = i;
			int c = 0;
			while(tmp2 % v[i][j] == 0) {
				tmp2 = tmp2 / v[i][j];
				c++;
			}
			p[v[i][j]] += c;
			ans[i] = (tmp*p[v[i][j]]) % MOD;
 
		}
		//if(i<10)cout<<i<<" "<<ans[i]<<endl;
		cum[i] = (cum[i-1] + ans[i])%MOD;
	}
}
 
 
 
int main() {
	pre();
	int l, r, t;
	inp(t);
	while(t--) {
		inp(l);inp(r);
		LL cans = cum[r] - cum[l-1];
		if(cans < 0)cans += MOD;
		printf("%lld\n", cans);
	}
	return 0;
} 