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
typedef pair<int, int> pi; 

inline void inp( int &n ) { 
	n=0;    int ch=getcx();int sign=1;   
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();} 
	while(  ch >= '0' && ch <= '9' )    
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}

inline void inp1( LL &n ) { 
	n=0;    LL ch=getcx();LL sign=1;   
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();} 
	while(  ch >= '0' && ch <= '9' )    
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}

struct triplet {
	int i1;
	int i2;
	int i3;
};

int main() {
	int t, n, k, i;
	inp(t);
	
	while(t--) {
		inp(n);inp(k);
		int i1, i2, i3;
		
		int pos[n+1];
		int a[n+1];
		int palti[n+1];
		MSV(palti, 0);
		
		priority_queue<pair<int, int> > pq;
		priority_queue<pi, vector<pi>, greater<pi> > gpq;
		
		for(i=1;i<=n;i++) {
			inp(a[i]);
			pos[a[i]] = i;
			if(i != a[i]) {
				pq.push(MP(0, a[i]));
				gpq.push(MP(0, a[i]));
			}
		}
		
		int op = 0;
		int curr = 0;
		int flag = true;
		int xyz = 0;
		vector<triplet> steps;
		while(op < k && !pq.empty()) {
			curr = pq.top().Y;
			pq.pop();

			if(pos[curr] == curr) continue;
						
			i1 = pos[curr];
			i2 = curr;
			i3 = pos[i1];
			
			if(i3 == i2) {
				int nme = -1;
				while(!gpq.empty()) {
					pair<int, int> f = gpq.top();
					if(f.Y == curr || f.Y == a[i2]) {gpq.pop();continue;}
					if(f.Y == pos[f.Y]) {gpq.pop(); continue;}
					if(palti[f.Y] > f.X) {gpq.pop();continue;}
					
					nme = f.Y;
					break;
				}
	
				if(nme == -1) {
					flag = false;
					break;
				}
				i3 = pos[nme];
			}
						
			int vi1 = a[i1];
			int vi2 = a[i2];
			int vi3 = a[i3];
			
			a[i1] = vi3;
			pos[vi3] = i1;
			palti[vi3]++;
			if(i1 != vi3) {
				pq.push(MP(palti[vi3], vi3));
				gpq.push(MP(palti[vi3], vi3));
			}
				
			
			a[i2] = vi1;
			palti[vi1]++;
			pos[vi1] = i2;
			if(i2 != vi1) {
				pq.push(MP(palti[vi1], vi1));
				gpq.push(MP(palti[vi1], vi1));
			}
			
			a[i3] = vi2;
			palti[vi2]++;
			pos[vi2] = i3;
			if(i3 != vi2) {
				pq.push(MP(palti[vi2], vi2));
				gpq.push(MP(palti[vi2], vi2));
			}
			
			steps.PB((triplet) {i1, i2, i3});
			op++;
			
			
			//~if(op == k) {
				//~int left = 0;
				//~for(i=1;i<=n;i++) {
					//~if(a[i] != i) {
					//~//cout<<i<<" "<<a[i]<<endl;
					//~left++;
					//~}
				//~}
				//~if(left > 0) {op--;xyz++;}
			//~}
		}
		
		if(!flag) {
			cout<<"-1\n";
		}
		else {
			int left = 0;
			for(i=1;i<=n;i++) {
				if(a[i] != i) {
					//cout<<i<<" "<<a[i]<<endl;
					left++;
				}
			}
			if(left > 0) cout<<"-1\n";
			else {
				cout<<op<<"\n";
				for(i=0;i<op;i++) cout<<steps[i].i1<<" "<<steps[i].i2<<" "<<steps[i].i3<<"\n";
			}
		}
	}

    return 0;
}

