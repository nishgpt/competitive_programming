/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define MP make_pair
#define MAX 2000005
#define MOD 1000000007

using namespace std;
void print(pair<int, int> p) {
    cout<<p.first<<" "<<p.second<<endl;
}

int main() {
    int t, n, a, b;
    
    cin>>t;
    while(t--) {
        cin>>n>>a>>b;
        
        bool found[MAX] = {false};

        int shift = b * n;
        queue<pair<int, int> > q;
        q.push(MP(a, n - 1));
        q.push(MP(-1 * b, n - 1));
        found[a + shift] = true;
        found[-1*b + shift] = true;
        
        int count = 2;
        while(!q.empty()) {
            pair<int, int> _front = q.front();
            q.pop();
            if(_front.second == 0) {
                continue;
            }
            
            int sum1 = _front.first + a;
            int sum2 = _front.first - b;
            
            if(found[sum1 + shift] == false) {
                q.push(MP(sum1, _front.second-1));
                found[sum1 + shift] = true;
                count++;
            }
            
            if(found[sum2 + shift] == false) {
                q.push(MP(sum2, _front.second-1));
                found[sum2 + shift] = true;
                count++;
            }
        }
        
        cout<<count+(!found[shift])<<endl;
    }
    return 0;
}
