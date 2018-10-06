/*
 Author : Nishant Gupta 2.0
  */
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 100005
#define LIMIT 1000000000
#define MOD 1000000007

 /**
 Logic to be applied :
  - Binary search on heights for all possibilities
  - the possibility logic for a "mid" height is for all heights (hi) in array < mid
  - create a vector of all such (i, i+w)
  - sort them on start idx which is i
  - start from smallest i and do a greedy provision water to attain mid height
 **/
 using namespace std;

 int n, m, w;
 LL a[MAX];

 bool possible(LL mid) {
     vector<pair<int, int> > ranges;

     int i;
     for(i=0;i<n;i++) {
        if(a[i] < mid) {
            int st = i;
            int end = (i+w-1) < n : (i+w-1) : (i-w+1);
            ranges.pb(mp(st, end));
        }
     }

     sort(ranges.begin(), ranges.end());

    LL curr = 0; int left = m, st = 0;
     for(i=0;i<ranges.size();) {
         if(!i) {
            LL need = mid - a[ranges[i].first];
            left = left - need;
            curr += need;
            i++;
         } else {
             LL need = mid - a[ranges[i].first];
             if(ranges[i].first <= ranges[st].second) {
                 need = need - curr;
                 a[ranges[i].first] += curr;
             } else {
                 st++;
             }
         }
     }
 }

 int main() {
     int i, j, k;

     cin>>n>>m>>w;
     for(i=0;i<n;i++) {
         cin>>a[i];
     }

     LL low = 0, high = LIMIT;
    LL ans = -1;
     while(low <= high) {
         LL mid = (low+high) >> 1;
         if(possible(mid)) {
            ans = mid;        
            low = mid + 1;
         } else {
             high = mid - 1;
         }
     }

     cout<<ans<<endl;
     return 0;
 }
