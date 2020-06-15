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
#define MAX 1005
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
#define in3(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define inl2(x, y) scanf("%lld %lld", &x, &y)
#define MSV(A,a) memset(A, a, sizeof(A))
#define rep_itr(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)
typedef pair<int, int> pi;
typedef pair<LL, LL> pl;
const char en = '\n';

int a[12][MAX];
int sum[12][MAX];

int get_sum(int x1, int y1, int x2, int y2) {
	int s = sum[x2][y2];
	if(x1 - 1 >= 0) s -=  sum[x1-1][y2];
	if(y1 - 1>=0) s -= sum[x2][y1-1];
	
	if(x1-1>=0 && y1-1>=0) s += sum[x1-1][y1-1];
	return s;
}

void solve() {
	int n, m, x;
	in3(n, m, x);
	string s[n];
	for(int i=0;i<n;i++) {
		cin>>s[i];
		for(int j=0;j<m;j++) a[i][j] = (s[i][j]-'0');
	}
	
	//precompute
	MSV(sum, 0);
	sum[0][0] = a[0][0];
	for(int i=1;i<m;i++) sum[0][i] = sum[0][i-1] + a[0][i];
	for(int i=1;i<n;i++) sum[i][0] = sum[i-1][0] + a[i][0];
	
	for(int i=1;i<n;i++) {
		for(int j=1;j<m;j++) {
			sum[i][j] = a[i][j] + sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1];
		}
	}
		
	vector<int> h;
	for(int i=0;i<n-1;i++) h.PB(i);
	int sz = h.size();
	
	int mini = INT_MAX;
	for(int i=0;i<(1<<sz);i++) {
		vector<int> temp;
		temp.PB(-1);
		int ans = 0;
		for(int j=0;j<sz;j++) {
			if((1<<j) & i) {
				temp.PB(h[j]);
				ans++;
			}
		}
		temp.PB(n-1);
		
		bool f = true;
		int pc = 0;
		for(int j=0;j<m;j++) {
			bool match = true;
			for(int k=1;k<temp.size();k++) {
				int cnt = get_sum(temp[k-1]+1, pc, temp[k], j);
				if(cnt > x) {match = false; break;}
			}
			
			if(!match && pc == j) {f = false;break;}
			if(!match) {
				ans++;
				pc = j;
				j--;
			}
		}
		if(f) mini = min(mini, ans);
	}
	cout<<mini<<en;
}

int main() {
	int t = 1;
	
	//~cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
