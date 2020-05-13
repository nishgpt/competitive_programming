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
	LL t, n, k;
	cin>>t;
	while(t--) {
		cin>>n>>k;
		
		if(n%2 == 0) {
			cout<<n+2*k<<endl;
			continue;
		}
		
		LL div = -1;
		for(LL i=2;i*i<=n;i++) {
			if(n%i == 0) {
				div = i;break;
			}
		}
		
		if(div == -1) div = n;
		
		k--;
		n = n + div;
		cout<<n+k*2<<endl;
	}

    return 0;
}

