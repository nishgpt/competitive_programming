/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 27
#define MOD 1000000007

using namespace std;

int main() {
	int t, n, i, j, k;
	cin>>t;
	while(t--) {
		cin>>n;
		int a[n];
		int left[n][MAX];
		int right[n][MAX];
		memset(left, 0, sizeof left);
		memset(right, 0, sizeof right);
		for(i=0;i<n;i++) {
			cin>>a[i];
			left[i][a[i]] = 1;
			if(i > 0) {
				for(j=1;j<MAX;j++) {
					left[i][j] += left[i-1][j]; 
				}
			}
		}
		
		for(i=n-1;i>=0;i--) {
			right[i][a[i]] = 1;
			if(i<n-1) {
				for(j=1;j<MAX;j++) {
					right[i][j] += right[i+1][j]; 
				}
			}
		}
		
		
		
		int ans = 1;
		for(i=0;i<n;i++) {
			for(j=i+1;j<n;j++) {
				if(left[i][a[i]] == right[j][a[i]]) {
					int maxi = 0;
					if(j-i>1) {
						for(k=1;k<MAX;k++) {
							int beech = left[j-1][k] - left[i][k];
							maxi = max(maxi, beech);
						}
					}
					if(ans < left[i][a[i]] + right[j][a[i]] + maxi) {
						ans = max(ans, left[i][a[i]] + right[j][a[i]] + maxi);
					}
				}
			}
		}
		
		cout<<ans<<endl;
	}
    return 0;
}

