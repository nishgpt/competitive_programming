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
	int t, n, a,  b, c, d;
	cin>>t;
	while(t--) {
		cin>>n>>a>>b>>c>>d;
		int mini_g = a-b;
		int maxi_g = a+b;
		int mini_w = c-d;
		int maxi_w = c+d;
		
		bool flag = false;
		for(int i=mini_w;i<=maxi_w;i++) {
			int each = i/n;
			int rem = i%n;
			if(rem == 0) {
				if(each >= mini_g && each <= maxi_g) flag = true;
			} else {
				if(each>=mini_g && each < maxi_g) flag = true;
			}
		}

		if(flag) {
			cout<<"Yes"<<endl;
		}
		else cout<<"No"<<endl;
	}
    return 0;
}

