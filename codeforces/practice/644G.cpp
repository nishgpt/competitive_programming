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
#define MAX 55
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
	int t, n, m, a, b;
	cin>>t;
	while(t--) {
		cin>>n>>m>>a>>b;
		
		if(a*n != b*m) {cout<<"NO"<<endl;continue;}
		int ans[MAX][MAX] = {0};
		cout<<"YES"<<endl;
		int d = 0;
		for(int i=0;i<n;i++) {
			for(int j=0;j<a;j++) {
				ans[i][(j+d) %m] = 1;
			}
			d += a;
		}
		
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				cout<<ans[i][j];
			}
			cout<<endl;
		}
		
	}

    return 0;
}

