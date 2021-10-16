/*
    Author: Team - baddy_boyz
    Members: Nishant Gupta, Arpit Uppal
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <cctype>
#include <utility>
#include <map>
#include <string>
#include <climits>
#include <set>
#include <sstream>
#include <utility>
#include <ctime>
#include <cassert>
#include <fstream>
#include <csignal>
using namespace std;

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 100005
#define MOD 1000000007

using namespace std;

bool basic_check(int *a, int n) {

    int i;
    for(i=1;i<n;i++) {
        if(a[i] != a[i-1]+1) return false;
    }

    return true;
}

void print(int *a, int n) {
    for(int i=0;i<n;i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

bool func(int *a, int *fill, int period, int n, int start, int end) {

        int i;

        int mod;
        bool imp;

        if((a[0]-1) < 0) {
            int positive = ((-1*(a[0]-1)) / period + 1) * period + (a[0] - 1);
            mod = positive % period;
        }

        else mod = (a[0]-1) % period;

        imp = false;
      
        for(i = 1; i <=start; i++) {

            int to_be_mod = (mod == period-1) ? 0 : mod + 1;
            mod = to_be_mod;
        
            if(fill[i] == 0 && a[i] != to_be_mod + 1) {
                imp = true;
                break;
            }

            if(fill[i] == 1 && a[i] - 1 < 0) {
                int positive = ((-1*(a[i]-1)) / period + 1) * period + (a[i]-1);
                if(positive % period != to_be_mod) {
                    imp = true;
                    break;
                }
            }
        }

        if(imp) return imp;

        if((a[end+1]-1) < 0) {
            int positive = ((-1*(a[end+1]-1)) / period + 1) * period + (a[end+1] - 1);
            mod = positive % period;
        }

        else mod = (a[end+1]-1) % period;

        for(i=end+2;i<n;i++) {
            int to_be_mod = (mod == period-1) ? 0 : mod + 1;
            mod = to_be_mod;
        
            if(fill[i] == 0 && a[i] != to_be_mod + 1) {
                imp = true;
                break;
            }
            if(fill[i] == 1 && a[i] - 1 < 0) {
                int positive = ((-1*(a[i]-1)) / period + 1) * period + (a[i]-1);
                if(positive % period != to_be_mod) {
                    imp = true;
                    break;
                }
            }
        }

        return imp;
}

int main() {
    int t, n, i;

    cin>>t;

    while(t--) {
        cin>>n;
        int a[n], fill[n];

        memset(fill, 0, sizeof fill);
        
        int c = 0; int first = -1;
        bool inf = true;
        for(i=0;i<n;i++) {
            cin>>a[i];
            if(a[i] != -1 && first == -1) first = i;
            if(a[i] == -1) {
                c++;
                fill[i] = 1;
            }
        }

        if(c == n) {
            cout<<"inf"<<endl;continue;
        }

        if(c) {
            //fill all -1
            int idx;
            for(idx = first+1;idx<n;idx++) {
                if(fill[idx]) a[idx] = a[first] + (idx-first);
            }

            for(idx=first-1;idx>=0;idx--) {
                if(fill[idx]) a[idx] = a[first] - (first-idx);
            }
        }
        
        if(basic_check(a, n)) {
            cout<<"inf"<<endl;
            continue;
        }

        bool impossible = false;
        int locha = -1;
        for(i=first+1;i<n;i++) {
            int x = a[first] + (i-first);

            if(a[i] > x) {
                impossible = true;
                break;
            }
            if(a[i] < x) {
                locha = i;
                break;
            }
        }

        if(impossible) {
            cout<<"impossible"<<endl;
            continue;
        }

        //work on locha
        int cnt = 1, end;
        bool imp = false;
        for(i=locha-1;;i--) {
            int to_fill = a[locha] - cnt;
            cnt++;
            if(to_fill < 1) {
                end = i;
                break;
            }
            if(to_fill >= 1 && i == first) {
                imp = true;
                break;
            }
            if(!fill[i] && a[i] != to_fill) {
                imp = true;
                break;
            }
            if(fill[i]) {
                a[i] = to_fill;
            }
        }
        if(imp) {
            cout<<"impossible"<<endl;
            continue;
        }

        cnt = 1;
        for(i=first+1;i<=end;i++) {
            int to_fill = a[first] + cnt;
            cnt++;
            if(fill[i]) a[i] = to_fill;
        }


        //print(a, n);
        bool flag = false;

        int ans = -1;

        int start = end;

        int period = a[end];
        //cout<<period<<endl;
        //print(a, n);
        
        while(true) {

            if(period < 1) {
             //   flag  = false;
                break;
            }

            if(start < first) {
                break;
            }

            if((end - start)% period == 0) {
            
                if(!func(a, fill, period, n, start, end)) {
                    ans = period;
                    flag = true;
                    break; 
                }
            }

            start--;
            period = a[start];
        }

        if(!flag) {
            cout<<"impossible"<<endl;continue;
        } else {
            cout<<ans<<endl;
        }
    }
    return 0;
}