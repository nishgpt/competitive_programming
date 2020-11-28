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

int parent[MAX];
int find(int u) {
	if(u == parent[u])return u;
	return parent[u] = find(parent[u]);
}

void _union(int u, int v) {
	parent[find(u)] = find(v);
}

const LL S_LIMIT = MOD;
const LL W_LIMIT = 1e6;
void solve() {
	int n;
	cin>>n;
	assert(n<MAX);
	
	LL slimit = rand() % S_LIMIT + 1; 
	cout<<n<<" "<<slimit<<en;
	
	for(int i=1;i<=n;i++) {
		parent[i] = i;
	}
	
	for(int i=1;i<n;i++) {
		while(true) {
			int u = (rand() % n) + 1;
			int v = (rand() % n) + 1;
			if(u == v || find(u) == find(v)) continue;
			
			int wt = rand() % W_LIMIT + 1;
			cout<<u<<" "<<v<<" "<<wt<<en;
			_union(u, v);
			break;
		}
	}
}

int main() {
	int t = 1;
	srand(time(0));
	//~cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
