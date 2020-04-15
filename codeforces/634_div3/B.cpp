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
	cin>>t;
	int n, a, b;
	while(t--) {
		string s;
		cin>>n>>a>>b;
		int i;
		for(i=0;i<b;i++) {
			s = s + (char) (i+'a');
		}
		i--;
		for(int j=b;j<a;j++) {
			s = s + (char) (i+'a');
		}
		
		for(i=a;i<n;i++) {
			char c = s[i-a];
			s = s + c;
		}
		
		cout<<s<<endl;
	}
    return 0;
}


