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
#define MAX 200005
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
typedef pair<int, int> pi;
typedef pair<LL, LL> pl;
const char en = '\n';

void print(int a[], int n) {
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
	cout<<en;
}
void solve() {
	int n, k;
	in2(n, k);
	int a[n];
	for(int i=0;i<n;i++) in(a[i]);
	
	for(int j=0;j<k;j++) {
		int temp[MAX] = {0};
		for(int i=0;i<n;i++) {
			int s = max(0, i-a[i]);
			int e = min(n-1, i+a[i]);
			temp[s]++;
			temp[e+1]--;
		}
		for(int i=1;i<n;i++) temp[i] += temp[i-1];
		int cnt = 0;
		for(int i=0;i<n;i++) {
			a[i] = temp[i];
			if(a[i] == n) cnt++;
		}
		if(cnt == n) break;
	}
	
	print(a, n);
}

int main() {
	int t = 1;
	
	//~cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
