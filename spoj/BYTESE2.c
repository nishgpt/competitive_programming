#include < stdio.h > #define M 105
void mergeSort(long long int arr[], long long int low, long long int mid, long long int high) {
  long long int i, m, k, l, temp[M];
  l = low;
  i = low;
  m = mid + 1;
  while ((l <= mid) && (m <= high)) {
    if (arr[l] <= arr[m]) {
      temp[i] = arr[l];
      l++;
    } else {
      temp[i] = arr[m];
      m++;
    }
    i++;
  }
  if (l > mid) {
    for (k = m; k <= high; k++) {
      temp[i] = arr[k];
      i++;
    }
  } else {
    for (k = l; k <= mid; k++) {
      temp[i] = arr[k];
      i++;
    }
  }
  for (k = low; k <= high; k++) {
    arr[k] = temp[k];
  }
}
void partition(long long int arr[], long long int low, long long int high) {
  long long int mid;
  if (low < high) {
    mid = (low + high) / 2;
    partition(arr, low, mid);
    partition(arr, mid + 1, high);
    mergeSort(arr, low, mid, high);
  }
}
int main() {
  long long int i, j, k, t, n, a[M], b[M], ans;
  scanf("%lld", & t);
  while (t--) {
    scanf("%lld", & n);
    k = 0;
    ans = 0;
    for (i = 0; i < n; i++) {
      scanf("%lld %lld", & a[i], & b[i]);
    }
    partition(a, 0, n - 1);
    partition(b, 0, n - 1);
    for (i = 0, j = 0; i < n;) {
      if (a[i] < b[j]) {
        k++;
        i++;
      } else {
        k--;
        j++;
      }
      ans = ans > k ? ans : k;
    }
    printf("%lld\n", ans);
  }
  return 0;
}