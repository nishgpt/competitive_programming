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

void print(int i, int j, int row, int col) {
    printf("%d %d %d %d\n", i, j, row, col);
}

void print(int *x, int n, int m) {
    int i, j;

    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            cout<<*((x+i*n) + j)<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int t, n, m;

    scanf("%d", &t);

    while(t--) {
        scanf("%d %d", &n, &m);

        int a[n][m], i, j;
        string s;
        
        for(i=0;i<n;i++) {
            cin>>s;
            for(j=0;j<m;j++) {
                a[i][j] = s[j] - '0';
            }
        }

        print(&a[0][0], n, m);
        
        vector<int> v;
        for(int d = 1;d<=n+m-2;d++) {
            int pairs = 0;
            for(i=0;i<n;i++) {
                for(j=0;j<m;j++) {
                    if(a[i][j]) {
                        for(int row=i;row<=min(n-1, d+i);row++) {
                            int col = d - (row-i);
                            if(j+col < m && a[row][j+col]) pairs++;
                            if(col != 0 && row != i && j-col >= 0 && a[row][j-col]) pairs++;
                        }
                    }
                }
                
            }
            v.pb(pairs);
        }

        for(i=0;i<v.size();i++) {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

