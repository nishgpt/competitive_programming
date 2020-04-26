/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 100005
#define MOD 1000000007
#define INF 1e9

using namespace std;

int main() {
	int t, i, n;
	string s;
	cin>>t;
	
	while(t--) {
		cin>>n;
		cin>>s;
	
		int lb[n];
		int ra[n];
		
		for(i=0;i<n;i++) {
			lb[i] = 0;
			if(s[i] == 'B') {
				lb[i] = 1;
			}
			if(i>0) lb[i] += lb[i-1];
		}
		
		for(i=n-1;i>=0;i--) {
			ra[i] = 0;
			if(s[i] == 'A') {
				ra[i] = 1;
			}
			if(i<n-1) ra[i] += ra[i+1];
		}
		
		int ans = INF;
		for(i=0;i<n;i++) {
			int convert_a = (i == 0) ? 0 : lb[i-1];
			int convert_b = ra[i];
			ans = min(ans,convert_a + convert_b);
			//cout<<ans<<endl;
		}
		
		ans = min(ans, lb[n-1]);
		
		cout<<ans<<endl;
	}
    return 0;
}

