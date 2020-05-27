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
#define chk(a) cerr << endl << #a << " : " << a << endl
#define chk2(a,b) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << endl
#define chk3(a,b,c) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << endl
#define chk4(a,b,c,d) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << "\t" << #d << " : " << d << endl
#define rep(i, a, n) for(i=a;i<n;i++)
#define rev(i, a, n) for(i=a;i>=n;i--)
#define MSV(A,a) memset(A, a, sizeof(A))
#define rep_itr(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)

using namespace std;

LL get_ap_sum(LL st, LL n) { //d=1
	if(n<=0) return 0;
	return n * (2 * st + n-1) / 2;
}

LL get_hugs(LL days, LL *a, int i, int j, LL n) {
	LL start = a[i] - days + 2;
	if(start >= 2) {
		LL rem = days - (a[i]-start+1);
		return get_ap_sum(start, a[i]-start+1) + get_ap_sum(1, rem);
	}
	LL jdays = min(days-1, a[j]);
	return get_ap_sum(1, jdays) + get_ap_sum(a[i]-(days-jdays)+1, days-jdays); 
}

int main() {
	LL n, x;
	scanf("%lld %lld", &n, &x);
	
	LL a[2*n];
	for(int i=0;i<n;i++) {
		scanf("%lld", &a[i]);
		a[n+i] = a[i];
	}
	
	LL sum = 0, maxi = -1, hugs = 0;
	for(int i=0, j=0;i<n;) {
		if(sum + a[j] >= x) {
			if(j == i) {
				maxi = max(maxi, get_ap_sum(a[j]-x+1, x));
			} 
			else {
				LL left_days = x - (sum-a[i]);
				if(left_days < 2) {
					sum-=a[i];hugs-=get_ap_sum(1, a[i]);
					i++;j--;
					sum-=a[j];hugs-=get_ap_sum(1, a[j]);
					continue;
				}
				maxi = max(maxi, hugs - get_ap_sum(1, a[i]) + get_hugs(left_days, a, i, j, n));
			} 
		}
		sum+=a[j];
		hugs+=get_ap_sum(1, a[j]);
		j++;
	}
	
	cout<<maxi<<endl;
	
    return 0;
}

