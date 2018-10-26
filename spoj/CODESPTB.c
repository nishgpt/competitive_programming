#include <stdio.h>
long long int res=0;
void mergeSort(long long int arr[],long long int low,long long int mid,long long int high)
{
long long int i,m,k,l,temp[200000];
    l=low;
    i=low;
    m=mid+1;
    while((l<=mid)&&(m<=high)){
         if(arr[l]>arr[m]){
             temp[i]=arr[l];res+=(high-m+1);
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
 void partition(long long int arr[],long long int low,long long int high)
 {
    long long int mid;
    if(low<high){
         mid=(low+high)/2;
         partition(arr,low,mid);
         partition(arr,mid+1,high);
         mergeSort(arr,low,mid,high);
    }
}
int main()
{
    long long int a[200000],n,p,t;
    scanf("%lld",&t);
    while(t--)
    {res=0;
        scanf("%lld",&n);
        for(p=0;p<n;p++)scanf("%lld",&a[p]);
        partition(a,0,n-1);
        printf("%lld\n",res);
    }
    return 0;
}
