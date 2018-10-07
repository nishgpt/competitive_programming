#include<bits/stdc++.h>
using namespace std;
#define LL long long int
#define MOD 1000000007
#define MP make_pair
#define PB push_back
#define MS(a) memset(a, 0, sizeof a)
#define M 1000000
 
 
 
int main() {
	int t, i, j;
	scanf("%d", &t);
	int n;
	LL m;
	while(t--) {
		scanf("%d", &n);
		map<int, int> mp;
		for(i=0;i<n;i++) {
			scanf("%d", &j);
			mp[j]++;
		}
		scanf("%lld", &m);
		map<int, int> :: iterator it;
		LL cost = 0;
		while(m) {
			if(mp.size() >= 2) {
				it = mp.end();
				it--;
				int maf = it->first;
				int mas = it->second;
				it--;
				int saf = it->first;
				LL c = (1L)*(maf - saf)*mas;
				c = min(c, m);
				//cout<<c<<" "<<m<<endl;
				LL f = c/mas;
				LL rem = c%mas;
				LL st = maf - f + 1;
				LL end = maf;
				LL num = end - st + 1;
				cost = cost + mas*num*(st+end)/2;
				cost = cost + rem * (st-1);
				mp.erase(maf);
				if(st-2 > 0)mp[st-2] += rem;
				mp[st-1] += (mas - rem);
				m-=c;
			}
			else {
				it = mp.end();
				it--;
				int maf = it->first;
				int mas = it->second;
				LL c = m/mas;
				LL rem = m%mas;
				LL st = maf - c + 1;
				LL end = maf;
				LL num = end - st + 1;
				cost = cost + mas*num*(end+st)/2;
				cost = cost + rem*(st-1);
				m = 0;
			}
		}
		printf("%lld\n", cost);
	}
	return 0;
} 