/*
	NISHANT GUPTA
	CSE-MNNIT ALLAHABAD
*/
#include<stdio.h>
#define inp(n) scanf("%d",&n)
#define rep(i,x,n) for(i=x;i<n;i++)
int a[100005],n,c;
void mergeSort(int arr[],int low,int mid,int high)
{
int i,m,k,l,temp[100005];
    l=low;
    i=low;
    m=mid+1;
    while((l<=mid)&&(m<=high)){
         if(arr[l]<=arr[m]){
             temp[i]=arr[l];
             l++;}
         else{
             temp[i]=arr[m];
             m++;
         }i++;
    }
    if(l>mid){
         for(k=m;k<=high;k++){
             temp[i]=arr[k];
             i++;
         }
    }
    else{
         for(k=l;k<=mid;k++){
             temp[i]=arr[k];
             i++;
         }
    }
    for(k=low;k<=high;k++){
         arr[k]=temp[k];
    }
} 
 void partition(int arr[],int low,int high)
 {
    int mid;
    if(low<high){
         mid=(low+high)/2;
         partition(arr,low,mid);
         partition(arr,mid+1,high);
         mergeSort(arr,low,mid,high);
    }
}

int possible(int x)
{
	int i,j,placed=1,last_cow=a[0];
	for(i=1;i<n;i++)
	{
		if(a[i]-last_cow>=x)
		{last_cow=a[i];placed++;}
	}
	if(placed<c)return 0;
	return 1;
}
int main()
{
	int t,i,j,k;
	inp(t);
	while(t--)
	{
		inp(n);inp(c);
		rep(i,0,n)inp(a[i]);
		partition(a,0,n-1);
		int st=0,mid;int end=10000000000;
		for(;st<=end; )
		{
			mid=(st+end)>>1;
			if(possible(mid))
				st=mid+1;
			else end=mid-1;
		}
		if(st==end)
		printf("%d\n",mid);
		else printf("%d\n",end);
	}
	return 0;
}