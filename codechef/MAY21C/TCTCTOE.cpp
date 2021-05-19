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
#define MAX 300005
#define LOG_MAX 20
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL (LL(1e18))
#define chk(a) cerr << endl << #a << " : " << a << endl
#define chk2(a,b) cout << endl << #a << " : " << a << "\t" << #b << " : " << b << endl
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

int player_won(string s[3], char p) {
	int cnt = 0;
	for(int i=0;i<3;i++) {
		//row-wise
		if(s[i][0] == s[i][1] && s[i][1] == s[i][2] && s[i][0] == p) cnt++;
		
		//column wise
		if(s[0][i] == s[1][i] && s[1][i] == s[2][i] && s[0][i] == p) cnt++;
	}	
	
	//diagonals
	if(s[0][0] == s[1][1] && s[1][1] == s[2][2] && s[0][0] == p) cnt++;
	if(s[0][2] == s[1][1] && s[1][1] == s[2][0] && s[0][2] == p) cnt++;
	
	return cnt;
}

void solve() {
	string s[3];
	for(int i=0;i<3;i++) cin>>s[i];
	
	int sp = 0, x = 0, o = 0;
	for(int i=0;i<3;i++) {
		for(int j=0;j<3;j++) {
			if(s[i][j] == 'X') x++;
			else if(s[i][j] == 'O') o++;
			else if(s[i][j] == '_') sp++;
		}
	}
	
	int xw = player_won(s, 'X');
	int ow = player_won(s, 'O');
	
	if(o > x || x-o > 1) finish(3);
	if(sp == 0 && xw == 0 && ow == 0) finish(1); //draw
	if(x > o && xw == 1 && ow == 0) finish(1); //X won
	if(x == o && xw == 0 && ow == 1) finish(1); //O won
	if(xw == 2 && sp == 0) finish(1);
	if(sp > 0 && xw == 0 && ow == 0) finish(2); //no one won, can continue
	finish(3);
}

int main() {
	int t = 1;
	
	cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
