import java.io.*;
class brack {
 public static void main(String args[]) throws IOException {
  BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));
  int i, a = 0, b = 0, j = 0, d = 0, q = 0, p = 0, sum = 0, t = 1;
  String s = cin.readLine();
  char c[] = new char[2000];
  for (; s.charAt(0) != '-';) {
   j = 0;
   for (i = 0; i < 2000; i++)
    c[i] = 'x';
   for (i = 0; i < s.length(); i++) {
    if (s.charAt(i) == '{') {
     c[j] = '{';
     j++;
    } else {
     if (j != 0) {
      if (c[j - 1] == '{') {
       c[j - 1] = 'x';
       j--;
      } else {
       c[j] = '}';
       j++;
      }
     } else {
      c[j] = '}';
      j++;
     }
    }
   }
   for (i = 0; i < j; i++) {
    if (c[i] == '{') {
     p++;
     sum++;
     a++;
    } else if (c[i] == '}') {
     sum--;
     q++;
     b++;
    }
    if (sum == 0) {
     d = d + ((p + q) / 2);
     q = 0;
     p = 0;
    }
   }
   if (sum != 0)
    d = d + ((p + q) / 2);
   if (a % 2 != 0 && b % 2 != 0)
    d = d + 1;
   System.out.println(t + ". " + d);
   t++;
   q = 0;
   d = 0;
   sum = 0;
   p = 0;
   a = 0;
   b = 0;
   s = cin.readLine();
  }
 }
}