/*
	NISHANT GUPTA
	CSE-MNNIT ALLAHABAD
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define rep(i,x,n) for(i=x;i<n;i++)
#define MS(a) memset(a,0,sizeof(a))

int preprocess(char p[200025],int *pie,int m)
{
	int i,j,q,k=0;
	pie[1]=0;
	rep(q,2,m+1)
	{
		while(k>0&&p[k]!=p[q-1])
		k=pie[k];
		if(p[k]==p[q-1])
		k++;
		pie[q]=k;
	}
	return pie[m];
}

int check_pal(char s[100005],int m)
{
	int i=0,j=m-1;
	while(i<j)
	{
		if(s[i]!=s[j])
		return 0;
		i++;j--;
	}
	return 1;
}
int main()
{
	int n,m,i,j,k,l,ans;
	char s[100005],copy[200025];
	while(scanf("%s",s)==1)
	{
		l=strlen(s);
		j=0;
		for(i=l-1;i>=0;i--)
		{
			copy[j++]=s[i];
		}
		copy[j++]='$';copy[j]='\0';
		strcat(copy,s);
		//printf("%s\n",s);
		//printf("%s\n",copy);
		int pie[200025]={0};
		m=2*l+1;
		k=preprocess(copy,pie,m);
		//printf("%d",k);
		printf("%s",s);
		for(i=l-k-1;i>=0;i--)
		printf("%c",s[i]);
		printf("\n");
	}
	return 0;
}
