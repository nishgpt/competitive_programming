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
	int t, n, k, c;
	
	cin>>t;
	while(t--) {
		cin>>n>>k;
		vector<vector<int> > v;
		for(int i=0;i<k;i++) {
			cin>>c;
			vector<int> sub(c);
			for(int j=0;j<c;j++) 
				cin>>sub[j];
			v.PB(sub);
		}
		//get max
		cout<<"? "<<n<<" ";
		for(int i=1;i<=n;i++) cout<<i<<" ";
		cout<<endl;
		
		int maxi, low = 0, high = k-1, res, ans = -1;
		cin>>maxi;
		
		while(low <= high) {
			chk2(low, high);
			int mid = (low + high) >> 1;
			
			vector<int> q;
			for(int i=low;i<=mid;i++)
				for(int j=0;j<v[i].size();j++) 
					q.PB(v[i][j]);
			
			cout<<"? "<<q.size()<<" ";
			for(int i=0;i<q.size();i++) cout<<q[i]<<" ";
			cout<<endl;
			
			cin>>res;
			if(res == maxi) {
				ans = mid;
				high = mid-1;
			} else {
				low = mid + 1;
			}
		}
		
		int separate;
		if(ans != -1) {
			set<int> s;
			for(int i=0;i<v[ans].size();i++) s.insert(v[ans][i]);
			
			cout<<"? "<<n-s.size()<<" ";
			for(int i=1;i<=n;i++) {
				if(s.find(i) == s.end()) cout<<i<<" ";
			}
			cout<<endl;
			
			cin>>separate;
		}
		cout<<"! ";
		for(int i=0;i<k;i++) {
			if(i == ans) cout<<separate<<" ";
			else cout<<maxi<<" ";
		}
		cout<<endl;
		
		string verdict;
		cin>>verdict;
		if(verdict.compare("Correct") != 0) return 0;
	}

    return 0;
}

