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

int main() {
	int i, t, n, k;
	cin>>t;
	while(t--) {
		cin>>n>>k;
		int a[n+1];
		int peak[n+1];
		int cum[n+1];
		memset(cum, 0, sizeof cum);
		memset(peak, 0, sizeof peak);
		for(i=1;i<n+1;i++) {
			scanf("%d", &a[i]);
		}
		
		for(i=2;i<n;i++) {
			if(a[i] > a[i-1] && a[i] > a[i+1]) {
				peak[i] = 1;
			}
		}
		
		for(i=1;i<n+1;i++) {
			cum[i] = cum[i-1] + peak[i];
		}
		
		int maxi = -1;
		int start = -1;
		for(i=k;i<n+1;i++) {
			int peaks = cum[i] - cum[i-k];
			if(peak[i]) peaks--;
			if(peak[i-k+1]) peaks--;
			
			if(maxi < peaks) {
				maxi = peaks;
				start = i-k+1;
			}
		}
		
		cout<<maxi+1<<" "<<start<<endl;
	}
    return 0;
}

