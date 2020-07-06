/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>
using namespace std;

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
#define in(x) scanf("%d", &x)
#define inl(x) scanf("%lld", &x)
#define in2(x, y) scanf("%d %d", &x, &y)
#define inl2(x, y) scanf("%lld %lld", &x, &y)
#define MSV(A,a) memset(A, a, sizeof(A))
#define rep_itr(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)
#define finish(x) {cout<<x<<'\n'; return;}
typedef pair<int, int> pi;
typedef pair<LL, LL> pl;
const char en = '\n';

/* Mulmod */
LL mulmod(LL a, LL b) {
	a = (a + MOD) % MOD;
	b = (b + MOD) % MOD;
	LL res = 0;
    a %= MOD; 
  
    while(b) { 
        if(b&1) res = (res+a)%MOD; 
        a = (a*2)%MOD; 
        b >>= 1;
    }
    return res; 
}

void solve() {
	int n, k;
	in2(n, k);
	
	LL a[n];
	for(int i=0;i<n;i++) inl(a[i]);
	
	sort(a, a+n); 
    LL prod = 1;
    if(!a[n-1] && (k%2 == 1)) finish(0);
  
    if(a[n-1] <= 0 && (k%2 == 1)) { 
        for(int i=n-1;i>=n-k;i--) {
			prod = mulmod(prod, a[i]);
		}
        finish(prod);
    } 
  
    int i=0, j=n-1; 
  
    if(k&1) { 
        prod = mulmod(prod, a[j]);
        j--; k--; 
    } 
    k = k/2;
  
    for(int idx=0;idx<k;idx++) { 
        LL l = a[i]*a[i + 1]; 
        LL r = a[j]*a[j - 1]; 
        if(l>r) { 
            prod = mulmod(prod, l);
            i+=2; 
        } else { 
            prod = mulmod(prod, r);
            j-=2; 
        } 
    } 
    cout<<prod<<en;
}

int main() {
	int t = 1;
	
	//~cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
