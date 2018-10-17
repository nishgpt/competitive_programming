/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 205
#define MOD 1000000007

using namespace std;

bool non_primes[MAX];
set<int> semi_primes;

void pre() {
    int i, j;
    non_primes[0] = non_primes[1] = true;

    for(i=2;i*i<MAX;i++) {
        if(!non_primes[i]) {
            for(j=i*i;j<MAX;j+=i) {
                non_primes[j] = true;
            }
        }
    }

    for(i=2;i*i<MAX;i++) {
        if(!non_primes[i]) {
            for(j=i*i;j<MAX;j+=i) {
                int q = j/i;
                if(!non_primes[q] && q!=i) {
                    semi_primes.insert(j);
                }
            }
        }
    }
}

int main() {
    pre();

    int t, n;
    cin>>t;

    while(t--) {
        cin>>n;
        
        set<int>::iterator it = semi_primes.begin();

        string found = "NO";
        while(it != semi_primes.end()) {
            if(semi_primes.find(n - *it) != semi_primes.end()) {
                found = "YES";
                break;
            }
            ++it;
        }

        cout<<found<<endl;
    }
    return 0;
}

