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
#define MAX 10000007
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
typedef pair<int, int> pi;
typedef pair<LL, LL> pl;

bitset<MAX> prime;
vector<int> factor;
void pre() {
	prime.flip();
	factor.resize(MAX, 0);
	prime[0] = prime[1] = false;
	
	for(int i=2;i*i<MAX;i++) {
		if(prime[i])
			for(int j=i*i;j<MAX;j+=i) {
				prime[j] = false;
				if(!factor[j]) factor[j] = i;
			}
	}
}

pi get_ans(int num, int pf) {
	int c = num;
	int f = 1;
	while(c % pf == 0) {
		c/=pf;
		f*=pf;
	}
	
	if(c>1) return MP(f, c);
	else return MP(-1, -1);
}

void solve() {
	int n;
	scanf("%d", &n);
	int a[n];
	
	vector<int> ans1, ans2;
	for(int i=0;i<n;i++) {
		scanf("%d", &a[i]);
		if(prime[a[i]]) {ans1.PB(-1);ans2.PB(-1);continue;}
		
		pi ans = get_ans(a[i], factor[a[i]]);
		ans1.PB(ans.X);
		ans2.PB(ans.Y);
	}
	
	for(int i=0;i<n;i++) cout<<ans1[i]<<" ";
	cout<<"\n";
	for(int i=0;i<n;i++) cout<<ans2[i]<<" ";
	cout<<"\n";
}

int main() {
	pre();
	int t = 1;
	
	//~cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
