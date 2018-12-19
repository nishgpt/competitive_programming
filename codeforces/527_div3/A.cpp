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
    int t, n, k;

    cin>>t;
    while(t--) {
        cin>>n>>k;

        int q = n/k;
        int qq = q;
        int c = 0;
        for(int i=0;i<n;i++) {
            if(qq == 0) {
                qq = q;
                c++;
                if(c==k)c--;
            }
            cout<<(char)(c+'a');
            qq--;
        }
        cout<<endl;
    }
    return 0;
}

