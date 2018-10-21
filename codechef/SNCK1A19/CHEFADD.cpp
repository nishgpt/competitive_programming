/*
    Author: Team - baddy_boyz
    Members: Nishant Gupta, Arpit Uppal
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 100005
#define MOD 1000000007

using namespace std;

LL dp[50][50][50][2];
vector<int> cbits;

int get_ones(int num) {
    int ones = 0;
    while(num) {
        ones += (num&1);
        num>>=1;
    }
    
    return ones;
}

LL func(int pos, int a_ones, int b_ones, int carry) {
    // cout<<"called "<<pos<<" "<<a_ones<<" "<<b_ones<<" "<<carry<<endl;
    if(a_ones < 0 || b_ones < 0) return 0;

    if(pos == cbits.size() - 1) {
        int temp = 0;
        if(carry) {
            if(a_ones == 0 && b_ones == 0) temp++;
        } else {
            if(a_ones + b_ones == 1) temp++;
        }
        return dp[pos][a_ones][b_ones][carry] = temp;
    }

    if(dp[pos][a_ones][b_ones][carry] != -1) return dp[pos][a_ones][b_ones][carry];

    LL ans = 0;
    if(carry) {
        if(cbits[pos] == 1) {
            ans = ans + func(pos+1, a_ones, b_ones, 0);
            ans = ans + func(pos+1, a_ones-1, b_ones-1, 1);
        }
        else {
            ans = ans + func(pos+1, a_ones-1, b_ones, 1);
            ans = ans + func(pos+1, a_ones, b_ones-1, 1);
        }
    }
    else {
        if(cbits[pos] ==1) {
            ans = ans + func(pos+1, a_ones-1, b_ones, 0);
            ans = ans + func(pos+1, a_ones, b_ones-1, 0);
        }
        else {
            ans = ans + func(pos+1, a_ones, b_ones, 0);
            ans = ans + func(pos+1, a_ones-1, b_ones-1, 1);
        }
    }
    return dp[pos][a_ones][b_ones][carry] = ans;
}

void convert_binary(int num) {
    while(num) {
        cbits.pb(num&1);
        num>>=1;
    }
}

int main() {
    int t, a, b, c;

    cin>>t;
    
    while(t--) {
        memset(dp, -1, sizeof dp);
        cbits.clear();

        cin>>a>>b>>c;
        
        convert_binary(c);
        cout<<func(0, get_ones(a), get_ones(b), 0)<<endl;
        // for(int i=0;i<cbits.size();i++) {
        //     for(int x = 0; x<=get_ones(a);x++) {
        //         for(int y = 0;y<=get_ones(b);y++) {
        //             cout<<"pos= "<<i<<" "<<x<< " " <<y<<" "<<dp[i][x][y][0]<<endl;
        //             cout<<"pos= "<<i<<" "<<x<<" "<<y<<" "<<dp[i][x][y][1]<<endl;
        //         }
        //     }
        // }
    }
    return 0;
}

