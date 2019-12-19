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
    int n, t, i, x;
    cin>>t;

    while(t--) {
        cin>>n;
        int zero = 0, two = 0;
        while(n--) {
            cin>>x;
            if(x == 0) zero++;
            else if(x == 2) two++;
        }
        cout<< (((zero * (zero - 1)) >> 1) + ((two * (two - 1)) >> 1)) << endl;
    }
    return 0;
}

