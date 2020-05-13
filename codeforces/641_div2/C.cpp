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
#define MAX 200005
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL (LL(1e18))
#define rep(i, a, n) for(i=a;i<n;i++)
#define rev(i, a, n) for(i=a;i>=n;i--)
#define MSV(A,a) memset(A, a, sizeof(A))
#define rep_itr(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)

using namespace std;

vector<pair<int, int> > factorise(int number) {
	int num = number;
	vector<pair<int, int> > v;
	for(int j=2;j*j<=number;j++) {
		int cnt = 0;
		while(num%j==0) {
			cnt++;
			num/=j;
		}
		v.PB(MP(j, cnt));
	}
	if(num > 1) v.PB(MP(num, 1));
	return v;
}

int main() {
	int n, i, j;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++) {
		scanf("%d", &a[i]);
	}
	
	LL ans = 1;
	int p[MAX][2];
	int c[MAX];
	for(i=1;i<MAX;i++) {
		p[i][0] = 100;
		p[i][1] = 100;
		c[i] = 0;
	}
	
	for(i=0;i<n;i++) {
		vector<pair<int, int> > v = factorise(a[i]);
		for(j=0;j<v.size();j++) {
			int b = v[j].X;
			int e = v[j].Y;
			c[b]++;
			if(p[b][0] >= e) {
				p[b][1] = p[b][0];
				p[b][0] = e;
			} else if(p[b][1] >= e) {
				p[b][1] = e;
			}
		}
	}
	
	for(i=2;i<MAX;i++) {
		if(c[i] < n-1) continue;
		
		int power = -1;
		if(p[i][1] == 100 && p[i][0] != 100) power = p[i][0];
		else power = p[i][1];
		
		if(power != -1) {
			ans = ans * pow(i, power);
		}
	}
	
	printf("%lld\n", ans);
    return 0;
}

