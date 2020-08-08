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

void solve() {
	int n;
	cin>>n;
	string s;
	cin>>s;
	
	int a[n];
	a[0] = 1;
	int maxi = 1;
	
	set<int> o, z;
	if(s[0] == '0') z.insert(1);
	else o.insert(1);
	
	for(int i=1;i<n;i++) {
		if(s[i] == '1') {
			if(z.empty()) {
				a[i] = maxi + 1;
				o.insert(maxi+1);
			}
			else{
				int x = *(z.begin());
				a[i] = x;
				o.insert(x);
				z.erase(x);
			}
		}
		else {
			if(o.empty()) {
				a[i] = maxi + 1;
				z.insert(maxi+1);
			}
			else {
				int x = *(o.begin());
				a[i] = x;
				z.insert(x);
				o.erase(x);
			}
		}
		maxi = max(maxi, a[i]);
	}
	cout<<maxi<<en;
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
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
