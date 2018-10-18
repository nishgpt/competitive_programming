/*
  NISHANT GUPTA
  MNNIT ALLAHABAD
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#define max(x,y) x>y?x:y
#define min(x,y) x<y?x:y
#define abso(x) x<0?(-x):x
#define rep(i,n) for(i=0;i<n;i++)
#define rev(i,n) for(i=n;i>=0;i--)
#define getcx getchar_unlocked
using namespace std;
inline void inp( int &n ) 
{
    n=0;
    int ch=getcx();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
    n=n*sign;
}   

int queue[2510],front=0,rear=0;
struct node
{
	int data;
	struct node *link;
};
struct node *adjacent(struct node *start,int item)
{
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=item;newnode->link=start;
	start=newnode;
	return start;
}
void insert(int x)
{
	queue[rear++]=x;
}
int del()
{
	if(front==rear)return -9999;
	return queue[front++];
}
int main()
{
	int n,m,i,j,k,t,u,v,x=1,flag,colour[2010];
	inp(t);
	struct node *start[2010];
	while(x<=t)
	{
		inp(n);inp(m);
		rep(i,2010)start[i]=NULL;
		memset(colour,-1,sizeof colour);
		front=rear=0;
		rep(i,m)
		{
			inp(u);inp(v);
			start[u]=adjacent(start[u],v);
			start[v]=adjacent(start[v],u);
		}
		if(n==1){printf("Scenario #%d:\nNo suspicious bugs found!\n",x++);continue;}
		/*rep(i,n+1)
		{
			struct node *p=start[i];
			while(p!=NULL){printf("%d ",p->data);p=p->link;}
			printf("\n");
		}*/
			
		for(i=1;i<=n;i++)
		{
			if(colour[i]==-1)
			{
				insert(i);colour[i]=0;flag=0;
				while(1)
				{
					k=del();
					if(k==-9999)break;//printf("deleted %d\n",k);
					struct node *p=start[k];
					while(p!=NULL)
					{
						if(colour[p->data]==colour[k]){flag=1;break;}
						else if(colour[p->data]==-1){insert(p->data);colour[p->data]=!colour[k];}
						p=p->link;
					}
					if(flag)break;
				}
				if(flag)break;
			}
		}
		//for(i=1;i<n+1;i++)printf("%d ",colour[i]);
		printf("Scenario #%d:\n",x++);
		if(flag)printf("Suspicious bugs found!\n");
		else printf("No suspicious bugs found!\n");
	}
	return 0;
}