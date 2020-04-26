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

int main() {

    return 0;
}

