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
#define MAX 500001
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

/* Union Find / DSU */
int parent[MAX];
int find(int u) {
	if (u == parent[u])return u;
	return parent[u] = find(parent[u]);
}

void _union(int u, int v) {
	parent[find(u)] = find(v);
}

bool valid_degree(int u, int v, int max_degree, vector<int> &degree) {
	return max_degree == -1 || (degree[u] <= max_degree && degree[v] <= max_degree);
}

void generate(int n, int max_degree) {
	//output number of nodes
	cout << n << en;

	int i, edges = 0;
	rep(i, 1, n + 1) parent[i] = i;

	vector<int> degree(n + 1, 0);

	while (edges < n - 1) {
		int u = 1 + rand() % n;
		int v = 1 + rand() % n;

		if (u != v && find(parent[u]) != find(parent[v]) && valid_degree(u, v, max_degree, degree)) {
			_union(u, v);
			degree[u]++; degree[v]++; edges++;
			cout << u << " " << v << en;
		}
	}
}

void generate_tree() {
	cout << "Enter number of nodes:";
	int n; in(n);
	if (n >= MAX) {
		cerr << "Maximum nodes allowed " << MAX - 1 << en;
		return;
	}

	cout << "Enter type of tree:" << en << "1 for Linear Tree" << en << "2 for Binary Tree" << en << "3 for N-ary Tree" << en;
	int type; in(type);

	switch (type) {
	case 1:
		generate(n, 1);
		break;
	case 2:
		generate(n, 2);
		break;
	case 3:
		generate(n, -1);
		break;
	default:
		cerr << "Invalid input for type!!" << en;
	}
}


int main() {
	srand(time(0));
	cout << "==============================Tree Generator==============================" << en;
	cout << "Output Format" << en << "First line contains a single integer N denoting number of nodes" << en;
	cout << "Next N-1 lines contain two integers U V denoting an edge b/w them" << en;
	cout << "==========================================================================" << en << en;
	generate_tree();
	return 0;
}