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
    int a, b, x, i;
    cin>>a>>b>>x;

    int st = a > b ? 0 : 1;
    int alt = (x+1)>>1;

    string s = ""; 
    for(i=0;i<alt;i++) {
        if(st) s = s + "10";
        else s = s + "01";
    }
    
    a = a - alt;
    b = b - alt;
    
    if(!(x&1)) {
        if(st) {
            b--;
        }
        else a--;
    }

    if(st) {
        while(b--) {
            cout<<"1";
        }
        cout<<s;
        while(a--) {
            cout<<"0";
        }
        if(!(x&1))cout<<"1";
    }

    else {
        while(a--) {
            cout<<0;
        }
        cout<<s;
        while(b--) {
            cout<<"1";
        }
        if(!(x&1))cout<<"0";
    }
    cout<<endl;
    return 0;
}

