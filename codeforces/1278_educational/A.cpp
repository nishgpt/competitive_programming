/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    int n, m;
    while(t--) {
        cin>>n>>m;
        char c;
        int a[n][m];
        int i, j;
        for(j=0;j<n;j++) {
            for(i=0;i<2*m;i++) {
                cin>>c;
                if(c == '/') a[j][i/2] = 1;
                else if(c == '\') a[j][i/2] = 2;
            }
        }
        
        for(i=0;i<n;i++) {
            for(j=0;j<m;j++) {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
