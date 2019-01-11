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

int sum_of_digits(string s) {
    while(s.length() != 1) {
        string temp = "";
        int sum = 0;
        for(int i=0;i<s.length();i++) {
            sum += (s[i]-'0');
        }

        while(sum) {
            int r = sum % 10;
            temp = (char)(r+'0') + temp;
            sum/=10;
        }

        s = temp;
    }

    return s[0] - '0';
}

int modulo(string s, int m) {
    int r = 0, i;
    for(i=0;i<s.length();i++) {
        int t = r*10 + (s[i]-'0');
        r = t % m;
    }

    return r;
}

int main() {
    string a, b;

    cin>>a;
    cin>>b;
    
    int x = sum_of_digits(a);
    int y = modulo(b, 6);
    int ans;
    if(x == 9) {
        ans = 9;
    }
    else if((b.length() > 1 || b[0] != '1') && (x==3 || x==6)) {
        ans = 9;
    }
    else {
        int xpy = pow(x, y);
        string t = "";
        while(xpy) {
            int r = xpy%10;
            t = (char)(r+'0') + t;
            xpy/=10;
        }
        ans = sum_of_digits(t);
    }

    cout<<ans<<endl;
    return 0;
}

