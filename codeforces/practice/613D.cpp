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
#define LOG_MAX 31
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
 
void convert_to_binary(LL num, vector<int> &v) {
	queue<int> q;
	while(num) {
		q.push(num&1);
		num>>=1;
	}
	
	for(int i=LOG_MAX-1;i>=0;i--) {
		if(q.empty()) break;
		else {
			v[i] = q.front();
			q.pop();
		}
	}
}
 
LL recur(int pos, vector<int> bin[], int n, vector<int> curr) {
	vector<int> o, z;
	for(int i=0;i<curr.size();i++) {
		if(bin[curr[i]][pos]) o.PB(curr[i]);
		else z.PB(curr[i]);
	}
	
	if(pos == LOG_MAX-1) {	
		return (o.size() != 0 && z.size() != 0) ? 1 : 0;
	}
	
	if(o.size() == 0 || z.size() == 0) {
		return recur(pos + 1, bin, n, curr);
	}
	
	LL pow = ((1L) << (LOG_MAX - pos - 1));
	return pow + min(recur(pos+1, bin, n, z), recur(pos+1, bin, n, o));
}

void solve() {
	int n;
	cin>>n;
	LL a[n];
	vector<int> v[n];
	vector<int> all;
	for(int i=0;i<n;i++) {
		v[i].resize(LOG_MAX, 0);
		cin>>a[i];
		convert_to_binary(a[i], v[i]);
		all.PB(i);
	}
	cout<<recur(0, v, n, all)<<endl;
}
 
int main() {
	int t = 1;
	
	//~cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
