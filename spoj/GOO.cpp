#include<bits/stdc++.h>
using namespace std;
#define LL long long int 
 
int main() {
	LL ncr[51][51] = {0};
	int i, j, k, t, n;
	for(i=0;i<51;i++) {
		ncr[i][i] = 1;
		ncr[i][0] = 1;
	}
 
	for(i=1;i<51;i++) {
		for(j=1;j<i;j++) {
			ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];
		}
	}
 
 
	cin>>t;
	while(t--) {
		cin>>n;
		LL x = pow(2, n-1);
		LL y = 0;
		for(i=1;i<n;i++) {
			y += (i*(ncr[n-1][i]));
		}
		cout<<x<<" "<<y+x<<endl;
	}
	return 0;
} 