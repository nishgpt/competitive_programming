/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int
#define getcx getchar_unlocked
#define X first
#define Y second
#define PB push_back
#define MP make_pair
#define MAX 100005
#define LOG_MAX 20
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL (LL(1e18))
#define chk(a) cerr << endl << #a << " : " << a << endl
#define chk2(a,b) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << endl
#define chk3(a,b,c) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << endl
#define chk4(a,b,c,d) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << "\t" << #d << " : " << d << endl
#define rep(i, a, n) for(i=a;i<n;i++)
#define rev(i, a, n) for(i=a;i>=n;i--)
#define in(x) scanf("%d", &x)
#define inl(x) scanf("%lld", &x)
#define in2(x, y) scanf("%d %d", &x, &y)
#define inl2(x, y) scanf("%lld %lld", &x, &y)
#define MSV(A,a) memset(A, a, sizeof(A))
#define rep_itr(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)
#define finish(x) {cout<<x<<'\n'; return;}
typedef pair<int, int> pi;
typedef pair<LL, LL> pl;
const char en = '\n';

long double get_area(LL x1, LL y1, LL x2, LL y2, LL x3, LL y3) { 
   long double x = 1.0 * (x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2));
   if(x < 0.0) x = -1.0 * x;
   return sqrt(x * 0.5); 
} 

bool inside_triangle(LL x1, LL y1, LL x2, LL y2, LL x3, LL y3, LL x, LL y) {    
   long double a = get_area(x1, y1, x2, y2, x3, y3);
   long double a1 = get_area(x, y, x2, y2, x3, y3); 
   long double a2 = get_area(x1, y1, x, y, x3, y3); 
   long double a3 = get_area(x1, y1, x2, y2, x, y); 
   cout.precision(17);
   cout<<a<<" "<<a1<<" "<<a2<<" "<<a3<<en;
   return (a == (a1+a2+a3)); 
}

LL is_inside(LL x1, LL y1, LL x2, LL y2, LL x, LL y) {
	LL d = ((x-x1) * (y2-y1)) - ((y-y1) * (x2-x1));
	return d;
}

void solve() {
	int n, q;
	in(n);
	vector<LL> a(n);
	for(int i=0;i<n;i++) inl(a[i]);
	
	in(q);
	while(q--) {
		LL x, y;
		inl2(x, y);
		int low = 0, high = n-1;
		int ans = n;
		while(low <= high) {
			int mid = (low+high) >> 1;
			LL d = is_inside(0, a[mid], a[mid], 0, x, y);
			if(d > 0) {
				ans = mid;
				high = mid - 1;
			} else if(d < 0) {
				low = mid + 1;
			}
			else {
				ans = -1;break;
			}
		}
		cout<<ans<<en;
	}
}

int main() {
	int t = 1;
	
	cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
