#include <stdio.h>
long long int res=0;
void merge(long long int left, long long int m, long long int right,long long int arr[])
{
    long long int k = 0;long long int temp[100010];
    long long int i = left, j = m + 1;
    while (i <= m && j <= right)
        if (arr[i] < arr[j])
        {
            temp[k++] = arr[i];
            res+= (long long)(right - j + 1) * arr[i++];
        }
        else
            temp[k++] = arr[j++];

    while (j <= right)
        temp[k++] = arr[j++];
    while (i <= m)
        temp[k++] = arr[i++];

    for (i = 0; i < k; ++i)
        arr[left + i] = temp[i];
}

void sort(long long int left, long long int right,long long int arr[])
{
    if (left < right)
    {
        int m = left + (right - left) / 2;
        sort(left, m,arr);
        sort(m + 1, right,arr);
        merge(left, m, right,arr);
    }
}

int main()
{
    long long int t,n,ar[100010],w,d;
    scanf("%lld", &t);
    for(w=0;w<t;w++)
    {
        scanf("%lld", &n);
        for(d=0;d<n;d++)
            scanf("%lld", &ar[d]);

        res=0;
        sort(0, n - 1,ar);

        printf("%lld\n",res);
    }

    return 0;
}