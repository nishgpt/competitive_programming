/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 100005
#define INF 1000000000
#define MOD 1000000007

using namespace std;

int main() {
	int t, n, m, k;
	cin>>t;
	
	while(t--) {
		scanf("%d %d %d", &n, &m, &k);
		int a[n][k];
		int i, j;
		int ans[n];
		int limit = n>>1;
		
		for(i=0;i<n;i++) {
			for(j=0;j<k;j++) {
				scanf("%d", &a[i][j]);
			}
		}
		
		for(i=0;i<=limit;i++) {
			int freq[10] = {0};
			for(j=0;j<k;j++) {
				freq[a[i][j]]++;
			}
	
			int maxi = -1;
			int answer = -1;
			for(j=1;j<=m;j++) {
				if(maxi < freq[j]) {
					maxi = freq[j];
					answer = j;
				}
			}
			ans[i] = answer;
		}
		
		//get scores till now
		int score[k];
		memset(score, 0, sizeof score);
		for(i=0;i<=limit;i++) {
			for(j=0;j<k;j++) {
				if(a[i][j] == ans[i]) {
					score[j]++;
				}
			}
		}
		
		//now try to balance the scores in the remaining question
		for(i=limit+1;i<n;i++) {
			//find the question with minimum score
			int mini = INF;
			int ques = -1;
			for(j=0;j<k;j++) {
				if(mini > score[j]) {
					mini = score[j];
					ques = j;
				}
			}
			
			//take the answer for that question as the accepted one
			ans[i] = a[i][ques];
			for(j=0;j<k;j++) {
				if(a[i][j] == ans[i]) {
					score[j]++;
				}
			}
		} 
		/*
		for(i=0;i<n;i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
		*/
		priority_queue<pair<int, int>, std::vector<pair<int, int> >, std::greater<pair<int, int> > > pq;
		for(i=0;i<k;i++) {
			pq.push(mp(score[i], i));
		}
		
		int limit2 = k;
		while(limit2--) {
			pair<int, int> _top = pq.top();
			pq.pop();
			int mini_score = _top.first;
			int ques = _top.second; 
			if(score[ques] != mini_score) {
				//if score present in pq does not matches current score 
				//then its obsolete record, ignore and move ahead
				continue;
			}
			
			for(i=0;i<n;i++) {
				if(a[i][ques] == ans[i]) continue; //if ans already matches, no sweat
				
				bool flag = true;
				int ans_to_be_chosen = a[i][ques];
				for(j=0;j<k;j++) {
					if(a[i][j] != ans_to_be_chosen &&  a[i][j] == ans[i] && score[j]-1 < mini_score) {
						flag = false;
						break;
					}
				}
				
				if(flag == true) {
					for(j=0;j<k;j++) {
						if(a[i][j] != ans_to_be_chosen && a[i][j] == ans[i]) {
							score[j]--;
							pq.push(mp(score[j], j));
						}
						else if(a[i][j] == ans_to_be_chosen) {
							score[j]++;
							pq.push(mp(score[j], j));
						}
					}
					ans[i] = ans_to_be_chosen;
					break;
				} 
			}
		}
		for(i=0;i<n;i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
    return 0;
}
