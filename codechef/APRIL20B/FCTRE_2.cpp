/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 1005
#define MAX_VAL 1000003
#define MOD 1000000007

using namespace std;

LL power(LL b, LL e, LL ans) {
	if(!e) return ans % MOD;
	if(e&1) ans = (ans * b) % MOD;
	return power((b*b) % MOD, e>>1, ans);
}

map<int, int> pfact[MAX_VAL];
vector<int> v[MAX_VAL];
void precompute() {
	int i, j;
	bool np[MAX_VAL] = {false};
	for(i=2;i*i<=MAX_VAL;i++) {
		if(!np[i]) {
			for(j=2*i;j<MAX_VAL;j+=i) {
				np[j] = true;
			}
		}
	}
	
	for(i=2;i*i<=MAX_VAL;i++) {
		for(j=2*i;j<MAX_VAL;j+=i) {
			if(!np[i] && i*i <= j) v[j].pb(i); //primes <= sqrt of number
			int other = j/i;
			if(!np[other] && other > i) v[j].pb(other); //primes > sqrt of number
		}
	}
	
	for(i=2;i<MAX_VAL;i++) {
		if(!np[i]) {
			pfact[i][i] = 1;
		} else {
			int copy = i;
			for(j=0;j<v[i].size();j++) {
				int cnt = 0;
				while(copy % v[i][j] == 0) {
					cnt++;
					copy/=v[i][j];
				}
				pfact[i][v[i][j]] = cnt;
			}
		}
	}
}

bool visited[MAX];
int powers[MAX_VAL];
void dfs_2(int node, int start, LL answers[MAX][MAX], vector<int> adj[MAX], int num[MAX], LL factors) {
	visited[node] = true;
	map<int, int> :: iterator it = pfact[num[node]].begin();
	
	while(it != pfact[num[node]].end()) {
		if(powers[it->first] > 0) {
			//multiply by inverse modulo, basically removing old power
			factors = (power(powers[it->first] + 1, MOD-2, 1) * factors) % MOD;
		}
		powers[it->first] += it->second;
		factors = (factors * (powers[it->first] + 1)) % MOD;
		it++;
	}
	//store the answer after including this 'node'
	answers[start][node] = factors;
	
	int i;
	for(i=0;i<adj[node].size();i++) {
		if(!visited[adj[node][i]]) {
			dfs_2(adj[node][i], start, answers, adj, num, factors); 
		}
	}
	
	//decrement the powers added before
	it = pfact[num[node]].begin();
	while(it != pfact[num[node]].end()) {
		powers[it->first] -= it->second;
		it++;
	}
	visited[node] = false;//automatically clears out visited as this node is done
	return;
}

void precompute_all_pair_answers(LL answers[MAX][MAX], vector<int> adj[MAX], int num[MAX], int n) {
	//we will compute for all pairs x, y where x<=y, since order does not matter here
	int i;
	for(i=1;i<=n;i++) {
		dfs_2(i, i, answers, adj, num, 1);
	}
	return ;
}

int main() {
	int t, i, n, q, U, V;
	precompute();
	
	scanf("%d", &t);
	
	while(t--) {
		scanf("%d", &n);
		vector<int> adj[MAX];
		for(i=1;i<n;i++) {
			scanf("%d %d", &U, &V);
			adj[U].pb(V);
			adj[V].pb(U);
		}
		
		int num[MAX];
		for(i=1;i<=n;i++) {
			scanf("%d", &num[i]);
		}
		
		LL answers[MAX][MAX];
		precompute_all_pair_answers(answers, adj, num, n);
		scanf("%d", &q);
		while(q--) {
			scanf("%d %d", &U, &V);
			printf("%lld\n", answers[U][V]);
		}
	}
    return 0;
}
