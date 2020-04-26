/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 100005
#define MOD 1000000007
#define LIMIT 50
using namespace std;

vector<LL> even_cp;
vector<LL> odd_cp;
void pre() {
	even_cp.pb(0);
	LL prev_even = 0;
	odd_cp.pb(1);
	LL prev_odd = 1;
	LL pow = 4;
	for(int i=1;i<LIMIT;i++) {
		prev_even += pow;
		prev_odd += pow;
		even_cp.pb(prev_even);
		odd_cp.pb(prev_odd);
		pow = pow*2;
	}
}

LL solve(LL n, LL k) {
	if(n < 3) return 1;
	
	int i;
	if(n&1) {//if odd
		LL cp = -1;
		for(i=0;i<odd_cp.size();i++) {
			if(odd_cp[i] <= n && odd_cp[i+1] > n) {
				cp = odd_cp[i];
				break;
			}
		}
		
		LL diff_cp = n - cp;
		LL start = -1;
		if(diff_cp == 0) start = n;
		else if(diff_cp == 2) start = 2;
		else if(diff_cp == 4) start = 5;
		else start = 5 + (n - (cp+4)) * 2;
		
		LL q = k % n;
		if(q == 0) q = n;
		
		if(start == 2) {
			//all even first and then odd
			LL pos_of_max_even = n/2 ;
			if(q<=pos_of_max_even) {
				return 2*q;
			}
			
			q -= n/2;
			return 2*q-1;
		} else {
			LL pos_of_max_odd = (n-start)/2 + 1;
			if(q<=pos_of_max_odd) {
				return start + (q-1)*2; 
			}
			
			q -= pos_of_max_odd;
			LL pos_of_max_even = (n-1)/2;
			if(q<=pos_of_max_even) {
				return 2*q;
			}
			
			q-=pos_of_max_even;
			return 2*q-1;
		}
	} else {
		LL cp = -1;
		for(i=0;i<even_cp.size();i++) {
			if(even_cp[i] <= n && even_cp[i+1] > n) {
				cp = even_cp[i];
				break;
			}
		}
		
		LL diff_cp = n - cp;
		LL start = -1; //always an odd number
		if(diff_cp == 0) start = n-1;
		else if(diff_cp == 2) start = 1;
		else if(diff_cp == 4) start = 3;
		else start = 3 + (n - (cp+4)) * 2;
		
		LL q = k % (n/2);
		if(q == 0) q = n/2;
		LL pos_of_max_odd = 1 + ((n - 1 - start) / 2);
		if(q<=pos_of_max_odd) {
			return (q-1)*2 + start;
		}
		q-=pos_of_max_odd;
		return (q-1)*2 + 1;
	}
}
int main() {
	LL n, k, t;
	cin>>t;
	pre();
	while(t--) {
		cin>>n>>k;
		cout<<solve(n, k)<<endl;
	}
		
    return 0;
}

