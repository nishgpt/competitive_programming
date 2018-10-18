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
    LL s, a, b, c;
    int t;
    cin>>t;
    while(t--) {
cin>>s>>a>>b>>c;

    LL q = s/c;
    cout<<q + (q/a) * b<<endl;
}
    return 0;
}

