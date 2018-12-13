
#include <iostream>
#include <cstdio>
#include <climits>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cmath>
#include <queue>
#include <utility>
using namespace std;

#define inp(a) scanf("%d", &a)
#define out(a) printf("%d\n", a)
#define inpll(a) scanf("%lld", &a)
#define outll(a) printf("%lld\n", a)
#define VI vector<int>
#define VLL vector<long long int>
#define PQI priority_queue<int>
#define PQLL priority_queue<long long int>

#define ll long long int
#define mod 1000000007
#define mp make_pair
#define X first
#define Y second
#define pb push_back
#define rep(i, a, b) for (i = a; i < b; i++)
#define MS(a) memset(a, 0, sizeof(a))

string s, s1, s2;
int i, j, k, n, t, len, step, cnt;
int p[22][1505];
struct arr {
    int a, b, c;
} l[1505];

struct sec {
    int suf, ind;
} indexi[1505];

bool compare(const arr& x, const arr& y)
{
    return x.a == y.a ? (x.b < y.b ? 1 : 0) : (x.a < y.a ? 1 : 0);
}

bool comp(const sec& x, const sec& y)
{
    return x.suf < y.suf;
}

void suffixarray(string s)
{
    len = s.length();
    rep(i, 0, len) p[0][i] = (int)s[i];
    for (step = 1, cnt = 1; (cnt >> 1) < len; cnt <<= 1, step++) {
        for (i = 0; i < len; i++) {
            l[i].a = p[step - 1][i];
            l[i].b = i + cnt < len ? p[step - 1][i + cnt] : -1;
            l[i].c = i;
        }
        sort(l, l + len, compare);
        for (i = 0; i < len; i++)
            p[step][l[i].c] = (i > 0 && l[i].a == l[i - 1].a && l[i].b == l[i - 1].b) ? p[step][l[i - 1].c] : i;
    }
    step--;
}

int lcp(int x, int y)
{
    int k, ret = 0;
    if (x == y)
        return len - x;
    for (k = step; ((k >= 0) && (x < len) && (y < len)); k--) {
        if (p[k][x] == p[k][y]) {
            x += 1 << k;
            y += 1 << k;
            ret += 1 << k;
        }
    }
    return ret;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        cin >> s;
        MS(p);
        MS(l);
        MS(indexi);
        suffixarray(s);
        rep(i, 0, len)
        {
            indexi[i].suf = p[step][i];
            //cout<<indexi[i].suf<<endl;
            indexi[i].ind = i;
        }

        sort(indexi, indexi + len, comp);

        int maxi = 0, idx = 1, val1, val2, big;
        maxi = len - indexi[0].ind;
        rep(i, 1, len)
        {
            val1 = indexi[i - 1].ind;
            val2 = indexi[i].ind;
            maxi += ((len - val2) - lcp(val1, val2));
        }
        out(maxi);
    }
    return 0;
}


Format!Style:
C++ online code formatter © 2014 by KrzaQ

Powered by vibe.d, the D language and clang-format