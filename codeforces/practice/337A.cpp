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
    int n, m, p;
    vector<int> a;

    cin>>n>>m;

    for(int i=0;i<m;i++) {
        cin>>p;
        a.pb(p);
    }

    sort(a.begin(), a.end());

    int mini = INT_MAX;
    for(int i=n-1;i<m;i++) {
        mini = min(mini, a[i]-a[i-n+1]);
    }

    cout<<mini<<endl;
    return 0;
}

