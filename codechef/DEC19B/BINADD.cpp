/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 100005
#define MOD 1000000007

using namespace std;

int main() {
    int t, i, j;
    string x, y;
    cin>>t;

    while(t--) {
        cin>>x;
        cin>>y;
        int lx = x.length();
        int ly = y.length();
        if(ly == 1 && y[0] == '0') {
            cout<<"0"<<endl;
            continue;
        }
        int l = max(lx, ly);
        int a[l], b[l];
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        int sa = 0, sb = 0;
        if(lx < ly) {
            sa = ly - lx;
        } else if(ly < lx) {
            sb = lx - ly;
        }

        j = 0;
        for(i=sa;i<l;i++,j++) {
            a[i] = x[j] - '0';
        }
        j = 0;
        for(i=sb;i<l;i++,j++) {
            b[i] = y[j] - '0';
        }

        int prev[l];
        memset(prev, -1, sizeof prev);
        for(i=1;i<l;i++) {
            if((a[i-1] ^ b[i-1]) == 0) {
                prev[i] = i-1;
            } else {
                prev[i] = prev[i-1];
            }
        }
        
        int ans = 0;
        for(i=0;i<l;i++) {
            if((a[i] & b[i]) == 1) {
                ans = max(ans, i-prev[i]);
            }
        }

        cout<<ans + 1<<endl;
    }
    return 0;
}

