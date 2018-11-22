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

int main() {
    int t, n, x, tc = 1;
    cin>>t;

    while(t--) {
        cin>>n;
        
        int c[n+1];
        bool has_come[n+1];
        memset(c, 0, sizeof c);
        memset(has_come, false, sizeof has_come);
        stack<int> st;
        for(int i=0;i<2*n;i++) {
            cin>>x;
            if(!has_come[x]) {
                has_come[x] = true;
                
                //add one child to stack's top node
                if(!st.empty()) {
                    c[st.top()]++;
                }

                //push new node in stack
                st.push(x);
            }
            else {
                st.pop();    
            }
        }

        printf("Case %d:\n", tc++);
        for(int i=1;i<=n;i++) {
            cout<<i<<" -> "<<c[i]<<endl;
        }
        cout<<endl;
    }
    return 0;
}

