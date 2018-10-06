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
    int n, i, j;
    string s;

    cin>>n;
    cin>>s;
    for(i=1;i<=n;i++) {
        if(n%i == 0) {
            string x = s.substr(0, i);
            reverse(x.begin(), x.end());
            string temp = x + s.substr(i);
            s = temp;
            //cout<<s<<" " <<i<<endl;
        }
    }

    cout<<s<<endl;
    return 0;
}

