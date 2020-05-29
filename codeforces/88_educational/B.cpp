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
	
	int t, n, m, x, y, i, j;
	cin>>t;
	while(t--) {
		cin>>n>>m>>x>>y;
		string s[n];
		for(i=0;i<n;i++) cin>>s[i];
		
		bool oo = (2*x <= y) ? true : false;
		int ans = 0;
		for(i=0;i<n;i++) {
			int cnt = 0;
			for(j=0;j<m;j++) {
				if(s[i][j] == '.') cnt++;
				else {
					if(oo) ans += (cnt*x);
					else ans += ((cnt/2) * y + (cnt&1) * x);
					cnt = 0;
				}
			}
			
			if(cnt) {
				if(oo) ans += (cnt*x);
				else ans += ((cnt/2) * y + (cnt&1) * x);
				cnt = 0;
			}
		}
		cout<<ans<<endl;
	}

    return 0;
}

