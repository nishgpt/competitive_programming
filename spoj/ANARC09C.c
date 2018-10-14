#include < stdio.h > 
#include < math.h > 
#include < stdlib.h >
int main() {
  long long int i, j, k, n, t = 1, c, m, ans1, ans2;
  long long int * a = malloc(sizeof(long long int) * 1000000);
  long long int * b = malloc(sizeof(long long int) * 1000000);
  while (scanf("%lld %lld", & n, & m) == 2) {
    if (n == 0 && m == 0) {
      break;
    } else {
      ans1 = 0;
      ans2 = 0;
      for (i = 2; i * i <= n; i++) {
        while (n % i == 0) {
          a[i]++;
          n /= i;
        }
      }
      if (n > 1) {
        i = n;
        a[i]++;
      }
      for (j = 2; j * j <= m; j++) {
        while (m % j == 0) {
          b[j]++;
          m /= j;
        }
      }
      if (m > 1) {
        j = m;
        b[j]++;
      }
      c = i > j ? i : j;
      for (k = 2; k <= c; k++) {
        if (a[k] | b[k]) {
          ans1++;
          ans2 += abs(a[k] - b[k]);
        }
        a[k] = 0;
        b[k] = 0;
      }
      printf("%lld. %lld:%lld\n", t, ans1, ans2);
      t++;
    }
  }
  return 0;
}