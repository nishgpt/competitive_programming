/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 100005
#define INF 1000000000
#define INFL (LL(1e18))
#define MOD 1000000007

using namespace std;

vector<pair<int, int> > edge[MAX]; // first = cost, second = destination node of edge
int mincost[MAX];

void dijkstra(int start, int end, int k) {
    priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    int i;
    for(i=1;i<=MAX;i++) mincost[i] = INF;
    
    pq.push(mp(0, start));
    mincost[start] = 0;

    while(!pq.empty()) {
        pair<int, int> _top = pq.top();
        pq.pop();
        for(i=0;i<edge[_top.second].size();i++) {
            pair<int, int> curr_edge = edge[_top.second][i];

            if(mincost[_top.second] + curr_edge.first < mincost[curr_edge.second]) {
                mincost[curr_edge.second] = mincost[_top.second] + curr_edge.first;
                int q = mincost[_top.second] / k;
                if(q > 0 && (q&1)) {
                    mincost[curr_edge.second] += k - (mincost[_top.second] % k);   
                }

                pq.push(mp(mincost[curr_edge.second], curr_edge.second));
            }
        }
    }
}

int main() {
    int i, j, k, n, m, t;
    
    scanf("%d", &n);
    scanf("%d", &k);
    scanf("%d", &m);

    while(m--) {
        scanf("%d %d %d", &i, &j, &t);
        edge[i].pb(mp(t, j));
        edge[j].pb(mp(t, i));
    }

    dijkstra(1, n, k);
    /*
    for(i=1;i<=n;i++) {
        printf("%d\n", mincost[i]);
    }
    */
    printf("%d\n", mincost[n]);

    return 0;
}

