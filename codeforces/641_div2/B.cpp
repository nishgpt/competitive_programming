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
#define MAX 100005
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL (LL(1e18))
#define rep(i, a, n) for(i=a;i<n;i++)
#define rev(i, a, n) for(i=a;i>=n;i--)
#define MSV(A,a) memset(A, a, sizeof(A))
#define rep_itr(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)

using namespace std;

vector<int> divisors(int num) {
	int i=1;
	vector<int> div;
	div.PB(i);
	
	for(i=2;i*i<=num;i++) {
		if(num %i == 0) div.PB(i);
		if(num %i == 0 && num/i != i) div.PB(num/i);
	}
	
	sort(div.begin(), div.end());
	return div;
}

int main() {
	int t, n, i, j;
	
	cin>>t;
	while(t--) {
		cin>>n;
		
		int a[n+1];
		for(i=1;i<=n;i++) cin>>a[i];
		
		int ans[n+1];
		ans[1] = 1;
		for(i=2;i<=n;i++) {
			vector<int> div = divisors(i);
			
			int maxi = 1;
			for(j = 0;j<div.size();j++) {
				if(a[div[j]] < a[i]) {
					maxi = max(maxi, 1+ans[div[j]]);
				}
			}
			ans[i] = maxi;
		}
		
		int ans_max = -1;
		for(i=1;i<=n;i++) ans_max = max(ans_max, ans[i]);
		cout<<ans_max<<endl;
		
	}
    return 0;
}

