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
#define MAX 20000005
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

int freq[MAX];
void solveHard() {
	int n;inp(n);
	vector<int> a(n), sum(n);
	int maxi = INT_MIN, me = INT_MAX;
	for(int i=0;i<n;i++) {
		inp(a[i]);
		sum[i] = a[i];
		if(i>0) sum[i] += sum[i-1];
		maxi = max(maxi, a[i]);
		me = min(me, sum[i]);
	}
	
	vector<int> sq;
	for(int i=0;;i++) {
		if(i*i <= maxi*n) sq.PB(i*i);
		else break;
	}
	
	LL ans = 0;
	int offset = abs(me);
	freq[offset] = 1;
	int mini = INT_MAX;
	
	for(int i=0;i<n;i++) {
		mini = min(mini, sum[i]);
		for(int j=0;j<sq.size();j++) {
			int diff = sum[i]-sq[j];
			if(diff < 0 && diff < mini) break;
			ans += freq[diff+offset];
		}
		freq[sum[i]+offset]++;
	}
	printf("%lld\n", ans);
	
	//clear off
	freq[offset] = 0;
	for(int i=0;i<n;i++) {
		freq[sum[i]+offset] = 0;
	}
}

void solve() {
	int n;in(n);
	vector<int> a(n), sum(n);
	for(int i=0;i<n;i++) {
		in(a[i]);
		sum[i] = a[i];
		if(i>0) sum[i] += sum[i-1];
	}
	
	int ans = 0;
	for(int i=0;i<n;i++) {
		for(int j=i;j<n;j++) {
			int s = sum[j] - (i>0 ? sum[i-1] : 0);
			if(s < 0) continue;
			int sq = sqrt(s);
			if(sq*sq == s) ans++;
		}
	}
	cout<<ans<<en;
}

int main() {
	int t = 1;
	
	cin>>t;
	for(int i=1;i<=t;i++) {
		cout<<"Case #"<<i<<": ";
		solveHard();
	}
    return 0;
}
