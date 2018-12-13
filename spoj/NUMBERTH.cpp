/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 10000005
#define MOD 1000000007

using namespace std;

bool np[MAX];
void pre() {
    int i, j;
    np[0] = np[1] = true;
    for(i=2;i*i<MAX;i++) {
        if(!np[i]) {
            for(j=i*i;j<MAX;j+=i) {
                np[j] = true;
            }
        }
    }
}

vector<int> get_digits(string s) {
    int i, l = s.length();
    vector<int> digits;
    for(i=0;i<l;i++) {
        digits.pb((s[i] - '0'));
    }

    return digits;
}

int get_number(vector<int> v) {
    int i, number = 0;
    for(i=0;i<v.size();i++) {
        number = number * 10 + v[i];
    }

    return number;
}

int main() {
    int n, i, j;
    string s;

    pre();
    cin>>n;
    while(n--) {
        cin>>s;
        vector<int> digits = get_digits(s);
        int l = digits.size();

        set<int> st;

        //Generate all subsets of digits, permute them and check if the number formed is prime
        for(i=0;i<(1<<l);i++) {
            vector<int> temp;
            for(j=0;j<l;j++) {
                if((1<<j) & i) {
                    temp.pb(digits[j]);
                }
            }

            sort(temp.begin(), temp.end());
            do {
                int num = get_number(temp);
                if(!np[num]) {
                    st.insert(num);
                }
            } while(next_permutation(temp.begin(), temp.end()));
        }

        cout<<st.size()<<endl;
    }
    return 0;
}

