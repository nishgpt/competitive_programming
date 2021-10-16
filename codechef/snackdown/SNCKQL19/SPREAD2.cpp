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
    int t, n;

    cin>>t;
    while(t--) {
        cin>>n;
        int a[n];

        for(int i=0;i<n;i++) { 
            cin>>a[i];
        }

        LL cum_sum[n];
        memset(cum_sum, 0, sizeof cum_sum);
        
        for(int i=0;i<n;i++) {
            cum_sum[i] = a[i];
            if(i>0) {
                cum_sum[i] += cum_sum[i-1];
            }
        }

        LL days = 0, people = 1, curr = 0;
        while(people < n) {
            people+=cum_sum[curr];
            curr = people-1;
            days++;
        }

        cout<<days<<endl;
    }
    return 0;
}

