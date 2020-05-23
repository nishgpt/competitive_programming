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

void print_sums(vector<int> v, int n) {
	int i, j, k;
	vector<pair<int, int> > freq[MAX];
	for(i=0;i<n;i++) {
		for(j=i;j<n;j++) {
			int sum = 0;
			for(k=i;k<=j;k++) {
				sum+=v[k];
			}
			freq[sum].PB(MP(i, j));
			//~cout<<sum<<" ";
		}
	}
	cout<<endl;
	
	for(i=0;i<MAX;i++) {
		if(freq[i].size() <= 1) continue;
		cout<<i<<" -> ";
		for(j=0;j<freq[i].size();j++) {
			cout<<"("<<freq[i][j].X<<", "<<freq[i][j].Y<<") ";
		}
		cout<<endl;
	}
}

map<int, bool> present;
int main() {
	int n, p=1, i, j;
	cin>>n;
	
	int sum[n];
	MSV(sum, 0);
	vector<int> ans(n);
	i = 0;
	while(i<n) {
		if(present[p]) {
			++p;
			continue;
		}
		
		bool ok = true;
		if(i>0) {
			for(j=0;j<i;j++) {
				int r = sum[i-1], l=0;
				if(j>0) l=sum[j-1];
				
				if(present[p+r-l]) {
					ok = false;
					break;
				}
			}
		}
		
		if(!ok) {
			++p;continue;
		}
		
		present[p] = true;
		if(i>0) {
			for(j=0;j<i;j++) {
				int r = sum[i-1], l=0;
				if(j>0) l=sum[j-1];
				present[p+r-l] = true;
			}
		}
		ans[i] = p;
		sum[i] = p;
		
		//erase all keys less than p
		map<int, bool> :: iterator it = present.begin();
		while(it != present.end()) {
			if(it->first >= p) break;
			present.erase(it->first);
			it++;
		}
		if(i>0) sum[i] += sum[i-1];
		++p;
		++i;
	}

	
	for(i=0;i<n;i++) cout<<ans[i]<<" ";
	cout<<endl;
	//print_sums(ans, n);
    return 0;
}

