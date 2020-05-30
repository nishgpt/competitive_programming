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
#define MAX 500005
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

LL ln[MAX], rn[MAX];
LL lmin[MAX], rmin[MAX], lsum[MAX], rsum[MAX];
int main() {
	
	int n, i, j;
	cin>>n;
	LL a[n];

	for(i=0;i<n;i++) {
		scanf("%lld", &a[i]);
	}
	
	ln[0] = a[0] < 0 ? a[0] : 0;
	rn[n-1] = a[n-1] < 0 ? a[n-1] : 0;
	lmin[0] = a[0];
	rmin[n-1] = a[n-1];
	lsum[0] = a[0] >= 0 ? a[0] : 0;
	rsum[n-1] = a[n-1] >= 0 ? a[n-1] : 0;
	for(i=1;i<n;i++) {
		ln[i] = ln[i-1];lsum[i] = lsum[i-1];
		if(a[i] < 0) ln[i] += a[i];
		else lsum[i] += a[i];
		lmin[i] = min(lmin[i-1], a[i]);
		//~chk3(ln[i], lmin[i], lsum[i]);
	}
	
	for(i=n-2;i>=0;i--) {
		rn[i] = rn[i+1]; rsum[i] = rsum[i+1];
		if(a[i] < 0) rn[i] += a[i];
		else rsum[i] += a[i];
		rmin[i] = min(rmin[i+1], a[i]);
		//~chk3(rn[i], rmin[i], rsum[i]);
	}
	
	LL ans = -1 * (1e18);
	for(i=0;i<n;i++) {
		if(i == 0) {
			if(rmin[i+1] < 0) ans = max(ans, a[i] - rn[i+1] + rsum[i+1]);
			else ans = max(ans, a[i] - (rmin[i+1] - (rsum[i+1] - rmin[i+1])));
		}
		else if(i == n-1) {
			if(lmin[i-1] < 0) ans = max(ans, a[i] - ln[i-1] + lsum[i-1]);
			else ans = max(ans, a[i] - (lmin[i-1] - (lsum[i-1] - lmin[i-1])));
		}
		else {
			LL leftx, rightx;
			if(rmin[i+1] < 0) rightx = rn[i+1] - rsum[i+1];
			else rightx = rmin[i+1] - (rsum[i+1] - rmin[i+1]);
			if(lmin[i-1] < 0) leftx = ln[i-1] - lsum[i-1];
			else leftx = lmin[i-1] - (lsum[i-1] - lmin[i-1]);
			
			ans = max(ans, a[i] - leftx - rightx);
		}
		//~chk2(i, ans);
	}
	
	if(n==1) cout<<a[0]<<endl;
	else cout<<ans<<endl;

    return 0;
}

