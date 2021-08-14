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

void solve1() {
	int n; in(n); int i;
	int l, r;
	map<int, vector<int> > mp;
	vector<int> ll;
	rep(i, 0, n) {
		in2(l, r);
		mp[l].PB(r);
		ll.PB(l);
	}

	sort(ll.begin(), ll.end());

	bool ok = true;

	int st = -1;

	priority_queue<int, vector<int>, greater<int> > pq;
	while (true) {
		if (mp.find(st) != mp.end()) {
			rep(i, 0, mp[st].size()) {
				pq.push(mp[st][i]);
			}
		}

		if (pq.empty()) {
			int idx = lower_bound(ll.begin(), ll.end(), st) - ll.begin();
			if (idx >= ll.size()) {
				break;
			}

			st = ll[idx];
			rep(i, 0, mp[st].size()) {
				pq.push(mp[st][i]);
			}
		}

		if (st <= pq.top()) {
			pq.pop();
			st++;
		}
		else {
			ok = false;
			break;
		}
	}
	if (ok) printf("Yes\n");
	else printf("No\n");
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t = 1;

	in(t);
	while (t--) {
		solve1();
	}
	return 0;
}