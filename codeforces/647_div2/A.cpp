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
#define LOG_MAX 20
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
	LL t, a, b;
	cin>>t;
	
	while(t--) {
		scanf("%lld %lld", &a, &b);
		
		if(a>b) swap(a, b);
		
		if(b % a != 0) cout<<-1<<endl;
		else {
			LL x = b/a;
			if((x & (x-1)) != 0) cout<<-1<<endl;
			else {
				LL ans = 0;
				while(x%8 == 0) {ans++; x=x/8;}
				while(x%4 == 0) {ans++; x=x/4;}
				while(x%2 == 0) {ans++; x=x/2;}
				cout<<ans<<endl;
			}
		}
	}

    return 0;
}

