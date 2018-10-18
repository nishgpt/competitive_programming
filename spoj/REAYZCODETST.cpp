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
    int t, n, x, i, num, tc = 1;

    scanf("%d", &t);

    while(t--) {
        scanf("%d %d", &n, &x);
        
        map<int, LL> freq;
        set<int> uniq;
        for(i=0;i<n;i++) {
            cin>>num;
            freq[num]++;
            uniq.insert(num);
        }

        set<int>::iterator sit = uniq.begin();
        
        LL ans = 0;
        while(sit != uniq.end()) {
            if(x == 0) {
                ans = ans + (freq[*sit] * (freq[*sit] - 1));
            }
            else {
                set<int>::iterator ptr = uniq.find(x + *sit);
                if(ptr != uniq.end()) {
                    ans += freq[*sit] * freq[*ptr];
                }
            }
            ++sit;
        }

        cout<<"Case "<<tc++<<": "<<ans<<endl;
    }
    return 0;
}

