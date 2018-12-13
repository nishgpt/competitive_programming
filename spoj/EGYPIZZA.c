#include <stdio.h>
int main()
{
    long unsigned int n,q=0,t=0,h=0,i,p=0;
    char s[4];
    scanf("%lu",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",s);
        if(s[0]=='3')
        t++;
        else if(s[2]=='4')
        q++;
        else h++;
    }
    if(!(h&1))
    p=p+(h/2);
    else p=p+(h/2)+1;
    p=p+t;
    if(q>t)
    {
        q=q-t;
        if(h%2!=0&&q>0)
        {if(q==1) q--; else if(q>1) q=q-2;}
        if(q%4==0)
        p=p+(q/4);
        else
        p=p+(q/4)+1;
    }
    printf("%lu\n",p+1);
    return 0;
}