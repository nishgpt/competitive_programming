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
	int t;
	cin>>t;
	
	int n1, n2, n3;
	while(t--) {
		cin>>n3>>n2>>n1;
		if(n1>0) for(int i=0;i<=n1;i++)cout<<"1";
		
		if(n2 & 1) {
			if(n1==0) {
				for(int i=0;i<(n2+1)/2;i++) cout<<"10";
			}
			else {
				for(int i=0;i<n2/2;i++) cout<<"01";
				cout<<"0";
			}
			
			for(int i=0;i<n3;i++) cout<<"0";
		} else {
			if(n1 == 0) {
				if(n2>0) {
					for(int i=0;i<n2/2;i++) cout<<"01";
					cout<<"0";
				}
				if(n2 == 0 && n3>0) n3++;
				for(int i=0;i<n3;i++) cout<<"0";
			} else {
				if(n2>0) {
					for(int i=0;i<(n2-1)/2;i++) cout<<"01";
					cout<<"0";
				}
				if(n2 == 0 && n3>0) n3++;
				for(int i=0;i<n3;i++) cout<<"0";
				if(n2>0) cout<<"1";
			}
		}
		cout<<endl;
	}

    return 0;
}

