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
    string s, c;

    cin>>s;
    cin>>c;
    int i, j;

    int ls = s.length(), lc = c.length();

    for(i=0;i<=ls-lc;i++) {
        int diff = 0;
        bool flag = true;
        int d = 0;
        for(j=0;j<lc;j++, d++) {
            if(s[i+d] != c[j]) {
                diff++;
            }
            if(diff > 1) {
                flag = false;
                break;
            }
        }
        if(flag) {
            cout<<i+1<<endl;
            return 0;
        }
    }
    return 0;
}

