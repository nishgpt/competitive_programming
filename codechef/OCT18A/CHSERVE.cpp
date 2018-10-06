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
    int t, k, p1, p2;
    cin>>t;

    while(t--) {
        cin>>p1>>p2>>k;

        if(((p1 + p2) / k) & 1) {
            cout<<"COOK"<<endl;
        } 
        else cout<<"CHEF"<<endl; 
    }
    return 0;
}

