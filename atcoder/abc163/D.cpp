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

LL sum(LL num) {
	if(num < 0) return 0;
	return (num * (num + 1)) / 2; 
}

int main() {
	LL n, k;
	cin>>n>>k;
	
	LL possible = 0;
	for(LL i=k;i<=n+1;i++) {
		LL mini = sum(i-1);
		LL maxi = sum(n) - sum(n-i);
		
		possible = ((maxi - mini + 1) + possible) % MOD;
		//cout<<possible<<endl;
	}
	
	cout<<possible<<endl;
    return 0;
}

