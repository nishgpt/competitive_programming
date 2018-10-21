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
using namespace std;
typedef long long LL;
#define MS(A) memset(A, 0, sizeof(A))
#define MSV(A,a) memset(A, a, sizeof(A))
#define MAX(a,b) ((a >= b) ? (a) : (b))
#define MIN(a,b) ((a >= b) ? (b) : (a))
#define ABS(a) (((a) > 0) ? (a) : (-a))
#define MP make_pair
#define PB push_back
#define getcx getchar_unlocked
#define INF (int(1e9))
#define INFL (LL(1e18))
#define EPS 1e-12
#define chkbit(s, b) (s & (1<<b))
#define setbit(s, b) (s |= (1<<b))
#define clrbit(s, b) (s &= ~(1<<b))


int coprime[51][51];
int parent[60];


int find(int u)
{
	if(u==parent[u])
	return u;
	int root=find(parent[u]);
	parent[u]=root;
	return root;
}

void uni(int u,int v)
{
	int ans1=find(u);
	int ans2=find(v);
	parent[ans1]=ans2;
}


int gcd(int a, int b) {

	if(a < b) return gcd(b,a);

	if(b == 0) return a;

	return gcd(b, a%b);
}


void pre() {

	int i, j;

	for(i = 2; i <=50; i++) {

		for(j = 2; j <= 50; j++) {

			if(gcd(i,j) == 1) {
				coprime[i][j] = 1;
			}
		}

	}
}


int main() {

	pre();

	int primes[15] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};

	int t;
	scanf("%d", &t);

	while(t--) {

		int n, i, j, m, flag = 0, pos = 0, ans = 0;
		set<int> numset;

		vector<int> vec;
		int hashi[100] = {0};

		scanf("%d", &n);

		for(i = 0; i < n; i++) {
			scanf("%d", &m);

			vec.PB(m);
			numset.insert(m);

			hashi[m]= 1;
			parent[m]=m;
		}


		for(i = 0; i < n ; i++) {

			for(j = i+1; j < n ; j++) {

				if(coprime[vec[i]][vec[j]] == 1) {
					uni(vec[i], vec[j]);
				}
			}

		}


		// for(i = 0; i < n; i++) {
		// 	printf("ele %d parent %d \n", vec[i], parent[vec[i]]);
		// }

		//find no. of disjoint sets now
		set<int> disjointsets;

		for(i = 0 ; i < n; i++) {
			disjointsets.insert(find(vec[i]));
		}


		if(n == 1) {

			printf("0\n");

			for(i = 0; i < n; i++) {
				printf("%d ", vec[i]);
			}

			printf("\n");
			continue;
		}

		if(numset.size() == 1) {
			
			printf("1\n");
			
			if(hashi[47] != 1) {

				vec[0] = 47;

			} else {
				vec[0] = 43;
			}

			for(i = 0; i < n; i++) {
					printf("%d ", vec[i]);
			}

			printf("\n");

			continue;
		}

		if(disjointsets.size() == 1) {

			printf("0\n");

			for(i = 0; i < n; i++) {
				printf("%d ", vec[i]);
			}

			printf("\n");

		} else {

			printf("1\n");
			if(hashi[47] != 1) {

				vec[0] = 47;

			} else {
				vec[0] = 43;
			}

			for(i = 0; i < n; i++) {
					printf("%d ", vec[i]);
			}

			printf("\n");
		}


		// for(i = 0; i < n; i++) {
		// 	parent[vec[i]] = 0;
		// }
	}

	return 0;
}