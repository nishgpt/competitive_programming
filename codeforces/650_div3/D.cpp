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
#define MAX 55
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

bool done;
bool taken[MAX];
string final_ans;
void call(int pos, int n, int m, string ans, string s, int a[], int cnt) {
	if(cnt == m) {
		final_ans = ans;
		done = true;
		return;
	}
	
	if(pos < 0) return ;
	
	//~chk(pos);
	char x = s[pos];
	for(int j=0;j<m;j++) {
		if(taken[j]) continue;
		int temp = 0;
		for(int k=0;k<m;k++) {
			if(taken[k] && x < ans[k]) temp += (abs(k-j)); 
		}
		if(temp == a[j]) {
			taken[j] = true;
			ans[j] = x;
			//~chk3(j, x, cnt+1);
			call(pos-1, n, m, ans, s, a, cnt+1);
			if(done) return;
			ans[j] = '#';
			taken[j] = false;
		}
	}
	call(pos-1, n, m, ans, s, a, cnt);
	if(done) return;
} 

void solve() {
	MSV(taken, false);
	done = false;
	
	int q;in(q);
	string s; cin>>s;
	int n, m;in(m);
	n = s.length();
	
	sort(s.begin(), s.end());
	int a[m];
	for(int i=0;i<m;i++) {
		in(a[i]);
	}
	
	string ans;
	ans.resize(m, '#');
	//~ans[last] = s[n-1];
	//~bool taken[MAX] = {false};
	//~taken[last] = true;
	
	//~for(int i=n-1;i>=0;i--) {
		//~//try to fit this char s[i]
		//~char x = s[i];
		//~bool found = false;
		//~for(int j=0;j<m;j++) {
			//~if(taken[j]) continue;
			
			//~//try for index j
			//~int temp = 0;
			//~for(int k=0;k<m;k++) {
				//~if(taken[k] && x < ans[k]) temp += (abs(k-j)); 
			//~}
			//~if(temp == a[j]) {
				//~chk2(j, x);
				//~taken[j] = true;
				//~ans[j] = x;
				//~found = true;
				//~break;
			//~}
		//~}
	//~}
	
	call(n-1, n, m, ans, s, a, 0);
	cout<<final_ans<<en;
}

int main() {
	int t = 1;
	
	cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
