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
#define MAX 1000005
#define LIM 500005
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL (LL(1e18))
#define rep(i, a, n) for(i=a;i<n;i++)
#define rev(i, a, n) for(i=a;i>=n;i--)
#define MSV(A,a) memset(A, a, sizeof(A))
#define rep_itr(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)

using namespace std;

LL sum[MAX];
int main() {
	LL a, b, c, d;
	cin>>a>>b>>c>>d;
	LL i;
	
	for(i=a;i<=b;i++) {
		LL mini = i+b;
		LL maxi = i+c;
		sum[mini] += 1;
		sum[maxi+1] -= 1;
	}
	
	for(i=1;i<MAX;i++) {
		sum[i] += sum[i-1];
	}
	for(i=1;i<MAX;i++) {
		sum[i] += sum[i-1];
	}
	
	//~for(i=1;i<10;i++)cout<<sum[i]<<" ";
	//~cout<<endl;
	
	LL ans = 0;
	LL last = c+b;
	for(i=c;i<=d;i++) {
		ans += (sum[last] - sum[i]);
	}
	
	cout<<ans<<endl;

    return 0;
}

