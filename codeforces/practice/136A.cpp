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
    int n, i, num;
    cin>>n;
    int a[n+1];
    for(i=1;i<n+1;i++) {
        cin>>num;
        a[num] = i;
    }

    for(i=1;i<n+1;i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}

