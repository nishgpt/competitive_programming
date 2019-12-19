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
    int t, n, i;
    string s;
    cin>>t;

    while(t--) {
        cin>>n;
        cin>>s;
        int a[n][26];
        memset(a, -1, sizeof a);
        int maxi = -1;
        for(i=1;i<n;i++) {
            for(int j = 0;j<26;j++) {
                if(s[i-1]-'a' == j) {
                    a[i][j] = i-1;
                } else {
                    a[i][j] = a[i-1][j];
                }
            }
            int prev = a[i][s[i]-'a'];
            if(prev != -1) {
                int temp_ans = prev + n - i;
                maxi = max(maxi, temp_ans); 
            }
        }

        maxi = max(maxi, 0);
        cout<<maxi<<endl;
    }
    return 0;
}

