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

void print_array(LL *a, LL n) {
	for(int i=0;i<n;i++) {
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int main() {
	LL t, n;
	cin>>t;
	
	while(t--) {
		scanf("%lld", &n);
		LL a[n], i, x;
		
		for(i=0;i<n;i++) {
			scanf("%lld", &x);
			if(x<0) x = -1*x;
			
			if(x%4 == 0) a[i] = 2; //this will include 0 as well
			else if(x%2 == 0) a[i] = 1;
			else a[i] = 0;
		}
		
		//print_array(a, n);
		
		LL prev_non_zero[n];
		LL prev = -1;
		for(i=0;i<n;i++) {
			prev_non_zero[i]  = prev; 
			if(a[i] != 0) {
				prev = i;
			}
		}
		
		//print_array(prev_non_zero, n);
		
		LL next_non_zero[n];
		LL next = n;
		for(i=n-1;i>=0;i--) {
			next_non_zero[i] = next;
			if(a[i] != 0) {
				next = i;
			}
		}
		
		//print_array(next_non_zero, n);
		LL non_ans = 0;
		for(i=0;i<n;i++) {
			if(a[i] == 1) {
				LL l = i - prev_non_zero[i] - 1;
				LL r = next_non_zero[i] - i - 1;
				non_ans = non_ans + (l*r) + l + r + 1;
			}
		}
		
		LL total = n*(n+1)/2;
		LL ans = total - non_ans;
		printf("%lld\n", ans);
	}
    return 0;
}

