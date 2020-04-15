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
		int limit = n/3;
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
		
		for(i=0;i<n;i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
    return 0;
}

