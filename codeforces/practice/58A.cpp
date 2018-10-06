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
    string s;
    cin>>s;

    int i, j=0;
    string pattern = "hello";
    for(i=0;i<s.length();i++) {
        if(pattern[j] == s[i]) {
            j++;
        }
        if(j == 5) {
            cout<<"YES"<<endl;
            return 0;
        }
    }

    cout<<"NO"<<endl;
    return 0;
}

