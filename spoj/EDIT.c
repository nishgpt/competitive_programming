#include <stdio.h>
#include<string.h>
int main()
{
    char str[1005];
    int len,i,count1,a,count2;
    while(scanf("%s",str)!=EOF)
    {
        len=strlen(str);
        int arr1[len];
        int arr2[len];
        int arr3[len];
        count1=0,count2=0;
        if(len==1)
            printf("0\n");
        else
        {
            for(i=0;i<len;i++)
            {
                a=str[i];
                if(a>=65&&a<=90)
                    arr1[i]=1;
                else
                    arr1[i]=0;
            }
 
            a=str[0];
            if(a>=65&&a<=90){
                arr2[0]=1;
                arr3[0]=0;
            }
            else{
                arr2[0]=0;
                arr3[0]=1;
            }
            for(i=1;i<len;i++)
            {
                if(arr2[i-1]==0)
                {
                    arr2[i]=1;
                    arr3[i]=0;
                }
                else{
                    arr2[i]=0;
                    arr3[i]=1;
                }
            }
            for(i=0;i<len;i++)
            {
                if(arr1[i]!=arr2[i])
                    count1+=1;
                if(arr1[i]!=arr3[i])
                    count2+=1;
            }
            printf("%d\n",(count1<count2)?count1:count2);
        }
    }
    return 0;
}