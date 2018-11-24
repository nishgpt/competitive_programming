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
    int x, s, p, h, t;

    cin>>p>>s>>t>>h>>x;
    
    if(s - t == 0) {
        cout<<h*x<<endl;
    } else if (s - t >= x) {
        cout<<p*x<<endl;
    } else {
        cout<<h*(x-s+t) + p*(s-t)<<endl;
    }
    return 0;
}

