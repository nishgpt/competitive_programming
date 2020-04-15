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
	int t;
	string s;
	int a[9][9];
	cin>>t;
	while(t--) {
		int i;
		for(i=0;i<9;i++) {
			cin>>s;
			for(int j=0;j<9;j++) {
				a[i][j] = s[j]-'0';
			}
		}
		
		a[0][0] = a[0][1];
		a[4][1] = a[4][0];
		a[8][2] = a[8][1];
		a[1][3] = a[1][4];
		a[5][4] = a[5][3];
		a[6][5] = a[6][4];
		a[2][6] = a[2][7];
		a[3][7] = a[3][8];
		a[7][8] = a[7][7];
		
		for(i=0;i<9;i++) {
			for(int j=0;j<9;j++) {
				cout<<a[i][j];
			}
			cout<<endl;
		}
	}
    return 0;
}

