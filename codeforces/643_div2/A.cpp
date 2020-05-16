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

pair<LL, LL> get_min_max(LL num) {
	LL mini=10, maxi = -1, d;
	while(num) {
		d = num % 10;
		num /= 10;
		mini = min(mini, d);
		maxi = max(maxi, d);
	}
	return MP(mini, maxi);
}

int main() {
	LL n, k, i, t;
	cin>>t;
	while(t--) {
		cin>>n>>k;
		for(i=2;i<=k;i++) {
			pair<LL, LL> p = get_min_max(n);
			if(p.X == 0 || p.Y == 0) break;
			n = n + p.X * p.Y;
		}
		
		cout<<n<<endl;
	}
    return 0;
}

