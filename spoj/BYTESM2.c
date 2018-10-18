#include < stdio.h >
  int main() {
    int n, m, i, j, h, k, t;
    scanf("%d", & t);
    int a[100][100], b[100][100];
    for (k = 0; k < t; k++) {
      scanf("%d %d", & n, & m);
      for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
          scanf("%d", & a[i][j]);
      }
      for (i = 0; i < m; i++)
        b[0][i] = a[0][i];
      for (i = 1; i < n; i++) {
        for (j = 0; j < m; j++) {
          if (j == 0)
            b[i][j] = a[i][j] + (b[i - 1][j] > b[i - 1][j + 1] ? b[i - 1][j] : b[i - 1][j + 1]);
          else if (j == m - 1)
            b[i][j] = a[i][j] + (b[i - 1][j - 1] > b[i - 1][j] ? b[i - 1][j - 1] : b[i - 1][j]);
          else
            b[i][j] = a[i][j] + (b[i - 1][j - 1] > (b[i - 1][j] > b[i - 1][j + 1] ? b[i - 1][j] : b[i - 1][j + 1]) ? b[i - 1][j - 1] : (b[i - 1][j] > b[i - 1][j + 1] ? b[i - 1][j] : b[i - 1][j + 1]));
        }
      }
      h = 0;
      for (i = 0; i < m; i++) {
        if (h < b[n - 1][i])
          h = b[n - 1][i];
      }
      printf("%d\n", h);
    }
    return 0;
  }