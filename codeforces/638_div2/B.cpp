/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define getcx getchar_unlocked
#define X first
#define Y second
#define PB push_back
#define MP make_pair
#define MAX 105
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL (LL(1e18))
#define rep(i, a, n) for(i=a;i<n;i++)
#define rev(i, a, n) for(i=a;i>=n;i--)
#define MSV(A,a) memset(A, a, sizeof(A))
#define rep_itr(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)

using namespace std;

int main() {
	int t, n, k;
	cin>>t;
	while(t--) {
		cin>>n>>k;
		
		int f[MAX] = {0}, i, j;
		int a[n];
		for(i=0;i<n;i++) {
			cin>>a[i];
			f[a[i]]=1;
		}
		
		int cnt = 0;
		for(i=1;i<MAX;i++) {
			if(f[i]) {
				cnt++;
			}
		}
		
		if(cnt > k) {
			cout<<-1<<endl;
			continue;
		}
		
		if(k == 1) {
			cout<<n<<endl;
			for(i=0;i<n;i++) cout<<a[i]<<" ";
			cout<<endl;
			continue;
		}
		
		//~================
		
		int left = k-cnt;
		for(i=1;i<MAX;i++) {
			if(left > 0) {
				if(!f[i]) {f[i] = 1;left--;}
			}
			else break; 
		}
		
		int sum = 0;
		for(i=1;i<MAX;i++) {
			if(f[i]) sum+=i;
		}
		
		queue<int> q;
		q.push(a[0]);
		int nf[MAX] = {0};
		int c = 1;
		nf[a[0]] = 1;
		
		vector<int> ans;
		ans.PB(a[0]);
		
		for(j=1;j<n;j++) {
			if(c==k) {
				int st = q.front();
				q.pop();
				nf[st] = 0;
				c--;
			}
			
			if(!nf[a[j]]) {
				q.push(a[j]);
				ans.PB(a[j]);
				nf[a[j]] = 1;
				c++;
			} else {
				j--;
				for(i=1;i<MAX;i++) {
					if(c >= k) break;
					if(!nf[i] && f[i]) {
						q.push(i);
						ans.PB(i);
						nf[i] = 1;
						c++;
					}
				}
			}
		}
		
		cout<<ans.size()<<endl;
		for(i=0;i<ans.size();i++) {
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}

    return 0;
}

