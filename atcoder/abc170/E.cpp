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
#define MAX 200005
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
typedef pair<int, int> pi;
typedef pair<LL, LL> pl;
const char en = '\n';

multiset<int> ch[MAX];
multiset<int> ms;
void solve() {
	int n, q;
	in2(n, q);
	
	int a[n], b;
	int curr[n];
	for(int i=0;i<n;i++) {
		in2(a[i], b);
		curr[i] = b;
		ch[b].insert(a[i]);
	}
	
	multiset<int> :: reverse_iterator rit;
	for(int i=1;i<MAX;i++) {
		if(ch[i].size() == 0) continue;
		rit = ch[i].rbegin();
		ms.insert(*rit);
	}
	
	int c, d;
	multiset<int> :: iterator it1, it2;
	while(q--) {
		in2(c, d);
		c--;
		int currk = curr[c]; //current kg
		rit = ch[currk].rbegin();
		int high = *rit; //curr highest rating
		it1 = ms.find(high);
		if(it1 != ms.end()) ms.erase(it1); //erase this rating
		
		it2 = ch[currk].find(a[c]);
		if(it2 != ch[currk].end()) ch[currk].erase(it2);
		
		if(ch[currk].size() != 0) {
			rit = ch[currk].rbegin();
			int newhigh = *rit;
			ms.insert(newhigh);
		}
		
		//=========second leg
		if(ch[d].size() != 0) {
			rit = ch[d].rbegin();
			int dhigh = *rit;
			it1 = ms.find(dhigh);
			if(it1 != ms.end()) ms.erase(it1);
		}
		
		ch[d].insert(a[c]);
		
		rit = ch[d].rbegin();
		int dnew = *rit;
		ms.insert(dnew);
		curr[c] = d;
		
		it2 = ms.begin();
		cout<<(*it2)<<en;
	}
}

int main() {
	int t = 1;
	
	//~cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
