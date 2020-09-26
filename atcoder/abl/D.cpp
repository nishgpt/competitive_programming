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
#define MAX 300005
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

int seg[4*MAX];

void construct(int node,int st,int end) {
	if(st == end) {
		seg[node] = 0;
		return;
	}
	
	int mid = (st+end)>>1;
	construct(node<<1, st, mid);
	construct(1+(node<<1), mid+1, end);
	int l = node<<1;
	int r = l+1; 
	seg[node] = max(seg[l], seg[r]);
}

void update(int node, int st, int end, int idx, int val) {
	if(st==end && st==idx) {
		seg[node] = max(val, seg[node]);
		return ;
	}
	
	int mid=(st+end)>>1;
	if(idx <= mid) update(node<<1,st,mid,idx,val);
	else if(idx > mid) update(1+(node<<1),mid+1,end,idx,val);
	
	int l=node<<1,r=l+1;
	
	seg[node] = max(seg[node], max(seg[l], seg[r]));
}

int query(int node, int st, int end, int qs, int qe) {
	if(st>end||qs>end||qe<st) {
		return 0;
	}
	
	if(st>=qs&&qe>=end) {
		return seg[node];
	}
	
	int mid=(st+end)>>1;
	int l = query(node<<1,st,mid,qs,qe);
	int r = query(1+(node<<1),mid+1,end,qs,qe);
	
	return max(l, r);
}

void solve() {
	int n, k;
	in2(n, k);
	
	int a[n];
	for(int i=0;i<n;i++) in(a[i]);
	
	int maxi = -1;
	for(int i=0;i<n;i++) {
		int qs = max(0, a[i]-k);
		int qe = min(a[i]+k, MAX);
		int max_now = query(1, 0, MAX, qs, qe);
		maxi = max(maxi, max_now+1);
		update(1, 0, MAX, a[i], max_now+1);
	}
	cout<<maxi<<en;
}

int main() {
	int t = 1;
	
	//~cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
