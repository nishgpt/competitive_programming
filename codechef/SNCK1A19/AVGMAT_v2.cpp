/*
    Author: Team - baddy_boyz
    Members: Nishant Gupta, Arpit Uppal
*/
#include<bits/stdc++.h>
 
#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 100005
#define MOD 1000000007
 
using namespace std;
 
void print(int *x, int n, int m) {
    int i, j;
 
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            cout<<*((x+i*m) + j)<<" ";
        }
        cout<<endl;
    }
}
 
int main() {
    int t, i, n, m, j, k;
 
    scanf("%d", &t);
 
    while(t--) {
        scanf("%d %d", &n, &m);
 
        int left[n][m], right[n][m], a[n][m];
        string s;
 
        for(i=0;i<n;i++) {
            cin>>s;
            for(j=0;j<m;j++) {
                a[i][j] = s[j] - '0';
            }
        }
 
        for(i=n-1;i>=0;i--) {
            for(j=0;j<m;j++) {
                left[i][j] = a[i][j];
 
                if(i != n-1 && j-1 >= 0) {
                    left[i][j] += left[i+1][j-1];
                }
            }
        }
 
        for(i=n-1;i>=0;i--) {
            for(j=m-1;j>=0;j--) {
                right[i][j] = a[i][j];
 
                if(i != n-1 && j+1 < m) {
                    right[i][j] += right[i+1][j+1];
                }
            }
        }
 
        vector<LL> ans;
        for(int d = 1;d<=n+m-2;d++) {
            LL pairs = 0;
            for(i=0;i<n;i++) {
                for(j=0;j<m;j++) {
                    if(a[i][j]) {
                        //left bounds
                        int lrow = i + d;
                        int lcol = j;
                        if(lrow >= n) {
                            lcol = lcol + lrow - (n-1);
                            lrow = n-1;
                        }
                        int urow = i;
                        int ucol = j + d;
                        if(ucol >= m) {
                            urow = urow + ucol - (m-1);
                            ucol = m-1;
                        }
 
                        if(lrow >= 0 && lrow < n && lcol >= 0 && lcol < m) {
                            pairs = pairs + left[urow][ucol];
 
                            if(lrow + 1 < n && lcol - 1 >= 0) {
                                pairs -= left[lrow+1][lcol-1];
                            }
                        }
 
                        //right bounds
                        int rlrow = i + d;
                        int rlcol = j;
                        if(rlrow >= n) {
                            rlcol = rlcol - (rlrow - (n-1));
                            rlrow = n-1;
                        }
 
                        int rurow = i;
                        int rucol = j - d;
                        if(rucol < 0) {
                            rurow = rurow - rucol;
                            rucol = 0;
                        }
 
                        if(rlrow >= 0 && rlrow < n && rlcol >= 0 && rlcol < m) {
                            pairs = pairs + right[rurow][rucol];
 
                            if(rlrow + 1 < n && rlcol + 1 < m) {
                                pairs -= right[rlrow+1][rlcol+1];
                            }
                        }
 
                        if(lrow == rlrow && lcol == rlcol && lrow < n && lrow >= 0 && lcol >=0 && lcol < m && a[lrow][lcol]) {
                            pairs--;
                        }
                    }
                }
            }
            ans.pb(pairs);
        }
 
        for(i=0;i<n;i++) {
            for(j=0;j<m;j++) {
                if(a[i][j]) {
                    for(k=j+1;k<m;k++) {
                        if(a[i][k]) {
                            ans[k-j-1]--;
                        }
                    }
                }
            }
        }
 
        for(i=0;i<ans.size();i++) {
            cout<<ans[i]<<" ";
        }
 
        cout<<endl;
    }
    return 0;
}