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
    int n, i, j, k;

    cin>>n>>k;

    string s;
    cin>>s;

    sort(s.begin(), s.end());

    int st = s[0] - 'a';
    k--;
    int ans = s[0] - 'a' + 1;

    for(i=1;i<s.length();i++) {
        if(k == 0) break;
        if(s[i]-'a' - st >= 2) {
            k--;
            st = s[i] - 'a';
            ans += s[i] - 'a' + 1;
        }
    }

    if(k == 0) {
        cout<<ans<<endl;
    }
    else cout<<"-1"<<endl;
    return 0;
}

