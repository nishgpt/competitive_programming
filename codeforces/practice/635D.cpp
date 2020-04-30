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
#define INFL 1e18
#define rep(i, a, n) for(i=a;i<n;i++)
#define rev(i, a, n) for(i=a;i>=n;i--)
#define MSV(A,a) memset(A, a, sizeof(A))
#define rep_itr(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)

using namespace std;

LL get_value(LL x, LL y, LL z) {
	if(x == -1 || y == -1 || z == -1) return 5*INFL;
	return (x-y)*(x-y) + (y-z)*(y-z) + (z-x)*(z-x);
}

void fill_array(set<int> s, int *arr) {
	set<int> :: iterator it;
	int i = 0;
	for(it = s.begin();it!=s.end();it++, i++) {
		arr[i] = *it;
	}
}

bool is_possible(int *r, int nr, int *g, int ng, int *b, int nb, LL mid) {
	int i;
	for(i=0;i<nr;i++) {
		int posg = lower_bound(g, g+ng, r[i]) - g;
		int posb = lower_bound(b, b+nb, r[i]) - b;
		if(posg == ng) posg--;
		if(posb == nb) posb--;
		
		LL v1 = get_value(r[i], posg < ng ? g[posg] : -1, posb < nb ? b[posb] : -1);
		LL v2 = get_value(r[i], posg < ng ? g[posg] : -1, posb + 1 < nb ? b[posb+1] : -1);
		LL v3 = get_value(r[i], posg < ng ? g[posg] : -1, posb - 1 >= 0 ? b[posb-1] : -1);
		
		LL v4 = get_value(r[i], posg - 1 >= 0 ? g[posg-1] : -1, posb - 1 >= 0 ? b[posb-1] : -1);
		LL v5 = get_value(r[i], posg - 1 >= 0 ? g[posg-1] : -1, posb < nb ? b[posb] : -1);
		LL v6 = get_value(r[i], posg - 1 >= 0 ? g[posg-1] : -1, posb + 1 < nb ? b[posb+1] : -1);
		
		LL v7 = get_value(r[i], posg + 1 < ng ? g[posg+1] : -1, posb - 1 >= 0 ? b[posb-1] : -1);
		LL v8 = get_value(r[i], posg + 1 < ng ? g[posg+1] : -1, posb < nb ? b[posb] : -1);
		LL v9 = get_value(r[i], posg + 1 < ng ? g[posg+1] : -1, posb + 1 < nb ? b[posb+1] : -1);

		LL vv1 = min(v1, min(v2, v3));
		LL vv2 = min(min(vv1, v4), min(v5, v6));
		LL vv3 = min(min(vv2, v7), min(v8, v9));
		
		if(vv3 <= mid) {
			return true;
		}
	}
	return false;
		
} 
LL solve() {
	LL nr, ng, nb;
	cin>>nr>>ng>>nb;
		
	int i, x;
	set<int> s;
	for(i=0;i<nr;i++) {
		scanf("%d", &x);
		s.insert(x);
	}
	nr = s.size();
	int r[nr];
	fill_array(s, r);
	
	s.clear();
	for(i=0;i<ng;i++) {
		scanf("%d", &x);
		s.insert(x);
	}
	ng = s.size();
	int g[ng];
	fill_array(s, g); 
	
	s.clear();
	for(i=0;i<nb;i++) {
		scanf("%d", &x);
		s.insert(x);
	}
	nb = s.size();
	int b[nb];
	fill_array(s, b);

	sort(r, r+nr);
	sort(g, g+ng);
	sort(b, b+nb);
	
	
	LL low = 0, high = INFL * 3;
	LL ans;
	while(low <= high) {
		LL mid = (low + high)>>1;
		
		bool flag = is_possible(r, nr, g, ng, b, nb, mid);
		flag = flag || is_possible(g, ng, b, nb, r, nr, mid);
		flag = flag || is_possible(b, nb, r, nr, g, ng, mid);
		
		if(flag) {
			ans = mid;
			high = mid -1;
		} else {
			low = mid + 1;
		}
	}
	
	return ans;
}

int main() {
	int t;
	
	cin>>t;
	while(t--) {
		cout<<solve()<<endl;
	}

    return 0;
}

