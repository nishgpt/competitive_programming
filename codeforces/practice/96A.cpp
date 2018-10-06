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
    string s;
    int i, team1=0, team2=0;
    cin>>s;

    for(i=0;i<s.length();i++) {
        if(s[i] == '0') {
            team2 = 0;
            team1++;
        } else {
            team1 = 0;
            team2++;
        }
        if(team1>=7 || team2>=7) {
            cout<<"YES"<<endl;
            return 0;
        }
    }

    cout<<"NO"<<endl;
    return 0;
}

