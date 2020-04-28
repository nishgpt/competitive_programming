/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define getcx getchar_unlocked
#define X first
#define Y second
#define PB push_back
#define MP make_pair
#define MAX 100005
#define MOD 1000000007

using namespace std;

int main() {
	LL t, a, b, x, y;
	
	cin>>t;
	while(t--) {
		cin>>x>>y;
		cin>>a>>b;
		
		LL diff = abs(x-y);
		LL mini = min(x, y);
		cout<<(a*diff) + min(b*mini, 2*a*mini)<<endl;
	}
		
    return 0;
}

