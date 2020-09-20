/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>
using namespace std;

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
#define INFL (1e18)
#define chk(a) cerr << endl << #a << " : " << a << endl
#define chk2(a,b) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << endl
#define chk3(a,b,c) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << endl
#define chk4(a,b,c,d) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << "\t" << #d << " : " << d << endl
#define rep(i, a, n) for(i=a;i<n;i++)
#define rev(i, a, n) for(i=a;i>=n;i--)
#define in(x) scanf("%d", &x)
#define inl(x) scanf("%lld", &x)
#define in2(x, y) scanf("%d %d", &x, &y)
#define inl2(x, y) scanf("%lld %lld", &x, &y)
#define MSV(A,a) memset(A, a, sizeof(A))
#define rep_itr(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)
#define finish(x) {cout<<x<<'\n'; return;}
typedef pair<int, int> pi;
typedef pair<LL, LL> pl;
const char en = '\n';

void solve() {
	int n;in(n);
	vector<LL> pos, neg;
	for(int i=0;i<n;i++) {
		LL x;inl(x);
		if(x>=0) pos.PB(x);
		else neg.PB(x);
	}
	
	sort(pos.rbegin(), pos.rend());
	sort(neg.begin(), neg.end());
	int ns = neg.size();
	
	LL maxi = -1*INFL;
	for(int i=0;i<=5;i++) {
		LL temp = 1;
		int cnt = 0;
		
		//positives
		if(i-1>=0 && i-1 < pos.size()) {
			for(int j=0;j<=i-1;j++) {temp = temp*pos[j];cnt++;}
		}
		
		//negatives
		int k = 5-i;
		if(k-1>=0 && k-1 < neg.size()) {
			if(k&1) {
				for(int j=ns-1;j>=ns-k;j--) {temp = temp*neg[j];cnt++;}
			}
			else {
				for(int j=0;j<=k-1;j++) {temp = temp*neg[j];cnt++;}
			}
		}
		
		if(cnt == 5) maxi = max(maxi, temp);
	}
	cout<<maxi<<en;
}

int main() {
	int t = 1;
	
	cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
