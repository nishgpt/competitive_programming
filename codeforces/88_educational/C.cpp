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
#define MAX 1e17
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

int main() {
	
	int t;
	cin>>t;
	int c, h, x;
	while(t--) {
		cin>>h>>c>>x;
		if(x == h) cout<<1<<endl;
		else if(x <= ((h+c)>>1)) cout<<2<<endl;
		else {	
			LL ans;
			double abst;
			if(abs(x-h) <= abs(c-x)) {
				ans = 1;
				abst = abs(x-h);
			} else {
				ans = 2;
				abst = abs(c-x);
			}
			
			LL diff = 2;
			LL ansg = 1, ansl = -1;
			double prev = -1.0;
			for(LL i=1;i<MAX;) {
				double temp = ((i/2) * c * 1.0+ (i-i/2)*h * 1.0) / (i * 1.0);
				if(temp > x && temp != prev) {
					ansg = i;
					prev = temp;
				} else if(temp <= x) {
					ansl = i;
					break;
				}
				i+=diff;
				diff<<=1;
			}
			
			LL low = ansg, high = ansl;
			while(low < high) {
				//~chk2(low, high);
				LL mid = (ansg+ansl)>>1;
				LL m = mid;
				if(mid%2==0) m+=1;
				
				double temp = ((m/2) * c * 1.0+ (m-m/2)*h * 1.0) / (m * 1.0);
				if(temp < x) {
					ansl = m;
					high = m-2;
				} else {
					ansg = m;
					low = m + 2;
				}
			}
			
			double minix = abs((((ansg/2) * c * 1.0+ (ansg-ansg/2)*h * 1.0) / (ansg * 1.0)) - x);
			LL aans = ansg;
			for(LL i=ansg;i<=ansl;i+=2) {
				double temp = ((i/2) * c * 1.0+ (i-i/2)*h * 1.0) / (i * 1.0);
				if(minix > abs(temp-x)) {
					aans = i;
					minix = abs(temp-x);
				}
			}
			
			if(abst <= minix) {
				cout<<ans<<endl;
			} else cout<<aans<<endl;
			
		}
		
	}

    return 0;
}

