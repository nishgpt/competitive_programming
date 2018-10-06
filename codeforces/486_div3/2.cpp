#include<bits/stdc++.h>
#define MAX 105
using namespace std;
bool compare(string &s1,string &s2) {
    return s1.size() < s2.size();
}

int n;
int main() {
    vector<string> s;
    string x;
    cin>>n;
    int i, j;
    for(i=0;i<n;i++) {
        cin>>x;
        s.push_back(x);
    }
    
    sort(s.begin(), s.end(), compare);
    
    int f = 0;
    for(i=0;i<n-1;i++) {
        for(j=i+1;j<n;j++) {
            if(s[j].find(s[i]) == string::npos) {
                f++;
                break;
            }
        }
        if(f) break;
    }

    if(f) {
        cout<<"NO\n";
    }
    else {
        cout<<"YES"<<endl;
        for(i=0;i<n;i++) {
            cout<<s[i]<<endl;
        }
    }

    return 0;
}
