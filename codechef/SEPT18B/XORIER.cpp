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
    int t, n, i, j;

    cin>>t;

    while(t--) {
        cin>>n;
        int a[n];
        int freq[MAX] = {0};

        for(i=0;i<n;i++) {
            cin>>a[i];
            freq[a[i]]++;
        }

        LL sum_odd = 0, sum_even = 0;
        for(i=1;i<MAX;i++) {
            if(i&1) sum_odd += freq[i];
            else sum_even += freq[i];
        }

        LL ans = 0;
        for(i=1;i<MAX;i++) {
            if(freq[i]) {
                ans += ((i&1) ? ((sum_odd - freq[i]) * freq[i]) : ((sum_even - freq[i]) * freq[i]));
                int xor_2 = 2 ^ i;
                if(freq[xor_2]) {
                    ans -= (freq[i] * freq[xor_2]);
                }
            }
        }

        cout<<(ans>>1)<<endl;
    }
    return 0;
}

