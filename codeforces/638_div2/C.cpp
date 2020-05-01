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

int main() {
	int t, n, k;
	cin>>t;
	string s;
	
	while(t--) {
		cin>>n>>k;
		cin>>s;
		sort(s.begin(), s.end());
		
		int right[n];
		int i, j=0;
		for(i=n-1;i>=0;i--) {
			if(i == n-1) right[i] = 1;
			if(i<n-1) {
				right[i] = right[i+1];
				if(s[i] != s[i+1]) right[i] += 1;
			} 
		}
		
		if(right[0] == 1) {
			int q = n/k;
			if(n%k != 0) q++;
			
			for(i=0;i<q;i++) cout<<s[0];
			cout<<endl;
			continue;
		}
		
		
		int x[26] = {0};
		string ans = "";
		int flag = 0;
		int st = 0;
		for(i=0;i<s.length();i++) {
			if(j<k) {
				x[s[i]-'a']++;
				j++;
			}
			
			if(j == k) {
				int tot = 0;
				int last = -1;
				for(int p=0;p<26;p++) {
					if(x[p] > 0) {
						tot++;
						last = p;
					}
				}
				
				if(tot > 1) {
					ans = (char)(last + 'a');
					break;
				} else {
					ans = ans + s[i];
					if(i+1==n) break;
					if(right[i+1] > 1) {
						flag = 1;
						st = k;
						break;
					}
				}
				memset(x, 0, sizeof x);
				j=0;
			}
		}
		
		if(j<k) {
			int tot = 0;
			int last = -1;
			for(int p=0;p<26;p++) {
				if(x[p] > 0) {
					tot++;
					last = p;
				}
			}
			
			if(tot > 0) {
				ans = ans + s[n-1];
			}
		}
		
		cout<<ans;
		if(flag == 1) {
			for(i=st;i<s.length();i++) {
				cout<<s[i];
			}
		}
		cout<<endl;
		
	}
    return 0;
}

