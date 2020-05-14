/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define X first
#define Y second
#define PB push_back
#define MP make_pair
#define MAX 1000005
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL (LL(1e18))
#define rep(i, a, n) for(i=a;i<n;i++)
#define rev(i, a, n) for(i=a;i>=n;i--)
#define MSV(A,a) memset(A, a, sizeof(A))
#define rep_itr(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)

using namespace std;

string s;
int n, k;
int dp[MAX][2][2];
int min_moves(int pos, int last, int used_one) {
	if(pos >= n) return 0;
	
	if(dp[pos][last][used_one] != -1) return dp[pos][last][used_one];
	
	int ans;
	if(last) {
		//understood that used_one is 1
		if(s[pos] == '1') ans = min_moves(pos+k, 1, 1);
		else ans = min(1 + min_moves(pos+k, 1, 1), min_moves(pos+k, 0, 1)); 
	} 
	else {
		if(used_one) {
			if(s[pos] == '1') ans = 1 + min_moves(pos+k, 0, 1);
			else ans = min_moves(pos+k, 0, 1);
		}
		else {
			if(s[pos] == '1') ans = min(1 + min_moves(pos+k, 0, 0), min_moves(pos+k, 1, 1));
			else ans = min(1+min_moves(pos+k, 1, 1), min_moves(pos+k, 0, 0));
		}
	}
	dp[pos][last][used_one] = ans;
	
	return dp[pos][last][used_one];
}

int main() {
	int t;
	cin>>t;
	
	while(t--) {
		cin>>n>>k;
		cin>>s;
		
		for(int i=0;i<n;i++) {
			dp[i][0][0] = -1;
			dp[i][0][1] = -1;
			dp[i][1][0] = -1;
			dp[i][1][1] = -1;
		}
		
		int total = 0;
		for(int i=0;i<n;i++) if(s[i] == '1') total++;
		
		int ans = INT_MAX;
		for(int i=0;i<k;i++) {
			int temp = 0;
			for(int j=i;j<n;j+=k) if(s[j] == '1') temp++;
			ans = min(ans, min_moves(i, 0, 0) + total - temp);
		}
		
		cout<<ans<<endl;
	} 

    return 0;
}

