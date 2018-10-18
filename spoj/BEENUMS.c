#include < stdio.h > #include < math.h >
  int main() {
    long long signed int N, n, a, b;
    do {
      scanf("%lld", & N);
      if (N == 1)
        printf("Y\n");
      else if (N == 0)
        printf("N\n");
      else if (N != -1) {
        a = 9 + 12 * (N - 1);
        b = 3 + sqrt(a);
        n = ((3 + b) / 2);
        if (((N - 1) % (n - 1)) == 0)
          printf("Y\n");
        else
          printf("N\n");
      }
    }
    while (N != -1);
    return 0;
  }