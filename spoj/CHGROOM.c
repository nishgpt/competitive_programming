#include<iostream>
#define LL long long int
using namespace std;
int main()
{
	LL n,i,j=0;
	cin>>n;LL nn=n;
	for(i=2;i*i<nn;i++)
	{
		while(n%i==0)
		{
			n=n/i;
			j++;
			if(j>=2)goto X;
		}
	}
	if(j==0)goto X;
	cout<<"MARIAN"<<endl;return 0;
	X:;
	cout<<"ANNE"<<endl;return 0;
}