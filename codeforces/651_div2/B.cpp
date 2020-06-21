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
#define MAX 1005
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
	int a[2*n];
	int mini=2, maxi = -1;
	for(int i=0;i<2*n;i++) {
		in(a[i]);
		maxi = max(maxi, a[i]);
	}

	bool done = false;
	vector<pi> final_ans;
	for(int x = mini; x<= maxi;x++) {
		vector<pi> ans;
		vector<int> v[MAX];
		bool f[MAX] = {false};
		
		for(int i=0;i<2*n;i++) {
			int d = a[i] % x;
			v[d].PB(i);
		}
		
		int total = 0;
		
		for(int i=1;i<v[0].size();i+=2) {
			ans.PB(MP(v[0][i], v[0][i-1]));
			f[v[0][i]] = true;
			f[v[0][i]] = true;
			total++;
			if(total == n-1) {
				done = true;
				final_ans = ans;
				break;
			}
		}
		
		if(done) break;
		
		for(int i=1;i<=(x-1)/2;i++) {
			int sz1 = v[i].size();
			int sz2 = v[x-i].size();
			int sz = min(sz1, sz2);
			for(int j=0;j<sz;j++) {
				total++;
				ans.PB(MP(v[i][j], v[x-i][j]));
				if(total == n-1) {
					done = true;
					final_ans = ans;
					break;
				}
			}
			if(done) break;
		}
		if(done) break;
		
		if(x % 2 == 0) {
			int z = x/2;
			for(int i=1;i<v[z].size();i+=2) {
				ans.PB(MP(v[z][i], v[z][i-1]));
				total++;
				if(total == n-1) {
					done = true;
					final_ans = ans;
					break;
				}
			}
			if(done) break;
		}
	}
	
	//~cout<<final_ans.size()<<en;
	for(int i=0;i<final_ans.size();i++) {
		cout<<final_ans[i].X+1<<" "<<final_ans[i].Y+1<<en;
	}
}

int main() {
	int t = 1;
	
	cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
