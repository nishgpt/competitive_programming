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

int get_points(int n)
{
	if(n<=4)return 1;
	if(n==5)return 2;
	if(n==6)return 3;
	if(n==7)return 5;
	else return 11;
}
int main()
{
	int n,i,j,k,m;
	char c[3500];
	scanf("%d\n",&n);
	vector<string> v[105];
	map<string,int> mp[105];
	rep(i,0,n)
	{
		gets(c);
		string t;k=1;
		for(j=0;c[j]!='\0';j++)
		{
			if(c[j]!=' ')t=t+c[j];
			else
			{
				v[i].PB(t);
				if(mp[i][t]==0)mp[i][t]=k++;
				t="";
			}
		}
		v[i].PB(t);
		if(mp[i][t]==0)mp[i][t]=k++;
	}
	/*rep(i,0,n)
	{
		rep(j,0,v[i].size())
		{cout<<v[i][j]<<" "<<mp[i][v[i][j]]<<endl;}
		cout<<endl;
	}*/
	int ans=-1,temp;
	rep(i,0,n)  //ith sentence (player)
	{
		temp=0;
		rep(k,0,v[i].size())  //all words of the ith player
		{
			int f=0;
			rep(j,0,n)   //other players
			{
				if(i==j)continue;
				if(mp[j][v[i][k]])//that means jth player has also found the word
				{f=1;break;}
			}
			if(!f) //word is unique to ith player he will get points
			temp+=get_points(v[i][k].length());
		}
		ans=MAX(ans,temp);
	}
	printf("%d\n",ans);
	return 0;
}