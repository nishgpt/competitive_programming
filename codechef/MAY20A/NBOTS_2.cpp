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

struct info {
	int wipeOff;
	int sum;
	int st;
	int end;
	int rc;
	char dir;
};

bool operator <(info x, info y) {
	return x.dir > y.dir;
}

int a[MAX][MAX], n, f, k;
vector<info> l(MAX), r(MAX), u(MAX), d(MAX);
priority_queue<info> pq;

void print(info res) {
	cout<<"Info: dir="<<res.dir<<", rc="<<res.rc<<", wipeOff="<<res.wipeOff<<", st="<<res.st<<", end="<<res.end<<", sum"<<res.sum<<endl;
}

void print() {
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

void compute_info() {
	int i, j;
	int sum = 0, cnt = 0, end = 0;
	
	//LEFT and RIGHT info
	for(i=1;i<=n;i++) {
		sum = 0, cnt = 0, end = 0;
		for(j=1;j<=n;j++) {
			if(sum + a[i][j] > f) break;
			sum += a[i][j];
			cnt++;
			end = j;
		}
		l[i] = (info) {cnt, sum, 1, end, i, 'L'};
		pq.push(l[i]);
		
		sum = 0, cnt = 0, end = 0;
		for(j=n;j>0;j--) {
			if(sum + a[i][j] > f) break;
			sum += a[i][j];
			cnt++;
			end = j;
		}	
		r[i] = (info) {cnt, sum, n, end, i, 'R'};
		pq.push(r[i]);
	}
	
	//UP and DOWN info
	for(j=1;j<=n;j++) {
		sum = 0, cnt = 0, end = 0;
		for(i=1;i<=n;i++) {
			if(sum + a[i][j] > f) break;
			sum +=a[i][j];
			cnt++;
			end = i;
		}
		u[j] = (info) {cnt, sum, 1, end, j, 'U'};
		pq.push(u[j]);
		
		sum = 0, cnt = 0, end = 0;
		for(i=n;i>0;i--) {
			if(sum + a[i][j] > f) break;
			sum += a[i][j];
			cnt++;
			end = i;
		}	
		d[j] = (info) {cnt, sum, n, end, j, 'D'};
		pq.push(d[j]);
	}
}

info get_best_fire_info(char prev) {
	while(!pq.empty()) {
		info _top = pq.top();
		int rc = _top.rc;
		char dir = _top.dir;
		pq.pop();
		
		if(dir == 'L' && (l[rc].wipeOff == _top.wipeOff && l[rc].end == _top.end)) return _top;
		if(dir == 'R' && (r[rc].wipeOff == _top.wipeOff && r[rc].end == _top.end)) return _top;
		if(dir == 'U' && (u[rc].wipeOff == _top.wipeOff && u[rc].end == _top.end)) return _top;
		if(dir == 'D' && (d[rc].wipeOff == _top.wipeOff && d[rc].end == _top.end)) return _top;
		
	}
	
	return (info) {0, 0, 0, 0, 0, 'O'};
}

void handle_left_right_fire(info res) {
	int i, j;
	//loop over columns from st to end
	int _st = min(res.st, res.end);
	int _end = max(res.st, res.end);
	for(j=_st;j<=_end;j++) {
		if(!a[res.rc][j]) continue;
		
		//for UP
		if(u[j].end >= res.rc) {
			int sum = u[j].sum - a[res.rc][j], cnt = u[j].wipeOff - 1, end = u[j].end;
			for(i=u[j].end+1;i<=n;i++) {
				if(sum + a[i][j] > f) break;
				sum += a[i][j];
				if(a[i][j]) cnt++;
				end = i;
			}
			u[j].end = end; u[j].wipeOff = cnt; u[j].sum = sum;
			if(cnt) {
				pq.push(u[j]);
			}
		}
		
		//for DOWN
		if(d[j].end <= res.rc) {
			int sum = d[j].sum - a[res.rc][j], cnt = d[j].wipeOff - 1, end = d[j].end;
			for(i=d[j].end-1;i>=1;i--) {
				if(sum + a[i][j] > f) break;
				sum += a[i][j];
				if(a[i][j]) cnt++;
				end = i;
			}
			d[j].end = end; d[j].wipeOff = cnt; d[j].sum = sum;
			if(cnt) {
				pq.push(d[j]);
			}
		}
	}
	
	//now update for left and right of res.rc row
	int lst, lend, rst, rend;
	if(res.dir == 'L') {
		lst = res.end + 1;
		lend = n;
		rst = r[res.rc].st;
		rend = res.end + 1;
	} else {
		rst = res.end - 1;
		rend = 1;
		lst = l[res.rc].st;
		lend = res.end - 1;
	}
	
	int sum = 0, cnt = 0, end = -1;
	for(j=lst;j<=lend;j++) {
		if(sum + a[res.rc][j] > f) break;
		sum += a[res.rc][j];
		if(a[res.rc][j]) cnt++;
		end = j;
	}
	l[res.rc].end = end; l[res.rc].wipeOff = cnt; l[res.rc].sum = sum; l[res.rc].st = lst;
	if(cnt) {
		pq.push(l[res.rc]);		
	}
	
	sum = 0, cnt = 0, end = -1;
	for(j=rst;j>=rend;j--) {
		if(sum + a[res.rc][j] > f) break;
		sum += a[res.rc][j];
		if(a[res.rc][j]) cnt++;
		end = j;
	}
	r[res.rc].end = end; r[res.rc].wipeOff = cnt; r[res.rc].sum = sum; r[res.rc].st = rst;
	if(cnt) {
		pq.push(r[res.rc]);
	}
}

void handle_up_down_fire(info res) {
	int i, j;
	int _st = min(res.st, res.end);
	int _end = max(res.st, res.end);
	//loop over rows from st to end
	for(i=_st;i<=_end;i++) {
		if(!a[i][res.rc]) continue;
		//for LEFT
		if(l[i].end >= res.rc) {
			int sum = l[i].sum - a[i][res.rc], cnt = l[i].wipeOff - 1, end = l[i].end;
			for(j=l[i].end+1;j<=n;j++) {
				if(sum + a[i][j] > f) break;
				sum += a[i][j];
				if(a[i][j]) cnt++;
				end = j;
			}
			l[i].end = end; l[i].wipeOff = cnt; l[i].sum = sum;
			if(cnt) {
				pq.push(l[i]);
			}
		}
		
		//for RIGHT
		if(r[i].end <= res.rc) {
			int sum = r[i].sum - a[i][res.rc], cnt = r[i].wipeOff - 1, end = r[i].end;
			for(j=r[i].end-1;j>=1;j--) {
				if(sum + a[i][j] > f) break;
				sum += a[i][j];
				if(a[i][j]) cnt++;
				end = j;
			}
			r[i].end = end; r[i].wipeOff = cnt; r[i].sum = sum;
			if(cnt) {
				pq.push(r[i]);
			}
		}
	}
	
	//now update for up and down of res.rc col
	int ust, uend, dst, dend;
	if(res.dir == 'U') {
		ust = res.end + 1;
		uend = n;
		dst = d[res.rc].st;
		dend = res.end + 1;
	} else {
		dst = res.end - 1;
		dend = 1;
		ust = u[res.rc].st;
		uend = res.end - 1;
	}
	
	int sum = 0, cnt = 0, end = -1;
	for(i=ust;i<=uend;i++) {
		if(sum + a[i][res.rc] > f) break;
		sum += a[i][res.rc];
		if(a[i][res.rc]) cnt++;
		end = i;
	}
	u[res.rc].end = end; u[res.rc].wipeOff = cnt; u[res.rc].sum = sum; u[res.rc].st = ust;
	if(cnt) {
		pq.push(u[res.rc]);
	}
	
	sum = 0, cnt = 0, end = -1;
	for(i=dst;i>=dend;i--) {
		if(sum + a[i][res.rc] > f) break;
		sum += a[i][res.rc];
		if(a[i][res.rc]) cnt++;
		end = i;
	}
	d[res.rc].end = end; d[res.rc].wipeOff = cnt; d[res.rc].sum = sum; d[res.rc].st = dst;
	if(cnt) {
		pq.push(d[res.rc]);
	}
}

void update_when_left_right_fire(info res) {
	int _st = min(res.st, res.end);
	int _end = max(res.st, res.end);
	for(int j=_st;j<=_end;j++) {
		a[res.rc][j] = 0;
	}
}

void update_when_up_down_fire(info res) {
	int _st = min(res.st, res.end);
	int _end = max(res.st, res.end);
	for(int i=_st;i<=_end;i++) {
		a[i][res.rc] = 0;
	}
}

void fire(info res) {
	if(res.dir == 'L' || res.dir == 'R') {
		handle_left_right_fire(res);
		update_when_left_right_fire(res);
	} else {
		handle_up_down_fire(res);
		update_when_up_down_fire(res);
	}
}

void print_values() {
	cout<<"left values"<<endl;
	for(int i=1;i<=n;i++) {
		print(l[i]);
	}
	cout<<endl;
	cout<<"right values"<<endl;
	for(int i=1;i<=n;i++) {
		print(r[i]);
	}
	cout<<endl;
	cout<<"up values"<<endl;
	for(int i=1;i<=n;i++) {
		print(u[i]);
	}
	cout<<endl;
	cout<<"down values"<<endl;
	for(int i=1;i<=n;i++) {
		print(d[i]);
	}
	cout<<endl;
}

int main() {
	int i, j;
	
	inp(n);inp(f);
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) inp(a[i][j]);
	inp(k);
	
	compute_info(); //will compute and push in pq
	
	vector<pair<char, int> > ans;
	char prev = '#';
	while(true) {
		info res = get_best_fire_info(prev);
		if(res.dir == 'O' || res.wipeOff == 0 || res.sum == 0) break;
		
		ans.PB(MP(res.dir, res.rc));
		fire(res);
		prev = res.dir;
		
		//~print_values();
		//~cout<<"====================="<<endl;
	}
	
	if(ans.size() >= k) raise(SIGABRT);
	
	cout<<ans.size()<<"\n";
	for(i=0;i<ans.size();i++) {
		cout<<ans[i].X<<" "<<ans[i].Y<<endl;
	}
	
    return 0;
}
