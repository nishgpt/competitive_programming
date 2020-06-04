/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define getcx getchar_unlocked
#define X first
#define Y second
#define PB push_back
#define MP make_pair
#define MAX 500005
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

using namespace std;

vector<int> adj[MAX];
int n, m;
int a[MAX];
vector<int> ans;
bool vis[MAX];

int main() {
	scanf("%d %d", &n, &m);
	
	int x, y;
	for(int i=0;i<m;i++) {
		scanf("%d %d", &x, &y);
		adj[x].PB(y);
		adj[y].PB(x);
	}
	
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	for(int i=1;i<=n;i++) {
		scanf("%d", &a[i]);
		if(a[i] == 1) {pq.push(MP(a[i], i));vis[i] = true;}
	}

	if(pq.size() == 0) {cout<<-1<<endl; return 0;}
	
	bool plug = true;
	while(!pq.empty()) {
		pair<int, int> p = pq.top();
		pq.pop();
		int node = p.Y;
		int assign = p.X;
		
		set<int> s;
		for(int i=0;i<adj[node].size();i++) {
			if(a[adj[node][i]] > assign && !vis[adj[node][i]]) {
				vis[adj[node][i]] = true;
				pq.push(MP(a[adj[node][i]], adj[node][i]));
			}
			
			if(a[adj[node][i]] < assign) {
				s.insert(a[adj[node][i]]);
			}
			if(a[adj[node][i]] == assign) {
				plug = false;
				break;
			}
		}
		
		if(!plug || s.size() != assign-1) {
			plug = false;
			break;
		}
		ans.PB(node);
	}
	
	if(!plug) {cout<<-1<<endl;return 0;}
	
	for(int i=0;i<ans.size();i++) 
		cout<<ans[i]<<" ";
	cout<<endl;

    return 0;
}

