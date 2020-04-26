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
	int n, m;
	cin>>n>>m;
	
	int i, j;
	int a[n], b[m];
	for(i=0;i<n;i++) {
		cin>>a[i];
	}
	
	for(i=0;i<m;i++) {
		cin>>b[i];
	}
	
	sort(a, a+n, greater<int>());
	sort(b, b+m, greater<int>());
	if(a[0] > b[0]) {
		cout<<-1<<endl;
		return 0;
	}
	
	int low = 1;
	int high = 1e6;
	int ans = -1;
	
	while(low <= high) {
		int mid = (low + high) >> 1; //every plane will make atmost 'mid' number of trips
		
		int flag = true;
		j = 0;
		int trips = mid;
		for(i=0;i<n && j<m;i++) {
			if(a[i] > b[j]) {
				flag = false;
				break;
			}
			trips--;
			if(trips == 0) {
				j++;
				trips = mid;
			}
		}
		
		if(i < n) {
			flag = false;
		}
		
		if(flag) {
			ans  = mid;
			//cout<<ans<<endl;
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	
	cout<<2 * ans - 1<<endl;
    return 0;
}

