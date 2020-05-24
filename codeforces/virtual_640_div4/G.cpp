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
	
	int t, n, i;
	cin>>t;
	
	while(t--) {
		cin>>n;
		if(n<=3) {cout<<"-1"<<endl;continue;}
		
		if(n&1) {
			for(i=1;i<=n;i+=2)cout<<i<<" ";
			i= n-3;
			cout<<i<<" ";
			i+=2;
			cout<<i<<" ";
			i-=4;
			if(i>0) {
				while(i) {
					cout<<i<<" ";
					i-=2;
				}
			}
		}
		else {
			for(i=2;i<=n;i+=2)cout<<i<<" ";
			i= n-3;
			cout<<i<<" ";
			i+=2;
			cout<<i<<" ";
			i-=4;
			if(i>0) {
				while(i>0) {
					cout<<i<<" ";
					i-=2;
				}
			}
		}
		cout<<endl;
	}

    return 0;
}

