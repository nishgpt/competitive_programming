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
#define MAX 300005
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
	int h, w, m;
	in2(h, w);in(m);
	
	vector<int> row[MAX];
	unordered_map<int, int> col;
	for(int i=0;i<m;i++) {
		int x, y;
		in2(x, y);
		row[x].PB(y);
		col[y]++;
	}
	
	unordered_map<int, int> :: iterator it = col.begin();
	set<pi> temp;
	while(it != col.end()) {
		temp.insert(MP(it->second, it->first));
		it++;
	}
	
	int ans = 0;
	for(int i=0;i<MAX;i++) {
		int rsz = row[i].size();
		if(rsz > 0) {
			for(int j=0;j<rsz;j++) {
				int curr = col[row[i][j]];
				temp.erase(temp.find(MP(curr, row[i][j])));
				temp.insert(MP(curr-1, row[i][j]));
			}
			
			pi maxi = *temp.rbegin();
			ans = max(ans, maxi.X + rsz);
			
			for(int j=0;j<rsz;j++) {
				int curr = col[row[i][j]];
				temp.erase(temp.find(MP(curr-1, row[i][j])));
				temp.insert(MP(curr, row[i][j]));
			}
		}
	}
	cout<<ans<<en;
}

int main() {
	int t = 1;
	
	//~cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
