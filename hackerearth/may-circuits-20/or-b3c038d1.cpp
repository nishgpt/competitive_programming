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

LL p[MAX], a, b, i, j;
void pre() {
    p[0] = 1;
    for(i=1;i<MAX;i++) p[i] = p[i-1]*2;
}

string to_binary(LL num) {
	string s;
	while(num) {
		if(num&1) s=s+'1';
		else s=s+'0';
		num>>=1;
	}
	for(i=s.length();i<=60;i++) {
		s = s+'0';
	}
	reverse(s.begin(), s.end());
	return s;
}

void brute() {
	vector<LL> v;
    map<LL, bool> mp;
    rep(i,a,b+1) {
        v.PB(i);
        mp[i] = true;
    }
 
    int sz = v.size();
    for(i=0;i<p[sz];i++) {
        LL or_ = 0;
        for(j=0;j<sz;j++) {
           if(i&p[j]) or_ = (or_ | v[j]); 
        }
        if(or_) mp[or_] = true;
    }
 
	map<LL, bool> :: iterator it = mp.begin();
    while(it != mp.end()) {
		cout<<it->first<<" -> "<<to_binary(it->first)<<endl;
		it++;
	}
}

LL get_msb(string s) {
	for(i=0;i<=60;i++) {
		if(s[i] == '1') return i;
	}
	return -1;
}

LL merge_ranges(vector<pair<LL, LL> > ranges) {
	int rs = ranges.size();
	LL ans = ranges[0].Y - ranges[0].X + 1;
	if(rs>1 && ranges[1].X > ranges[0].Y) {
		ans += (ranges[1].Y - ranges[1].X + 1);
	} else if(rs > 1) {
		if(ranges[1].Y > ranges[0].Y) ans += (ranges[1].Y - ranges[0].Y);
	}
	
	if(rs>2 && ranges[2].X > ranges[1].Y) {
		ans += (ranges[2].Y - ranges[2].X + 1);
	} else if(rs > 2) {
		if(ranges[2].Y > ranges[1].Y) ans += (ranges[2].Y - ranges[1].Y);
	}
	
	return ans;
}

int main() {
	
    pre();
    inp1(a);inp1(b);
    brute();
    LL l1 = a, r1=b;
    string as = to_binary(a);
	string bs = to_binary(b);
	
	for(i=60;i>=0;i--) {
		if(bs[i] == '1') break;
	}
	
	LL l2 = -1, r2 = -1;
	if(60-i > 0) {
		LL diff = ((1L)<<(60-i)) - 1;
		l2 = b+1;
		r2 = b+diff;
	}
	
	LL amsb = get_msb(as), bmsb = get_msb(bs);
	for(j=amsb+1;j<=60;j++) {
		if(as[j] == '0' && bs[j] == '1') break;
	}
	chk(j);
	
	LL l3=-1, r3=-1;
	if(j>60) l3 = b | a;
	else l3 = (b - (1L<<(60-j))) | a;
	
	if(amsb > bmsb) {
		r3 = ((1L)<<(61-bmsb)) - 1;
	} else {
		for(j=amsb+1;j<=60;j++) {
			if(as[j] == '0' && bs[j] == '1') break;
		}
		LL xyz = (((1L)<<(61-j)) - 1);
		chk(xyz);
		r3 = b | xyz;
	}
	
	LL l4=-1, r4=-1;
	LL candidate = a|b, last_bit;
	chk(b);
	string cs = to_binary(candidate);
	for(i=0;i<61;i++) {
		if(cs[i] == '1' && (candidate - ((1L)<<(60-i))) > b) {
			chk(i);
			candidate = candidate - ((1L)<<(60-i));
			chk(candidate);
			cs[i] = '0';
		}
		if(cs[i] == '1') last_bit = i;
	}
	l4 = candidate;
	r4 = l4 + ((1L) << (60-last_bit)) - 1;
	
	chk2(l1, r1);
	chk2(l2, r2);
	chk2(l3, r3);
	chk2(l4, r4);
	vector<pair<LL, LL> > ranges;
	if(l1 != -1 && r1 != -1) ranges.PB(MP(l1, r1));
	if(l2 != -1 && r2 != -1) ranges.PB(MP(l2, r2));
	if(l3 != -1 && r3 != -1) ranges.PB(MP(l3, r3));
	//~if(l4 != -1 &&
	
	sort(ranges.begin(), ranges.end());
	
	LL ans = merge_ranges(ranges);
	
	cout<<ans<<endl;
    

    return 0;
}

