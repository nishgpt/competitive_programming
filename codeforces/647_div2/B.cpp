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
#define MAX 1024
#define LOG_MAX 20
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL (LL(1e18))
#define chk(a) cerr << endl << #a << " : " << a << endl
#define chk2(a,b) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << endl
#define chk3(a,b,c) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << endl
#define chk4(a,b,c,d) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << "\t" << #d << " : " << d << endl
#define rep(i, a, n) for(i=a;i<n;i++)
#define rev(i, a, n) for(i=a;i>=n;i--)
#define MSV(A,a) memset(A, a, sizeof(A))
#define rep_itr(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)

using namespace std;

int main() {
	int t, n;
	
	cin>>t;
	
	while(t--) {
		cin>>n;
		unordered_map<int, int> mp;
		int a[n];
		int freq[MAX] = {0};
		for(int i=0;i<n;i++) {
			scanf("%d", &a[i]);
			freq[a[i]]++;
		}
		
		int dist = 0;
		for(int i=0;i<MAX;i++) if(freq[i]>0) dist++;
		
		int ans = -1;
		for(int i=1;i<MAX;i++) {
			unordered_map<int, int> mp1;
			for(int j=0;j<n;j++)
				mp1[a[j]^i]++;
			
			if(dist != mp1.size()) continue;
			
			unordered_map<int, int> ::iterator it;
			bool f = true;
			for(it = mp1.begin();it!= mp1.end();it++) {
				int k = it->first;
				if(freq[k] != (it->second)) {
					f = false;
					break;
				}
			}
			if(f) {
				ans = i;
				break;
			}
		}
		
		printf("%d\n", ans);
	}
	
}

