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
#define MSV(A,a) memset(A, a, sizeof(A))
#define rep_itr(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)

using namespace std;


void solve() {
	int n, m;
	cin>>n>>m;
	int a[n][m];
	bool row[55] = {false}, col[55] = {false};
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin>>a[i][j];
			if(a[i][j]) {row[i] = true;col[j] = true;}
		}
	}
	
	int x = 0, y= 0;
	for(int i=0;i<n;i++) {
		if(!row[i]) x++;
	}
	
	for(int i=0;i<m;i++) {
		if(!col[i]) y++;
	}
			
	int ans = min(x, y);
	if(ans%2 == 0) cout<<"Vivek"<<endl;
	else cout<<"Ashish"<<endl;
	
}

int main() {
	int t = 1;
	
	cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
