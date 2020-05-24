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
	int t, n, k, i;
	cin>>t;
	while(t--) {
		cin>>n>>k;
		if(k == 1) cout<<n<<endl;
		else if(k >= n) cout<<"1"<<endl;
		else {
			int mini = n;
			for(i=2;i*i<=n;i++) {
				if(n % i == 0 && (i<=k)) {
					mini = min(mini, n/i);
				}
				
				int q = n/i;
				if(n%i == 0 && q<=k) {
					mini = min(mini, n/q);
				}
			}
			cout<<mini<<endl;
		}
	}

    return 0;
}

