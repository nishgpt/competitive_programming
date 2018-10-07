#include<bits/stdc++.h>
using namespace std;
#define LL long long int
int isqrt(int x)  
{  
    register int op, res, one;  
  
    op = x;  
    res = 0;  
  
    /* "one" starts at the highest power of four <= than the argument. */  
    one = 1 << 30;  /* second-to-top bit set */  
    while (one > op) one >>= 2;  
  
    while (one != 0) {  
        if (op >= res + one) {  
            op -= res + one;  
            res += one << 1;  // <-- faster than 2 * one  
        }  
        res >>= 1;  
        one >>= 2;  
    }  
    return res;  
}  
 
int p[1000001];
int main() {
	int i, j, k, n, t;
	memset(p, -1, sizeof p);
	p[0] = 0;
	for(i=1;i<1000001;i++) {
		int sq = isqrt(i);
		if(sq*sq == i) {
			p[i] = 1;
			continue;
		}
		int f = 0;
		for(j=1;;j++) {
			if(i-j*j > 0) {
				if(p[i-j*j] == 0) {
					p[i] = 1;
					f = 1;
					break;
				}
			}
			else break;
		}
		if(f == 0)p[i] = 0;
	}
	
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		if(p[n] == 0) {
			printf("Lose\n");
		}	
		else printf("Win\n");
	}
	return 0;
}