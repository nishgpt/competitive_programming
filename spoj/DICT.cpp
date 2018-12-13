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
#define INF (int(1e9))
#define INFL (LL(1e18))
#define EPS 1e-12 
#define chkbit(s, b) (s & (1<<b))
#define setbit(s, b) (s |= (1<<b))
#define clrbit(s, b) (s &= ~(1<<b))
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rev(i, a, n) for(int i = a; i > n; i--)
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
int f;
struct trie
{
	int next[26],flag;
}node[500005];

int insert(char s[25],int k)
{
	int curr=0,a=k,i;
	for(i=0;s[i]!='\0';i++)
	{
		if(!node[curr].next[s[i]-'a'])
		{
			node[curr].next[s[i]-'a']=a;
			curr=a++;
		}
		else
		curr=node[curr].next[s[i]-'a'];
		if(s[i+1]=='\0'){node[curr].flag=1;/*printf("%d\n",curr);*/}
	}
	return a;
}

void dfs(int curr,char str[50],int idx,int mode)
{
	int i,j;
	//printf("hi cur is %d",curr);
	if(mode)
	{
		if(node[curr].flag==1)
		{str[idx]='\0';printf("%s\n",str);f=1;}
	}
	rep(i,0,26)
	{
		if(node[curr].next[i])
		{	
			//rep(j,0,idx)printf("%c",str[j]);printf("\n");
			//printf("%d\n",curr);
			str[idx]=(char)(i+97);
			//rep(j,0,idx+1)printf("%c",str[j]);printf("\n");
			dfs(node[curr].next[i],str,idx+1,1);
			//printf("%d over",i);
		}
	}
	return ;
}
void find(char s[25])
{
	int curr=0,x=0,i,j,k;
	char str[50];
	for(i=0;s[i]!='\0';i++)
	{
		if(!node[curr].next[s[i]-'a']){x=1;break;}
		else {curr=node[curr].next[s[i]-'a'];str[i]=s[i];}
	}
	if(!x){
		//printf("%c%c%c%d%d%d\n",str[0],str[1],str[2],i,curr,node[7].next[8]);
		dfs(curr,str,i,0);}
	return ;
}
int main()
{
	int n,q,i,j,k;
	//map<string,int> mp;
	inp(n);
	char s[25];
	k=1;
	rep(i,0,n)
	{
		scanf("%s",s);
		k=insert(s,k);
	}
	inp(q);
	rep(i,1,q+1)
	{
		scanf("%s",s);//query word
		printf("Case #%d:\n",i);
		f=0;	
		find(s);
		if(!f)printf("No match.\n");
	}
	return 0;
}