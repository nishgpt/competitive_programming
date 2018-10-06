#include <bits/stdc++.h>

using namespace std;

int main() {
   int t, n, a, b;
   cin>>t;
   
   while(t--) {
       cin>>n>>a>>b;

       int arr[n], freq[n+1];
       memset(freq, 0, sizeof freq);

       for(int i=0;i<n;i++) {
           cin>>arr[i];
           freq[arr[i]]++;
       }

       double ans = freq[a]* 1.00 / n;
       ans = ans * freq[b] / n;

       printf("%0.6lf\n", ans);
   }

   return 0;
}

