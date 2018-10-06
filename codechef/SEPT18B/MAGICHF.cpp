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
    int t, n, s, x, a, b;

    cin>>t;
    while(t--) {
        cin>>n>>x>>s;

        while(s--) {
            cin>>a>>b;

            if(a == x) x = b;
            else if(b == x) x = a;
        }
        cout<<x<<endl;
    }
    return 0;
}

