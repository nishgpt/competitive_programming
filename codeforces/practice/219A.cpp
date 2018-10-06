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
    int k, i, j, n;
    string s;

    int a[26] = {0};
    
    cin>>k;
    cin>>s;
    n = s.length();
    for(i=0;i<n;i++) {
        a[s[i] - 'a']++;
    }

    for(i=0;i<26;i++) {
        if(a[i] % k != 0) {
            cout<<"-1"<<endl;
            return 0;
        }
        a[i] = a[i] / k;
    }

    while(k--) {
        for(i=0;i<26;i++) {
            for(j=0;j<a[i];j++) {
                cout<<(char)(i+'a');
            }
        }
    }
    cout<<endl;
    return 0;
}

