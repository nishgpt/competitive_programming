#include<bits/stdc++.h>
#define LL long long int

using namespace std;

int count_of_ones(LL num) {
    LL r = num;
    int count = 0;
    while(r) {
        count = count + (r & 1);
        r = r / 2;
    }

    return count;
}

int trailing_zeroes(LL num) {
    LL r = num;
    int count = 0;
    while(!(r&1)) {
        count++;
        r = r / 2;
    }

    return count;
}

int main() {
    LL a, b;
    int t;
    cin>>t;

    while(t--) {
        cin>>a>>b;
        int cb = count_of_ones(b);
        int ca = count_of_ones(a);

        LL ans = 0;
        if(a == b) ans = 0;
        else if(b == 0 || (b == 1 && a != 0)) ans = -1;
        else if(ca == cb) {
            if(b&1) ans = 2;
            else ans = trailing_zeroes(b);
        }
        else if(ca < cb) {
            ans = (cb-ca);
            if(!(b&1)) ans += trailing_zeroes(b); 
        }
        else {
            if(b&1) ans = 2;
            else {
                //leave all common 1's except the last one in B
                ca = ca - (cb - 1);
                int tz = trailing_zeroes(b);
                if(tz >= ca) {
                    ans = tz - ca + 1;
                } 
                else {
                    ans = 2;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
