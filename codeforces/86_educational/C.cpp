//WRONG ANSWER
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

LL lcm(LL x, LL y) {
	return (x*y) / __gcd(x, y);
}
int main() {
	int t;
	LL a, b, q;
	LL l, r;
	cin>>t;
	while(t--) {
		cin>>a>>b>>q;
		
		LL maxi = max(a, b);
		LL mini = min(a, b);
		while(q--) {
			cin>>l>>r;
			
			//if(r < maxi) {cout<<0<<" ";continue;}
			
			LL mul = lcm(mini, maxi);;
			LL qmul = l / mul;
			if(l%mul !=0) qmul++;
			
			LL rmul = (r / mul);
			LL end = rmul * mul;
			
			LL ans = (rmul-qmul) * maxi;
			
			ans = ans + min(maxi, (r-end+1));
			cout<<(r-max(l, maxi) +1) - ans<<" ";
			
		}
		cout<<endl;
	}
		
    return 0;
}

