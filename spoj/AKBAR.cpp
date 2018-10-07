/*
	NISHANT GUPTA
	CSE-MNNIT ALLAHABAD
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <cctype>
#include <utility>
#include <map>
#include <string>
#include <climits>
#include <set>
#include <string>
#include <sstream>
#include <utility>
#include <ctime>
#include <cassert>
#include <fstream>
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> II;
typedef vector<long long> VLL;
typedef vector<bool> VB; 
#define SZ(A) ((int)A.size())
#define LEN(A) ((int)A.length())
#define MS(A) memset(A, 0, sizeof(A))
#define MSV(A,a) memset(A, a, sizeof(A))
#define MAX(a,b) ((a >= b) ? (a) : (b))
#define MIN(a,b) ((a >= b) ? (b) : (a))
#define ABS(a) (((a) > 0) ? (a) : (-a))
#define MP make_pair
#define X first
#define Y second
#define PB push_back
#define FOUND(A, x) (A.find(x) != A.end())
#define getcx getchar_unlocked
#define INF 0x3f3f3f3f
#define INFL (LL(1e18))
#define EPS 1e-12 
#define chkbit(s, b) (s & (1<<b))
#define setbit(s, b) (s |= (1<<b))
#define clrbit(s, b) (s &= ~(1<<b))
#define rep(i, a, n) for(i = a; i < n; i++)
#define rev(i, a, n) for(i = a; i > n; i--)
#define FORALL(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)
#define ALL(A) A.begin(), A.end()
#define LLA(A) A.rbegin(), A.rend()
inline void inp( int &n )
{ 
	n=0;    int ch=getcx();int sign=1;   
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();} 
	while(  ch >= '0' && ch <= '9' )    
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}   	
inline void inp1( LL &n )
{ 
	n=0;    LL ch=getcx();LL sign=1;   
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();} 
	while(  ch >= '0' && ch <= '9' )    
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}   	
 
vector<int> adj[1000006];
int visited[1000006];
int flag = 0, m;
void bfs() {
	int i, j;
	queue<pair<int, int> > q;
	
	int node, strength;
	for(j=0;j<m;j++) {
		inp(node);inp(strength);
		if(flag == 1)continue;
		
		if(visited[node] == 0) {
			q.push(MP(node, 0));
			visited[node] = node;
			while(!q.empty()) {
				int n = q.front().X;
				int l = q.front().Y;
				q.pop();
				for(i=0;i<adj[n].size();i++) {
					if(l+1 > strength) continue;
					if(visited[adj[n][i]] != 0 && visited[adj[n][i]] != node) {
						flag = 1; break;
					}
					if(visited[adj[n][i]] == 0) {
						q.push(MP(adj[n][i], l+1));
						visited[adj[n][i]] = node;
					}
				}
				if(flag == 1) break;
			}
		}
		else flag = 1;
	}
}
 
int main() {
	int t, i, j, k, n, r, u, v;
	inp(t);
	while(t--) {
		inp(n);inp(r);inp(m);
		for(i=1;i<=n;i++) {
			adj[i].clear();
			visited[i] = 0;
		}		
		for(i=0;i<r;i++) {
			inp(u);inp(v);
			adj[u].PB(v);
			adj[v].PB(u);
		}
		flag = 0;
		bfs();
		if(flag == 0) {
			for(i=1;i<=n;i++) {
				if(visited[i] == 0) {
					flag = 1;break;
				}
			}
		}
		if(flag) {
			printf("No\n");
		}
		else printf("Yes\n");
	}
	return 0;
} 