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
	cin>>t;
	int n;
	while(t--) {
		cin>>n;
		if(n&1) {
			cout<<n/2<<endl;
		}
		else {
			cout<<(n/2)-1<<endl;
		}
	}
    return 0;
}

