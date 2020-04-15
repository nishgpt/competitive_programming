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
		int a[n];
		int i;
		for(i=0;i<n;i++) {
			cin>>a[i];
		}
		
		int prev = -1;
		bool flag = true;
		for(i=0;i<n;i++) {
			if(a[i] == 1) {
				if(prev != -1 && i - prev < 6) {
					flag = false;
					break;
				} 
				prev = i;
			} 
		}
		
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
    return 0;
}

