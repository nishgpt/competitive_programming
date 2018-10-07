#include<iostream>
using namespace std;
 
int main() {
	int t, n;
	cin>>t;
 
	while(t--) {
		cin>>n;
 
		if(n % 3 == 0) {
			printf("Ragini\n");
			continue;
		}
 
		printf("Hemlata\n");
	}
	return 0;
}