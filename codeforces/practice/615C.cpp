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
void solve(int n) {
	int c = n, i;
	
	int a[3], j=0;;
	for(i=2;i*i<=n;i++) {
		if(c % i ==0) {
			a[j++] = i;
			c/=i;
			if(j == 2) {
				a[j++] = c;
				break;
			}
		}
	}
	
	if(j != 3 || a[0] == a[1] || a[1] == a[2] || a[0] == a[2]) cout<<"NO"<<endl;
	else {
		cout<<"YES"<<endl;
		cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
	} 
}
int main() {
	int t, n;
	cin>>t;
	while(t--) {
		cin>>n;
		solve(n);
	}
    return 0;
}

