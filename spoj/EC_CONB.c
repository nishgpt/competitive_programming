#include <stdio.h>
long long int stk[50],top=-1;
void push(long long int x)
{
	if(top!=49)
	{
		stk[++top]=x;
	}
}
long long int pop()
{
	if(top!=-1)
	{
		return stk[top--];
	}
	else return -99;
}
void display()
{
    long long int i;
    for(i=0;i<=top;i++)printf("%lld ",stk[i]);
}
int main()
{
	long long int t,j,n,i,ans,k;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);ans=0;top=-1;
		if(!(n&1))
		{
			for(i=n;i!=0;i/=2)
			push(i%2);
			//display();
			k=1;
			while(1)
			{
				j=pop();
				if(j==-99)break;
				ans+=(k*j);
				k*=2;
			}
			printf("%lld\n",ans);
		}
		else printf("%lld\n",n);
	}
	return 0;
}
