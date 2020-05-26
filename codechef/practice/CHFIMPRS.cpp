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
	int t, n, m, i, j;
	
	inp(t);
	
	while(t--) {
		inp(n);inp(m);
		int a[n][m], ans[n][m], odd = 0;
		
		map<int, int> mp;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++) {
				inp(a[i][j]);
				mp[a[i][j]]++;
			}
			
		map<int, int> :: iterator it = mp.begin();
		while(it != mp.end()) {
			if((it->second) & 1) odd++;
			it++;
		}
		
		if((m&1 && odd > n) || (!(m&1) && odd > 0)) {
			cout<<"-1"<<endl;
			continue;
		}
		
		it = mp.begin();
		if(m & 1) {
			int row = 0;
			while(it != mp.end()) {
				if((it->second) & 1) {
					ans[row++][m/2] = it->first;
					mp[it->first]--;
				}
				it++;
			}
			
			if(row < n-1) {
				it = mp.begin();
				while(it != mp.end() && row < n-1) {
					int freq = it->second;
					while(freq > 0) {
						ans[row++][m/2] = it->first;
						ans[row++][m/2] = it->first;
						freq-=2;
						if(row == n) break;
					}
					mp[it->first] = freq;
					it++;
				}
			}
		}
		
		
		it = mp.begin();
		int row = 0;
		i=0; j=m-1;
		while(true) {
			if(row == n) break;
			int freq = it->second;
			while(freq) {
				ans[row][i++] = it->first;
				ans[row][j--] = it->first;
				freq-=2;
				if(i >= j) {
					row++;i=0;j=m-1;
				}
			}
			it++;
			if(it == mp.end()) break;
		}
		
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) {
				printf("%d ", ans[i][j]);
			}
			printf("\n");
		}
		
	}
	

    return 0;
}

