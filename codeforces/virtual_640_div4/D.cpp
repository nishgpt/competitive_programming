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

int main() {
	
	int n, t, k;
	cin>>t;
	while(t--) {
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++) {
			cin>>a[i];
		}
		
		int i = 0, j = n-1;
		int suma = 0, sumb = 0, total = 0;
		int prev = 0, move=1;
		while(i<=j) {
			if(move) {//left
				int sum =0;
				for(k=i;k<=j;k++) {
					sum += a[k];
					if(sum > prev) break;
				}
				i=++k;
				suma+=sum;
				prev = sum;
				total++;
				move = 1-move;
			}
			
			else {//right
				int sum = 0;
				for(k=j;k>=i;k--) {
					sum+=a[k];
					if(sum > prev) break;
				}
				j=--k;
				sumb += sum;
				prev = sum;
				total++;
				move = 1-move;
			}
		}
		
		cout<<total<<" "<<suma<<" "<<sumb<<endl;
	}

    return 0;
}

