/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 105
#define MOD 1000000007

using namespace std;

vector<int> knows[MAX];
bool visited[MAX];
int parent[MAX];
void dfs(int root, int node, bool friends[MAX][MAX]) {
    if(visited[node]) return;

    visited[node] = true;
    if(root != node) friends[root][node] = true;

    for(int i=0;i<knows[node].size();i++) {
        if(!visited[knows[node][i]]) {
            dfs(root, knows[node][i], friends);
        }
    }
}

int find_parent(int node) {
	if(node == parent[node]) return node;
	return parent[node] = find_parent(parent[node]);
}

void _union(int u, int v) {
    parent[find_parent(u)] = find_parent(v);
}

int main() {
    int t, n, i, j;

    scanf("%d", &t);

    while(t--) {
        scanf("%d", &n);
        char s[n][n];

        for(i=0;i<n;i++) {
            scanf("%s", s[i]);
            knows[i].clear();
            parent[i] = i;
        }

        bool friends[MAX][MAX] = {false};

        for(i=0;i<n;i++) {
            for(j=0;j<n;j++) {
                if(s[i][j] == 'Y') {
                    knows[i].pb(j);
                }
            }
        }
        
        for(i=0;i<n;i++) {
            //do a dfs from ith node and mark visited nodes as i's friends
            memset(visited, false, sizeof visited);
            dfs(i, i, friends);
        }

        for(i=0;i<n;i++) {
            for(j=0;j<n;j++) {
                //if true friends, put them in a group
                if(friends[i][j] && friends[j][i]) {
                    _union(i, j);
                }
            }
        }

        set<int> st;
        for(i=0;i<n;i++) {
            parent[i] = find_parent(i);
            st.insert(parent[i]);
        }

        cout<<st.size()<<endl;
    }
    return 0;
}

