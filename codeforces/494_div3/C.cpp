/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 5005
#define MOD 1000000007

using namespace std;

int main() {
    int i, j, k, a[MAX], cum[MAX] = {0}, n;

    cin>>n>>k;

    for(i=0;i<n;i++) {
        cin>>j;
        cum[i] = (i==0) ? j : (cum[i-1] + j);
    }

    double maxi = -1.00;
    for(i=0;i<=n-k+1;i++) {
        for(j=i+k-1;j<n;j++) {
            double avg; int num = 0;
            if(i-1 < 0) num = cum[j];
            else num = cum[j] - cum[i-1];

            avg = (1.0 * num) / (j-i+1);
            maxi = max(maxi, avg);
        }
    }

    printf("%0.8f\n", maxi);
    return 0;
}

