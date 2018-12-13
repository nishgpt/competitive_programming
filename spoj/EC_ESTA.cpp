/*
	NISHANT GUPTA
	CSE-MNNIT ALLAHABAD
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <cctype>
#include <utility>
#include <map>
#include <string>
#include <climits>
#include <set>
#include <string>
#include <sstream>
#include <utility>
#include <ctime>
#include <cassert>
#include <fstream>
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> II;
typedef vector<long long> VLL;
typedef vector<bool> VB; 
#define SZ(A) ((int)A.size())
#define LEN(A) ((int)A.length())
#define MS(A) memset(A, 0, sizeof(A))
#define MSV(A,a) memset(A, a, sizeof(A))
#define MAX(a,b) ((a >= b) ? (a) : (b))
#define MIN(a,b) ((a >= b) ? (b) : (a))
#define ABS(a) (((a) > 0) ? (a) : (-a))
#define MP make_pair
#define X first
#define Y second
#define PB push_back
#define FOUND(A, x) (A.find(x) != A.end())
#define getcx getchar_unlocked
#define INF 0x3f3f3f3f
#define INFL (LL(1e18))
#define EPS 1e-12 
#define chkbit(s, b) (s & (1<<b))
#define setbit(s, b) (s |= (1<<b))
#define clrbit(s, b) (s &= ~(1<<b))
#define rep(i, a, n) for(i = a; i < n; i++)
#define rev(i, a, n) for(i = a; i > n; i--)
#define FORALL(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)
#define ALL(A) A.begin(), A.end()
#define LLA(A) A.rbegin(), A.rend()
inline void inp( int &n )
{ 
	n=0;    int ch=getcx();int sign=1;   
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();} 
	while(  ch >= '0' && ch <= '9' )    
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}   	
inline void inp1( LL &n )
{ 
	n=0;    LL ch=getcx();LL sign=1;   
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();} 
	while(  ch >= '0' && ch <= '9' )    
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}   	

int main()
{
	int t,i,j,k,n,s1,s2;
	inp(t);
	//cout<<t<<endl;
	while(t--)
	{
		priority_queue<int,std::vector<int>,std::greater<int> > minHeap;
		priority_queue<int> maxHeap;
		inp(n);
		int a[n];
		s1=s2=0;
		//cout<<n<<endl;
		rep(i,0,n)
		{
			inp(a[i]);
			if(!i) //1st element
				{printf("%d\n",a[i]);continue;}
			else if(i==1) //second element
			{
				maxHeap.push(MIN(a[0],a[1]));s1++;
				minHeap.push(MAX(a[0],a[1]));s2++;
			}
			else 
			{
				if(a[i]<maxHeap.top()){maxHeap.push(a[i]);s1++;}
				else {minHeap.push(a[i]);s2++;}
			}
			//balance heaps
			if(s1-s2>1) //maxHeap has more
			{
				k=maxHeap.top();
				maxHeap.pop();
				minHeap.push(k);
				s1--;s2++;
			}
			else if(s2-s1>1) //minHeap has more
			{
				k=minHeap.top();
				minHeap.pop();
				maxHeap.push(k);
				s2--;s1++;
			}
			//calculate median
			if(s1==s2) //even elements
			{
				unsigned int ans=maxHeap.top();ans+=minHeap.top();
				printf("%u",ans>>1);
				if(ans&1)printf(".5");
				printf("\n");
			}
			else if(s1>s2)printf("%d\n",maxHeap.top());
			else printf("%d\n",minHeap.top());
		}
	}
	return 0;
}
