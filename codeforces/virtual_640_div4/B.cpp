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
	int n, k, t, i;
	cin>>t;
	while(t--) {
		cin>>n>>k;
		if(k > n) {
			cout<<"NO"<<endl; continue;
		}
		
		vector<int> odd, even;
		for(i=0;i<k-1;i++) {
			odd.PB(1);
		}
		odd.PB(n-k+1);
		
		for(i=0;i<k-1;i++) {
			even.PB(2);
		}
		even.PB(n-(2*(k-1)));
		
		int cnt1 = 0, cnt2=0;
		for(i=0;i<k;i++) if(odd[i] %2 != 1 || odd[i] <= 0) {cnt1++; break;}
		
		for(i=0;i<k;i++) if(even[i] %2 == 1 || even[i] <= 0) {cnt2++; break;}
		
		if(cnt1 && cnt2) cout<<"NO"<<endl;
		else {
			cout<<"YES"<<endl;
			if(!cnt1) {
				for(i=0;i<k;i++) cout<<odd[i]<<" ";
			} else {
				for(i=0;i<k;i++) cout<<even[i]<<" ";
			}
			cout<<endl;
		}
	}
	

    return 0;
}

