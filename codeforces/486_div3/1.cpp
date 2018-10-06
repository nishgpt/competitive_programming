#include<bits/stdc++.h>

#define MAX 105
using namespace std;

int main() {
    int n, k, c;
    cin >> n >> k;

    int freq[MAX][2] = {0};
    for(int i=0;i<n;i++) {
        cin>>c;
        freq[c][0]++;
        freq[c][1] = i+1;
    }

    int dist = 0;
    vector<int> ans;
    for(int i=1;i<MAX;i++) {
        if(freq[i][0]) {
            dist++;
            ans.push_back(freq[i][1]);
        }
    }

    if(dist >= k) {
        cout<<"YES\n";
        for(int i=0;i<k;i++) {
            cout<<ans[i]<<" ";
        }
    } else {
        cout<<"NO\n";
    }
    return 0;
}
