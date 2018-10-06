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
    string s, t, p;
    int a[26] = {0}, b[26] = {0}, i;

    cin>>s;
    cin>>t;
    cin>>p;

    for(i=0;i<s.length();i++) {
        a[s[i] - 'A']++;
    }

    for(i=0;i<t.length();i++) {
        a[t[i] - 'A']++;
    }

    for(i=0;i<p.length();i++) {
        b[p[i] - 'A']++;
    }

    for(i=0;i<26;i++) {
        if(a[i] != b[i]) {
            cout<<"NO"<<endl;
            return 0;
        }
    }

    cout<<"YES"<<endl;
    return 0;
}

