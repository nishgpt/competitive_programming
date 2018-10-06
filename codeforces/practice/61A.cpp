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
    string s, t;

    cin>>s;
    cin>>t;

    for(int i=0;i<s.length();i++) {
        if(s[i] == t[i]) cout<<'0';
        else cout<<'1';
    }

    cout<<endl;
    return 0;
}

