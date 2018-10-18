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
    long long int n,sum=0,j;
    long long int a[100000],p[100000];
    scanf("%lld",&n);
    while(n!=0)
    {sum=0;
        for(j=0;j<n;j++){scanf("%lld ",&a[j]);}
        for(j=0;j<n;j++){scanf("%lld ",&p[j]);}
        partition(a,0,n-1);
        partition(p,0,n-1);
        for(j=0;j<n;j++)
            sum=sum+a[j]*p[n-j-1];
            printf("%lld\n",sum);
        scanf("%lld",&n);
    }
    return 0;
}
