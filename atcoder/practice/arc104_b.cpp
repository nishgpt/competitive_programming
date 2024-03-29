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
	string s;
	in(n);
	cin>>s;
	
	vector<int> v[4];
	for(int i=0;i<4;i++) v[i].resize(n, 0);
	
	for(int i=0;i<n;i++) {
		if(s[i] == 'A') v[0][i] = 1;
		else if(s[i] == 'G') v[1][i] = 1;
		else if(s[i] == 'C') v[2][i] = 1;
		else v[3][i] = 1;
		
		if(i > 0) {
			for(int j=0;j<4;j++) v[j][i] += v[j][i-1];
		}
	}
	
	int cnt = 0;
	for(int i=0;i<n;i++) {
		for(int j=i+1;j<n;j++) {
			int a = v[0][j] - (i>0 ? v[0][i-1] : 0);
			int g = v[1][j] - (i>0 ? v[1][i-1] : 0);
			int c = v[2][j] - (i>0 ? v[2][i-1] : 0);
			int t = v[3][j] - (i>0 ? v[3][i-1] : 0);
			if(a == t && g == c) cnt++;
		}
	}
	
	cout<<cnt<<en;
}

int main() {
	int t = 1;
	
	//~cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
