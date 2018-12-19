/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define MP make_pair
#define MAX 105
#define MOD 1000000007

using namespace std;

bool prefix[MAX];
vector<string> v[MAX];
int n;
map<string, int> mpp;
map<string, int> mps;

int p_or_s(string sx, string p) {
    string pre = sx.substr(0, p.length());

    if(pre.compare(p) == 0) return 1;

    string suf = sx.substr(sx.length() - p.length());
    
    if(suf.compare(p) == 0) return 2;

    return -1;
}

bool check(string sx) {
    int i, j;
    for(i=1;i<=n-1;i++) {
        int what1 = p_or_s(sx, v[i][0]);

        if(what1 == -1) {
            return false;
        }
        if(what1 == 1) {
            string suf = sx.substr(sx.length() - v[i][1].length());
            mpp[v[i][0]] = 1;
            if(suf.compare(v[i][1]) != 0) return false;
            mps[v[i][1]] = 2;
        }
        if(what1 == 2) {
            string pre = sx.substr(0, v[i][1].length());
            mps[v[i][0]] = 2;
            if(pre.compare(v[i][1]) != 0) return false;
            mpp[v[i][1]] = 1;
        }
    }
    return true;
}

void print_ans(vector<string> actual) {
    for(int i=0;i<actual.size();i++) {
        if(mpp[actual[i]] != 0) {
            cout<<"P";
            mpp.erase(actual[i]);
        }
        else if(mps[actual[i]] != 0) {
            cout<<"S";
            mps.erase(actual[i]);
        }
    }
    cout<<endl;
}

int main() {
    int i, j;
    cin>>n;

    string x;
    int l = 2*n-2;
    vector<string> actual;

    for(i=0;i<l;i++) {
        cin>>x;
        int xl = x.length();
        actual.pb(x);
        v[xl].pb(x);
    }
        
    string sx = v[n-1][0] + v[1][0];
    mpp[v[n-1][0]] = 1;
    mps[v[1][0]] = 2;
    if(n>2 && check(sx)) {
        print_ans(actual);
        return 0;
    }

    mpp.clear();
    mps.clear();
    string sx1 = v[n-1][0] + v[1][1];
    mpp[v[n-1][0]] = 1;
    mps[v[1][1]] = 2;
    if(check(sx1)) {
        print_ans(actual);
        return 0;
    }

    mpp.clear();
    mps.clear();
    string sx2 = v[n-1][1] + v[1][0];
    mpp[v[n-1][1]] = 1;
    mps[v[1][0]] = 2;
    if(check(sx2)) {
        print_ans(actual);
        return 0;
    }

    mpp.clear();
    mps.clear();
    string sx3 = v[n-1][1] + v[1][1];
    mpp[v[n-1][1]] = 1;
    mps[v[1][1]] = 2;
    if(n>2 && check(sx3)) {
        print_ans(actual);
        return 0;
    }

    mpp.clear();
    mps.clear();
    string sx4 = v[1][0] + v[n-1][0];
    mpp[v[1][0]] = 1;
    mps[v[n-1][0]] = 2;
    if(n>2 && check(sx4)) {
        print_ans(actual);
        return 0;
    }

    mpp.clear();
    mps.clear();
    string sx5 = v[1][0] + v[n-1][1];
    mpp[v[1][0]] = 1;
    mps[v[n-1][1]] = 2;
    if(check(sx5)) {
        print_ans(actual);
        return 0;
    }

    mpp.clear();
    mps.clear();
    string sx6 = v[1][1] + v[n-1][0];
    mpp[v[1][1]] = 1;
    mps[v[n-1][0]] = 2;
    if(check(sx6)) {
        print_ans(actual);
        return 0;
    }

    mpp.clear();
    mps.clear();
    string sx7 = v[1][1] + v[n-1][1];
    mpp[v[1][1]] = 1;
    mps[v[n-1][1]] = 2;
    if(n>2 && check(sx7)) {
        print_ans(actual);
        return 0;
    }

    return 0;
}

