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
#define MAX 105
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
		int a[n];
		int f[MAX] = {0};
		int even = 0, odd = 0;
		for(i=0;i<n;i++) {
			cin>>a[i];
			if(a[i]&1) odd++;
			else even++;
			f[a[i]]++;
		}
		
		if(even % 2 == 0 && odd % 2 == 0) cout<<"YES"<<endl;
		else if(even % 2 == 1 && odd % 2 == 1) {
			bool ff = false;
			for(i=1;i<MAX-1;i++) {
				if(f[i] && f[i+1]) {
					ff= true;
					break;
				}
			}
			if(ff) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
		

    return 0;
}

