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
typedef long long LL;
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

LL mod = 10000007;

int get_bits(int num) {
    int i, bits = 0;
    for(i=num;i;i/=2) {
        bits++;
    }
    return bits;
}

int main() {
    int t, i, j, k=1, n;
    scanf("%d", &t);
    int maxi, a[10005];
    while(t--) {
        scanf("%d", &n);
        maxi = -1;
        for(i=0;i<n;i++) {
            scanf("%d", &a[i]);
            maxi = MAX(maxi, a[i]);
        }
        int bits = get_bits(maxi);
        LL ans = 0, z, o;
        for(i=0;i<bits;i++) {
            z=0;o=0;
            for(j=0;j<n;j++) {
                if((1<<i)&a[j]) {
                    o++;
                }
                else z++;
            }
            ans = ans + z*o;
            if(ans >= mod) {
                ans %= mod;
            }
        }
        ans <<= 1;
        printf("Case %d: ", k++);
        printf("%lld\n", ans%mod);
    }
    return 0;
}
