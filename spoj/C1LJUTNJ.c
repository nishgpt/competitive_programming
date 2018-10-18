#include <stdio.h>
void mergeSort(long long int arr[],long long int low,long long int mid,long long int high)
{
long long int i,m,k,l,temp[100000];
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
 void partition(long long int arr[],long long int low,long long int high)
 {
    long long int  mid;
    if(low<high){
         mid=(low+high)/2;
         partition(arr,low,mid);
         partition(arr,mid+1,high);
         mergeSort(arr,low,mid,high);
    }
}
int main()
{
    long long int i,j,k=1,ans=0,n,m,a[100000],e,r,sum=0;
    scanf("%lld %lld",&m,&n);
    for(i=0;i<n;i++){scanf("%lld",&a[i]);sum=sum+a[i];}
    partition(a,0,n-1);
    sum=sum-m;
    for(i=0;i<n;i++)
    {
        j=a[i]<(sum/(n-i))?a[i]:(sum/(n-i));
        sum-=j;
       k=j*j;
        ans=ans+k;
    }
    printf("%lld\n",ans);
    return 0;
}
