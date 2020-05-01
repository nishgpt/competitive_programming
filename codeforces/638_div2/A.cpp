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
	int t, n;
	cin>>t;
	while(t--) {
		cin>>n;
		int i;
		int a = 0;
		int b = 0;
		
		if(n == 2) {
			cout<<2<<endl;
			continue;
		}
		
		a = (1<<n);
		b = (1<<(n-1));
		n-=2;
		for(i=1;i<=n/2;i++) {
			a += (1<<i);
			b += (1<<(n-i+1));
		}
		cout<<abs(a-b)<<endl;
	}
    return 0;
}

