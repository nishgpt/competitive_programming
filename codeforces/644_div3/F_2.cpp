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

int get_miss(string a, string b) {
	int miss = 0;
	for(int i=0;i<a.length();i++) {
		if(a[i] != b[i]) miss++;
	}
	return miss;
}

int main() {
	int t, n, m, i, j, k;
	cin>>t;
	while(t--) {
		cin>>n>>m;
		string s[n];
		for(i=0;i<n;i++) cin>>s[i];
		
		string ans;
		bool found = false;
		for(i=0;i<m;i++) {
			for(int c1 = 0;c1<26;c1++) {
				string x;
				for(j=0;j<m;j++) {
					if(j == i) x = x + (char)(c1+'a');
					else x = x + s[0][j];
				}
				
				bool flag = true;
				for(j=0;j<n;j++) {
					if(get_miss(x, s[j]) > 1) {
						flag =false;
						break;
					}
				}
				
				if(flag) {
					ans = x;
					found = true;
					break;
				}
			}
			if(found) break;
		}
		
		if(found) cout<<ans<<endl;
		else cout<<"-1"<<endl;
	}

    return 0;
}

