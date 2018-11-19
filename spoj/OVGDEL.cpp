/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 1000005
#define MOD 1000000007

using namespace std;

int main() {
    int n, i, tc = 1, j, t;

    cin>>t;

    while(t--) {
        cin>>n;
        int a[n], freq[MAX] = {0};
        for(i=0;i<n;i++) {
            cin>>a[i];
            freq[a[i]]++;
        }

        int count = 0;
        for(i=0;i<n;i++) {
            int flag = 0;
            for(LL p = 1;p < MAX;p=p*a[i]) {
                if(p == a[i] && freq[p] > 1) {
                    flag = 1; break;
                }
                else if(p == 1 && a[i] == 1) {
                	break;
                }
                else if(p != a[i] && freq[p] > 0) {
                    flag = 1; break;
                }
            }
            count+=flag;
        }

        printf("Case %d: %d\n", tc++, count);
    }
    return 0;
}
