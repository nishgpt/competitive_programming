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
		
		int a[n], b[n], x;
		map<int, int> mp1;
		for(i=0;i<n;i++) {
			cin>>x;
			a[i] = (x == 1) ? 1 : -1;
			if(i) a[i] += a[i-1];
			mp1[a[i]]  = i+1;
		}	
		
		for(i=0;i<n;i++) {
			cin>>b[i];
			if(b[i]==2) b[i] = -1;
		}
		
		map<int, int> mp;
		mp[b[n-1]] = n;
		for(i=n-2;i>=0;i--) {
			b[i] += b[i+1];
			mp[b[i]] = i+1;
		}
		
		
		int mini = INT_MAX;
		for(i=0;i<n;i++) {
			int temp = mp[-1 * a[i]];
			//cout<<temp<<endl;
			if(temp) {
				int t_ans = (n-i-1) + temp-1;
				mini = min(mini, t_ans);
			}
			if(a[i] == 0) {
				mini =  min(mini, 2*n - (i+1));
			}
		}
		
		for(i=n-1;i>=0;i--) {
			int temp = mp1[-1 * b[i]];
			if(temp) {
				int t_ans = n - temp + i;
				mini = min(mini, t_ans);
			}
			if(b[i] == 0) {
				mini = min(mini, n + i);
			}
		}
		
		if(mini == INT_MAX) mini = 2*n;
		cout<<mini<<endl;
	}    
	return 0;
}

