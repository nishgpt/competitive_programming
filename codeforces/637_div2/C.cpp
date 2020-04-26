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
		map<int, int> mp;
		for(i=0;i<n;i++) {
			cin>>a[i];
			mp[a[i]] = i;
		}
		
		bool flag = true;
		int cnt = 1;
		int maxi = n-1;
		while(cnt<=n) {
			int p = mp[cnt];
			for(i=p;i<=maxi;i++) {
				if(mp[cnt] != i) {
					flag = false;
					break;
				}
				cnt++;
			}
			if(flag == false) break;
			maxi = p-1;
		}
		if(flag) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
    return 0;
}

