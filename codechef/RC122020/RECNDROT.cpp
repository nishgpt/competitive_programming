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
#define rep(i, a, n) for(i=a;i<n;i++)
#define rev(i, a, n) for(i=a;i>=n;i--)
#define MSV(A,a) memset(A, a, sizeof(A))
#define rep_itr(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)

using namespace std;

inline void inp( int &n ) { 
	n=0;    int ch=getcx();int sign=1;   
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();} 
	while(  ch >= '0' && ch <= '9' )    
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}

inline void inp1( LL &n ) { 
	n=0;    LL ch=getcx();LL sign=1;   
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();} 
	while(  ch >= '0' && ch <= '9' )    
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}

int main() {
	int t;
	int n, i;
	inp(t);
	while(t--) {
		inp(n);
		int a[n];
		map<int, vector<int> > pos;
		map<int, bool> found;
		vector<int> uniq;
		for(i=0;i<n;i++) {
			inp(a[i]);
			if(found[a[i]] == false) {
				uniq.PB(a[i]);
				found[a[i]] = true;
			}
			pos[a[i]].PB(i);
		}
		
		sort(uniq.begin(), uniq.end());
		
		int m = 1;
		int first = pos[uniq[0]][0];
		int sz = uniq.size();
		for(i=0;i<sz;i++) {
			if(first >= n-1)  {
				i++;
				if(i==sz) break;
				m++;
			}
			
			if(i+1 == sz) break;
			if(first == -1 || first >= n-1) {
				first = pos[uniq[i]][0];
			}
			
			int finder = upper_bound(pos[uniq[i+1]].begin(), pos[uniq[i+1]].end(), first) - pos[uniq[i+1]].begin();
			if(finder == pos[uniq[i+1]].size()) {
				first = -1;
				m++;
			} else {
				first = pos[uniq[i+1]][finder];
			}
		}
		
		cout<<m<<endl;
	}
    return 0;
}
