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
	in(n);
	string s, t;
	cin>>s;
	cin>>t;
	
	vector<int> a;
	int sz = 0, tz = 0;
	for(int i=0;i<n;i++) {
		if(s[i] == '0') sz++;
		if(t[i] == '0') tz++;
		if(s[i] != t[i]) a.push_back(s[i]-'0');
	}
	
	if(sz != tz) finish(-1);
	
	int zlast[2] = {0}, olast[2] = {0};
	for(int i=0;i<a.size();i++) {
		if(!a[i]) {
			if(zlast[1]) {
				zlast[1]--;
				zlast[0]++;
			} else if(olast[1]) {
				olast[1]--;
				olast[0]++;
			} else {
				zlast[0]++;
			}
		} else {
			if(zlast[0]) {
				zlast[0]--;
				zlast[1]++;
			} else if(olast[0]) {
				olast[0]--;
				olast[1]++;
			} else {
				olast[1]++;
			}
		}
		//chk(a[i]);
		//chk4(zlast[0] , zlast[1] , olast[1] , olast[0]);
	}
	
	int ans = zlast[0] + zlast[1] + olast[1] + olast[0]; 
	cout<<ans<<en;
	
}

int main() {
	int t = 1;
	
	//~cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
