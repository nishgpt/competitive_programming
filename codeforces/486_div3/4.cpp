#include<bits/stdc++.h>
#define MAX 200005
using namespace std;

bool found(int *a, int n, int f) {
    return binary_search(a, a+n, f);
}

int main() {
    int i, j, k, n, m;
    cin>>n;

    int a[MAX];
    for(i=0;i<n;i++) {
        cin>>a[i];
    }

    sort(a, a+n);

    int p = 1;
    int mm = 1;
    int factor, start;
    for(i=0;i<31;i++) {
        for(j=0;j<n;j++) {
            //cout<<p<<endl; 
            int l = a[j];
            int h = a[j] + ((a[n-1]-a[j]) / p) * p;
            cout<<"here "<<l<<" "<<h<<endl;
            int maxa = -1;
            while(l<=h) {
                int mid = (l+h)>>1;
                if(!found(a, n, mid)) {maxa = mid; h = mid-1;}
                else l = mid+1;
            }
            int size=1;
            if(maxa != -1) {
                size = (maxa-a[j])/p + 1;
            }
            vector<int> ansi;
            if(mm<size) {
                mm=size;
                factor = p;
                start = a[j];
           }
        }
        p = p<<1;
    }
    
    if(mm == 1) {
        cout<<1<<endl;
        cout<<a[0]<<endl;
    } else {
        cout<<mm<<endl;
        while(mm--) {
            cout<<start<<" ";
            start = start+factor;
        }
    }
    return 0;
}
