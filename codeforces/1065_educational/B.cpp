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

LL a[MAX];
void pre() {
    LL i;
    for(i=0;i<MAX;i++) {
        a[i] = i * (i-1) / 2;
        //if(i<10) cout<<a[i]<<endl;
    }
}

int main() {
    LL n, i, j, m;
    pre();
    cin>>n>>m;
    
    LL mini, maxi = n, conn = 0;
    mini = n - 2*m;
    if(mini < 0) mini = 0;
    
    int x = lower_bound(a, a+MAX, m) - a;
    conn += x;
    maxi -= conn;
    cout<<mini<<" "<<maxi<<endl;
    return 0;
}

