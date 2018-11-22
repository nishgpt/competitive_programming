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

vector<pair<LL, LL> > answers;

pair<LL, LL> a_plus_minus_b(pair<int, int> a, pair<int, int> b, bool plus) {
    if(!plus) b.first = -1 * b.first;

    LL den = (a.second * b.second) / __gcd(a.second, b.second);
    LL num = a.first * (den/a.second) + b.first * (den/b.second);
    
    LL g = __gcd(num, den);

    return mp(num/g, den/g);
}

void pre() {
    pair<LL, LL> left, right;//pair.first is x , pair.second is y

    left = mp(0, 1);
    right = mp(1, 1);

    LL pow2 = 2;
    for(int i=1;i<=25;i++) {
        if(i&1) {
            //right end to be picked for folding
            right = a_plus_minus_b(right, mp(1, pow2), false);
            answers.pb(right);
        } else {
            //left end to be picked for folding
            left = a_plus_minus_b(left, mp(1, pow2), true);
            answers.pb(left);
        }
        pow2<<=1;
    }
}

int main() {
    LL t, n;

    pre();
    cin>>t;

    for(int i=0;i<25;i++) {
        cout<<answers[i].first<<" "<<answers[i].second<<endl;
    }
    while(t--) {
        cin>>n;
        cout<<answers[n-1].first<<" "<<answers[n-1].second<<" ";
    }
    return 0;
}

