#include<bits/stdc++.h>
#define LL long long int
#define N 5005
using namespace std;

int main() {
    int n, i, j;

    cin>>n;
    int a[n];
    int ans[n];
    for(i=0;i<n;i++) {
        cin>>a[i];
        ans[i] = 1;
    }

    int final_ans = 1;
    for(i=1;i<n;i++) {
        int maxi = ans[i];
        for(j=0;j<=i;j++) {
            LL mul = ((LL) a[i]) * a[j];
            if(abs(a[j]) < abs(a[i]) && (mul < 0) && maxi < ans[j] + 1) {
                maxi = ans[j] + 1;
            }
        }
        ans[i] = maxi;
        final_ans = max(maxi, final_ans);
    }

    cout<<final_ans<<endl;
    return 0;
}
