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

using namespace std;

int main() {
	int t, i;
	string s;
	
	cin>>t;
	while(t--) {
		cin >>s;
		int z = 0,o = 0;
		for(i=0;i<s.length();i++) {
			if(s[i] == '0') z++;
			else o++;
		}
		
		if(o == 0 || z == 0) {
			cout<<s<<endl;
			continue;
		}
		
		for(i=0;i<2*s.length();i++) {
			cout<<(i&1);
		}
		cout<<endl;
	}
		
    return 0;
}

