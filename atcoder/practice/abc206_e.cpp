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
#define MAX 1000005
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

bitset<MAX> prime;
LL etf[MAX];
int d[MAX];
LL ans[MAX];
void compute_prime() {
	prime.flip(); //makes all true
	prime[0] = prime[1] = false;

	for (int i = 2; i * i < MAX; i++) {
		if (prime[i])
			for (int j = i * i; j < MAX; j += i) prime[j] = false;
	}
}

void pre() {
	compute_prime();

	etf[1] = 0; d[1] = 0;
	for (int i = 2; i < MAX; i++) {
		etf[i] = i;
		d[i] = 1;
	}

	for (int i = 2; i * i < MAX; i++) {
		for (int j = i; j < MAX; j += i) {
			if (i == j && prime[i]) {
				etf[j] = (etf[j] * (i - 1)) / i;
			}

			if (i * i <= j && prime[i]) {
				etf[j] = (etf[j] * (i - 1)) / i;
			}

			LL q = j / i;
			if (q * q > j && prime[q]) {
				etf[j] = (etf[j] * (q - 1)) / q;
			}

			if (i * i < j) d[j] += 2;
			else if (i * i == j) d[j]++;
		}
	}

	ans[0] = 0; ans[1] = 0;
	for (int i = 2; i < MAX; i++) {
		ans[i] = ans[i - 1];
		ans[i] += 2 * (i - (etf[i] + d[i]));
	}
}

void solve() {
	int l, r;
	in2(l, r);

	cout << d[r] << en;
	cout << ans[r] - ans[l - 1] << en;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	pre();
	int t = 1;

	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}