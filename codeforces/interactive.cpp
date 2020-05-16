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
#define INF 0x3f3f3f3f
#define INFL (LL(1e18))
#define rep(i, a, n) for(i=a;i<n;i++)
#define rev(i, a, n) for(i=a;i>=n;i--)
#define MSV(A,a) memset(A, a, sizeof(A))
#define rep_itr(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)

using namespace std;

int main() {
	int low=1, high=1000000;
	int ans;
	string s;
	while(low <= high) {
		int mid = (low + high) >> 1;
		cout<<mid<<endl;
		cin>>s;
		
		if(s[0] == '>') {
			ans = mid;
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	
	cout<<"! "<< ans<<endl;

    return 0;
}

