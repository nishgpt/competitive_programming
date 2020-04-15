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
	int t, x, k;
	
	cin>>t;
	while(t--) {
		cin>>x>>k;
		if(k > 30) {
			cout<<0<<endl;
			continue;
		}
		
		int num = x;
		int sum = 0;
		for(int i=2;i*i<=x;i++) {
			int cnt = 0;
			while(num%i == 0) {
				num/=i;
				cnt++;
			}
			sum += cnt;
		}
		
		if(num > 1) sum++;
		
		if(sum >= k) cout<<"1"<<endl;
		else cout<<"0"<<endl;
		
	}

    return 0;
}

