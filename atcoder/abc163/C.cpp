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
	int n, i, x;
	cin>>n;
	int a[n+1];
  memset(a, 0, sizeof a);
	for(i=1;i<n;i++) {
		cin>>x;
		a[x]++;
	}
	
  for(i=1;i<=n;i++) {
  	cout<<a[i]<<endl;
  }
    return 0;
}

