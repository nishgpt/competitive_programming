#include<bits/stdc++.h>

#define MAX 999999999
using namespace std;

int main() {
	int t = 1000;
	cout<<t<<endl;
	while(t--) {
		int a = rand() % MAX + 1;
		int b = rand() % MAX + 1;
		cout<<a<<" "<<b<<endl;
	}
}