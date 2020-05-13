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
#define MAX 520
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

int a[MAX][MAX], n, f, k;
pair<char, int> get_fire_info() {
	int i, j;
	char dir = 'O';
	int maxi_fired = 0;
	int row_num = -1;
	int col_num = -1;
	
	//from LEFT
	int left_row = -1, maxi_left = 0;
	for(i=1;i<=n;i++) {
		int sum = 0;
		int cnt = 0;
		for(j=1;j<=n;j++) {
			if(a[i][j]) {
				if(sum + a[i][j] > f) break;
				sum += a[i][j];
				cnt++;
			}
		}
		if(cnt > maxi_left) {
			maxi_left = cnt;
			left_row = i;
		}
	}
	if(maxi_left > maxi_fired) {
		maxi_fired = maxi_left;
		row_num = left_row;
		dir = 'L';
	}
	
	
	//from RIGHT
	int right_row = -1, maxi_right = 0;
	for(i=1;i<=n;i++) {
		int sum = 0;
		int cnt = 0;
		for(j=n;j>=1;j--) {
			if(a[i][j]) {
				if(sum + a[i][j] > f) break;
				sum += a[i][j];
				cnt++;
			}
		}
		if(cnt > maxi_right) {
			maxi_right = cnt;
			right_row = i;
		}
	}
	if(maxi_right > maxi_fired) {
		maxi_fired = maxi_right;
		row_num = right_row;
		dir = 'R';
	}
	
	//from UP
	int up_col = -1, maxi_up = 0;
	for(j=1;j<=n;j++) {
		int sum = 0;
		int cnt = 0;
		for(i=1;i<=n;i++) {
			if(a[i][j]) {
				if(sum + a[i][j] > f) break;
				sum += a[i][j];
				cnt++;
			}
		}
		if(cnt > maxi_up) {
			maxi_up = cnt;
			up_col = j;
		}
	}
	if(maxi_up > maxi_fired) {
		maxi_fired = maxi_up;
		col_num = up_col;
		dir = 'U';
	}
	
	//from DOWN
	int down_col = -1, maxi_down = 0;
	for(j=1;j<=n;j++) {
		int sum = 0;
		int cnt = 0;
		for(i=n;i>=1;i--) {
			if(a[i][j]) {
				if(sum + a[i][j] > f) break;
				sum += a[i][j];
				cnt++;
			}
		}
		if(cnt > maxi_down) {
			maxi_down = cnt;
			down_col = j;
		}
	}
	if(maxi_down > maxi_fired) {
		maxi_fired = maxi_down;
		col_num = down_col;
		dir = 'D';
	}
	
	if(dir == 'L' || dir == 'R') return MP(dir, row_num);
	else return MP(dir, col_num);
}

void update(pair<char, int> info) {
	int i, j;
	if(info.X == 'L') {
		i = info.Y;
		int sum = 0;
		for(j=1;j<=n;j++) {
			if(a[i][j]) {
				if(sum + a[i][j] > f) break;
				sum+=a[i][j];
				a[i][j] = 0;
			}
		}
		return;
	}
	
	if(info.X == 'R') {
		i = info.Y;
		int sum = 0;
		for(j=n;j>=1;j--) {
			if(a[i][j]) {
				if(sum + a[i][j] > f) break;
				sum += a[i][j];
				a[i][j] = 0;
			}
		}
		return;
	}
	
	if(info.X == 'U') {
		j = info.Y;
		int sum = 0;
		for(i=1;i<=n;i++) {
			if(a[i][j]) {
				if(sum + a[i][j] > f) break;
				sum += a[i][j];
				a[i][j] = 0;
			}
		}
		return;
	}
	
	if(info.X == 'D') {
		j = info.Y;
		int sum = 0;
		for(i=n;i>=1;i--) {
			if(a[i][j]) {
				if(sum + a[i][j] > f) break;
				sum += a[i][j];
				a[i][j] = 0;
			}
		}
		return;
	}
}


void print() {
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main() {
	int i, j;
	
	inp(n);inp(f);
	
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) inp(a[i][j]);
	
	inp(k);
	
	pair<char, int> res;
	vector<pair<char, int> > ans;
	int sum, cnt, maxi;
	char dir;
	for(i=1;i<=n;i++) {
		maxi = 0;dir = 'O';
		
		for(j=1;j<=n;j++) {
			if(!a[i][j]) continue;
			
			//check LEFT
			sum = 0; cnt = 0;
			for(int p=j;p<=n;p++) {
				if(a[i][p] + sum > f) break;
				sum += a[i][p];
				cnt++;
			}
			if(cnt > maxi) {
				dir = 'L';
				maxi = cnt;
			}
			
			//check UP
			sum = 0; cnt = 0;
			for(int p=i;p<=n;p++) {
				if(a[p][j] + sum > f) break;
				sum += a[p][j];
				cnt++;
			}
			if(cnt > maxi) {
				dir = 'U';
				maxi = cnt;
			}

			sum = 0;
			if(dir == 'L') {
				for(int p=j;p<=n;p++) {
					if(a[i][p] + sum > f) break;
					sum += a[i][p];
					a[i][p] = 0;
				}
				ans.PB(MP(dir, i));
			} else {
				for(int p=i;p<=n;p++) {
					if(a[p][j] + sum > f) break;
					sum += a[p][j];
					a[p][j] = 0;
				}
				ans.PB(MP(dir, j));
			}
			
			//~print();
			//~cout<<"============"<<endl;
		}
	}
	
	//~raise(SIGABRT);
	
	if(ans.size() >= k) raise(SIGABRT);
	
	cout<<ans.size()<<"\n";
	for(i=0;i<ans.size();i++) {
		cout<<ans[i].X<<" "<<ans[i].Y<<"\n";
	}
	
    return 0;
}

