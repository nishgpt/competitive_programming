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
#define MAX 105
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

int xx1, yy1, xx2, yy2;
int n, m;
set<int> sums;

bool valid(int i, int j) {
	return i>=0 && i<n && j>=0 && j<m;
}

void dfs(int a[MAX][MAX], int i, int j, int sum) {
	if(i == xx2 && j == yy2) {
		sums.insert(sum);
		return;
	}
	
	if(valid(i+1, j)) dfs(a, i+1, j, sum+a[i][j]);
	if(valid(i, j+1)) dfs(a, i, j+1, sum+a[i][j]);
}

int main() {
	int t, i, j;
	cin>>n>>m;
	
	int a[MAX][MAX];
	int rows = 1, diff = 1;
	
	for(i=0;i<n;i++) {
		int d = diff, s = rows;
		for(j=0;j<m;j++) {
			a[i][j] = s;
			s+=d;
			d++;
		}
		diff++;
		rows+=diff;
	}
	
	cin>>xx1>>yy1>>xx2>>yy2;
	
	dfs(a, xx1, yy1, 0);
	cout<<sums.size()<<endl;
	
	for(i=0;i<n;i++) {
		for(j=0;j<m;j++) { 
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
    return 0;
}

