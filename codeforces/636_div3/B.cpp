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
	int t, i;
	int n;
	cin>>t;
	while(t--) {
		cin>>n;
		if((n/2) & 1) {
			cout<<"NO"<<endl;
			continue;
		} 
		
		cout<<"YES"<<endl;
		int half = n>>1;
		int even = 2;
		LL sum = 0;
		for(i=0;i<half;i++, even+=2) {
			cout<<even<<" ";
			sum = sum + even;
		}
		
		LL sum_odd = 0;
		int odd = 1;
		for(i=half;i<n-1;i++, odd+=2) {
			cout<<odd<<" ";
			sum_odd = sum_odd + odd;
		}
		
		cout<<sum-sum_odd<<endl;
	}
    return 0;
}

