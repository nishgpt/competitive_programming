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
    int t;
    cin>>t;

    string s;
    while(t--) {
        cin>>s;
        int f = 0;
        for(int i=0;i<s.length()-1;i+=2) {
            if(s[i] == s[i+1]) {
                f = 1; break;
            }
        }

        if(f) cout<<"no"<<endl;
        else cout<<"yes"<<endl;
    }
    return 0;
}

