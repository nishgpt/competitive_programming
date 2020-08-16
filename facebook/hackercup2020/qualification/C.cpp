/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

#define LL long long int
#define getcx getchar_unlocked
#define X first
#define Y second
#define PB push_back
#define MP make_pair
#define MAX 800005
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

inline void inp( int &n ) { 
	n=0;    int ch=getcx();int sign=1;   
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();} 
	while(  ch >= '0' && ch <= '9' )    
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}

unordered_map<int, int> trees; //index of tree at a position (1-indexed)
unordered_map<int, int> lans, rans; //answers for left and right
map<int, vector<int> > lt, rt; //tree indexes which fall at a position
set<int> positions; //all positions where trees can fall to

void cleanse() {
	trees.clear();
	lt.clear(); rt.clear();
	lans.clear(); rans.clear();
	positions.clear();
}

void solve() {
	cleanse();
	
	int n; inp(n);
	vector<pi> v(n); //pair<pos, height>
	for(int i=0;i<n;i++) {
		inp(v[i].X);
		inp(v[i].Y);
	}
	
	sort(v.begin(), v.end());
	
	for(int i=0;i<n;i++) {
		trees[v[i].X] = i+1;
		lt[v[i].X + v[i].Y].PB(i);
		positions.insert(v[i].X + v[i].Y);
		rt[v[n-i-1].X - v[n-i-1].Y].PB(n-i-1);
		positions.insert(v[n-i-1].X - v[n-i-1].Y);
	}
	
	map<int, vector<int> > :: iterator it;
	for(it=lt.begin();it!=lt.end();it++) {
		int pos = it->first;
		vector<int> idx = it->second;
		
		for(int i=0;i<idx.size();i++) {
			lans[pos] = max(lans[pos], lans[v[idx[i]].X] + v[idx[i]].Y); 
		}
	}
	
	map<int, vector<int> > :: reverse_iterator rit;
	for(rit=rt.rbegin();rit!=rt.rend();rit++) {
		int pos = rit->first;
		vector<int> idx = rit->second;
		
		for(int i=0;i<idx.size();i++) {
			rans[pos] = max(rans[pos], rans[v[idx[i]].X] + v[idx[i]].Y);
		}
	}
	
	set<int> :: iterator sit;
	int ans = 0;
	for(sit=positions.begin();sit!=positions.end();sit++) {
		int pos = *sit;
		
		ans = max(ans, lans[pos] + rans[pos]);
		if(trees[pos]) {
			ans = max(ans, lans[pos] + v[trees[pos]-1].Y);
			ans = max(ans, rans[pos] + v[trees[pos]-1].Y);
		}
	}
	cout<<ans<<en;
}

int main() {
	int t = 1;
	
	cin>>t;
	for(int i=1;i<=t;i++) {
		cout<<"Case #"<<i<<": ";
		solve();
	}
    return 0;
}
