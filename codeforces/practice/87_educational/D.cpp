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
#define MAX 1000005
#define MaxIdx 1000000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL (LL(1e18))
#define rep(i, a, n) for(i=a;i<n;i++)
#define rev(i, a, n) for(i=a;i>=n;i--)
#define MSV(A,a) memset(A, a, sizeof(A))
#define rep_itr(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)

using namespace std;

int bit[MAX];
void update(int idx, int val) {
  while (idx <= MaxIdx) {
    bit[idx] += val;
    idx += (idx & -idx);
  }
}

int read(int idx) {
  int sum = 0;
  while (idx > 0) {
    sum += bit[idx];
    idx -= (idx & -idx);
  }
  return sum;
}

int get_kth_order(int k) {
	int low = 1, high = MAX;
	int ans;
	while(low <= high) {
		int mid = (low + high) >> 1;
		
		int elements = read(mid); //how many elements are there till mid 
		if(elements >= k) {
			ans = mid;
			high = mid-1;
		} else {
			low = mid + 1;
		}
	}
	return ans;
}

int readSingle(int idx) {
  int sum = bit[idx];
  if (idx > 0) {
    int z = idx - (idx & -idx);
    idx--;
    while (idx != z) {
      sum -= bit[idx];
      idx -= (idx & -idx);
    }
  }
  return sum;
}

int main() {
	int n, q, k, x;
	cin>>n>>q;
	for(int i=0;i<n;i++) {
		scanf("%d", &x);
		update(x, 1);
	}
	
	while(q--) {
		scanf("%d", &k);
		if(k < 0) {
			k*=-1;
			int kth = get_kth_order(k);
			update(kth, -1);
		} else {
			update(k, 1);
		}
	}
	
	int ans = 0;
	for(int i=1;i<MAX;i++) {
		if(readSingle(i) > 0) {
			ans = i;
			break;
		}
	}
	printf("%d\n", ans);
    return 0;
}

