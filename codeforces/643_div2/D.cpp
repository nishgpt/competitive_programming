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
	int n, s, i;
	cin>>n>>s;
	
	if(s < 2*n) {
		cout<<"NO"<<endl;
		return 0;
	}
	
	cout<<"YES"<<endl;
	for(i=1;i<n;i++) {
		cout<<1<<" ";
	}
	cout<<s-n+1<<endl;
	cout<<s-n<<endl;

    return 0;
}

