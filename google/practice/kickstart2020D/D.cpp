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

void solve() {
	int n, q;
	in2(n, q);
	
	vector<int> a(n, 0);
	vector<pi> r(n);
	for(int i=0;i<n-1;i++) {
		in(a[i]);
	}
	
	for(int i=0;i<n;i++) {
		if(i == 0) r[i] = MP(-1, a[i]);
		else if(i == n-1) r[i] = MP(a[i-1], -1); 
		else r[i] = MP(a[i-1], a[i]);
	}

	while(q--) {
		int pos, k;
		in2(pos, k);
		pos--;k--;
		
		vector<bool> vis(n, false);
		priority_queue<pi, vector<pi>, greater<pi> > pq;
		
		vector<int> ans;
		ans.PB(pos+1);
		vis[pos] = true;
		if(pos+1<n) pq.push(MP(a[pos], pos+1));
		if(pos-1>=0) pq.push(MP(a[pos-1], pos-1));
		
		while(!pq.empty()) {
			pi _top = pq.top();
			pq.pop();
			int room = _top.Y;
			ans.PB(room+1);
			vis[room] = true;
			
			if(room-1>=0 && !vis[room-1]) {
				pq.push(MP(r[room].X, room-1));
			}
			if(room+1<n && !vis[room+1]) {
				pq.push(MP(r[room].Y, room+1));
			}
		}
		cout<<ans[k]<<" ";
	}
	cout<<en;
}

int main() {
	int t = 1;
	
	cin>>t;
	for(int i=1;i<=t;i++) {
		cout<<"Case #"<<i<<": ";
		solve();
	}
    return 0;
}
