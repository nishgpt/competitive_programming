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
	int t, n, i;
	cin>>t;
	while(t--) {
		cin>>n;
		int a[n];
		int freq[n+1];
		memset(freq, 0, sizeof freq);
		for(i=0;i<n;i++) {
			cin>>a[i];
			freq[a[i]]++;
		}
		
		int distinct = 0;
		int maxi_freq_num = -1;
		int maxi = -1;
		for(i=1;i<=n;i++) {
			if(freq[i]) distinct++;
			if(maxi < freq[i]) {
				maxi = freq[i];
				maxi_freq_num = i;
			}
		}
		
		int b = distinct - 1;
		int ans = -1;
		if(b > maxi) {
			ans = maxi;
		} else if(maxi > b) {
			ans = b;
			if(maxi - b > 1) {
				ans++;
			}
		} else {
			ans = maxi;
		}
		cout<<ans<<endl;
	}
    return 0;
}

