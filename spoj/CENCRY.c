#include <stdio.h>
#include <string.h>
int main()
{
	int t,i,j,k,freq[26];
	char v[]="aeiou",s[50010],con[]="bcdfghjklmnpqrstvwxyz";
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		memset(freq,0,sizeof freq);
		for(i=0;s[i]!='\0';i++)
		{
			freq[(int)s[i]-97]++;
			if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
			{
				for(j=0;v[j]!='\0';j++)
				if(v[j]==s[i])break;
				k=(freq[(int)s[i]-97]-1)*5+j;
				k=k%21;
				printf("%c",con[k]);
			}
			else
			{
				for(j=0;con[j]!='\0';j++)
				if(con[j]==s[i])break;
				k=(freq[(int)s[i]-97]-1)*21+j;
				k=k%5;
				printf("%c",v[k]);
			}
		}
		printf("\n");
	}
	return 0;
}
	