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

LL get_num(string s, vector<int> a) {
	int n = s.length();
	if(a[s[0]-'a'] == 0) return -1;
	
	LL num = 0;
	for(int i=0;i<n;i++) {
		num = num*10 + a[s[i]-'a'];
	}
	return num;
}

void solve() {
	string s[3];
	cin>>s[0]>>s[1]>>s[2];
	
	vector<int> a(26), c;
	for(int i=0;i<3;i++) {
		int l = s[i].length();
		for(int j=0;j<l;j++) {
			if(a[s[i][j]] != -1) c.PB(s[i][j]-'a');
			a[s[i][j]] = -1;
		}
	}
	if(c.size() > 10) finish("UNSOLVABLE");
	
	vector<int> v;
	for(int i=0;i<10;i++) v.PB(i);
	
	do {
		for(int i=0, j=0;i<c.size();i++) {
			a[c[i]] = v[j++];
		}
		
		LL n1 = get_num(s[0], a);
		LL n2 = get_num(s[1], a);
		LL n3 = get_num(s[2], a);
		
		if(n1 != -1 && n2 != -1 && n3 != -1 && n1+n2 == n3) {
			cout<<n1<<en<<n2<<en<<n3<<en;
			return;
		}
	} while(next_permutation(v.begin(), v.end()));
	
	finish("UNSOLVABLE");
}

int main() {
	int t = 1;
	
	//~cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
