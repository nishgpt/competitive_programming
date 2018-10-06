/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 400005
#define MOD 1000000007

using namespace std;

int main() {
    string s;
    int i, j, k, n;

    int a[MAX] = {0};

    cin>>n>>k;
    cin>>s;

    set<int> v[26];
    for(i=0;i<n;i++) {
        v[s[i]-'a'].insert(i);
    }

    while(k--) {
        for(i=0;i<26;i++) {
            if(v[i].empty()) continue;

            set<int>:: iterator it = v[i].begin();
            a[*it] = -1;
            v[i].erase(it);
            break;
        }
    }

    for(i=0;i<n;i++) {
        if(a[i]!=-1) {
            cout<<s[i];
        }
    }
    cout<<endl;
    return 0;
}

