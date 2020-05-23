/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 100005
#define MOD 1000000007

using namespace std;

/* Factorial modulo MOD */
LL fact[MAX];
void factorial() {
	fact[0] = 1;
	for(int i=1;i<MAX;i++) {
		fact[i] = (i * fact[i-1]) % MOD;
	}
}

/* Modulo exponentiation */
LL power(LL base, LL exp, LL ans) {
	if(!exp) return ans % MOD;
	if(exp&1) ans = (ans * base) % MOD;
	return power((base * base) % MOD, exp>>1, ans);
}

/* nCr modulo MOD */
LL nCr(LL n, LL r) {
	if(n < r) return 0;
	LL numerator = fact[n];
	LL denominator = (fact[n-r] * fact[r]) % MOD;
	return (numerator * power(denominator, MOD-2, 1)) % MOD;
}

/* DFS on tree */
bool visited[MAX];
void dfs(int node, vector<int> adj[MAX]) {
	visited[node] = true;
	
	for(int i=0;i<adj[node].size();i++) {
		if(!visited[adj[node][i]]) {
			dfs(adj[node][i], adj);
		}
	}
	return ;
}

/* Dijkstra Algo */
int dijkstra(int s, int d, vector<pi> adj[MAX]) {
	int mincost[MAX], i;
	rep(i, 0, MAX) mincost[i] = INF;
	
	priority_queue<pi, vector<pi>, greater<pi> > pq;
	pq.push(MP(0, s));
	mincost[s] = 0;
	
	while(!pq.empty()) {
		pi _top = pq.top();
		pq.pop();
		int node = _top.Y;
		
		for(i=0;i<adj[node].size();i++) {
			int ch = adj[node][i].X;
			int wt = adj[node][i].Y;
			if(mincost[node] + wt < mincost[ch]) {
				mincost[ch] = mincost[node] + wt;
				pq.push(MP(mincost[ch], ch));
			} 
		}
	}
	
	return mincost[d];
}

int main() {

    return 0;
}

