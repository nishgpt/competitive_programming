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
	int t, n;
	scanf("%d", &t);
	
	while(t--) {
		scanf("%d", &n);
		if(n == 1) {
			cout<<1<<endl<<"1 1"<<endl;
			continue;
		}
		
		int ans = n>>1;
		cout<<ans<<endl;
		int i;
		if(n & 1) {
			printf("3 1 2 %d\n", n);
			//cout<<"3 1 2 "<<n<<endl;
		} else {
			printf("2 1 2\n");
		}
		for(i=2;i<=ans;i++) {
			printf("2 %d %d\n", 2*i-1, 2*i);
			//cout<<"2 "<<2*i-1<<" "<<2*i<<endl;
		}
	}
    return 0;
}

