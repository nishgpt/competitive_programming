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

bool check_lucky(int num) {
    if(num == 0) return false;

    while(num) {
        int r = num % 10;
        if(r != 4 && r != 7) return false;
        num = num / 10;
    }

    return true;
}

int main() {
    LL n;
    cin>>n;

    LL num = n; int count = 0;
    while(num) {
        int r = num % 10;
        if(r == 4 || r == 7) count++;

        num = num / 10;
    }

    if(check_lucky(count)) {
        cout<<"YES\n";
    }
    else cout<<"NO\n";

    return 0;
}

