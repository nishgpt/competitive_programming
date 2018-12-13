/*
	NISHANT GUPTA
	CSE-MNNIT ALLAHABAD
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <cctype>
#include <utility>
#include <map>
#include <string>
#include <climits>
#include <set>
#include <string>
#include <sstream>
#include <utility>
#include <ctime>
#include <cassert>
#include <fstream>
using namespace std;
typedef long long int LL;
typedef vector<int> VI;
typedef pair<int, int> II;
typedef vector<long long> VLL;
typedef vector<bool> VB; 
#define SZ(A) ((int)A.size())
#define LEN(A) ((int)A.length())
#define MS(A) memset(A, 0, sizeof(A))
#define MSV(A,a) memset(A, a, sizeof(A))
#define MAX(a,b) ((a >= b) ? (a) : (b))
#define MIN(a,b) ((a >= b) ? (b) : (a))
#define ABS(a) (((a) > 0) ? (a) : (-a))
#define MP make_pair
#define X first
#define Y second
#define PB push_back
#define FOUND(A, x) (A.find(x) != A.end())
#define getcx getchar_unlocked
#define INF 0x3f3f3f3f
#define INFL (LL(1e18))
#define EPS 1e-12 
#define chkbit(s, b) (s & (1<<b))
#define setbit(s, b) (s |= (1<<b))
#define clrbit(s, b) (s &= ~(1<<b))
#define rep(i, a, n) for(i = a; i < n; i++)
#define rev(i, a, n) for(i = a; i > n; i--)
#define FORALL(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)
#define ALL(A) A.begin(), A.end()
#define LLA(A) A.rbegin(), A.rend()

LL mod = 1000000007;

int main() {
	LL i,j,k,n,m;
	int t;
	scanf("%d", &t);
	string s;
	while(t--) {
		cin>>s;
		n = s.length();
		LL v[26] = {0}, f[26] = {0};
		LL ans[100005] = {0};
		ans[0] = 1;
		f[s[0] - 'A'] = 1;
		for(i=1;i<n;i++) {
			if(f[s[i] - 'A'] == 0) {
				ans[i] = (ans[i-1] + ans[i-1] + 1) % mod;
				//cout<<i<<" "<<"if"<<endl;
			}
			else {
				ans[i] = (ans[i-1] + ans[i-1] - v[s[i] - 'A'] + mod) % mod;
				//cout<<i<<" "<<"else"<<endl;
			}
			f[s[i] - 'A'] = 1;
			v[s[i] - 'A'] = (ans[i-1]) % mod;
			//cout<<ans[i]<<" ";
		}
		printf("%lld\n", (ans[n-1] + 1) % mod);
	}
	return 0;
}