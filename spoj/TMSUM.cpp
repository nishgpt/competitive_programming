#include<bits/stdc++.h>
using namespace std;
#define LL long long int
 
int check(int cp, int cn, int z) {
	if(cp && cn && z) {
		return 1;
	}
	if(cp && cn) return 0;
	if(cp)return 1;
	if(cn && z) return 0;
	if(cn) return -1;
	else return 0; 
}
int main() {
	LL i, j, k, n, m;
	int t;
	cin>>t;
	while(t--) {
		cin>>n;
		int cp = 0;int cn = 0;int z = 0;
		LL a[1005];
		for(i=0;i<n;i++) {
			cin>>a[i];
			if(a[i] == 0) z++;
			if(a[i] == 1) cp++;
		}
		sort(a, a+n);
		LL sum = 0;
		for(i=n-1;i>=0;) {
			if(a[i] <= 1) break;
			if(i-1>=0 && a[i-1] > 1) {
				sum += a[i]*a[i-1];
				i-=2;
			}
			else break;
		}
		if(i>=0 && a[i] > 1) sum += a[i];
		for(i=0;i<n;) {
			if(a[i] >= 0) break;
			if(i+1 < n && a[i+1] < 0) {
				sum += a[i]*a[i+1];
				i+=2;
			}
			else break;
		}
		if(i<n && a[i] < 0) {
			if(!z)
				sum += a[i];
			else z--;
		}
		sum += check(cp, cn, z);
		cout<<sum<<endl;
	}
	return 0;
} 