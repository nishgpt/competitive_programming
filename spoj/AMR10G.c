#include <stdio.h>
void mergeSort(long long int arr[],long long int low,long long int mid,long long int high)
{
long long int i,m,k,l,temp[20000];
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
    long long int a[20000],n,p,q=0,r,t,min,z;
    scanf("%lld",&t);
    while(t--)
    {q=0;
        scanf("%lld %lld",&n,&r);
        for(p=0;p<n;p++)scanf("%lld",&a[p]);
        min=1000000000;
        partition(a,0,n-1);
        for(p=0;p<=n-r;p++)
        {
            z=a[p+r-1]-a[p];
            if(z<min){min=z;}
        }
        printf("%lld\n",min);
    }
    return 0;
}