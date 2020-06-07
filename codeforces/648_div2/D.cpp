/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

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
#define MSV(A,a) memset(A, a, sizeof(A))
#define rep_itr(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)

using namespace std;

bool valid(int i, int j, int n, int m) {
	return i>=0 && i<n && j>=0 && j<m;
}

bool handle(string s[], int i, int j, int n, int m) {
	if(valid(i, j, n, m) && s[i][j] == 'G') return false;
	if(valid(i, j, n, m) && s[i][j] == '.') s[i][j] = '#';
	return true;
}

bool pos[MAX][MAX];
bool vis[MAX][MAX];

bool cross(int i, int j, int n, int m, string s[]) {
	vis[i][j] = true;
	if(i == n-1 && j == m-1) return s[i][j] == 'G' || s[i][j] == '.';
	
	if(pos[i][j]) return pos[i][j];
	
	bool possible = false;
	if(valid(i+1, j, n, m) && s[i+1][j] != '#' && !vis[i+1][j]) possible |= cross(i+1, j, n, m, s);
	if(valid(i-1, j, n, m) && s[i-1][j] != '#' && !vis[i-1][j]) possible |= cross(i-1, j, n, m, s);
	if(valid(i, j+1, n, m) && s[i][j+1] != '#' && !vis[i][j+1]) possible |= cross(i, j+1, n, m, s);
	if(valid(i, j-1, n, m) && s[i][j-1] != '#' && !vis[i][j-1]) possible |= cross(i, j-1, n, m, s);
	
	return pos[i][j] = possible;
}

void solve() {
	int n, m;
	cin>>n>>m;
	string s[n];
	
	for(int i=0;i<n;i++) cin>>s[i];
	
	if(s[n-1][m-1] == 'B' || s[n-1][m-1] == '#') {cout<<"No"<<endl; return;}
	
	bool ok = true;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(s[i][j] == 'B') {
				ok = handle(s, i-1, j, n, m);
				ok = ok & handle(s, i+1, j, n, m);
				ok = ok & handle(s, i, j-1, n, m);
				ok = ok & handle(s, i, j+1, n, m);
				
				if(!ok) break;
			}
		}
		if(!ok) break;
	}
	
	//~if(s[n-1][m-1] == '#') ok = false;
	if(!ok) {cout<<"No"<<endl;return;}
	
	memset(pos, false, sizeof pos);
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(s[i][j] == 'G') {
				memset(vis, false, sizeof vis);
				if(!cross(i, j, n, m, s)) {
					ok = false;
					break;
				}
			}
		}
		if(!ok) break;
	}
	
	if(ok) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}

int main() {
	int t = 1;
	
	cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
