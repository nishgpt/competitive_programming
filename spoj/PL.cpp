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

bool check(string s) {
    int a[26] = {0};

    for(int i=0;i<s.length();i++) {
        a[s[i]-'a']++;
    }

    int odd = 0;
    for(int i=0;i<26;i++) {
        if(a[i] & 1) odd++;
    }

    return odd <= 1; 
}

int main() {
    string s;

    while(getline(cin, s)) {
        if(check(s)) cout<<"1"<<endl;
        else cout<<"-1"<<endl;
    }
    return 0;
}

