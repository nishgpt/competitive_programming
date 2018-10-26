#include < stdio.h > #include < string.h >
int str[]={1,0,1,0,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0};

int ill(char arr[]) {
  int i = arr[3], j = arr[4];
  int k, v = 0;
  if (i >= 65 && i <= 90 && j >= 65 && j <= 90) {
    for (k = 0; k < 5; k++) {
      if (str[arr[k] - 65]) {
        v++;
      }
    }
    if (v > 0) return 3;
    else return 2;
  } else if (i >= 48 && i <= 57 && j >= 48 && j <= 57) {
    return 1;
  } else return 3;
}
long long int sec(char arr[], char brr[]) {
  long long int as = 0, i, j, k = 100, n1, n2, d, i1, i2;
  char bet[] = "0BDEFGHJKLNOQRSTUVWXYZ";
  n1 = arr[6] - 48 + (arr[5] - 48) * 10;
  n2 = brr[6] - 48 + (brr[5] - 48) * 10;
  d = n2 - n1;
  for (i = 4; i >= 0; i--) {
    for (j = 1; j < 22; j++) {
      if (arr[i] == bet[j]) {
        i1 = j;
        break;
      }
    }
    for (j = 1; j < 22; j++) {
      if (brr[i] == bet[j]) {
        i2 = j;
        break;
      }
    }
    as = as + (i2 - i1) * k;
    k *= 21;
  }
  return as + d;
}
int main() {
  char s[8], m[8], f[] = "ZZZ9999";
  long long int i, j, k, c, ans, p, n1, n2, d, x, y, z;
  while (scanf("%s %s %lld", m, s, & c) == 3) {
    if (s[0] == '*') {
      break;
    } else {
      j = ill(m);
      k = ill(s);
      ans = 0;
      if (k == 3) {
        printf("N\n");
      } else {
        p = strcmp(s, m);
        if (j == 2 && k == 1) {
          printf("N\n");
        } else if (j == 1 && k == 1) {
          if (p <= 0) printf("N\n");
          else {
            n1 = m[6] - 48 + (m[5] - 48) * 10 + (m[4] - 48) * 100 + (m[3] - 48) * 1000;
            n2 = s[6] - 48 + (s[5] - 48) * 10 + (s[4] - 48) * 100 + (s[3] - 48) * 1000;
            d = n2 - n1;
            ans = ans + d;
            x = s[2] - m[2];
            ans = ans + x * 10000;
            x = s[1] - m[1];
            ans += x * 260000;
            x = s[0] - m[0];
            ans += x * 6760000;
            if (ans <= c) printf("Y\n");
            else printf("N\n");
          }
        } else if (j == 2 && k == 2) {
          if (p <= 0) printf("N\n");
          else {
            ans = sec(m, s);
            if (ans <= c) printf("Y\n");
            else printf("N\n");
          }
        } else if (j == 1 && k == 2) {
          n1 = m[6] - 48 + (m[5] - 48) * 10 + (m[4] - 48) * 100 + (m[3] - 48) * 1000;
          n2 = f[6] - 48 + (f[5] - 48) * 10 + (f[4] - 48) * 100 + (f[3] - 48) * 1000;
          d = n2 - n1;
          ans = ans + d;
          x = f[2] - m[2];
          ans = ans + x * 10000;
          x = f[1] - m[1];
          ans += x * 260000;
          x = f[0] - m[0];
          ans += x * 6760000;
          z = sec("BBBBB00", s);
          ans = ans + z + 1;
          if (ans <= c) printf("Y\n");
          else printf("N\n");
        }
      }
    }
  }
  return 0;
}