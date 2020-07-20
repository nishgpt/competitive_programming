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

string p = "abacaba";
bool possible(string s) {
	for(int i=0;i<7;i++) {
		if(s[i] != p[i] && s[i] != '?') return false;
	}
	return true;
}

string get_ans(string s, int n) {
	for(int i=0;i<n;i++) {
		if(s[i] == '?') s[i] = 'x';
	}
	
	int cnt = 0;
	for(int i=0;i<=n-7;i++) {
		if(s.substr(i, 7).compare(p) == 0) cnt++;
	}
	if(cnt == 1) return s;
	else return "#";
}

void solve() {
	int n;
	in(n);
	string s;
	cin>>s;
	
	vector<string> v;
	for(int i=0;i<=n-7;i++) {
		string x = s.substr(i, 7);
		if(possible(x)) {
			string candidate = "";
			if(i > 0) candidate = candidate + s.substr(0, i);
			candidate = candidate + p;
			if(i+7<n) candidate = candidate + s.substr(i+7);
			v.PB(candidate);
		}
	}
	
	for(int i=0;i<v.size();i++) {
		string x = get_ans(v[i], n);
		if(x[0] != '#') {
			cout<<"Yes"<<en;
			finish(x);
		}
	}
	finish("No");
}

int main() {
	int t = 1;
	
	cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
