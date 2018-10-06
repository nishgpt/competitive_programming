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

int a, b, c;

void update(int x) {
    if(x == 25) a++;
    if(x == 50) b++;
    if(x == 100) c++;
}

bool check_and_update(int change, int x) {
    switch(change) {
        case 0: 
            update(x);
            return true;

        case 25:
            if(a) {
                a--;
                update(x);
                return true;
            }
            return false;

        case 50:
            if(b) {
                b--;update(x);return true;
            }
            else if(a >= 2) {
                a-=2;update(x);return true;
            }
            return false;

        case 75:
            if(b && a) {
                a--;b--;update(x);return true;
            }
            else if(a>=3) {
                a-=3;update(x);return true;
            }
            return false;

        default:
            return false;
    }
}

int main() {
    int n, x;
    cin>>n;
    
    for(int i=0;i<n;i++) {
        cin>>x;

        int change = x - 25;
        if(!check_and_update(change, x)) {
            cout<<"NO"<<endl;
            return 0;
        }
    }

    cout<<"YES"<<endl;
    return 0;
}

