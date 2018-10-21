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

int main() {
    int t, n;

    cin>>t;

    map<char, int> hands; //1 for left, 2 for right
    hands['d'] = 1;
    hands['f'] = 1;
    hands['k'] = 2;
    hands['j'] = 2;

    while(t--) {
        cin>>n;
        
        map<string, int> stime;
        string s;
        int time = 0;
        
        for(int i=0;i<n;i++) {
            cin>>s;
            
            if(stime[s] != 0) {
                time += stime[s]>>1;
                continue;
            }

            int t = 0;
            for(int j=0;j<s.length();j++) {
                if(j==0) {
                    t+=2;
                }
                else {
                    if(hands[s[j-1]] != hands[s[j]]) {
                        t+=2;
                    } else {
                        t+=4;
                    }
                }
            }
            time += t;
            stime[s] = t;
        }

        cout<<time<<endl;
    }
    return 0;
}

