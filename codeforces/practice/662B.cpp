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

bool check(int fs, int ts, int ss, int es) {
	return (fs >= 2) || (ss >= 1 && ts >= 1) || (ss >= 2) || (fs >= 1 && ss >= 1) || (fs >= 1 && ts >= 2) || (es >= 1);
}

void solve() {
	int n;
	in(n);
	int x;
	int freq[MAX] = {0};
	for(int i=0;i<n;i++) {
		in(x);
		freq[x]++;
	}
	
	int q; char c;
	in(q);
	int fs = 0, ts = 0, ss = 0, es = 0;
	for(int i=1;i<MAX;i++) {
		if(freq[i]>=8) es++;
		else if(freq[i] >= 6) ss++;
		else if(freq[i]>=4) fs++;
		else if(freq[i]>=2) ts++;
	}
	
	while(q--) {
		cin>>c;
		in(x);
		if(c == '+') {
			freq[x]++;
			if(freq[x]>=8 && freq[x]-1<8) {es++;ss--;}
			else if(freq[x]>=6 && freq[x]-1 < 6) {ss++;fs--;}
			else if(freq[x]>=4 && freq[x]-1 < 4) {fs++;ts--;}
			else if(freq[x]>=2 && freq[x]-1 < 2) ts++;
		}
		else {
			freq[x]--;
			if(freq[x]<2 && freq[x]+1>=2) ts--;
			else if(freq[x] < 4 && freq[x]+1>=4) {fs--;ts++;}
			else if(freq[x]<6 && freq[x]+1>=6) {ss--;fs++;}
			else if(freq[x] < 8 && freq[x]+1>=8) {es--;ss++;}
		}
		
		if(check(fs, ts, ss, es)) cout<<"YES"<<en;
		else cout<<"NO"<<en;
	}
}

int main() {
	int t = 1;
	
	//~cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
