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

vector<int> convert_to_binary(int num) {
	stack<int> st;
	while(num) {
		st.push(num&1);
		num>>=1;
	}
	
	int size = st.size();
	for(int i=size;i<16;i++) {
		st.push(0);
	}
	
	vector<int> vec;
	while(st.size()>0) {
		vec.pb(st.top());
		st.pop();
	}
	
	return vec;
}

int convert_to_decimal(vector<int> shifted_bin) {
	int pow = 1;
	int number = 0;
	int l = shifted_bin.size();
	for(int i=l-1;i>=0;i--) {
		number += pow*shifted_bin[i];
		pow<<=1;
	}
	
	return number;
}

int main() {
	int t, n, m, i;
	char c;
	cin>>t;
	
	while(t--) {
		cin>>n>>m;
		cin>>c;
		
		vector<int> v = convert_to_binary(n);
		vector<int> shifted_bin;
		int l = v.size();
		
		if(c == 'L') {
			for(i=m;i<l;i++) {
				shifted_bin.pb(v[i]);
			}
			
			for(i=0;i<m;i++) {
				shifted_bin.pb(v[i]);
			}
		} else {
			for(i=l-m;i<l;i++) {
				shifted_bin.pb(v[i]);
			}
			
			for(i=0;i<l-m;i++) {
				shifted_bin.pb(v[i]);
			}
		}
		
		cout<<convert_to_decimal(shifted_bin)<<endl;
	}
    return 0;
}

