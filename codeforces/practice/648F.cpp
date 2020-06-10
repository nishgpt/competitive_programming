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
typedef pair<int, int> pi;
typedef pair<LL, LL> pl;

struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 

void solve() {
	int n;
	cin>>n;
	int a[n], b[n];
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	
	if((n & 1) && a[n/2] != b[n/2]) {
		cout<<"No"<<endl;
		return ;
	} 
	
	unordered_map<pi, int, hash_pair> mp1, mp2;
	for(int i=0;i<n/2;i++) {
		mp1[MP(min(a[i], a[n-i-1]), max(a[i], a[n-i-1]))]++;
		mp2[MP(min(b[i], b[n-i-1]), max(b[i], b[n-i-1]))]++;
	}
	
	unordered_map<pi, int, hash_pair> :: iterator it = mp1.begin();
	while(it != mp1.end()) {
		pi p = it -> first;
		if(mp2[p] != it->second) {cout<<"No"<<endl; return;}
		it++;
	}
	
	cout<<"Yes"<<endl;
}

int main() {
	int t = 1;
	
	cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
