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
#define MAX 8005
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL (LL(1e18))
#define chk(a) cerr << endl << #a << " : " << a << endl
#define chk2(a,b) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << endl
#define chk3(a,b,c) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << endl
#define chk4(a,b,c,d) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << "\t" << #d << " : " << d << endl
#define rep(i, a, n) for(i=a;i<n;i++)
#define rev(i, a, n) for(i=a;i>=n;i--)
#define MSV(A,a) memset(A, a, sizeof(A))
#define rep_itr(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)

using namespace std;

pair<bool, int> bin_search(int *v, int key, int s, int e) {
	int low =s, high = e;
	while(low<=high) {
		int mid = (low+ high)>>1;
		if(v[mid] == key) return MP(true, mid);
		
		if(v[mid] < key) low = mid + 1;
		else high = mid - 1;
	}
	return MP(false, -1);
}

int main() {
	int n, t, i, j;
	cin>>t;
	
	while(t--) {
		cin>>n;
		vector<int> a(n);
		int sum[n]; 
		for(i=0;i<n;i++) {
			cin>>a[i];
			sum[i] = a[i];
			if(i>0) sum[i]+=sum[i-1];
		}
		
		int ans = 0;
		for(i=0;i<n;i++) {
			int num = a[i];
			
			for(j=1;j<n;j++) {
				if(sum[j] == num) {
					ans++;
					break;
				}
				
				pair<bool, int> pi = bin_search(sum, sum[j]-num, 0, j-1);
				if(pi.X && (j-pi.Y) >=2) {
					ans++;
					break;
				} 
			}
		}
		cout<<ans<<endl;
		
	}

    return 0;
}

