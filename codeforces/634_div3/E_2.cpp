/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 204
#define MOD 1000000007

using namespace std;

vector<int> v[MAX];
int main() {
	int t, n, i, j, k;
	cin>>t;
	while(t--) {
		cin>>n;
		int a[n];
		for(i=1;i<MAX;i++) {
			v[i].clear();
		}
		
		for(i=0;i<n;i++) {
			cin>>a[i];
			v[a[i]].pb(i);
		}		
		
		int ans = 1;
		for(i=0;i<n;i++) {
			int pi = lower_bound(v[a[i]].begin(), v[a[i]].end(), i)  - v[a[i]].begin();
			int left = pi+1;

			int low = i+1;
			int high = n-1;
			int pj = -1;
			while(low <= high) {
				int mid = (low + high) >> 1;
				int p = lower_bound(v[a[i]].begin(), v[a[i]].end(), mid)  - v[a[i]].begin();
				int right = v[a[i]].size() - p;
				
				if(left == right) {
					pj = p;
					low = mid + 1;
				} else if(left < right) {
					low = mid + 1;
				} else {
					high = mid - 1;
				}
			}
			
			if(pj == -1) continue;
			for(k=1;k<MAX;k++) {
				
			}
		}
		
		cout<<ans<<endl;
	}
    return 0;
}

