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
	int t, n;
	cin>>t;
	
	while(t--) {
		cin>>n;
		int a[n]; LL ans = 0;
		int i;
		
		for(i=0;i<n;i++) {
			cin>>a[i];
		}
		
		sort(a, a+n, greater<int>());
		
		for(i=0;i<n;i++) {
			ans = (ans + max(a[i]-i, 0)) %  MOD;
		}
		
		cout<<ans<<endl;
	}
    return 0;
}

