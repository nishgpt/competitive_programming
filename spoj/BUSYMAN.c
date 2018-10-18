#include <stdio.h>
void mergeSort(long long int arr[],long long int brr[],long long int low,long long int mid,long long int high)
{
long long int i,m,k,l,temp[100000],s[100000];
    l=low;
    i=low;
    m=mid+1;
    while((l<=mid)&&(m<=high)){
         if(arr[l]<=arr[m]){
             temp[i]=arr[l];s[i]=brr[l];
             l++;}
         else{
             temp[i]=arr[m];s[i]=brr[m];
             m++;
         }i++;
    }
    if(l>mid){
         for(k=m;k<=high;k++){
             temp[i]=arr[k];s[i]=brr[k];
             i++;
         }
    }
    else{
         for(k=l;k<=mid;k++){
             temp[i]=arr[k];s[i]=brr[k];
             i++;
         }
    }
    for(k=low;k<=high;k++){
         arr[k]=temp[k];brr[k]=s[k];
    }
} 
 void partition(long long int arr[],long long int brr[],long long int low,long long int high)
 {
    long long int mid;
    if(low<high){
         mid=(low+high)/2;
         partition(arr,brr,low,mid);
         partition(arr,brr,mid+1,high);
         mergeSort(arr,brr,low,mid,high);
    }
}
int main()
{
    long long int n,i,j,k,a[100000],b[100000],p,t,q;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);p=1;
        for(i=0;i<n;i++)
        {scanf("%lld %lld",&b[i],&a[i]);}
        partition(a,b,0,n-1);
        q=a[0];
        for(i=1;i<n;i++)
        {
            if(b[i]>=q){p++;q=a[i];}
        }
        printf("%lld\n",p);
    }
    return 0;
}