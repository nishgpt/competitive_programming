/*
  NISHANT GUPTA
  MNNIT ALLAHABAD
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#define max(x,y) x>y?x:y
#define min(x,y) x<y?x:y
#define abso(x) x<0?(-x):x
#define rep(i,n) for(i=0;i<n;i++)
#define rev(i,n) for(i=n;i>=0;i--)
#define getcx getchar_unlocked
using namespace std;
struct node 
{
	int data;
	struct node *link;
};

inline void inp( int &n ) 
{
    n=0;
    int ch=getcx();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
    n=n*sign;
} 
//insert
struct node *insert(struct node *start,int item,int *c)
{
	struct node *p=start;
	while(p!=NULL)
	{
		if(p->data==item)return start;    //if that link is already present then no need to insert
	    p=p->link;
	}
	//printf("hi i m here with %d\n",item);
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=item;
	newnode->link=start;
	start=newnode;
	(*c)++;return start;
}
int tot=0;
void dfs(int item,struct node *start[],int visited[])
{
	struct node *p=start[item];
	if(!visited[item])
	{
		visited[item]=1;
		tot++;
		while(p!=NULL)
		{
			dfs(p->data,start,visited);
			p=p->link;
		}
	}
	return ;
}
int main()
{
	struct node *start[10005];
	int a[10005],i,j,n,m,count,num,u,v,p=-1,visited[10005];
	rep(i,10005)
		start[i]=NULL;
	inp(n);
	inp(m);
	count=num=0;
	memset(a,0,sizeof a);memset(visited,0,sizeof visited);
	if(!m&&n==1)printf("YES\n");
	else
	{
		rep(i,m)
		{
			inp(u);inp(v);if(p==-1)p=u;
			if(!a[u]){a[u]=1;num++;}
			if(!a[v]){a[v]=1;num++;}
			start[u]=insert(start[u],v,&count);
			start[v]=insert(start[v],u,&count);
		}
		count>>=1;
	    dfs(p,start,visited);
	    if(tot==num&&count==(num-1))printf("YES\n");
	    else printf("NO\n");
	}
	//printf("%d %d",count,num);
	return 0;
}

