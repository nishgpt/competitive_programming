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
	int n, m, x, sum = 0;
	cin>>n>>m;
	
	for(int i=0;i<m;i++) {
		cin>>x;
		sum += x;
	}
	
	n = n - sum;
	if(n<0) n = -1;
	cout<<n<<endl;
    return 0;
}

