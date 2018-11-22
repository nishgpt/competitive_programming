/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 1605
#define MOD 1000000007

using namespace std;

struct triplet {
    LL bits;
    LL nibbles;
    LL bytes;
} new_formed[MAX], total[MAX];

void pre() {
    int i, j;
    total[0].bits = new_formed[0].bits = 1;
    total[0].nibbles = total[0].bytes = new_formed[0].nibbles = new_formed[0].bytes = 0;

    for(i=1;i<MAX;i++) {
        total[i].bits = total[i-1].bits;
        total[i].nibbles = total[i-1].nibbles;
        total[i].bytes = total[i-1].bytes;

        //new nibbles formed
        if(i-2 >= 0) {
            new_formed[i].nibbles = new_formed[i-2].bits;
            total[i].nibbles += new_formed[i].nibbles;
            total[i].bits -= new_formed[i].nibbles;
        }
        
        //new bytes formed
        if(i-8 >= 0) {
            new_formed[i].bytes = new_formed[i-8].nibbles;
            total[i].bytes += new_formed[i].bytes;
            total[i].nibbles -= new_formed[i].bytes;
        }

        //new bits formed
        if(i-16 >= 0) {
            new_formed[i].bits = new_formed[i-16].bytes * 2;
            total[i].bits += new_formed[i].bits;
            total[i].bytes -= new_formed[i].bits >> 1;
        }
    }
}

int main() {
    int t, n;
    cin>>t;

    pre();

    while(t--) {
        cin>>n;
        n--;
        cout<<total[n].bits<<" "<<total[n].nibbles<<" "<<total[n].bytes<<endl;
    }
    return 0;
}

