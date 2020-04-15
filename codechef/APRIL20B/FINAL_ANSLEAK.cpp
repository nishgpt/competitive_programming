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
		int limit = n/5;
		int rev[n][10];
		memset(rev, 0, sizeof rev);
		for(i=0;i<n;i++) {
			for(j=0;j<k;j++) {
				scanf("%d", &a[i][j]);
				//how many question papers have a[i][j] as the answer to ith question
				rev[i][a[i][j]]++; 
			}
		}
		
		int score[k];
		memset(score, 0, sizeof score);
		
		//greedy go for answer which covers maximum question papers
		for(i=0;i<=limit;i++) {
			int maxi = -1;
			int answer = -1;
			for(j=1;j<=m;j++) {
				if(maxi < rev[i][j]) {
					maxi = rev[i][j];
					answer = j;
				}
			}
			ans[i] = answer;
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
			int ques_paper = -1;
			for(j=0;j<k;j++) {
				if(mini > score[j]) {
					mini = score[j];
					ques_paper = j;
				} else if(mini == score[j] && rev[i][a[i][ques_paper]] < rev[i][a[i][j]]) {
					mini = score[j];
					ques_paper = j;
				}
			}
			
			//take the answer for that question as the accepted one
			ans[i] = a[i][ques_paper];
			for(j=0;j<k;j++) {
				if(a[i][j] == ans[i]) {
					score[j]++;
				}
			}
		} 
		
		int xy = 400;
		while(xy--) {
			//find minimum score and its question paper
			int ms = INF;
			int paper = -1;
			for(i=0;i<k;i++) {
				if(ms > score[i]) {
					ms = score[i];
					paper = i;
				}
			}
			
			for(i=0;i<n;i++) {
				int ans_paper = a[i][paper];
				if(ans_paper == ans[i]) continue;
				
				bool f = true;
				for(j=0;j<k;j++) {
					if(a[i][j] == ans[i] && (score[j]-1) <= ms) {
						f = false;
						break;
					}
				}
				
				if(f) {
					for(j=0;j<k;j++) {
						if(a[i][j] == ans[i]) {
							score[j]--;
						}
						else if(a[i][j] == ans_paper) {
							score[j]++;
						}
					}
					ans[i] = ans_paper;
					break;
				}
			}
		}
		
		xy = 1;
		while(xy--) {
			//find minimum score and its question paper
			int ms = INF;
			for(i=0;i<k;i++) {
				if(ms > score[i]) {
					ms = score[i];
				}
			}
			
			//get all minimum ones
			vector<int> v;
			for(i=0;i<k;i++) {
				if(ms == score[i]) v.pb(i);
			}
			
			for(i=0;i<n;i++) {
				bool f = true;
				for(j=0;j<k;j++) {
					if(a[i][j] == ans[i] && (score[j]-1) <= ms) {
						f = false;
						break;
					}
				}
				
				if(f) {
					int freq[m+1];
					memset(freq, 0, sizeof freq);
					for(int x=0;x<v.size();x++) {
						freq[a[i][v[x]]]++;
					}
					
					int maxi =-1;
					int final_ans = -1;
					for(j=1;j<=m;j++) {
						if(maxi <= freq[j]) {
							maxi = freq[j];
							final_ans = j;
						}
					}
					
					for(j=0;j<k;j++) {
						if(ans[i] == a[i][j]) score[j]--;
						else if(a[i][j] == final_ans) score[j]++;
					}
					ans[i] = final_ans;
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
