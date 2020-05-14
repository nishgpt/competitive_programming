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
#define rep(i, a, n) for(i=a;i<n;i++)
#define rev(i, a, n) for(i=a;i>=n;i--)
#define MSV(A,a) memset(A, a, sizeof(A))
#define rep_itr(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)

using namespace std;

struct seg {
	int s;
	int l;
	int r;
};

bool operator<(const seg &p1, const seg &p2) {
    if(p1.s == p2.s) {
		return p1.l > p2.l;
	} 
	return p1.s < p2.s;
} 

int main() {
	int t, n, i;
	cin>>t;
	while(t--) {
		cin>>n;
		int a[n+1];
		MSV(a, 0);
		priority_queue<seg> pq;
		pq.push((seg){n, 1, n});
		
		int op = 1;
		while(!pq.empty()) {
			seg f = pq.top();
			pq.pop();
			int pos;
			if(f.s % 2 == 0) {
				pos = (f.l + f.r - 1)/2;
			} 
			else pos = (f.l + f.r)/2;
			
			a[pos] = op++;
			
			
			if(pos-f.l > 0) pq.push((seg){pos-f.l, f.l, pos-1});
			if(f.r-pos > 0) pq.push((seg){f.r-pos, pos+1, f.r});
		}
		for(i=1;i<=n;i++)cout<<a[i]<<" ";
		cout<<endl;
	}

    return 0;
}

