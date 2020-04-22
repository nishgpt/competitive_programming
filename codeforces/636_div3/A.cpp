/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 100005
#define MOD 1000000007

using namespace std;

vector<int> v;
void pre() {
	int i;
	int pow = 4;
	for(i=1;i<31;i++) {
		v.pb(pow-1);
		pow = pow*2;
	}
}

int main() {
	pre();
	int t, num;
	cin>>t;
	while(t--) {
		cin>>num;
		
		for(int i=0;i<v.size();i++) {
			if(num % v[i] == 0) {
				cout<<num/v[i]<<endl;
				break;
			}
		}
	}
    return 0;
}

