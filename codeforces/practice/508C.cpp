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
#define MAX 100005
#define LOG_MAX 20
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL (LL(1e18))
#define chk(a) cerr << endl << #a << " : " << a << endl
#define chk2(a,b) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << endl
#define chk3(a,b,c) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << endl
#define chk4(a,b,c,d) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << "\t" << #d << " : " << d << endl
#define rep(i, a, n) for(i=a;i<n;i++)
#define rev(i, a, n) for(i=a;i>=n;i--)
#define MSV(A,a) memset(A, a, sizeof(A))
#define rep_itr(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)

using namespace std;

int main() {
	int n;
	cin>>n;
	LL a, b;
	priority_queue<LL> aq, bq;
	for(int i=0;i<n;i++) {
		cin>>a;
		aq.push(a);
	}
		
	for(int i=0;i<n;i++) {
		cin>>b;
		bq.push(b);
	}
	
	LL as = 0, bs = 0, ch = 0;
	while(true) {
		if(aq.empty() && bq.empty()) break;
		
		if(!ch) {
			if(aq.empty() || (!bq.empty() && bq.top() > aq.top())) {
				bq.pop();
			} else {
				as += aq.top();
				aq.pop();
			}
		} else {
			if(bq.empty() || (!aq.empty() && bq.top() < aq.top())) {
				aq.pop();
			} else {
				bs += bq.top();
				bq.pop();
			}
		}
		ch = !ch;
	}
	cout<<as-bs<<endl;
		

    return 0;
}

