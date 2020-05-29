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


int kadane(int a[], int size, int rem) {

    bool found = false;
    for (int i = 0; i < size; i++) {
        if (a[i] == rem)
            found = true;
    }
    if (!found)
        return 0;

    int ms = INT_MIN, me = 0, cnt = 1;
    for (int i = 0; i < size; i++) {
        if (a[i] > rem) {
            me = 0;
            cnt = 1;
            continue;
        }

        me += a[i];
        if (cnt && a[i] == rem) cnt--;

        if (me < 0) {
            me = 0;
            cnt = 1;
            continue;
        }

        if (ms < me && cnt == 0) ms = me;
    }
    return max(ms - rem, 0);
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int maxi = 0;
    for (int i = -30; i <= 30; i++) {
        int k = kadane(a, n, i);
        maxi = max(maxi, k);
    }
    cout << maxi << endl;

    return 0;
}

