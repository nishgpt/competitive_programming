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
	int t, n, k, i, j;
	cin>>t;
	while(t--) {
		cin>>n>>k;
		int a[n]; int b[n];
		
		for(i=0;i<n;i++) cin>>a[i];
		for(i=0;i<n;i++) cin>>b[i];
		
		sort(a, a+n);
		sort(b, b+n);
		
		i=0;j=n-1;
		while(k--) {
			if(a[i] < b[j]) {
				a[i] = b[j];
				j--;i++;
			}
			else break;
		}
		
		int sum = 0;
		for(i=0;i<n;i++) sum += a[i];
		cout<<sum<<endl;
	}

    return 0;
}

