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
    int a, b, c, d;
    cin>>a>>b>>c>>d;

    int misha = max(3*a/10, a - (a/250)*c);
    int vasya = max(3*b/10, b - (b/250)*d);

    if(misha > vasya) cout<<"Misha"<<endl;
    else if(misha < vasya) cout<<"Vasya"<<endl;
    else cout<<"Tie"<<endl;

    return 0;
}

