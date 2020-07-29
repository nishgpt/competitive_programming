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
#define INFL (LL(1e18))
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

LL ap_sum(LL n, LL a, LL d) {
	return (n * (2*a + (n-1) * d)) / 2;
}

void solve() {
	LL n, l, r;
	inl(n);
	inl2(l, r);
	
	LL low = 1, high = n-1;
	LL node = -1, idx = -1;
	while(low <= high) {
		LL mid = (low + high) >> 1;	
		LL st = 2 * ap_sum(mid-1, n-1, -1) + 1;
		LL e = st + 2 * (n-mid) - 1;
		if(l>=st && l<=e) {
			node = mid;
			idx = st; //to keep the starting point of this node
			break;
		} 
		else if(l < st) high = mid-1;
		else if(l > e) low = mid + 1;
	}
	
	if(node == -1) finish(1); //i.e l = r = n(n-1)+1
	
	LL partner = node+1;
	LL last = n*(n-1)+1;
	for(LL i=idx;i<=min(last-1, r);) {
		if(i>=l) cout<<node<<" ";
		i++;
		if(i>r) break;
		if(i>=l) cout<<partner<<" ";
		i++;
		partner++;
		if(partner > n) {
			node++;
			partner = node+1;
		}
	}
	if(r == last) cout<<1;
	cout<<en;
}

int main() {
	int t = 1;
	
	cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
