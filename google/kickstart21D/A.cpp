/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>
#include<unordered_map>
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

void solve() {
	int a[3][3];
	for (int i = 0; i < 3; i++) in(a[0][i]);
	in(a[1][0]); in(a[1][2]);
	for (int i = 0; i < 3; i++) in(a[2][i]);

	int ans = 0;
	//row
	for (int i = 0; i < 3; i++) {
		if (i != 1) {
			if (a[i][1] - a[i][0] == a[i][2] - a[i][1]) ans++;
		}
	}

	//column
	for (int i = 0; i < 3; i++) {
		if (i != 1) {
			if (a[1][i] - a[0][i] == a[2][i] - a[1][i]) ans++;
		}
	}

	//remaining
	unordered_map<int, int> mp;
	int x1 = a[1][0] + ((a[1][2] - a[1][0]) / 2);
	if ((a[1][2] - a[1][0]) % 2 == 0) mp[x1]++;

	int x2 = a[0][1] + ((a[2][1] - a[0][1]) / 2);
	if ((a[2][1] - a[0][1]) % 2 == 0) mp[x2]++;

	int x3 = a[0][0] + ((a[2][2] - a[0][0]) /  2);
	if ((a[2][2] - a[0][0]) % 2 == 0) mp[x3]++;

	int x4 = a[2][0] + ((a[0][2] - a[2][0]) /  2);
	if ((a[0][2] - a[2][0]) % 2 == 0) mp[x4]++;

	int maxi = 0;
	unordered_map<int, int> :: iterator it = mp.begin();
	while (it != mp.end()) {
		maxi = max(maxi, it->second);
		it++;
	}

	ans += maxi;
	cout << ans << en;
}

int main() {

	int t = 1;

	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
