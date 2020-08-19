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
	int n;
	in(n);
	unordered_map<int, int> mp;
	for(int i=0;i<n;i++) {
		int x;in(x);
		mp[x]++;
	}
	
	set<pi, greater<pi> > s;
	for(unordered_map<int, int> :: iterator it=mp.begin();it!=mp.end();++it) {
		s.insert(MP(it->second, it->first));
	}
	
	int ans = -1;
	int low = 0, high = n;
	while(low <= high) {
		int mid = (low + high) >> 1;
		set<pi, greater<pi> > temp = s;
		vector<pi> v;
		set<pi> :: iterator st;
		
		bool ok = true;
		for(int i=0;i<n;i++) {
			if(temp.empty()) {
				ok = false;
				break;
			}
			
			st = temp.begin();
			v.PB(*st);
			temp.erase(st);
			if(v.size() == mid+1) {
				for(int j=0;j<mid+1;j++) {
					if(v[j].X > 1) temp.insert(MP(v[j].X-1, v[j].Y));
				}
				v.clear();
			}
		}
		
		if(ok) {
			ans = mid;
			low = mid + 1;
		} else high = mid - 1;
	}
	
	cout<<ans<<en;
}

int main() {
	int t = 1;
	
	cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
