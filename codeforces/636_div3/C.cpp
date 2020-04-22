/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 100005
#define MOD 1000000007
#define INF (1e9 + 5)

using namespace std;

int main() {
	int t, n;
	cin>>t;
	while(t--) {
		cin>>n;
		LL a[n];
		int i;
		for(i=0;i<n;i++) {
			cin>>a[i];
		}
		
		int pos = -1;
		LL pos_sum = -INF;
		int neg = -1;
		LL neg_sum = -INF;
		for(i=0;i<n;i++) {
			if(a[i] < 0) {
				if(pos == -1) {
					neg = 1;
					neg_sum =max(neg_sum,  a[i]);
				} else {
					if(pos + 1 > neg) {
						neg = pos+1;
						neg_sum = pos_sum + a[i];
					} else if(pos+1 == neg && pos_sum+a[i] > neg_sum) {
						neg_sum = pos_sum + a[i];
					}
				}
			}
			
			else {
				if(neg == -1) {
					pos = 1;
					pos_sum = max(a[i], pos_sum);
				} else {
					if(neg + 1 > pos) {
						pos = neg + 1;
						pos_sum = neg_sum + a[i];
					} else if(neg + 1 == pos && neg_sum+a[i] > pos_sum) {
						pos_sum = neg_sum + a[i];
					}
				}
			}
		}
		
		if(pos > neg) {
			cout<<pos_sum<<endl;
		} else if(neg > pos) {
			cout<<neg_sum<<endl;
		} else {
			cout<<max(neg_sum, pos_sum)<<endl;
		}
	}
    return 0;
}

