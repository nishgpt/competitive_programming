/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 200005
#define MOD 1000000007
#define INF 1000000

using namespace std;

int main() {
	int t, n, k, i, j;
	cin>>t;
	while(t--) {
		cin>>n>>k;
		int a[n];
		for(i=0;i<n;i++) {
			scanf("%d", &a[i]);
		}
		
		map<int, int> mp;
		int less[k+1];
		int more[k+1];
		memset(less, 0, sizeof less);
		memset(more, 0, sizeof more);
		j=n-1;
		for(i=0;i<n/2;i++, j--) {
			mp[a[i]+a[j]]++;
			
			less[max(a[i], a[j])]++;
			more[min(a[i], a[j])]++;
		}
		
		for(i=1;i<=k;i++) {
			more[i] = more[i] + more[i-1];
		}
		
		for(i=k-1;i>=0;i--) {
			less[i] = less[i] + less[i+1];
		}
		
		j=n-1;
		int ans = n/2;
		for(i=0;i<n/2;i++, j--) {
			int s = a[i] + a[j];
			if(s > k) {
				int temp = less[1] - less[s-k];
				ans = min(ans, 2*temp + (n/2-temp) - mp[s]);
			} else if(s == k) {
				int temp = more[k] - more[k-1];
				ans = min(ans, 2*temp + (n/2-temp) - mp[s]);
			} else {
				int temp = more[k] - more[s-1];
				ans = min(ans, 2*temp + (n/2-temp) - mp[s]);
			}
		}
		
		cout<<ans<<endl;
	}
    return 0;
}

