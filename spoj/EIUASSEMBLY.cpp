#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define INF 1000000000000000000

bool fun(LL target, LL budget, vector<pair<LL, LL> > v) {
	int i, j;
	for(i=0;i<v.size();i++) {
		if(budget < 0) {
			return false;
		}
		if(v[i].first < target) {
			budget = budget - (target-v[i].first)*v[i].second;
		}
	}
	if(budget < 0)return false;
	return true;
}

int main() {
	int t, i, j;
	LL n, m, x, y;
	scanf("%d", &t);
	while(t--) {
		scanf("%lld %lld", &n, &m);
		vector<pair<LL, LL> > v;
		for(i=0;i<n;i++) {
			scanf("%lld %lld", &x, &y);
			v.push_back(make_pair(x, y));
		}
		//sort(v.begin(), v.end());
		
		//binary search
		LL l = 0, h = INF, ans = -1;
		while(l <= h) {
			LL mid = (l+h)>>1;
			if(fun(mid, m, v)) {
				ans = mid;
				l = mid + 1;
			}	
			else h = mid - 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}