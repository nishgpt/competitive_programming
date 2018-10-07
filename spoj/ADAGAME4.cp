#include "bits/stdc++.h"
#include<signal.h>
using namespace std;
#define LL long long int
#define MAX 20000007
#define LIM 20000007
 
//d[i][0] = number of divisors of number i
//d[i][1] = number i after being divided by some prime divisors
//int d[MAX][2];
int ans[MAX];
int numdiv[MAX];
int prime[MAX];
 
void sieve() {
 
    int i, j;
 
    numdiv[1] = 1;
 
    for(i = 2; i * i < LIM; i++) {
 
        if(prime[i] == 0) {
            prime[i] = i;
            for(j = 2*i; j < LIM; j += i) {
                prime[j] = i;
            }
        }
    }
 
    for(; i < LIM; i++ ){
        if(prime[i] == 0) {
            prime[i] = i;
        }
    }
 
    numdiv[0] = 0;
    numdiv[1] = 1;
 
    for(i = 2; i <LIM; i++) {
 
        int cnt = 0;
        j = i;
        while(j % prime[i] == 0) {
            cnt++;
            j /= prime[i];
        }
        numdiv[i] = numdiv[j] * (cnt + 1);
    }
    int lastv = 0;
    for(i=3;i<LIM;i++) {
        if(i - numdiv[i] > lastv) {
            ans[i] = 1;
            lastv = i;
        }
    }
}
 
int main() {
    int i, n, t;
    scanf("%d", &t);
    
    sieve();
 
    while(t--) {
        scanf("%d", &n);
        if(ans[n]) cout<<"Vinit"<<endl;
        else cout<<"Ada"<<endl;
    }
} 