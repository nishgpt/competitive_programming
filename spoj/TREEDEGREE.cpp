#include "bits/stdc++.h"
using namespace std;
#define MAX 100005
 
int get_degree(int node, int l, int r, int *deg, vector<int> v[MAX], int *a) {
    int i, j, degree = 0;
    for(i=l+1;i<r;) {
        int next_node = a[i];
        degree++;
        deg[next_node] = get_degree(next_node, i, v[next_node][1], deg, v, a);
        i = v[next_node][1] + 1;
    }
 
    return  degree;
}
 
int main() {
    int t, i, j, n;
    scanf("%d", &t);
    
    while(t--) {
        scanf("%d", &n);
        int deg[MAX] = {0};
        vector<int> v[MAX];
        int a[2*n];
        for(i=0;i<2*n;i++) {
            scanf("%d", &a[i]);
            v[a[i]].push_back(i);
        }
 
        deg[1] = get_degree(1, 0, 2*n-1, deg, v, a);
 
        int m = -1;
        for(i=1;i<=n;i++) {
            int x = (i == 1) ? deg[i] : (1+deg[i]);
            m = max(m, x);
        }
 
        printf("%d\n", m);
    }
    return 0;
}