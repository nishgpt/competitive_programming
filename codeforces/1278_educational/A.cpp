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

int main() {
	int t;
	string  p, h;
	
	cin>>t;
	
	while(t--) {
		cin>>p;
		cin>>h;
		
		int i, j;
		
		bool flag  = true;
		for(i=0;i<h.length();i++) {
			flag = true;
			int temp[26] = {0};
			for(j=0;j<p.length();j++) {
				temp[p[j]-'a']++;
			}
			
			for(j=i;j<i+p.length();j++) {
				temp[h[j]-'a']--;
			}
			
			for(j=0;j<26;j++) {
				if(temp[j] != 0) {
					flag = false; break;
				}
			}
			
			if(flag) break;
		}
		
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
    return 0;
}

