#include<bits/stdc++.h>
using namespace std;
#define LL long long int 
 
int main() {
	int i, j, k, n, t, m;
	scanf("%d", &t);
	j = 1;
	char c;
 
	while(t--) {
		stack<pair<int, int> > st;
		//<<"Case "<<j++<<":"<<endl;
		printf("Case %d:\n", j++);
		scanf("%d", &n);
		while(n--) {
			getchar();
			scanf("%c", &c);
			if(c == 'A') {
				getchar();
				scanf("%d", &k);
				if(st.empty()) {
					m = k;
				}
				else m = max(st.top().second, k);
				st.push(make_pair(k, m));
			}
			else if(c == 'R') {
				if(!st.empty())
					st.pop();
			}
			else {
				if(st.empty()) {
					printf("Empty\n");
				}
				else printf("%d\n", st.top().second);
			}
		}
	}
	return 0;
} 