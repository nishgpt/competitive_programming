#include<bits/stdc++.h>
#define MAX 100005
using namespace std;

int main() {
    int k;
    vector<pair<int, pair<int, int> > > sums;
    //vector<int> a;

    int i, j, n, x;
    cin>>k;
    for(i=0;i<k;i++) {
        cin>>n;
        vector<int> a;
        int sum = 0;
        for(j=0;j<n;j++) {
            cin>>x;
            a.push_back(x);
            sum+=x;
        }

        map<int, int> mp;
        for(j=0;j<a.size();j++) {
            if(!mp[sum-a[j]]) {
                sums.push_back(make_pair(sum-a[j], make_pair(j+1, i+1)));
                mp[sum-a[j]]=1;
            }
        }
    }

    sort(sums.begin(), sums.end());

    for(i=1;i<sums.size();i++) {
        if(sums[i].first == sums[i-1].first) {
            cout<<"YES"<<endl;
            //cout<<sums[i].first<<endl;
            cout<<sums[i].second.second<< " "<< sums[i].second.first<<endl;
            cout<<sums[i-1].second.second<< " "<<sums[i-1].second.first<<endl;
            return 0;
        }
    }

    cout<<"NO"<<endl;
    return 0;
}
