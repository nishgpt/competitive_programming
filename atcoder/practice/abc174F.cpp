#include<bits/stdc++.h> 
using namespace std; 
  
const int MAX = 500005; 
  
struct Query 
{ 
    int l, r, idx; 
}; 
  
bool cmp(Query x, Query y) 
{ 
    return x.r < y.r; 
} 
  
void update(int idx, int val, int bit[], int n) 
{ 
    for (; idx <= n; idx += idx&-idx) 
        bit[idx] += val; 
} 
  
int query(int idx, int bit[], int n) 
{ 
    int sum = 0; 
    for (; idx>0; idx-=idx&-idx) 
        sum += bit[idx]; 
    return sum; 
} 
  
void answeringQueries(int arr[], int n, Query queries[], int q) 
{ 
    int bit[MAX]; 
    memset(bit, 0, sizeof(bit)); 
  
    int last_visit[MAX]; 
    memset(last_visit, -1, sizeof(last_visit)); 
  
    int ans[q]; 
    int query_counter = 0; 
    for (int i=0; i<n; i++) 
    { 
        if (last_visit[arr[i]] !=-1) 
            update (last_visit[arr[i]] + 1, -1, bit, n); 
  
        last_visit[arr[i]] = i; 
        update(i + 1, 1, bit, n); 
  
        while (query_counter < q && queries[query_counter].r == i) 
        { 
            ans[queries[query_counter].idx] = 
                     query(queries[query_counter].r + 1, bit, n)- 
                     query(queries[query_counter].l, bit, n); 
            query_counter++; 
        } 
    } 
  
    for (int i=0; i<q; i++) 
        cout << ans[i] << '\n'; 
} 
  
int main() 
{ 
    int n, q;
    scanf("%d %d", &n, &q);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    
    Query queries[q];
    for(int i=0;i<q;i++) {
		int ql, qr;
		scanf("%d %d", &ql, &qr);
		queries[i].l = ql-1;
		queries[i].r = qr-1;
		queries[i].idx = i; 
	}
	
    sort(queries, queries+q, cmp); 
    answeringQueries(a, n, queries, q); 
    return 0; 
} 
