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
    int h1, m1, h2, m2, m, d;
    cin>>h1>>m1;
    cin>>h2>>m2;
    cin>>m>>d;
    
    int min1 = h1*60 + m1;
    int min2 = h2*60 + m2;
    min1 += (d+m);
    
    if(min1<=min2) {
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }
    return 0;
}

