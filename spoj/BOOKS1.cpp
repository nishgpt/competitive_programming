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

LL n;
bool get_max(LL *a, LL x, LL m) {
	LL i,j=0,k,sum,maxi=-1;
	for(i=0;i<m;i++) {
		sum = 0;
		for(k=j;k<n;k++) {
			if(sum+a[k]<=x && (n-k-1)>=(m-k-1)) { 
				sum+=a[k];
			}
			else break;
		}
		j=k;
		maxi = MAX(maxi,sum);
	}
	if(j<n)for(k=j;k<n;k++)sum+=a[k];
	maxi = MAX(maxi, sum);
	//cout<<"maxi "<<maxi<<endl;
	if(maxi <= x)return true;
	return false;
}

int main() {
	LL i,j,k,m,t;
	scanf("%lld",&t);
	LL a[100005];
	while(t--) {
		scanf("%lld %lld",&n, &m);
		k = 0;
		rep(i,0,n) {
			scanf("%lld",&a[i]);
			k += a[i];
		}
		
		LL l = 0, h = k, mid;
		bool value;
		LL ans = k;
		while(l<=h) {
			mid = (l+h) >> 1;
			//cout<<mid<<endl;
			value = get_max(a, mid, m);
			if(value) {
				h = mid - 1;
				ans = mid;
			}
			else l = mid + 1;
		}
	//	printf("%lld\n", ans);
		LL sum = 0;
		vector<LL> v[m];
		LL left = m-1;
		for(i=n-1;i>=0;) {
			LL x = i;
			if(sum+a[i]<=ans && left<=x) {
				sum = sum + a[i];
				v[left].PB(a[i]);
				i--;
			}	
			else {
				left --;
				sum = 0;
			}
		}
		rep(i,0,m) {
			for(j=v[i].size()-1;j>=0;j--) {
				printf("%lld ", v[i][j]);
			}
			if(i!=m-1)printf("/ ");
		}
		printf("\n");
	}
	return 0;
}