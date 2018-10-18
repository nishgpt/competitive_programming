import java.io.*;
class base {
  public static void main(String args[]) throws IOException {
    BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));
    String s, b = "";
    int n, b1, b2, l, f, i, j, k, p, q, flag;
    int a[] = new int[14];
    while ((s = cin.readLine()) != null) {
      s = s.trim();
      k = 0;
      p = 1;
      q = 0;
      flag = 0;
      for (i = 0; i < 14; i++) {
        a[i] = -99;
      }
      f = s.indexOf(' ');
      b = s.substring(0, f);
      s = (s.substring(f)).trim();
      f = s.indexOf(' ');
      b1 = Integer.parseInt(s.substring(0, f));
      f = s.lastIndexOf(' ');
      b2 = Integer.parseInt(s.substring(f + 1));
      if (b1 <= 9) {
        n = Integer.parseInt(b);
        for (i = n; i != 0; i /= 10) {
          k = k + (i % 10) * p;
          p = p * b1;
        }
      } else if (b1 == 10) {
        k = Integer.parseInt(b);
      } else {
        l = b.length();
        for (i = l - 1; i >= 0; i--) {
          j = (int)(b.charAt(i));
          if (j <= 57 && j >= 48) {
            j = j - 48;
          } else if (j >= 65 && j <= 90) {
            j = j - 65;
            j += 10;
          }
          k = k + j * p;
          p = p * b1;
        }
      }
      if (k == 0) {
        System.out.println("      0");
      } else {
        for (i = k; i != 0; i /= b2) {
          a[q++] = (i % b2);
          if (q > 7) {
            flag = 1;
            break;
          }
        }
        if (flag == 0) {
          for (i = 6; i >= 0; i--) {
            if (a[i] == -99) System.out.print(" ");
            else if (a[i] < 10 && a[i] >= 0) System.out.print(a[i]);
            else if (a[i] >= 10) {
              a[i] = a[i] - 10;
              a[i] += 65;
              System.out.print((char) a[i]);
            }
          }
          System.out.println();
        } else System.out.println("  ERROR");
      }
    }
  }
}