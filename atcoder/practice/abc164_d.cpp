/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define getcx getchar_unlocked
#define X first
#define Y second
#define PB push_back
#define MP make_pair
#define MAX 200005
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL (LL(1e18))
#define rep(i, a, n) for(i=a;i<n;i++)
#define rev(i, a, n) for(i=a;i>=n;i--)
#define MSV(A,a) memset(A, a, sizeof(A))
#define rep_itr(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)

using namespace std;

inline void inp( int &n ) { 
	n=0;    int ch=getcx();int sign=1;   
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();} 
	while(  ch >= '0' && ch <= '9' )    
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}

inline void inp1( LL &n ) { 
	n=0;    LL ch=getcx();LL sign=1;   
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();} 
	while(  ch >= '0' && ch <= '9' )    
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}
/*
int mod[MAX];
int first[2019];
vector<int> possible;
void pre() {
	memset(first, -1, sizeof first);
	int i;
	int x = 10;
	for(i=1;i<MAX;i++) {
		if(first[x] == -1) {
			first[x] = i;
		}
		x = (x*10) % 2019;
	}
	
	for(i=1;i<2019;i++) {
		if(first[i] != -1) possible.PB(i);
	}
}
*/
vector<int> mods[2019];
int main() {
	string s;
	int i, j;
	//pre();
	cin>>s;
	
	LL ans = 0;
	int r = 0;
	int x = 1;
	int freq[2019] = {0};
	for(i=s.length()-1;i>=0;i--) {
		r = (r + x*(s[i]-'0')) % 2019;
		x = (x*10)%2019;
		freq[r]++; 
	}
	
	
	for(i=1;i<2019;i++) {
		ans = ans + (freq[i]*(freq[i]-1))/2;
	}
	
	ans = ans + (freq[0]*(freq[0]+1))/2;
	
	cout<<ans<<endl;
	
    return 0;
}

