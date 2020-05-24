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
		
		bool flag = true;
		set<int> pos;
		for(i=0;i<n;i++) {
			for(j=i+1;j<n;j++) {
				int mis = 0;
				for(k=0;k<m;k++) {
					if(s[i][k] != s[j][k]) {
						mis++;
						pos.insert(k);
					}
				}
				if(mis > 2) {
					flag = false;
					break;
				}
			}
			if(!flag) break;
		}
		
		if(!flag) cout<<"-1"<<endl;
		else { 
			if(pos.size() > 2) {
				cout<<"-1"<<endl;
				continue;
			} 
			if(pos.size() == 0) {
				cout<<s[0]<<endl;
				continue;
			}
			
			if(pos.size() == 1) {
				set<int> :: iterator it = pos.begin();
				int p1 = (*it);
				string ans;
				
				bool found = false;
				for(int c1=0;c1<26;c1++) {
					string x;
					for(i=0;i<m;i++) {
						if(i == p1) x = x + (char)(c1+'a');
						else x = x + s[0][i];
					}
					
					bool f = true;
					for(i=0;i<n;i++) {
						if(get_miss(x, s[i]) > 1) {
							f = false;
							break;
						}
					}
					if(f) {
						//~chk(x);
						found = true;
						ans = x;
						break;
					}
				}
				
				if(found) cout<<ans<<endl;
				else cout<<"-1"<<endl;
				continue;
			}
			
			set<int> :: iterator it = pos.begin();
			int p1 = (*it);
			it++;
			int p2 = (*it);
			string ans;
				
			bool found = false;
			for(int c1=0;c1<26;c1++) {
				for(int c2=0;c2<26;c2++) {
					string x;
					for(i=0;i<m;i++) {
						if(i == p1) x = x + (char)(c1+'a');
						else if (i == p2) x = x + (char)(c2+'a');
						else x = x + s[0][i];
					}
					
					bool f = true;
					for(i=0;i<n;i++) {
						if(get_miss(x, s[i]) > 1) {
							f = false;
							break;
						}
					}
					if(f) {
						//~chk(x);
						found = true;
						ans = x;
						break;
					}
				}
				if(found) break;
			}
			
			if(found) cout<<ans<<endl;
			else cout<<"-1"<<endl;
		}
	}

    return 0;
}

